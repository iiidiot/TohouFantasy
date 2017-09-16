#include "Map.h"
#include "Tools.h"
#pragma once

class Logic
{
	friend void Tools::load();
	friend void Map::next_stage();
	int  frame_num;//游戏即时帧数，相当于游戏时间，用帧数的原因是方便replay，帧数是整数无误差，时间有很小的误差，积累之后会使录像回放失败

	short up,down,left,right,z,x;//上下左右zx，用于记录玩家键盘输入
    bool frame_result;//帧函数的返回值
	void stage1_logic();
	void stage2_logic();
	void stage3_logic();
	void stage4_logic();
	void stage5_logic();
	void game_logic();//游戏逻辑，汇总了上述5个关卡

	//菜单控制
	bool replay_key_control();
	bool key_control();
	bool gui_control();
	bool pause_gui_control();
	bool win_gui_control();
	bool lose_gui_control();
	bool bg_gui_control();
	bool bgm_gui_control();
	bool option_gui_control();
	bool ranking_gui_control();
	bool difficulty_gui_control();

	//对于音乐的处理函数
	void play_bgm();
	void pause_bgm();
	void resume_bgm();
	//start系统状态下重置一些变量
	void initialize_start();
public:
	bool FrameFunc();//游戏的帧函数

	int get_frame_num() { return frame_num; }

	Logic():frame_result(false),frame_num(0){}
};