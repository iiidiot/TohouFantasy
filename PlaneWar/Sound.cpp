#include "Sound.h"
#include "Drawer.h"

extern Drawer drawer;

void Sound::load()
{
	explode_snd         = drawer.get_hge()->Effect_Load ("explode.wav");
	shoot_snd           = drawer.get_hge()->Effect_Load("shoot.wav");
	win_snd             = drawer.get_hge()->Effect_Load ("win.wav");
	win_music           = drawer.get_hge()->Effect_Load("win_music.wav");
	lose_snd            = drawer.get_hge()->Effect_Load("lose.wav");
	lose_music          = drawer.get_hge()->Effect_Load("lose_music.wav");
	power_snd           = drawer.get_hge()->Effect_Load ("power.wav");
	run_snd             = drawer.get_hge()->Effect_Load ("run_music.mp3");
	menu_snd            = drawer.get_hge()->Effect_Load("menu.wav");
	music1              = drawer.get_hge()->Effect_Load("music1.mp3");
	music2              = drawer.get_hge()->Effect_Load("music2.mp3");
	music3              = drawer.get_hge()->Effect_Load("music3.mp3");
}

void Sound::end_up()
{
	drawer.get_hge()->Effect_Free(explode_snd);
	drawer.get_hge()->Effect_Free(shoot_snd);
	drawer.get_hge()->Effect_Free(win_snd);
	drawer.get_hge()->Effect_Free(win_music);
	drawer.get_hge()->Effect_Free(lose_snd);
	drawer.get_hge()->Effect_Free(lose_music);
	drawer.get_hge()->Effect_Free(run_snd);
	drawer.get_hge()->Effect_Free(power_snd);
	drawer.get_hge()->Effect_Free(menu_snd);
}