#include "Tools.h"
#include "Drawer.h"
#include "Map.h"
#include <algorithm>

extern Map map;
extern Drawer drawer;

bool Tools::IsCollision(hgeSprite* spr1, 
	                    float x1, float y1, 
	                    hgeSprite* spr2, 
	                    float x2, float y2, 
	                    HTEXTURE hot1 , HTEXTURE hot2 , 
	                    DWORD airColor)
{
	/** Set the rect */  
	hgeRect r1, r2;  
	r1.Set(x1, y1, x1 + spr1->GetWidth(), y1 + spr1->GetHeight());  
	r2.Set(x2, y2, x2 + spr2->GetWidth(), y2 + spr2->GetHeight());  

	/** Test for the intersect of rectangles */  
	if(r1.Intersect(&r2))  
	{  
		int x[] = { x1, x2, x1 + spr1->GetWidth(), x2 + spr2->GetWidth() };  
		int y[] = { y1, y2, y1 + spr1->GetHeight(), y2 + spr2->GetHeight() };  
		std::sort(x, x + 4);  
		std::sort(y, y + 4);  
		hgeRect r;  

		/** Set the rectangle area where the two rectangles intersected. */  
		r.Set(x[1], y[1], x[2], y[2]);  

		/** The start point of sprite1 and sprite2. (From the intersected area) */  
		int sx1, sy1, sx2, sy2;  
		sx1 = x[1] - x1;  
		sy1 = y[1] - y1;  
		sx2 = x[1] - x2;  
		sy2 = y[1] - y2;  

		/** Get the "hotspot" of texture */  
		HTEXTURE hTex1 = hot1;  
		HTEXTURE hTex2 = hot2;  
		if(hTex1 == 0) hTex1 = spr1->GetTexture();  
		if(hTex2 == 0) hTex2 = spr2->GetTexture();  

		float tx1, ty1, tw1, th1, tx2, ty2, tw2, th2;  
		int w1 = drawer.get_hge()->Texture_GetWidth(hTex1), w2 = drawer.get_hge()->Texture_GetWidth(hTex2);  
		spr1->GetTextureRect(&tx1, &ty1, &tw1, &th1);  
		spr2->GetTextureRect(&tx2, &ty2, &tw2, &th2);  

		DWORD* color1 = new DWORD[(x[2] - x[1]) * (y[2] - y[1])];  
		DWORD* color2 = new DWORD[(x[2] - x[1]) * (y[2] - y[1])];  
		DWORD* color;  

		/** Copy the effectivearea of texture 1 */  
		color = drawer.get_hge()->Texture_Lock(hTex1, true);  
		for(int i = 0; i < y[2] - y[1]; i++)  
		{  
			for(int j = 0; j < x[2] - x[1]; j++)  
			{   
				color1[i * (x[2] - x[1]) + j] = color[((int)ty1 + sy1) * w1 + (int)tx1 + sx1 + i * w1 + j];  
			}   
		}   
		drawer.get_hge()->Texture_Unlock(hTex1);  

		/** Copy the effectivearea of texture 2 */  
		color = drawer.get_hge()->Texture_Lock(hTex2, true);  
		for(int i = 0; i < y[2] - y[1]; i++)  
		{  
			for(int j = 0; j < x[2] - x[1]; j++)   
			{   
				color2[i * (x[2] - x[1]) + j] = color[((int)ty2 + sy2) * w2 + (int)tx2 + sx2 + i * w2 + j];   
			}   
		}   
		drawer.get_hge()->Texture_Unlock(hTex2);  

		/** Test for the collision */  
		for(int i = 0; i < y[2] - y[1]; i++)  
		{  
			for(int j = 0; j < x[2] - x[1]; j++)  
			{  
				if(color1[i * (x[2] - x[1]) + j] != airColor && color2[i * (x[2] - x[1]) + j] != airColor)  
				{  
					delete []color1;  
					delete []color2;  

					return true;  
				}  
			}  
		}  

		delete []color1;  
		delete []color2;  
		return false;  
	}  
	else return false;  
}

