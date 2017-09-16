#include "Map.h"
#include "Drawer.h"
#include "Tools.h"
//由于map里要播放声音，所以要用声音精灵，而且有关玩家飞机的碰撞是像素检测，所以要用到图片精灵，所以extern了这2个对象
extern Drawer drawer;
extern Tools tool;

Map::Map()
	:
	replay(false),load(false),difficulty(1),
	game_stage(STAGE_1),
	pass_frame(0),boss_dead_frame(0),volume(10),
	bg_time(0),bg_time_offset(0),bg_order(0),bgm_order(0),
	score(0),old_score(0),enemy_num(0),power_num(0),
	system_status(START),old_system_stauts(0),
	first(NULL),last(new Enemy(0,0,0)),boss(NULL),
	player(new Player(WIN_W/2.0,WIN_H-PL_H,PL_W,PL_H,PL_SPEED)),
	b_first(NULL),b_last(new Bullet(0,0,0)),
	p_first(NULL),p_last(new Power(0,0,0)),
	e_first(NULL),e_last(new Explosion(0,0,0))
{
	first = last;
	b_first = b_last;
	p_first = p_last;
	e_first = e_last;
}

Map::~Map()
{
	delete first;
	delete b_first;
	delete p_first;
	delete e_first;
	delete player;
	if(boss) delete boss;
}

void Map::add_enemy(float x,float y,int tp)
{
	Enemy* p = new Enemy(x,y,tp);
	switch(tp)
	{
	case BOSS_1:
	case BOSS_2:
	case BOSS_3:
	case BOSS_4:
	case BOSS_5:
		boss = p;
		break;
	case SNAIL:
		break;
	default:
		break;
	}
	last = first;
	while(last->get_next())
		last = last->get_next();
	last->set_next(p);
	p->set_prev(last);
	p->set_next(NULL);
	enemy_num++;
}

void Map::erase_enemy(Enemy* p)
{
	if(p->get_next())
	{
		p->get_prev()->set_next(p->get_next());
		p->get_next()->set_prev(p->get_prev()); 
	}
	else
		p->get_prev()->set_next(NULL);

	delete p;
	enemy_num--;
}

void Map::move_bullet()
{
	float dt = 0.02;
	Bullet* p = player->get_first()->get_next();

	while(p)
	{
		if(p->get_type()==RED_WINGMAN_BULLET)
		{
			Enemy* last = first->get_next();
			if(last)
			{
				float a = atan2((last->get_y() - p->get_y()),(last->get_x() - p->get_x()));
			    p->set_sita(a);
			}
			else
				p->set_sita(-PI/2.0);
		}
		p->move(dt*p->get_speed(),p->get_sita());
		p = p->get_next();
	}

	p = b_first->get_next();

	while(p)
	{
		p->move(dt*p->get_speed(),p->get_sita());
		p = p->get_next();
	}
}

void Map::move_enemy()
{
	Enemy* enmy_tmp = first->get_next();
	while(enmy_tmp)
	{
		switch(enmy_tmp->get_type())
		{
		case BLUE_MIKO:
			Tools::Move_2(enmy_tmp);
			break;
		case RED_MIKO:
			Tools::Move_3(enmy_tmp);
			break;
		case SNAIL:
			Tools::Move_4(enmy_tmp);
			break;
		case SNOWMAN:
			Tools::Move_4(enmy_tmp);
			break;
		case BUTTERFLY:
			Tools::Move_5(enmy_tmp);
			break;
		case GHOST:
			Tools::Move_5(enmy_tmp);
			break;
		case BOSS_1:
		case BOSS_2:
		case BOSS_4:
			Tools::Move_1(enmy_tmp);
			break;
		case BOSS_3:
			if(drawer.get_logic()->get_frame_num()%500==0)
			{
 				enmy_tmp->set_super(true);
				enmy_tmp->set_frozen(false);
				enmy_tmp->set_super_frame(drawer.get_logic()->get_frame_num());
			}
			if(enmy_tmp->is_super())
				enmy_tmp->set_speed(0.3*BOSS_3_SPEED);
			else
				enmy_tmp->set_speed(BOSS_3_SPEED);
			Tools::Move_1(enmy_tmp);
			break;
		case BOSS_5:
			if(drawer.get_logic()->get_frame_num()%500==0)
			{
				enmy_tmp->set_super(true);
				enmy_tmp->set_frozen(false);
				enmy_tmp->set_super_frame(drawer.get_logic()->get_frame_num());
			}
			Tools::Move_1(enmy_tmp);
			break;
		}
		enmy_tmp = enmy_tmp->get_next();
	}
}

