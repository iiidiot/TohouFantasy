#include "Logic.h"
#include "Drawer.h"
#include "Map.h"
#include "Tools.h"

extern Map map;
extern Drawer drawer;
extern Tools tool;

void Logic::stage1_logic()
{
	if(frame_num<BOSS_APPEAR_FRAME && frame_num>PASS_FRAME)
	{
		//每隔7秒加一个蓝巫女
		if(frame_num%(int)(350*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-MIKO_H/2.0,BLUE_MIKO);
		}
		if(frame_num%(int)(150*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-MIKO_H/2.0,RED_MIKO);
		}
	}
	else if(frame_num==BOSS_APPEAR_FRAME)
		map.add_enemy(WIN_W/2.0,0,BOSS_1);
}

void Logic::stage2_logic()
{

	if(frame_num<BOSS_APPEAR_FRAME && frame_num>PASS_FRAME)
	{
		if(frame_num%(int)(250*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-MIKO_H/2.0,BLUE_MIKO);
		}
		if(frame_num%(int)(250*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-MIKO_H/2.0,RED_MIKO);
		}
		if(frame_num%(int)(600*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-SNAIL_H/2.0,SNAIL);
		}
	}
	else if(frame_num==BOSS_APPEAR_FRAME)
		map.add_enemy(WIN_W/2.0,0,BOSS_2);
}

void Logic::stage3_logic()
{

	if(frame_num<BOSS_APPEAR_FRAME && frame_num>PASS_FRAME)
	{
		if(frame_num%(int)(250*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-MIKO_H/2.0,BLUE_MIKO);
		}
		if(frame_num%(int)(400*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-BUTTERFLY/2.0,BUTTERFLY);
		}
		if(frame_num%(int)(500*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-SNAIL_H/2.0,SNAIL);
		}
	}
	else if(frame_num==BOSS_APPEAR_FRAME)
		map.add_enemy(WIN_W/2.0,0,BOSS_3);
}

void Logic::stage4_logic()
{

	if(frame_num<BOSS_APPEAR_FRAME && frame_num>PASS_FRAME)
	{
		if(frame_num%(int)(150*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-MIKO_H/2.0,BLUE_MIKO);
		}
		if(frame_num%(int)(250*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-BUTTERFLY_H/2.0,BUTTERFLY);
		}
		if(frame_num%(int)(600*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-SNOWMAN_H/2.0,SNOWMAN);
		}
	}
	else if(frame_num==BOSS_APPEAR_FRAME)
		map.add_enemy(WIN_W/2.0,0,BOSS_4);
}

void Logic::stage5_logic()
{

	if(frame_num<BOSS_APPEAR_FRAME && frame_num>PASS_FRAME)
	{
		if(frame_num%(int)(250*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-BUTTERFLY_H/2.0,BUTTERFLY);
		}
		if(frame_num%(int)(500*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-SNOWMAN_H/2.0,SNOWMAN);
		}
		if(frame_num%(int)(450*map.difficulty)==0)
		{
			int ran;
			if(map.replay)
				tool.rand_fin>>ran;
			else 
			{
				ran = rand()%WIN_W;
				tool.rand_fout<<ran<<" ";
			}
			map.add_enemy(ran,-GHOST/2.0,GHOST);
		}
	}
	else if(frame_num==BOSS_APPEAR_FRAME)
		map.add_enemy(WIN_W/2.0,0,BOSS_5);
}