void Tools::save()
{
	save_fout.open("save.txt");
	save_fout<<drawer.get_logic()->get_frame_num()<<" "<<map.get_pass_frame()<<" "<<map.get_bossdead_frame()<<" "
		<<map.get_bg_time()<<" "<<map.get_system_status()<<" "<<map.get_old_system_status()<<" "
		<<map.get_game_stage()<<" "<<map.get_score()<<" "<<map.get_old_score()<<" "
		<<map.get_power_num()<<" "<<map.get_enemy_num()<<" "<<map.get_bg_order()<<" "<<map.get_bgm_order()<<" "
		<<map.get_volume()<<" "<<map.get_difficulty()<<" ";
	Player* pl = map.get_player();
	save_fout<<pl->get_x()<<" "<<pl->get_y()<<" "<<pl->get_status()<<" "<<pl->get_type()<<" ";
	save_fout<<pl->get_shoot_frame()<<" "<<pl->get_super_frame()<<" "<<pl->get_frozen_frame()<<" "<<pl->get_blood()<<" "
		<<pl->get_life()<<" "<<pl->get_move_status()<<" "<<pl->get_bull_num()<<" "<<pl->get_wingman_num()<<" "
		<<pl->get_super_bull_frame()<<" "<<pl->get_super_bull()<<" ";
	Wingman* wm = pl->get_w_first()->get_next();
	while(wm)
	{
		save_fout<<wm->get_type()<<" ";
		wm = wm->get_next();
	}
	Enemy* ep = map.get_first()->get_next();
	while(ep)
	{
		save_fout<<ep->get_x()<<" "<<ep->get_y()<<" "<<ep->get_status()<<" "<<ep->get_type()<<" ";
		save_fout<<ep->get_blood()<<" "<<ep->get_move_frame()<<" "<<ep->get_shoot_frame()<<" "<<ep->get_frozen_frame()<<" "
			<<" "<<ep->get_sita()<<" "<<ep->get_move_status()<<" "<<ep->is_frozen()<<" "<<ep->is_super()<<" ";
		ep = ep->get_next();
	}
	Power* p = map.get_p_first()->get_next();
	while(p)
	{
		save_fout<<p->get_x()<<" "<<p->get_y()<<" "<<p->get_type()<<" ";
		p = p->get_next();
	}
	save_fout.close();
}

void Tools::load()
{
	float      bg_time,difficulty;
	int        frame_num,pass_frame,boss_dead_frame;
	int        system_status,old_system_stauts;//系统状态
	int        game_stage,score,old_score;
	int        power_num,enemy_num;
	int        bg_order,bgm_order,volume;
	fin.close();
	fin.open("save.txt");
	fin>>frame_num>>pass_frame>>boss_dead_frame>>bg_time>>system_status>>old_system_stauts>>game_stage>>score>>old_score
		>>power_num>>enemy_num>>bg_order>>bgm_order>>volume>>difficulty;
	drawer.get_logic()->frame_num = frame_num;
	map.pass_frame = pass_frame;
	map.boss_dead_frame = boss_dead_frame;
	map.bg_time = bg_time;
	map.bg_time_offset = drawer.get_hge()->Timer_GetTime()-bg_time;
	map.system_status = system_status;
	map.old_system_stauts = old_system_stauts;
	map.game_stage = game_stage;
	map.score = score;
	map.old_score = old_score;
	map.power_num = 0;
	map.enemy_num = 0;
	map.bg_order = bg_order;
	map.bgm_order = bgm_order;
	map.volume = volume;
	map.difficulty = difficulty;
	map.replay = false;
	map.load = true;

	float    x,y;
	int      status;
	int      type;
	int      shoot_frame;
	int      super_frame,frozen_frame;//无敌时间,冰冻时间
	int      life;
	int      move_status;
	int      bull_num,wingman_num; 
	int      super_bull_frame;
	bool     super_bull;
	float    blood;
	float    sita;
	fin>>x>>y>>status>>type>>shoot_frame>>super_frame>>frozen_frame>>blood>>life>>move_status>>bull_num>>wingman_num>>super_bull_frame>>super_bull;
	map.player->set_x(x);
	map.player->set_y(y);
	map.player->set_status(status);
	map.player->set_type(type);
	map.player->set_shoot_frame(shoot_frame);
	map.player->set_super_frame(super_frame);
	map.player->set_frozen_frame(frozen_frame);
	map.player->set_blood(blood);
	map.player->set_life(life);
	map.player->set_move_status(move_status);
	map.player->set_bull_num(bull_num);
	map.player->set_wingman_num(0);
	if(super_bull)
	{
		map.player->add_wingman(type);
		map.player->add_super_bull(frame_num);
	}
	else
		map.player->set_super_bull(false);
	map.player->set_super_bull_frame(super_bull_frame);

	for(int i=0;i<wingman_num;++i)
	{
		fin>>type;
		map.player->add_wingman(type);
	}
	int   move_frame;
	bool  frozen,super;
	Enemy* ep = map.first;
	for(int i=0;i<enemy_num;++i)
	{
		fin>>x>>y>>status>>type>>blood>>move_frame>>shoot_frame>>frozen_frame>>sita>>move_status>>frozen>>super;
		map.add_enemy(x,y,type);
		ep = ep->get_next();
		ep->set_status(status);
		ep->set_blood(blood);
		ep->set_move_frame(move_frame);
		ep->set_shoot_frame(shoot_frame);
		ep->set_frozen_frame(frozen_frame);
		ep->set_sita(sita);
		ep->set_move_status(move_status);
		ep->set_frozen(frozen);
		ep->set_super(super);
	}
	for(int i=0;i<power_num;++i)
	{
		fin>>x>>y>>type;
		map.add_power(x,y,type);
	}
	fin.close();
}