void Map::enemy_add_bullet()
{
	int frame_num = drawer.get_logic()->get_frame_num();
	Enemy* enmy_tmp = first->get_next();

	while(enmy_tmp)
	{
		switch(enmy_tmp->get_type())
		{
		case RED_MIKO:
		case BLUE_MIKO:
		case SNAIL:
		case SNOWMAN:
		case GHOST:
			if((frame_num-enmy_tmp->get_shoot_frame() >= enmy_tmp->get_shoot_interval()) && enmy_tmp->get_status()==ADD_BULLET)
				add_bullet(enmy_tmp);
			break;
		case BUTTERFLY:
			if(enmy_tmp->get_status()==ADD_BULLET)
				tool.AddBullet_3(enmy_tmp);
			break;
		case BOSS_1:
			if(enmy_tmp->get_status()==ADD_BULLET)
				Tools::AddBullet_1(enmy_tmp);
			break;
		case BOSS_2:
			if(enmy_tmp->get_status()==ADD_BULLET)
				tool.AddBullet_2(enmy_tmp);
			break;
		case BOSS_3:
			if(enmy_tmp->get_status()==ADD_BULLET)
				Tools::AddBullet_4(enmy_tmp);
			break;
		case BOSS_4:
			if(enmy_tmp->get_status()==ADD_BULLET)
			{
				int ran;
				if(replay)
					tool.rand_fin>>ran;
				else
				{
					ran = rand()%(int)(50*difficulty);
					tool.rand_fout<<ran<<" ";
				}
				tool.AddBullet_3(enmy_tmp);
				if(ran==0) 
				{
					enmy_tmp->set_shoot_frame(0);
					Tools::AddBullet_4(enmy_tmp);
				}
			}
			break;
		case BOSS_5:
			if(enmy_tmp->get_status()==ADD_BULLET)
			{
				int ran;
				if(replay)
					tool.rand_fin>>ran;
				else
				{
					ran = rand()%(int)(30*difficulty);
					tool.rand_fout<<ran<<" ";
				}
				Tools::AddBullet_5(enmy_tmp);
				if(ran==0)
				{
					enmy_tmp->set_shoot_frame(0);
					Enemy* tmp = new Enemy(enmy_tmp->get_x(),enmy_tmp->get_y(),BOSS_3);
					Tools::AddBullet_4(tmp);
					delete tmp;
				}
			}
			break;
		}
		enmy_tmp = enmy_tmp->get_next();
	}
}

