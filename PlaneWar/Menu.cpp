#include "Menu.h"
#include "Drawer.h"
#include "menuitem.h"
#include "Tools.h"

extern Drawer drawer;
extern Tools tool;

void Menu::load()
{
	bg_tex    = drawer.get_hge()->Texture_Load("menu_bg.png");
	bg_1_tex  = drawer.get_hge()->Texture_Load("bg.png");
	pause_bg_tex = drawer.get_hge()->Texture_Load("background.png");
	menu_fnt  = new hgeFont("menu_font.fnt");
}

void Menu::set_sprite()
{
	bg_spr = new hgeSprite(bg_tex,0,0,WIN_W,WIN_H);
	bg_1_spr = new hgeSprite(bg_1_tex,0,0,WIN_W,WIN_H);
	pause_bg_spr = new hgeSprite(pause_bg_tex,0,0,WIN_W,WIN_H);
}

void Menu::draw_menu()
{
	bg_spr->Render(0,0);
}

void Menu::draw_pause_menu()
{
	pause_bg_spr->SetColor(0xA0FF0000);
	pause_bg_spr->Render(0,0);
}

void Menu::draw_win_menu()
{
	pause_bg_spr->SetColor(0xA0000000);
	pause_bg_spr->Render(0,0);
	menu_fnt->SetColor(0xFFFFFF22);
	menu_fnt->printf(140,300,HGETEXT_LEFT,"The game is so easy\nChoose a harder mode?");
	menu_fnt->SetColor(0xFFFFFFFF);
}

void Menu::draw_lose_menu()
{
	pause_bg_spr->SetColor(0xA0FF0000);
	pause_bg_spr->Render(0,0);
	menu_fnt->SetColor(0xFFFF2222);
	menu_fnt->printf(120,300,HGETEXT_LEFT,"Too young Too simple\nChoose an easier mode?");
	menu_fnt->SetColor(0xFFFFFFFF);
}

void Menu::draw_option_menu()
{
	bg_1_spr->Render(0,0);
}

void Menu::draw_ranking_menu()
{
	bg_1_spr->Render(0,0);
	menu_fnt->SetColor(0xFFFFFF33);
	tool.rand_fin.close();
	tool.rand_fin.open("ranking.txt");
	menu_fnt->printf(100,50,HGETEXT_LEFT,"Ranking Board");
	for(int i=0;i<5;++i)
	{
		int score;
		tool.rand_fin>>score;
		menu_fnt->printf(100,150+i*50,HGETEXT_LEFT,"%d: %d",i+1,score);
	}
	menu_fnt->SetColor(0xFFFFFFFF);
	tool.rand_fin.close();
}

