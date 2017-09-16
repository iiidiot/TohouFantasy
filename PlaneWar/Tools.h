#include "include\hge.h"
#include "include\hgesprite.h"
#include "Elements.h"
#include <string>
#include <vector>
#include <fstream>
#pragma once

//工具类，提供了像素级碰撞检测，高级加子弹方式，高级移动方式，和读写文件流
struct Tools
{
	ofstream fout,save_fout,rand_fout,score_fout,difficulty_fout;
	ifstream fin,rand_fin,score_fin,diffculty_fin;

	vector<int>rank;//rank向量用于排序，从而重置排行榜
	void save();
	void load();
	void update_ranking();//更新排行榜，每次游戏结束时都会即时更新
	void initialize_difficulty();//读取游戏难度，背景，背景音乐，用于回放

	static void Move_1(Enemy *e);//高级移动方式
	static void Move_2(Enemy *e);
	static void Move_3(Enemy *e);
	static void Move_4(Enemy *e);
	static void Move_5(Enemy *e);
	
	static void AddBullet_1(Enemy *e);//高级加子弹方式
	static void AddBullet_4(Enemy *e);
	static void AddBullet_5(Enemy *e);

	void AddBullet_2(Enemy *e);
	void AddBullet_3(Enemy *e);

	static bool IsCollision(hgeSprite* spr1, //像素碰撞检测
		             float x1, float y1, 
					 hgeSprite* spr2, 
					 float x2, float y2, 
					 HTEXTURE hot1 = 0, HTEXTURE hot2 = 0, 
					 DWORD airColor = 0x00ffffff);
};