void Map::add_bullet(Enemy* enmy_tmp)
{
	int tp = enmy_tmp->get_type();
	switch(tp)
	{
	case BLUE_MIKO:
		tp = BLUE_MIKO_BULLET;
		break;
	case RED_MIKO:
		tp = RED_MIKO_BULLET;
		break;
	case SNAIL:
		tp = SNAIL_BULLET;
		break;
	case SNOWMAN:
		tp = SNOWMAN_BULLET;
		break;
	case BUTTERFLY:
		tp = BUTTERFLY_BULLET;
		break;
	case GHOST:
		tp = GHOST_BULLET;
		break;
	case BOSS_1:
		tp = BOSS_1_BULLET;
		break;
	case BOSS_2:
		tp = BOSS_2_BULLET;
		break;
	case BOSS_3:
		tp = BOSS_3_BULLET;
		break;
	case BOSS_4:
		tp = BOSS_4_BULLET;
		break;
	case BOSS_5:
		tp = BOSS_5_BULLET;
		break;
	}

	Bullet* bull = new Bullet(enmy_tmp->get_x(),enmy_tmp->get_y() + enmy_tmp->get_h()/2.0,tp);

	float a = atan2((player->get_y() - bull->get_y()),(player->get_x() - bull->get_x()));
	bull->set_sita(a);

	b_last = b_first;
	while(b_last->get_next())
		b_last = b_last->get_next();
	b_last->set_next(bull);
	bull->set_prev(b_last);
	bull->set_next(NULL);
	b_last = bull;
	enmy_tmp->set_shoot_frame(drawer.get_logic()->get_frame_num());
}

void Map::erase_bullet(Bullet* p)
{
	if(p->get_next())
	{
		p->get_prev()->set_next(p->get_next());
		p->get_next()->set_prev(p->get_prev()); 
	}
	else
		p->get_prev()->set_next(NULL);

	delete p;
}

void Map::add_power(float x,float y,int tp)
{
	Power* p = new Power(x,y,tp);

	p_last = p_first;
	while(p_last->get_next())
		p_last = p_last->get_next();
	p_last->set_next(p);
	p->set_prev(p_last);
	p->set_next(NULL);
	power_num++;
}

void Map::move_power()
{
	float dt = 0.02;
	Power* tmp = p_first->get_next();

	while(tmp)
	{
		tmp->move(dt*tmp->get_speed(),PI/2.0);
		tmp = tmp->get_next();
	}
}

void Map::erase_power(Power* p)
{
	if(p->get_next())
	{
		p->get_prev()->set_next(p->get_next());
		p->get_next()->set_prev(p->get_prev()); 
	}
	else
		p->get_prev()->set_next(NULL);

	delete p;
	power_num--;
}

void Map::add_explode(float x,float y,int tp)
{
	drawer.get_hge()->Effect_Play(drawer.get_sound()->get_explode_snd());
	Explosion* p = new Explosion(x,y,tp);
	p->set_frame(drawer.get_logic()->get_frame_num());
	e_last = e_first;
	while(e_last->get_next())
		e_last = e_last->get_next();
	e_last->set_next(p);
	p->set_prev(e_last);
	p->set_next(NULL);
}

void Map::erase_explode(Explosion* p)
{
	if(p->get_next())
	{
		p->get_prev()->set_next(p->get_next());
		p->get_next()->set_prev(p->get_prev()); 
	}
	else
		p->get_prev()->set_next(NULL);

	delete p;
}

void Map::clean()
{
	//重置所有的状态时间和帧数
	bg_time = 0;
	pass_frame = 0;
	boss_dead_frame = 0;
	score = 0;
	game_stage = 0;
	
	//清player
	player->restart();
	
	//清子弹
	Bullet* p = b_first->get_next();

	while(p)
	{
		p = p->get_prev();
		erase_bullet(p->get_next());
		p = p->get_next();
	}

	//清敌机
	boss = NULL;
	Enemy* enmy_tmp = first->get_next();

	while(enmy_tmp)
	{
		enmy_tmp = enmy_tmp->get_prev();
		erase_enemy(enmy_tmp->get_next());
		enmy_tmp = enmy_tmp->get_next();
	}
	
	//清power
	Power* p_tmp = p_first->get_next();

	while(p_tmp)
	{
		p_tmp = p_tmp->get_prev();
		erase_power(p_tmp->get_next());
		p_tmp = p_tmp->get_next();
	}

	//清爆炸链表
	Explosion* e_tmp = e_first->get_next();

	while(e_tmp)
	{
		e_tmp = e_tmp->get_prev();
		erase_explode(e_tmp->get_next());
		e_tmp = e_tmp->get_next();
	}
}