void Logic::game_logic()
{
	switch(map.game_stage)
	{
	case STAGE_1:
		stage1_logic();
		break;
	case STAGE_2:
		stage2_logic();
		break;
	case STAGE_3:
		stage3_logic();
		break;
	case STAGE_4:
		stage4_logic();
		break;
	case STAGE_5:
		stage5_logic();
		break;
	}
	map.enemy_add_bullet();
	map.move();
	//检测是否碰撞，更新状态
	map.collison();
	map.update_elements();
	map.update_status();
}
//键盘操作
bool Logic::key_control()
{
	float froze = 1;
	float dt = 0.02;
	Player* player = map.player;
	HGE* hge = drawer.get_hge();
	bool up_keydown = false;
	bool down_keydown = false;
	bool left_keydown = false;
	bool right_keydown = false;
	bool z_keydown = false;
	bool x_keydown = false;

	if(player->get_status()==FROZEN)
		froze = 0.5;
	if (hge->Input_KeyDown(HGEK_ESCAPE))
	{
		map.old_system_stauts = map.system_status;
		map.system_status = PAUSE;
	}

	if (!hge->Input_GetKeyState(HGEK_LEFT) && !hge->Input_GetKeyState(HGEK_RIGHT))
		player->set_move_status(STAY);

	if (hge->Input_GetKeyState(HGEK_LEFT) && player->get_x() > (PL_W/2.0)) 
	{
		player->set_x(player->get_x()-dt*PL_SPEED*froze);
		player->set_move_status(LEFT);
		left_keydown = true;
	}
	if (hge->Input_GetKeyState(HGEK_RIGHT) && player->get_x() < (WIN_W-PL_W/2.0))
	{
		player->set_x(player->get_x()+dt*PL_SPEED*froze);
		player->set_move_status(RIGHT);
		right_keydown = true;
	}
	if (hge->Input_GetKeyState(HGEK_UP) && player->get_y() >( PL_H/2.0)) 
	{
		player->set_y(player->get_y()-dt*PL_SPEED*froze);
		up_keydown = true;
	}

	if (hge->Input_GetKeyState(HGEK_DOWN) && player->get_y() < (WIN_H-PL_H/2.0))
	{
		player->set_y(player->get_y()+dt*PL_SPEED*froze);
		down_keydown = true;
	}


	if (hge->Input_GetKeyState(HGEK_Z)||hge->Input_GetKeyState(HGEK_SPACE))//Z或者空格发子弹，大招时间里无法射击
	{
		if((!player->get_super_bull()) && (frame_num-player->get_shoot_frame()>=PL_SHOOT_INTERVAL || player->get_shoot_frame()==0))
		{
			hge->Effect_Play(drawer.get_sound()->get_shoot_snd());
			player->add_bullet(frame_num);
		}
		z_keydown = true;
	}

	if (hge->Input_KeyDown(HGEK_X))//发大招，大招时间里无法再次发大招
	{
		if(player->get_wingman_num()>0 && !player->get_super_bull())
			player->add_super_bull(frame_num);
		x_keydown = true;
	}

	Bullet* p = player->get_first()->get_next();
	while(p)//移动大招
	{
		if(p->get_type()==SUPER_BULL)
		{
			if(up_keydown) p->move(dt*PL_SPEED*froze,-PI/2.0);
			if(down_keydown) p->move(dt*PL_SPEED*froze,PI/2.0);
			if(left_keydown) p->move(dt*PL_SPEED*froze,PI);
			if(right_keydown) p->move(dt*PL_SPEED*froze,0);
		}
		p = p->get_next();
	}

	//记录玩家键盘输入
	if(up_keydown) tool.fout<<1<<" ";
	else tool.fout<<0<<" ";
	if(down_keydown) tool.fout<<1<<" ";
	else tool.fout<<0<<" ";
	if(left_keydown) tool.fout<<1<<" ";
	else tool.fout<<0<<" ";
	if(right_keydown) tool.fout<<1<<" ";
	else tool.fout<<0<<" ";
	if(z_keydown) tool.fout<<1<<" ";
	else tool.fout<<0<<" ";
	if(x_keydown) tool.fout<<1<<" ";
	else tool.fout<<0<<" ";

	return false;
}
//回放时的键盘操作
bool Logic::replay_key_control()
{
	//具体情况参考key_control()
	float froze = 1;
	float dt = 0.02;
	Player* player = map.player;
	HGE* hge = drawer.get_hge();

	if(hge->Input_KeyDown(HGEK_ESCAPE))
	{
		map.old_system_stauts = map.system_status;
		map.system_status = PAUSE;
	}

	if(player->get_status()==FROZEN)
		froze = 0.5;

	if (left==0 && right==0)
		player->set_move_status(STAY);

	if (left==1 && player->get_x() > (PL_W/2.0)) 
	{
		player->set_x(player->get_x()-dt*PL_SPEED*froze);
		player->set_move_status(LEFT);
	}

	if (right==1 && player->get_x() < (WIN_W-PL_W/2.0))
	{
		player->set_x(player->get_x()+dt*PL_SPEED*froze);
		player->set_move_status(RIGHT);
	}

	if (up==1 && player->get_y() >( PL_H/2.0)) 
		player->set_y(player->get_y()-dt*PL_SPEED*froze);


	if (down==1 && player->get_y() < (WIN_H-PL_H/2.0))
		player->set_y(player->get_y()+dt*PL_SPEED*froze);

	if (z==1 && (!player->get_super_bull()) && (frame_num-player->get_shoot_frame()>=PL_SHOOT_INTERVAL || player->get_shoot_frame()==0))
	{
		hge->Effect_Play(drawer.get_sound()->get_shoot_snd());
		player->add_bullet(frame_num);
	}

	if(x==1 && player->get_wingman_num()>0 && !player->get_super_bull())
		player->add_super_bull(frame_num);



	Bullet* p = player->get_first()->get_next();
	while(p)
	{
		if(p->get_type()==SUPER_BULL)
		{
			if(up==1) p->move(dt*PL_SPEED*froze,-PI/2.0);
			if(down==1) p->move(dt*PL_SPEED*froze,PI/2.0);
			if(left==1) p->move(dt*PL_SPEED*froze,PI);
			if(right==1) p->move(dt*PL_SPEED*froze,0);
		}
		p = p->get_next();
	}

	return false;
}
//开始菜单
bool Logic::gui_control()
{
	HGE* hge = drawer.get_hge();
	Menu* menu = drawer.get_menu();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid=5; menu->get_gui()->Leave(); }

	id=menu->get_gui()->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			map.clean();
			tool.fout.open("LastReplay.txt");
			tool.rand_fout.open("rand_num.txt");
			map.system_status = PASS;
			map.game_stage = STAGE_1;
			menu->get_gui()->SetFocus(1);
			menu->get_gui()->Enter();
			break;
		case 2:
			map.clean();
			tool.load();
			menu->get_gui()->SetFocus(1);
			menu->get_gui()->Enter();
			break;
		case 3:
			map.clean();
			map.replay = true;
			tool.rand_fin.open("rand_num.txt");
			tool.fin.open("LastReplay.txt");
			tool.initialize_difficulty();
			map.system_status = PASS;
			map.game_stage = STAGE_1;
			menu->get_gui()->SetFocus(1);
			menu->get_gui()->Enter();
			break;
		case 4:
			map.system_status = OPTION;
			menu->get_gui()->SetFocus(1);
			menu->get_gui()->Enter();
			break;
		case 5: return true;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) menu->get_gui()->Leave(); }
	return false;
}
//暂停菜单
bool Logic::pause_gui_control()
{
	HGE* hge = drawer.get_hge();
	hgeGUI* gui = drawer.get_menu()->get_pause_gui();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid = 4;gui->Leave();}

	id=gui->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		int stage = map.game_stage;
		int score = map.old_score;
		switch(lastid)
		{
		case 1:
			tool.update_ranking();
			map.clean();
			map.system_status = START;
			map.replay = false;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 2:
			map.clean();
			map.system_status = PASS;
			map.game_stage = stage;
			map.score = score;
			frame_num = 0;
			if(map.replay)
			{
				tool.rand_fin.close();
				tool.rand_fin.open("rand_num.txt");
				tool.fin.close();
				tool.fin.open("LastReplay.txt");
				map.game_stage = STAGE_1;
				map.score = 0;
			}
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 3:
			tool.save();
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 4: 
			map.system_status = map.old_system_stauts;
			resume_bgm();
			gui->SetFocus(1);
			gui->Enter();
			break;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) gui->Leave(); }
	return false;
}
//胜利菜单
bool Logic::win_gui_control()
{
	HGE* hge = drawer.get_hge();
	hgeGUI* gui = drawer.get_menu()->get_win_gui();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid = 1;gui->Leave();}

	id=gui->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			tool.update_ranking();
			map.clean();
			map.system_status = START;
			map.replay = false;
			gui->SetFocus(1);
			gui->Enter();
			break;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) gui->Leave(); }
	return false;
}
//排行榜菜单
bool Logic::ranking_gui_control()
{
	HGE* hge = drawer.get_hge();
	hgeGUI* gui = drawer.get_menu()->get_ranking_gui();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid = 1;gui->Leave();}

	id=gui->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			map.system_status = OPTION;
			gui->SetFocus(1);
			gui->Enter();
			break;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) gui->Leave(); }
	return false;
}
//难度菜单
bool Logic::difficulty_gui_control()
{
	HGE* hge = drawer.get_hge();
	hgeGUI* gui = drawer.get_menu()->get_difficulty_gui();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid = 5;gui->Leave();}

	id=gui->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			map.difficulty = 2;
			map.system_status = DIFFICULTY;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 2:
			map.difficulty = 1;
			map.system_status = DIFFICULTY;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 3:
			map.difficulty = 0.5;
			map.system_status = DIFFICULTY;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 4:
			map.difficulty = 0.3;
			map.system_status = DIFFICULTY;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 5:
			map.system_status = OPTION;
			gui->SetFocus(1);
			gui->Enter();
			break;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) gui->Leave(); }
	return false;
}
//失败菜单
bool Logic::lose_gui_control()
{
	HGE* hge = drawer.get_hge();
	hgeGUI* gui = drawer.get_menu()->get_lose_gui();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid = 1;gui->Leave();}

	id=gui->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		int stage = map.game_stage;
		int score = map.old_score;
		switch(lastid)
		{
		case 1:
			tool.update_ranking();
			map.clean();
			map.system_status = START;
			map.replay = false;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 2:
			hge->Channel_StopAll();
			map.clean();
			map.system_status = PASS;
			map.game_stage = stage;
			map.score = score;
			frame_num = 0;
			if(map.replay)
			{
				tool.rand_fin.close();
				tool.rand_fin.open("rand_num.txt");
				tool.fin.close();
				tool.fin.open("LastReplay.txt");
				map.game_stage = STAGE_1;
				map.score = 0;
			}
			gui->SetFocus(1);
			gui->Enter();
			break;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) gui->Leave(); }
	return false;
}
//背景菜单
bool Logic::bg_gui_control()
{
	HGE* hge = drawer.get_hge();
	hgeGUI* gui = drawer.get_menu()->get_bg_gui();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid = 4;gui->Leave();}

	id=gui->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			map.system_status = OPTION;
			map.bg_order = 0;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 2:
			map.system_status = OPTION;
			map.bg_order = 1;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 3:
			map.system_status = OPTION;
			map.bg_order = 2;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 4:
			map.system_status = OPTION;
			gui->SetFocus(1);
			gui->Enter();
			break;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) gui->Leave(); }
	return false;
}
//背景音乐菜单
bool Logic::bgm_gui_control()
{
	HGE* hge = drawer.get_hge();
	hgeGUI* gui = drawer.get_menu()->get_bgm_gui();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid = 7;gui->Leave();}

	id=gui->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			hge->Channel_StopAll();
			hge->Effect_PlayEx(drawer.get_sound()->get_music1(),map.volume);
			map.system_status = BGM;
			map.bgm_order = 1;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 2:
			hge->Channel_StopAll();
			hge->Effect_PlayEx(drawer.get_sound()->get_music2(),map.volume);
			map.system_status = BGM;
			map.bgm_order = 2;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 3:
			hge->Channel_StopAll();
			hge->Effect_PlayEx(drawer.get_sound()->get_music3(),map.volume);
			map.system_status = BGM;
			map.bgm_order = 3;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 4:
			hge->Channel_StopAll();
			hge->Effect_PlayEx(drawer.get_sound()->get_run_snd(),map.volume);
			map.system_status = BGM;
			map.bgm_order = 0;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 5:
			hge->Channel_StopAll();
			map.system_status = BGM;
			map.volume++;
			gui->SetFocus(5);
			gui->Enter();
			break;
		case 6:
			hge->Channel_StopAll();
			map.system_status = BGM;
			map.volume--;
			gui->SetFocus(6);
			gui->Enter();
			break;
		case 7:
			hge->Channel_StopAll();
			map.system_status = OPTION;
			gui->SetFocus(1);
			gui->Enter();
			break;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) gui->Leave(); }
	return false;
}
//选择菜单
bool Logic::option_gui_control()
{
	HGE* hge = drawer.get_hge();
	hgeGUI* gui = drawer.get_menu()->get_option_gui();
	static float t=0.0f;
	int id;
	static int lastid=0;

	if(hge->Input_KeyDown(HGEK_ESCAPE)) { lastid = 5;gui->Leave();}

	id=gui->Update(hge->Timer_GetDelta());
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			map.system_status = BACKGROUND;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 2:
			map.system_status = BGM;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 3:
			map.system_status = RANKING;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 4:
			map.system_status = DIFFICULTY;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 5:
			map.system_status = START;
			gui->SetFocus(1);
			gui->Enter();
			break;
		}
	}
	else if(id) { lastid=id; if(hge->Input_GetKeyState(HGEK_ENTER)) gui->Leave(); }
	return false;
}

