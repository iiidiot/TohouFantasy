#include "Map.h"
#include "Tools.h"
#pragma once

class Logic
{
	friend void Tools::load();
	friend void Map::next_stage();
	int  frame_num;//��Ϸ��ʱ֡�����൱����Ϸʱ�䣬��֡����ԭ���Ƿ���replay��֡������������ʱ���к�С��������֮���ʹ¼��ط�ʧ��

	short up,down,left,right,z,x;//��������zx�����ڼ�¼��Ҽ�������
    bool frame_result;//֡�����ķ���ֵ
	void stage1_logic();
	void stage2_logic();
	void stage3_logic();
	void stage4_logic();
	void stage5_logic();
	void game_logic();//��Ϸ�߼�������������5���ؿ�

	//�˵�����
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

	//�������ֵĴ�����
	void play_bgm();
	void pause_bgm();
	void resume_bgm();
	//startϵͳ״̬������һЩ����
	void initialize_start();
public:
	bool FrameFunc();//��Ϸ��֡����

	int get_frame_num() { return frame_num; }

	Logic():frame_result(false),frame_num(0){}
};