void Map::collison()   //玩家和敌机以及它们的子弹,powers碰，玩家的子弹和敌机碰，以及元素飞出画面就消除
{
	int  frame_num = drawer.get_logic()->get_frame_num();
	Scene* scene = drawer.get_scene();
	hgeSprite* player_ani = scene->get_pl_ani(player);
	hgeSprite *spr,*pl_bull_spr;

	//玩家和敌机碰以及敌机飞出消除
	Enemy* enmy_tmp = first->get_next();

	while(enmy_tmp)
	{
		//敌机飞出消除
		if(enmy_tmp->get_y() < -(enmy_tmp->get_h()/2.0) || 
			enmy_tmp->get_y() > WIN_H+(enmy_tmp->get_h()/2.0) || 
			enmy_tmp->get_x() < -(enmy_tmp->get_w()/2.0) || 
			enmy_tmp->get_x() > WIN_W+(enmy_tmp->get_w()/2.0))
		{
			enmy_tmp = enmy_tmp->get_prev();
			erase_enemy(enmy_tmp->get_next());
		}
		else 
		{
			//如果和玩家碰了，没有无敌的一方掉血
			spr = scene->get_enemy_ani(enmy_tmp);
			if(Tools::IsCollision(player_ani,player->get_x()-player->get_w()/2.0,player->get_y()-player->get_h()/2.0, 
				spr,enmy_tmp->get_x()-enmy_tmp->get_w()/2.0,enmy_tmp->get_y()-enmy_tmp->get_h()/2.0))		
			{
				if(player->get_status()!=SUPER)
					player->set_blood(player->get_blood()-0.5);
				if(!enmy_tmp->is_super())
					enmy_tmp->set_blood(enmy_tmp->get_blood()-0.5);
			}
		}
		enmy_tmp = enmy_tmp->get_next();
	}

	//玩家和敌方子弹碰以及子弹飞出消除
	Bullet* p = b_first->get_next();

	while(p)
	{
		//子弹飞出消除
		if(p->get_y() < 0 || 
			p->get_y() > WIN_H || 
			p->get_x() < 0 || 
			p->get_x() > WIN_W)
		{
			p = p->get_prev();
			erase_bullet(p->get_next());
		}
		else
		{
			//如果玩家不是无敌，就掉血，消除此子弹，如果子弹类型特殊，再附加冰冻效果
			spr = scene->get_bull_spr(p);
			if(Tools::IsCollision(player_ani,player->get_x()-player->get_w()/2.0,player->get_y()-player->get_h()/2.0,
				spr,p->get_x()-p->get_w()/2.0,p->get_y()-p->get_h()/2.0))
			{
				if(player->get_status()!=SUPER)
				{
					player->set_blood(player->get_blood()-p->get_power());
					switch(p->get_type())
					{
					case BLUE_MIKO_BULLET:
					case SNOWMAN_BULLET:
					case BOSS_3_BULLET:
						player->befrozen(frame_num);
						break;
					default:
						break;
					}
					drawer.get_hge()->Effect_Play(drawer.get_sound()->get_explode_snd());
				}
				p = p->get_prev();
				erase_bullet(p->get_next());
			}
		}

		p = p->get_next();
	}
	//玩家子弹和敌机碰以及玩家子弹飞出消除
	p = player->get_first()->get_next();

	while(p)
	{
		//玩家子弹飞出消除，大招不在此列
		if((p->get_y() < 0 || p->get_y() > WIN_H || p->get_x() < 0 || p->get_x() > WIN_W) && p->get_type()!=SUPER_BULL)
		{
			p = p->get_prev();
			erase_bullet(p->get_next());
		}
		else
		{
			//大招会消除碰到的敌人的子弹
			pl_bull_spr = scene->get_bull_spr(p);
			if(p->get_type()==SUPER_BULL)
			{
				Bullet* b = b_first->get_next();
				while(b)
				{
					if(p->collision_test(*b))
					{
						b = b->get_prev();
						erase_bullet(b->get_next());
					}
					b = b->get_next();
				}
			}
			//如果子弹和敌人碰到，消除子弹，大招除外，敌人如果不是无敌就掉血
			Enemy* tmp = first->get_next();
			while(tmp)
			{
				spr = scene->get_enemy_ani(tmp);
				if(!tmp->is_super() && Tools::IsCollision(pl_bull_spr,p->get_x()-p->get_w()/2.0,p->get_y()-p->get_h()/2.0,
					spr,tmp->get_x()-tmp->get_w()/2.0,tmp->get_y()-tmp->get_h()/2.0))
				{
					if(p->get_type()==BLUE_WINGMAN_BULLET)
						tmp->befrozen(frame_num);
					tmp->set_blood(tmp->get_blood()-p->get_power());

					if(p->get_type()!=SUPER_BULL)
					{
						p = p->get_prev();
						erase_bullet(p->get_next());
					}
					break;
				}
				else if(tmp->is_super() && p->get_type()==RED_WINGMAN_BULLET)
				{
					p = p->get_prev();
					erase_bullet(p->get_next());
				}
				tmp = tmp->get_next();			
			}
		}
		p = p->get_next();
	}

	//玩家和powers碰以及powers的飞出消除
	Power* p_tmp = p_first->get_next();

	while(p_tmp)
	{
		if(p_tmp->get_y() < 0 || 
			p_tmp->get_y() > WIN_H || 
			p_tmp->get_x() < 0 || 
			p_tmp->get_x() > WIN_W)
		{
			p_tmp = p_tmp->get_prev();
			erase_power(p_tmp->get_next());
		}
		else if(player->collision_test(*p_tmp))
		{
			switch(p_tmp->get_type())
			{
			case POWER_LIFE:
				player->life_increase();
				score+=10;
				break;
			case POWER_BULL:
				player->bull_num_increase();
				score+=1;
				break;
			case POWER_BLOOD:
				player->blood_increase();
				score+=2;
				break;
			case RED_WINGMAN:
				player->add_wingman(RED_WINGMAN);
				score+=3;
				break;
			case BLUE_WINGMAN:
				player->add_wingman(BLUE_WINGMAN);
				score+=5;
				break;
			case RED_SCORE:
				score+=10;
				break;
			case BLUE_SCORE:
				score+=20;
				break;
			case BLACK_SOCRE:
				score+=50;
				break;
			}
			p_tmp = p_tmp->get_prev();
			drawer.get_hge()->Effect_Play(drawer.get_sound()->get_power_snd());
			erase_power(p_tmp->get_next());
		}
		p_tmp = p_tmp->get_next();
	}
}