void Tools::update_ranking()
{
	score_fin.close();
	score_fin.open("ranking.txt");
	for(int i=0;i<5;i++)
	{
		int score;
		score_fin>>score;
		if(score_fin.eof()||score_fin.fail()||score_fin.bad())
			rank.push_back(0);
		else
			rank.push_back(score);
	}
	score_fin.close();
	score_fout.close();
	score_fout.open("ranking.txt");
	rank.push_back(map.get_score());
	std::sort(rank.begin(),rank.end());
	for(int i=5;i>0;i--)
	{
		score_fout<<rank[i]<<" ";
		rank.pop_back();
	}
	rank.pop_back();
	score_fout.close();
	if(!map.get_load())
	{
		difficulty_fout.close();
		difficulty_fout.open("difficulty.txt");
		difficulty_fout<<map.get_difficulty()<<" "<<map.get_bg_order()<<" "<<map.get_bgm_order()<<" "<<map.get_volume()<<" ";
		difficulty_fout.close();
	}
}

void Tools::initialize_difficulty()
{
	diffculty_fin.close();
	diffculty_fin.open("difficulty.txt");
	float diffculty;
	int bg_order,bgm_order,volume;
	diffculty_fin>>diffculty>>bg_order>>bgm_order>>volume;
	map.difficulty = diffculty;
	map.bg_order = bg_order;
	map.bgm_order = bgm_order;
	map.volume = volume;
	diffculty_fin.close();
}

void Tools::Move_1(Enemy *e)
{
	float dt = 0.02;
	float speed = e->get_speed();
	float sita = e->get_sita();
	int   frame_num = drawer.get_logic()->get_frame_num();
	if(e->is_frozen()) speed = 0.5*speed;
	if(e->get_y()<WIN_H/4.0)
	{
		e->move(dt*speed,PI/2.0);
		e->set_move_frame(frame_num);
		e->set_sita(0);
	}
	else
	{
		e->set_status(NORMAL);
		if(((frame_num-e->get_move_frame())>=50) && ((frame_num-e->get_move_frame())<=100))
		{
			if(sita==0) e->set_move_status(RIGHT);
			else e->set_move_status(LEFT);

			e->move(2.5*dt*speed,sita);

			if(e->get_x()>WIN_W-e->get_w()/2.0)
			{
				e->set_sita(PI);
				e->set_x(WIN_W-e->get_w()/2.0);
			}
			else if(e->get_x()<e->get_w()/2.0)
			{
				e->set_sita(0);
				e->set_x(e->get_w()/2.0);
			}
		}
		else if((frame_num-e->get_move_frame())>100)
		{
			e->set_move_frame(frame_num);
		}
		else
		{
			e->set_status(ADD_BULLET);
			e->set_move_status(SHOOT);
		}
	}
}

void Tools::Move_2(Enemy *e)
{
	float dt = 0.02;
	float speed = e->get_speed();
	int frame_num = drawer.get_logic()->get_frame_num();
	if(e->is_frozen()) speed = 0.5*speed;
	e->set_status(NORMAL);
	if(e->get_y()<WIN_H/2.5)
	{
		e->move(dt*speed,PI/2.0);
		e->set_move_frame(frame_num);
		if(e->get_x()<WIN_W/2.0)
			e->set_sita(0);
		else
			e->set_sita(PI);
	}
	else if(frame_num-e->get_move_frame()<=250)
	{
		if(e->get_sita()==0)
			e->set_move_status(RIGHT);
		else
			e->set_move_status(LEFT);

		e->move(0.25*dt*speed,e->get_sita());
		e->set_status(ADD_BULLET);
	}
	else
		e->move(2*dt*speed,e->get_sita());
}