void Menu::intialize_gui()
{
	// Create and initialize the GUI
	gui=new hgeGUI();

	gui->AddCtrl(new hgeGUIMenuItem(1,menu_fnt,drawer.get_sound()->get_menu_snd(),120,200,0.0f,"New Game"));
	gui->AddCtrl(new hgeGUIMenuItem(2,menu_fnt,drawer.get_sound()->get_menu_snd(),120,250,0.1f,"Load"));
	gui->AddCtrl(new hgeGUIMenuItem(3,menu_fnt,drawer.get_sound()->get_menu_snd(),210,300,0.2f,"LastReplay"));
	gui->AddCtrl(new hgeGUIMenuItem(4,menu_fnt,drawer.get_sound()->get_menu_snd(),210,350,0.3f,"Options"));
	gui->AddCtrl(new hgeGUIMenuItem(5,menu_fnt,drawer.get_sound()->get_menu_snd(),240,400,0.4f,"Exit"));

	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->SetFocus(1);
	gui->Enter();

	option_gui=new hgeGUI();

	option_gui->AddCtrl(new hgeGUIMenuItem(1,menu_fnt,drawer.get_sound()->get_menu_snd(),100,100,0.0f,"Background"));
	option_gui->AddCtrl(new hgeGUIMenuItem(2,menu_fnt,drawer.get_sound()->get_menu_snd(),100,160,0.1f,"Music"));
	option_gui->AddCtrl(new hgeGUIMenuItem(3,menu_fnt,drawer.get_sound()->get_menu_snd(),100,220,0.2f,"Ranking"));
	option_gui->AddCtrl(new hgeGUIMenuItem(4,menu_fnt,drawer.get_sound()->get_menu_snd(),100,280,0.3f,"Difficulty"));
	option_gui->AddCtrl(new hgeGUIMenuItem(5,menu_fnt,drawer.get_sound()->get_menu_snd(),100,340,0.4f,"Back"));

	option_gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	option_gui->SetFocus(1);
	option_gui->Enter();

	pause_gui=new hgeGUI();

	pause_gui->AddCtrl(new hgeGUIMenuItem(1,menu_fnt,drawer.get_sound()->get_menu_snd(),300,200,0.0f,"Back to Main Menu"));
	pause_gui->AddCtrl(new hgeGUIMenuItem(2,menu_fnt,drawer.get_sound()->get_menu_snd(),300,250,0.1f,"Restart"));
	pause_gui->AddCtrl(new hgeGUIMenuItem(3,menu_fnt,drawer.get_sound()->get_menu_snd(),300,300,0.2f,"Save"));
	pause_gui->AddCtrl(new hgeGUIMenuItem(4,menu_fnt,drawer.get_sound()->get_menu_snd(),300,350,0.3f,"Cancel"));

	pause_gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	pause_gui->SetFocus(1);
	pause_gui->Enter();

	win_gui=new hgeGUI();

	win_gui->AddCtrl(new hgeGUIWinMenu(1,menu_fnt,drawer.get_sound()->get_menu_snd(),400,500,0.0f,"Back to Main Menu"));

	win_gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	win_gui->SetFocus(1);
	win_gui->Enter();

	lose_gui=new hgeGUI();

	lose_gui->AddCtrl(new hgeGUIMenuItem(1,menu_fnt,drawer.get_sound()->get_menu_snd(),170,500,0.0f,"Back to Main Menu"));
	lose_gui->AddCtrl(new hgeGUIMenuItem(2,menu_fnt,drawer.get_sound()->get_menu_snd(),500,500,0.1f,"Restart"));

	lose_gui->SetNavMode(HGEGUI_LEFTRIGHT | HGEGUI_UPDOWN | HGEGUI_CYCLED);
	lose_gui->SetFocus(1);
	lose_gui->Enter();

	bg_gui=new hgeGUI();

	bg_gui->AddCtrl(new hgeGUIBGMenu(1,0,menu_fnt,drawer.get_sound()->get_menu_snd(),100,100,0.0f,"BG 1"));
	bg_gui->AddCtrl(new hgeGUIBGMenu(2,1,menu_fnt,drawer.get_sound()->get_menu_snd(),100,200,0.1f,"BG 2"));
	bg_gui->AddCtrl(new hgeGUIBGMenu(3,2,menu_fnt,drawer.get_sound()->get_menu_snd(),100,300,0.2f,"BG 3"));
	bg_gui->AddCtrl(new hgeGUIMenuItem(4,menu_fnt,drawer.get_sound()->get_menu_snd(),100,400,0.3f,"Back"));

	bg_gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	bg_gui->SetFocus(1);
	bg_gui->Enter();

	bgm_gui=new hgeGUI();

	bgm_gui->AddCtrl(new hgeGUIMenuItem(1,menu_fnt,drawer.get_sound()->get_menu_snd(),300,50,0.0f,"BGM 1"));
	bgm_gui->AddCtrl(new hgeGUIMenuItem(2,menu_fnt,drawer.get_sound()->get_menu_snd(),350,100,0.1f,"BGM 2"));
	bgm_gui->AddCtrl(new hgeGUIMenuItem(3,menu_fnt,drawer.get_sound()->get_menu_snd(),400,150,0.2f,"BGM 3"));
	bgm_gui->AddCtrl(new hgeGUIMenuItem(4,menu_fnt,drawer.get_sound()->get_menu_snd(),450,200,0.3f,"BGM 4"));
	bgm_gui->AddCtrl(new hgeGUIMenuItem(5,menu_fnt,drawer.get_sound()->get_menu_snd(),50,300,0.4f,"add"));
	bgm_gui->AddCtrl(new hgeGUIMenuItem(6,menu_fnt,drawer.get_sound()->get_menu_snd(),350,300,0.5f,"minus"));
	bgm_gui->AddCtrl(new hgeGUIMenuItem(7,menu_fnt,drawer.get_sound()->get_menu_snd(),500,250,0.6f,"Back"));

	bgm_gui->SetNavMode(HGEGUI_LEFTRIGHT | HGEGUI_UPDOWN | HGEGUI_CYCLED);
	bgm_gui->SetFocus(1);
	bgm_gui->Enter();

	ranking_gui=new hgeGUI();

	ranking_gui->AddCtrl(new hgeGUIMenuItem(1,menu_fnt,drawer.get_sound()->get_menu_snd(),500,400,0.0f,"Back"));

	ranking_gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	ranking_gui->SetFocus(1);
	ranking_gui->Enter();

	difficulty_gui=new hgeGUI();

	difficulty_gui->AddCtrl(new hgeGUIMenuItem(1,menu_fnt,drawer.get_sound()->get_menu_snd(),100,150,0.0f,"Easy"));
	difficulty_gui->AddCtrl(new hgeGUIMenuItem(2,menu_fnt,drawer.get_sound()->get_menu_snd(),100,200,0.1f,"Normal"));
	difficulty_gui->AddCtrl(new hgeGUIMenuItem(3,menu_fnt,drawer.get_sound()->get_menu_snd(),100,250,0.2f,"Hard"));
	difficulty_gui->AddCtrl(new hgeGUIMenuItem(4,menu_fnt,drawer.get_sound()->get_menu_snd(),100,300,0.3f,"Hell"));
	difficulty_gui->AddCtrl(new hgeGUIMenuItem(5,menu_fnt,drawer.get_sound()->get_menu_snd(),500,400,0.4f,"Back"));

	difficulty_gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	difficulty_gui->SetFocus(1);
	difficulty_gui->Enter();
};

void Menu::end_gui()
{
	delete gui;
	delete pause_gui;
	delete win_gui;
	delete lose_gui;
	delete bg_gui;
	delete option_gui;
	delete bgm_gui;
	delete ranking_gui;
	delete difficulty_gui;
}
