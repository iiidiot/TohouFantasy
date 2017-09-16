#include "Map.h"
#include "Scene.h"
#include "Sound.h"
#include "Menu.h"
#include "Logic.h"
#pragma once

//Drawer�ฺ��ͼ�Ͳ�����������hge��װ�����У�����Render����Ҳ������
class Drawer
{
	static Scene *scene;//ר�Ż���Ϸ������Ԫ��ͼƬ����������ö������н���
	static Sound *sound;//ר�Ų�����������������������ö�����������
	static HGE   *hge;//hgeָ��
	static Menu  *menu; //�˵��࣬�����и��ֲ˵���������˵��������һЩ�˵����軭��������ĳ�ʼ��
	static Logic *logic;//�߼��࣬��Ϸ�߼���֡������������
public:
	static bool RenderFunc();//hge����Ļ�ͼ����
	static bool FrameFunc();//hge������߼��������������������߼�������ֻ�ǵ���Logic�������֡����

	void initialize_hge();
	void end_hge();
	void load();//load�Ǹ����ܺ�������scene���load��sound���load����ͼƬ����������
	void start_draw();//start_draw�Ǹ����ܺ������Ȱ���Ϸ��������Ԫ��load��Ȼ���ʼ��hge���˵��ȣ�Ȼ��ͼ��Ȼ�������Ϸ

	static HGE   *get_hge()   { return hge; }
	static Scene *get_scene() { return scene; }
	static Sound *get_sound() { return sound; }
	static Menu  *get_menu()  { return menu; }
	static Logic *get_logic() { return logic; }

	~Drawer();
};