//把血量小于等于0的元素清除
void Map::update_elements() 
{
	int frame_num = drawer.get_logic()->get_frame_num();
	Enemy* enmy_tmp = first->get_next();

	while(enmy_tmp)
	{
		//boss无敌状态保持10秒
		if(enmy_tmp->is_super() && frame_num-enmy_tmp->get_super_frame()>BOSS_SUPER_FRAME)
			enmy_tmp->set_super(false);
		else if(enmy_tmp->get_blood()<=0)
		{
			int ran;
			if(replay)
				tool.rand_fin>>ran;
			else
			{
				ran = rand()%10;
				tool.rand_fout<<ran<<" ";
			}
			//掉落物品的设置
			float x = enmy_tmp->get_x();
			float y = enmy_tmp->get_y();
			switch(enmy_tmp->get_type())
			{
			case BOSS_1:
				system_status = BOSS_DEAD;
				boss_dead_frame = frame_num;
				boss = NULL;
				if(ran<3) add_power(x,y,POWER_LIFE);
				else if(ran<7) add_power(x-ran,y+ran,POWER_BULL);
				else if(ran<8) add_power(x+ran,y,BLUE_WINGMAN);
				for(int i=0;i<2;i++)
				{
					int ran1,ran2;
					if(replay)
						tool.rand_fin>>ran1>>ran2;
					else
					{
						ran1 = rand()%100-50;
						ran2 = rand()%50-25;
						tool.rand_fout<<ran1<<" "<<ran2<<" ";
					}		
					add_power(x+ran1,y+ran1,POWER_BLOOD);
					add_power(x+ran1,y+ran2,RED_SCORE);
					add_power(x+ran1,y-ran2,BLUE_SCORE);
					add_power(x-ran2,y+ran2,BLACK_SOCRE);
				}
				break;
			case BOSS_2:
				system_status = BOSS_DEAD;
				boss_dead_frame = frame_num;
				boss = NULL;
				if(ran<3) add_power(x,y,POWER_LIFE);
				else if(ran<7) add_power(x-ran,y+ran,POWER_BULL);
				else if(ran<9) add_power(x+ran,y,RED_WINGMAN);
				for(int i=0;i<2;i++)
				{
					int ran1,ran2;
					if(replay)
						tool.rand_fin>>ran1>>ran2;
					else
					{
						ran1 = rand()%100-50;
						ran2 = rand()%60-30;
						tool.rand_fout<<ran1<<" "<<ran2<<" ";
					}	
					add_power(x+ran2,y+ran1,POWER_BLOOD);
					add_power(x+ran2,y-ran2,BLUE_SCORE);
					add_power(x-ran1,y+ran1,BLUE_SCORE);
					add_power(x+ran2,y+ran2,BLACK_SOCRE);
				}
				break;
			case BOSS_3:
				system_status = BOSS_DEAD;
				boss_dead_frame = frame_num;
				boss = NULL;
				if(ran<3) add_power(x,y,POWER_LIFE);
				else if(ran<7) add_power(x-ran,y+ran,POWER_BULL);
				else add_power(x+ran,y,BLUE_WINGMAN);
				for(int i=0;i<2;i++)
				{
					int ran1,ran2;
					if(replay)
						tool.rand_fin>>ran1>>ran2;
					else
					{
						ran1 = rand()%100-50;
						ran2 = rand()%60-30;
						tool.rand_fout<<ran1<<" "<<ran2<<" ";
					}	
					add_power(x+ran2,y+ran1,POWER_BLOOD);
					add_power(x+ran2,y-ran2,BLUE_SCORE);
					add_power(x-ran1,y+ran1,BLUE_SCORE);
					add_power(x+ran2,y+ran2,BLACK_SOCRE);
					add_power(x+ran2,y-ran2,BLACK_SOCRE);
				}
				break;
			case BOSS_4:
				system_status = BOSS_DEAD;
				boss_dead_frame = frame_num;
				boss = NULL;
				if(ran<3) add_power(x,y,POWER_LIFE);
				else add_power(x-ran,y+ran,POWER_BULL);
				add_power(x,y,RED_WINGMAN);
				for(int i=0;i<2;i++)
				{
					int ran1,ran2;
					if(replay)
						tool.rand_fin>>ran1>>ran2;
					else
					{
						ran1 = rand()%100-50;
						ran2 = rand()%60-30;
						tool.rand_fout<<ran1<<" "<<ran2<<" ";
					}	
					add_power(x+ran2,y+ran1,POWER_BLOOD);
					add_power(x+ran2,y-ran2,BLUE_SCORE);
					add_power(x-ran1,y+ran1,BLUE_SCORE);
					add_power(x+ran2,y+ran2,BLACK_SOCRE);
					add_power(x-ran1,y+ran1,BLUE_SCORE);
					add_power(x+ran2,y+ran2,BLACK_SOCRE);
				}
				break;
			case BOSS_5:
				system_status = PASS;
				pass_frame = frame_num+150;
				boss = NULL;
				drawer.get_hge()->Effect_Play(drawer.get_sound()->get_win_snd());
				for(int i=0;i<2;i++)
				{
					int ran1,ran2;
					if(replay)
						tool.rand_fin>>ran1>>ran2;
					else
					{
						ran1 = rand()%100-50;
						ran2 = rand()%60-30;
						tool.rand_fout<<ran1<<" "<<ran2<<" ";
					}	
					add_power(x+ran2,y+ran1,BLACK_SOCRE);
					add_power(x+ran2,y-ran2,BLACK_SOCRE);
					add_power(x-ran1,y+ran1,BLACK_SOCRE);
					add_power(x+ran2,y+ran2,BLACK_SOCRE);
				}
				break;
			case RED_MIKO:
				if(ran<1*difficulty) add_power(x,y,RED_WINGMAN);
				else if(ran<4*difficulty) add_power(x,y,POWER_BULL);
				else if(ran<8) add_power(x,y,RED_SCORE);
				break;
			case BLUE_MIKO:
				if(ran<1*difficulty) add_power(x,y,BLUE_WINGMAN);
				else if(ran<3/difficulty) add_power(x,y,RED_SCORE);
				else if(ran<7*difficulty) add_power(x,y,POWER_BLOOD);
				else add_power(x,y,BLUE_SCORE);
				break;
			case SNAIL:
				if(ran<2*difficulty) add_power(x,y,RED_WINGMAN);
				else if(ran<4*difficulty) add_power(x,y,POWER_BULL);
				else if(ran<8/difficulty) add_power(x,y,RED_SCORE);
				break;
			case BUTTERFLY:
				if(ran<1*difficulty) add_power(x,y,RED_WINGMAN);
				else if(ran<3/difficulty) add_power(x,y,RED_SCORE);
				else if(ran<7*difficulty) add_power(x,y,POWER_BULL);
				else add_power(x,y,BLUE_SCORE);
				break;
			case SNOWMAN:
				if(ran<2*difficulty) add_power(x,y,BLUE_WINGMAN);
				else if(ran<4*difficulty) add_power(x,y,POWER_BLOOD);
				else if(ran<8/difficulty) add_power(x,y,BLUE_SCORE);
				break;
			case GHOST:
				if(ran<1*difficulty) add_power(x,y,RED_WINGMAN);
				else if(ran<5*difficulty) add_power(x,y,POWER_BLOOD);
				else add_power(x,y,BLUE_SCORE);
				break;
			}
			add_explode(x,y,enmy_tmp->get_type());
			enmy_tmp = enmy_tmp->get_prev();
			erase_enemy(enmy_tmp->get_next());
		}
		else if(enmy_tmp->is_frozen() && frame_num-enmy_tmp->get_frozen_frame()>FROZEN_FRAME)
			enmy_tmp->benotfrozen();
		enmy_tmp = enmy_tmp->get_next();
	}
	if(player->get_blood()<=0)
	{
		pl_drop_score();
		player->boom(replay);
		player->life_decrease(frame_num);
		drawer.get_hge()->Effect_Play(drawer.get_sound()->get_explode_snd());
	}

	Wingman* p = player->get_w_first()->get_next();
	while(p)
	{
		if(frame_num-p->get_shoot_frame()>=p->get_shoot_interval())
			player->wingman_add_bullet(frame_num,p);
		p = p->get_next();
	}

	//玩家无敌状态保持2.5秒
	if(player->get_status()==SUPER && frame_num-player->get_super_frame()>SUPER_FRAME)
		player->set_status(NORMAL);
	//冰冻状态保持2秒
	if(player->get_status()==FROZEN && frame_num-player->get_frozen_frame()>FROZEN_FRAME)
		player->set_status(NORMAL);
	if(player->get_super_bull() && frame_num-player->get_super_bull_frame()>SUPER_BULL_FRAME)
	{
		Bullet* p = player->get_first()->get_next();
		while(p)
		{
			if(p->get_type()==SUPER_BULL)
			{
				p = p->get_prev();
				erase_bullet(p->get_next());
			}
			p = p->get_next();
		}
		player->set_super_bull(false);
	}

}