void Tools::Move_3(Enemy *e)
{
	float dt = 0.02;
	float speed = e->get_speed();
	int   frame_num = drawer.get_logic()->get_frame_num();
	if(e->is_frozen()) speed = 0.5*speed;
	e->set_status(NORMAL);
	if(e->get_y()<0)
	{
		e->move(dt*speed,PI/2.0);
		e->set_move_frame(frame_num);
		if(e->get_x()<WIN_W/2.0)
		{
			e->set_sita(PI/6.0);
			e->set_move_status(RIGHT);
		}
		else
		{
			e->set_sita(5*PI/6.0);
			e->set_move_status(LEFT);
		}
	}
	else if(e->get_y()<WIN_H/6.0)
	{
		e->move(4*dt*speed,e->get_sita());
	}
	else if(e->get_y()<WIN_H/2.0)
	{
		e->set_status(ADD_BULLET);
		e->set_move_status(SHOOT);
		e->move(0.75*dt*speed,PI/2.0);
	}
	else
	{
		if(e->get_sita()<PI/2.0)
		{
			e->set_move_status(LEFT);
			e->move(4*dt*speed,5*PI/6.0);
		}
		else
		{
			e->set_move_status(RIGHT);
			e->move(4*dt*speed,PI/6.0);
		}
	}
}

void Tools::Move_4(Enemy *e)
{
	float dt = 0.02;
	float speed = e->get_speed();
	int   frame_num = drawer.get_logic()->get_frame_num();
	if(e->is_frozen()) speed = 0.5*speed;
	if(e->get_y()<WIN_H/3.0)
		e->move(1.2*dt*speed,PI/2.0);
	else
		e->set_status(ADD_BULLET);
}

void Tools::Move_5(Enemy *e)
{
	float dt = 0.02;
	float speed = e->get_speed();
	float sita = e->get_sita();
	int   frame_num = drawer.get_logic()->get_frame_num();
	if(e->is_frozen()) speed = 0.5*speed;
	if(e->get_y()<WIN_H/5.0)
	{
		e->move(dt*speed,PI/2.0);
		e->set_move_frame(frame_num);
		e->set_sita(0);
	}
	else
	{
		e->set_status(NORMAL);
		if(((frame_num-e->get_move_frame())>=50) && ((frame_num-e->get_move_frame())<=150))
		{
			if(sita==0) e->set_move_status(RIGHT);
			else e->set_move_status(LEFT);

			e->move(2.5*dt*speed,sita);
			e->move(0.25*dt*speed,PI/2.0);

			if(e->get_x()>WIN_W-e->get_w()/2.0)
			{
				e->set_sita(PI);
				e->set_x(WIN_W-e->get_w()/2.0);
			}
			else if(e->get_x()<e->get_w()/2.0)
			{
				e->set_sita(0);
				e->set_x(e->get_w()/2.0);
			}
		}
		else if((frame_num-e->get_move_frame())>150)
		{
			e->set_move_frame(frame_num);
		}
		else
		{
			e->set_status(ADD_BULLET);
			e->set_move_status(SHOOT);
		}
	}
}

void Tools::AddBullet_1(Enemy *e)
{
	if((drawer.get_logic()->get_frame_num()-e->get_shoot_frame())>= e->get_shoot_interval())
	{
		for(int i=0;i<5;i++)
		{	
			map.add_bullet(e);
			map.get_b_last()->set_x(e->get_x()-(i-2)*e->get_w()/1.5);
		}
	}
}

void Tools::AddBullet_2(Enemy *e)
{
	if((drawer.get_logic()->get_frame_num()-e->get_shoot_frame())>= e->get_shoot_interval())
	{
		int ran;
		if(map.get_replay())
		rand_fin>>ran;
		else 
		{
			ran = (int)(rand()%((int)(e->get_w()*6))-(e->get_w()*3));
			rand_fout<<ran<<" ";
		}
			map.add_bullet(e);
			map.get_b_last()->set_x(e->get_x()+ran);
			map.get_b_last()->set_y(e->get_y()-e->get_h());
	}
}

void Tools::AddBullet_3(Enemy *e)
{
	if((drawer.get_logic()->get_frame_num()-e->get_shoot_frame())>= e->get_shoot_interval())
	{
		int ran;
		if(map.get_replay())
			rand_fin>>ran;
		else
		{
			ran = (int)(rand()%((int)(e->get_w()*2))-e->get_w());
			rand_fout<<ran<<" ";
		}
		map.add_bullet(e);
		map.get_b_last()->set_x(e->get_x()+ran);
	}
}

void Tools::AddBullet_4(Enemy *e)
{
	if((drawer.get_logic()->get_frame_num()-e->get_shoot_frame())>= e->get_shoot_interval())
	{
		for(float i=0;i<2*PI;i+=PI/10)
		{
			map.add_bullet(e);
			map.get_b_last()->set_sita(i);
			map.get_b_last()->set_y(e->get_y());
		}
	}
}

void Tools::AddBullet_5(Enemy *e)
{
	if((drawer.get_logic()->get_frame_num()-e->get_shoot_frame())>= e->get_shoot_interval())
	{
		for(float i=0;i<5;i++)
		{
			map.add_bullet(e);
			map.get_b_last()->set_sita(PI/6.0+i*PI/6.0);
		}
	}
}