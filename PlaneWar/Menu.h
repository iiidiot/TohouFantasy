#include "include\hgegui.h"
#include "include\hgefont.h"
#include "include\hgesprite.h"
#pragma once

class Menu
{
	friend      class hgeGUIBGMenu;
	hgeGUI	    *gui,*option_gui,//��ʼ�˵�����ͣ�˵���ѡ��˵���ʤ���˵���ʧ�ܲ˵��������˵����������ֲ˵������а�˵����ѶȲ˵�
		        *pause_gui,*win_gui,*lose_gui,
		        *bg_gui,*bgm_gui,*ranking_gui,*difficulty_gui;
	hgeFont     *menu_fnt;
	HTEXTURE     bg_tex,bg_1_tex,pause_bg_tex;
	hgeSprite   *bg_spr,*bg_1_spr,*pause_bg_spr;
	int          order;//������������ѡ�񱳾�ʱչʾ����
public:
	
    hgeGUI*    get_gui()             { return gui; }
	hgeGUI*    get_option_gui()      { return option_gui; }
	hgeGUI*    get_bg_gui()          { return bg_gui; }
	hgeGUI*    get_bgm_gui()         { return bgm_gui; }
	hgeGUI*    get_pause_gui()       { return pause_gui; }
	hgeGUI*    get_win_gui()         { return win_gui; }
	hgeGUI*    get_lose_gui()        { return lose_gui; }
	hgeGUI*    get_ranking_gui()     { return ranking_gui; }
	hgeGUI*    get_difficulty_gui()  { return difficulty_gui; }
	hgeFont*   get_font()            { return menu_fnt; }

	void load();
	void set_sprite();

	void draw_menu();
	void draw_option_menu();
	void draw_pause_menu();
	void draw_win_menu();
	void draw_lose_menu();
	void draw_ranking_menu();

	void intialize_gui();
	void end_gui();
	
	int get_order()     { return order; }

	Menu():order(0) {}
};