//根据系统状态做一些逻辑处理，并且也会更改系统状态
void Map::update_status()
{
	if(player->get_life()<=0)
	{
		system_status = FAILE;
		drawer.get_hge()->Effect_Play(drawer.get_sound()->get_lose_snd());
	}

	if(system_status == WIN)
	{
		drawer.get_hge()->Channel_StopAll();
		drawer.get_hge()->Effect_Play(drawer.get_sound()->get_win_music());//播放胜利音乐
	}
	else if(system_status == FAILE)
	{
		drawer.get_hge()->Channel_StopAll();
		drawer.get_hge()->Effect_Play(drawer.get_sound()->get_lose_music());//播放失败音乐
	}
	//boss死亡后的时间6秒钟，用于吃东西
	else if(system_status == BOSS_DEAD && drawer.get_logic()->get_frame_num()-boss_dead_frame > BOSS_DEAD_FRAME)
	{
		system_status = PASS;
		pass_frame = drawer.get_logic()->get_frame_num();
	}
	//过场动画时间2.5秒
	else if(system_status == PASS && drawer.get_logic()->get_frame_num()-pass_frame>PASS_FRAME)
		next_stage();
}

void Map::move()
{
	player->move_wingman();
	move_bullet();
	move_enemy();
	move_power();
}

