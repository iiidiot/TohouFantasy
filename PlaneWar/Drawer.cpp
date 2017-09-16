#include "Drawer.h"
#include "Map.h"
#include "Tools.h"

extern Map map;

void Drawer::start_draw()
{
	if(hge->System_Initiate())
	{
		load();
		menu->intialize_gui();
		// Let's rock now!
		hge->System_Start();
		menu->end_gui();
		scene->end_up();
		sound->end_up();
	}
}

void Drawer::initialize_hge()
{
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_LOGFILE, "hge.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "Mountain of Faith");
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SHOWSPLASH,false);
	hge->System_SetState(HGE_FPS,50);
	hge->System_SetState(HGE_SCREENWIDTH, WIN_W);
	hge->System_SetState(HGE_SCREENHEIGHT, WIN_H);
	hge->System_SetState(HGE_SCREENBPP, 32);
}

void Drawer::end_hge()
{
	hge->System_Shutdown();
	hge->Release();
}

bool Drawer::RenderFunc()//根据系统状态进行不同的绘制
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0xFFFF0000);
	scene->draw();
	hgeFont* fnt2 = scene->get_fnt2();
	switch(map.get_system_status())
	{
	case START:
		hge->Gfx_Clear(0);
		menu->draw_menu();
		menu->get_gui()->Render();	
		break;
	case OPTION:
		hge->Gfx_Clear(0);
		menu->draw_option_menu();
		menu->get_option_gui()->Render();
		break;
	case PAUSE:
		menu->draw_pause_menu();
		menu->get_pause_gui()->Render();
		break;
	case WIN:
		menu->draw_win_menu();
		menu->get_win_gui()->Render();
		fnt2->SetColor(0xFFFFFF22);
		fnt2->printf(WIN_W/2.0-fnt2->GetStringWidth("You Win!!")/2.0,150,HGETEXT_LEFT,"You Win!!");
		fnt2->SetColor(0xFFFFFFFF);
		break;
	case FAILE:
		menu->draw_lose_menu();
		menu->get_lose_gui()->Render();
		fnt2->SetColor(0xFFFF2222);
		fnt2->printf(WIN_W/2.0-fnt2->GetStringWidth("Game Over")/2.0,150,HGETEXT_LEFT,"Game Over");
		fnt2->SetColor(0xFFFFFFFF);
		break;
	case BACKGROUND:
		hge->Gfx_Clear(0);
		menu->draw_option_menu();
		menu->get_bg_gui()->Render();
		switch(menu->get_order())
		{
		case 0:
			scene->get_bg0()->RenderEx(200,100,0,0.6);
			break;
		case 1:
			scene->get_bg1()->RenderEx(200,100,0,0.6);
			break;
		case 2:
			scene->get_bg2()->RenderEx(200,100,0,0.6);
			break;
		}
		break;
	case BGM:
		hge->Gfx_Clear(0);
		menu->draw_option_menu();
		menu->get_bgm_gui()->Render();
		scene->draw_volume();
		break;
	case DIFFICULTY:
		hge->Gfx_Clear(0);
		menu->draw_option_menu();
		menu->get_difficulty_gui()->Render();
		break;
	case RANKING:
		hge->Gfx_Clear(0);
		menu->draw_ranking_menu();
		menu->get_ranking_gui()->Render();
		break;
	default:
		break;
	}
	hge->Gfx_EndScene();

	return false;
}

bool Drawer::FrameFunc()//调用logic的逻辑函数
{
	return logic->FrameFunc();
}

void Drawer::load()//将菜单，场景，声音全部载入，是个汇总函数
{
	menu->load();
	menu->set_sprite();
	scene->load();
	sound->load();
	scene->set_font();
	scene->set_sprite();
	scene->set_animition();
}

Drawer::~Drawer()
{
	delete scene;
	delete sound;
	delete menu;
	delete logic;
}