void Logic::play_bgm()//根据玩家的选择播放背景音乐
{
	HGE* hge = drawer.get_hge();
	switch(map.bgm_order)
	{
	case 0:
		if(!hge->Channel_IsPlaying(drawer.get_sound()->get_run_channel()))//用于播放和重置背景音乐
			drawer.get_sound()->set_run_channel(hge->Effect_PlayEx(drawer.get_sound()->get_run_snd(),map.volume));	
		break;
	case 1:
		if(!hge->Channel_IsPlaying(drawer.get_sound()->get_music1_channel()))//用于播放和重置背景音乐
			drawer.get_sound()->set_music1_channel(hge->Effect_PlayEx(drawer.get_sound()->get_music1(),map.volume));	
		break;
	case 2:
		if(!hge->Channel_IsPlaying(drawer.get_sound()->get_music2_channel()))//用于播放和重置背景音乐
			drawer.get_sound()->set_music2_channel(hge->Effect_PlayEx(drawer.get_sound()->get_music2(),map.volume));	
		break;
	case 3:
		if(!hge->Channel_IsPlaying(drawer.get_sound()->get_music3_channel()))//用于播放和重置背景音乐
			drawer.get_sound()->set_music3_channel(hge->Effect_PlayEx(drawer.get_sound()->get_music3(),map.volume));	
		break;
	}
}

