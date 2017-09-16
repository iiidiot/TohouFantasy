#include "include\hge.h"
#include "include\hgesprite.h"
#include "Elements.h"
#include <string>
#include <vector>
#include <fstream>
#pragma once

//�����࣬�ṩ�����ؼ���ײ��⣬�߼����ӵ���ʽ���߼��ƶ���ʽ���Ͷ�д�ļ���
struct Tools
{
	ofstream fout,save_fout,rand_fout,score_fout,difficulty_fout;
	ifstream fin,rand_fin,score_fin,diffculty_fin;

	vector<int>rank;//rank�����������򣬴Ӷ��������а�
	void save();
	void load();
	void update_ranking();//�������а�ÿ����Ϸ����ʱ���ἴʱ����
	void initialize_difficulty();//��ȡ��Ϸ�Ѷȣ��������������֣����ڻط�

	static void Move_1(Enemy *e);//�߼��ƶ���ʽ
	static void Move_2(Enemy *e);
	static void Move_3(Enemy *e);
	static void Move_4(Enemy *e);
	static void Move_5(Enemy *e);
	
	static void AddBullet_1(Enemy *e);//�߼����ӵ���ʽ
	static void AddBullet_4(Enemy *e);
	static void AddBullet_5(Enemy *e);

	void AddBullet_2(Enemy *e);
	void AddBullet_3(Enemy *e);

	static bool IsCollision(hgeSprite* spr1, //������ײ���
		             float x1, float y1, 
					 hgeSprite* spr2, 
					 float x2, float y2, 
					 HTEXTURE hot1 = 0, HTEXTURE hot2 = 0, 
					 DWORD airColor = 0x00ffffff);
};