#include "Drawer.h"
#include "Tools.h"
#include <time.h>
#pragma   comment   (linker,"/NODEFAULTLIB:libc.lib")

HGE*   Drawer::hge   = 0;
Scene* Drawer::scene = new Scene();
Sound* Drawer::sound = new Sound();
Menu*  Drawer::menu  = new Menu();
Logic* Drawer::logic = new Logic();

Tools   tool;
Map     map;//存储数据类map
Drawer  drawer;//绘图类drawer

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	srand(time(NULL));//设置随机种子
	drawer.initialize_hge();//初始化hge
	drawer.start_draw();//开始画图
	drawer.end_hge();//结束
}