void Map::pl_drop_score()
{
	score -= 20;//掉分,然后掉落一些分数power
	if(score<100 && score>10)
	{
		score = 0;
		int num = score/10;
		for(int i=0;i<num;++i)
		{
			int ran1,ran2;
			if(replay)
			{
				tool.rand_fin>>ran1>>ran2;
			}
			else
			{
				ran1 = rand()%100-50;
				ran2 = rand()%100-50;
				tool.rand_fout<<ran1<<" "<<ran2<<" ";
			}
			add_power(player->get_x()+ran1,player->get_y()+ran2,RED_SCORE);
		}
	}
	else if(score>=100)
	{
		score -= 100;
		for(int i=0;i<3;++i)
		{
			int ran1,ran2;
			if(replay)
			{
				tool.rand_fin>>ran1>>ran2;
			}
			else
			{
				ran1 = rand()%100-50;
				ran2 = rand()%100-50;
				tool.rand_fout<<ran1<<" "<<ran2<<" ";
			}
			add_power(player->get_x()+ran1,player->get_y()+ran2,RED_SCORE);
			add_power(player->get_x()-ran1,player->get_y()-ran2,BLUE_SCORE);
		}
		int ran1,ran2;
		if(replay)
		{
			tool.rand_fin>>ran1>>ran2;
		}
		else
		{
			ran1 = rand()%100-50;
			ran2 = rand()%100-50;
			tool.rand_fout<<ran1<<" "<<ran2<<" ";
		}
		add_power(player->get_x()+ran1,player->get_y()+ran2,RED_SCORE);
	}
}

void Map::next_stage()
{
	//重置所有帧数，stage++
	player->set_shoot_frame(0);
	pass_frame = 0;
	boss_dead_frame = 0;
	old_score = score;
	system_status = RUNNING;
	if(drawer.get_logic()->frame_num>BOSS_APPEAR_FRAME)
	{
		if(game_stage!=STAGE_5)
			game_stage++;
		else
		{
			system_status = WIN;
			drawer.get_hge()->Channel_StopAll();
			drawer.get_hge()->Effect_Play(drawer.get_sound()->get_win_music());
		}
	}
	drawer.get_logic()->frame_num = 0;
	player->set_shoot_frame(1);
	Wingman* p = player->get_w_first()->get_next();
	while(p)
	{
		p->set_shoot_frame(0);
		p = p->get_next();
	}
}
