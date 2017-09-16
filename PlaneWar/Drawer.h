#include "Map.h"
#include "Scene.h"
#include "Sound.h"
#include "Menu.h"
#include "Logic.h"
#pragma once

//Drawer类负责画图和播放声音，将hge封装在其中，并且Render函数也在其中
class Drawer
{
	static Scene *scene;//专门画游戏场景，元素图片的载入和设置都在其中进行
	static Sound *sound;//专门播放声音，声音的载入和设置都在其中设置
	static HGE   *hge;//hge指针
	static Menu  *menu; //菜单类，里面有各种菜单，并负责菜单的载入和一些菜单所需画面和声音的初始化
	static Logic *logic;//逻辑类，游戏逻辑和帧函数都在其中
public:
	static bool RenderFunc();//hge所需的画图函数
	static bool FrameFunc();//hge所需的逻辑函数，但它本身不进行逻辑操作，只是调用Logic类里面的帧函数

	void initialize_hge();
	void end_hge();
	void load();//load是个汇总函数，有scene类的load和sound类的load，将图片和声音载入
	void start_draw();//start_draw是个汇总函数，先把游戏所需所有元素load，然后初始化hge，菜单等，然后画图，然后结束游戏

	static HGE   *get_hge()   { return hge; }
	static Scene *get_scene() { return scene; }
	static Sound *get_sound() { return sound; }
	static Menu  *get_menu()  { return menu; }
	static Logic *get_logic() { return logic; }

	~Drawer();
};