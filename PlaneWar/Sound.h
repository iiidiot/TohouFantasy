#include "include\hge.h"
#pragma once

class Sound //存放了游戏的相关声音素材，并提供相关操作
{
	HEFFECT		explode_snd,shoot_snd,win_snd,win_music,lose_snd,lose_music,
		        power_snd,run_snd,menu_snd,
				music1,music2,music3;
	HCHANNEL    run_channel,win_channel,lose_channel,
		        music1_channel,music2_channel,music3_channel;
public:
	void load();//load声音

	HEFFECT get_shoot_snd()    { return shoot_snd; }
	HEFFECT get_explode_snd()  { return explode_snd; }
	HEFFECT get_win_snd()      { return win_snd; }
	HEFFECT get_win_music()    { return win_music; }
	HEFFECT get_lose_snd()     { return lose_snd; }
	HEFFECT get_lose_music()   { return lose_music; }
	HEFFECT get_run_snd()      { return run_snd; }
	HEFFECT get_power_snd()    { return power_snd; }
	HEFFECT get_menu_snd()     { return menu_snd; }
	HEFFECT get_music1()       { return music1; }
	HEFFECT get_music2()       { return music2; }
	HEFFECT get_music3()       { return music3; }

	HCHANNEL get_run_channel()           { return run_channel; }
	HCHANNEL get_win_channel()           { return win_channel; }
	HCHANNEL get_lose_channel()          { return lose_channel; }
	HCHANNEL get_music1_channel()        { return music1_channel; }
	HCHANNEL get_music2_channel()        { return music2_channel; }
	HCHANNEL get_music3_channel()        { return music3_channel; }
	void set_run_channel(HCHANNEL m)     { run_channel = m; }
	void set_win_channel(HCHANNEL m)     { win_channel = m; }
	void set_lose_channel(HCHANNEL m)    { lose_channel = m; }
	void set_music1_channel(HCHANNEL m)  { music1_channel = m; }
	void set_music2_channel(HCHANNEL m)  { music2_channel = m; }
	void set_music3_channel(HCHANNEL m)  { music3_channel = m; }

	void end_up();
};