void Logic::pause_bgm()//暂停背景音乐
{
	HGE* hge = drawer.get_hge();
	switch(map.bgm_order)
	{
	case 0:
		hge->Channel_Pause(drawer.get_sound()->get_run_channel());
		break;
	case 1:
		hge->Channel_Pause(drawer.get_sound()->get_music1_channel());
		break;
	case 2:
		hge->Channel_Pause(drawer.get_sound()->get_music2_channel());
		break;
	case 3:
		hge->Channel_Pause(drawer.get_sound()->get_music3_channel());	
		break;
	}
}

void Logic::resume_bgm()//继续背景音乐
{
	HGE* hge = drawer.get_hge();
	switch(map.bgm_order)
	{
	case 0:
		hge->Channel_Resume(drawer.get_sound()->get_run_channel());
		break;
	case 1:
		hge->Channel_Resume(drawer.get_sound()->get_music1_channel());
		break;
	case 2:
		hge->Channel_Resume(drawer.get_sound()->get_music2_channel());
		break;
	case 3:
		hge->Channel_Resume(drawer.get_sound()->get_music3_channel());	
		break;
	}
}

void Logic::initialize_start()//将文件读写流关闭，并且重置系统状态
{
	tool.fin.close();
	tool.fout.close();
	tool.rand_fin.close();
	tool.rand_fout.close();
	tool.save_fout.close();
	tool.score_fin.close();
	tool.score_fout.close();
	tool.diffculty_fin.close();
	tool.difficulty_fout.close();
	drawer.get_hge()->Channel_StopAll();
	frame_num = 0;
	map.replay = false;
	map.load = false;
	map.player->set_super_bull(false);
}

bool Logic::FrameFunc()
{
	HGE* hge = drawer.get_hge();
	if(map.replay)
	{
		if(!tool.fin.eof()&&!tool.fin.fail())
		{
			if(map.system_status!=PAUSE)
				tool.fin>>frame_num>>up>>down>>left>>right>>z>>x;
		}
		else
			map.system_status = START;
	}

	switch(map.system_status)
	{
	case START:
		initialize_start();
		map.bg_time_offset = hge->Timer_GetTime();
		frame_result = gui_control();
		break;
	case OPTION:
		frame_result = option_gui_control();
		break;
	case BGM:
		frame_result = bgm_gui_control();
		break;
	case BACKGROUND:
		frame_result = bg_gui_control();
		break;
	case RANKING:
		frame_result = ranking_gui_control();
		break;
	case DIFFICULTY:
		frame_result = difficulty_gui_control();
		break;
	case WIN:
		if(!hge->Channel_IsPlaying(drawer.get_sound()->get_win_channel()))//用于播放和重置胜利音乐
			drawer.get_sound()->set_win_channel(hge->Effect_PlayEx(drawer.get_sound()->get_win_music(),map.volume));
		frame_result = win_gui_control();
		break;
	case FAILE:
		if(!hge->Channel_IsPlaying(drawer.get_sound()->get_lose_channel()))//用于播放和重置失败音乐
			drawer.get_sound()->set_lose_channel(hge->Effect_PlayEx(drawer.get_sound()->get_lose_music(),map.volume));
		frame_result = lose_gui_control();
		break;
	case PAUSE://暂停时停止画面并且暂停音乐
		pause_bgm();
		map.bg_time_offset = hge->Timer_GetTime() - map.bg_time;
		frame_result = pause_gui_control();
		break;
	default:
		play_bgm();
		map.bg_time = hge->Timer_GetTime() - map.bg_time_offset;
		if(map.replay)
		{
			frame_result = replay_key_control();
			drawer.get_scene()->update();
			game_logic();
		}
		else
		{
			tool.fout<<frame_num<<" ";//即时记录游戏帧数和玩家键盘信息
			frame_result = key_control();
			drawer.get_scene()->update();
			game_logic();
			frame_num++;
		}
		break;
	}
	return frame_result;
}