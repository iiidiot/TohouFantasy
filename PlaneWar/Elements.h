
//定义了Elements类，之后的类都是从其中继承而来

#include <math.h>
#include "Definition.h"
#include <iostream>
using namespace std;
#pragma once

class Elements
{
protected:   //速度，位置，长宽，状态，类型
	float speed;
	float x,y;
	float w,h;
	int   status;
	int   type;
public:
	void move(float ds,float a);      //move函数是沿指定角度移动
	bool collision_test(Elements &a); //进行简化的矩形碰撞检测

	float get_x() { return x; }
	float get_y() { return y; }

	float get_w() { return w; }
	float get_h() { return h; }

	int get_type() { return type; }
	float get_speed() { return speed;}
	int  get_status() { return status;}
	void set_type(int tp)  { type = tp;  } 
	void set_speed(float s){ speed = s;  }
	void set_status(int i) { status = i; }

	void set_x(float xx) { x = xx; }
	void set_y(float yy) { y = yy; }

	void set_w(float ww) { w = ww; }
	void set_h(float hh) { h = hh ;}
};

class Bullet : public Elements 
{
	float power;//威力
	float sita; //发射角度
    Bullet *prev, *next;//前后指针
public:
	void set_power(float p)  { power = p; }
	void set_sita(float a)   { sita = a ; }
	float get_sita()         { return sita; }

	Bullet* get_next()       { return next; }
	Bullet* get_prev()       { return prev; }
	float get_power()        { return power; }
	void set_next(Bullet* p) { next = p; }
	void set_prev(Bullet* p) { prev = p; }

	Bullet(float xx,float yy,int tp);
};

class Enemy : public Elements
{
	Enemy*  next;//前后指针
	Enemy*  prev;
	int     move_status;//移动状态，分为左右，射击，前后，用于画对应的动画
	int     move_frame;//移动帧数，和游戏时的即时帧数结合来实现保持一定时间的移动状态不变
	int     shoot_frame,frozen_frame,super_frame;//状态帧数，和游戏时的即时帧数结合来实现定时功能，比如保持无敌2秒，保持冰冻2秒等
	int     shoot_interval;//射击间隔
	float   blood;
	float   sita;//移动方向
	bool    frozen,super;
public:
	Enemy* get_next()                { return next; }
	Enemy* get_prev()                { return prev; }
	int get_shoot_frame()            { return shoot_frame; }
	int get_shoot_interval()         { return shoot_interval; }
	int get_move_frame()             { return move_frame; }
	int get_frozen_frame()           { return frozen_frame; }
	int get_super_frame()            { return super_frame; }
	int get_move_status()            { return move_status; }
	float get_sita()                 { return sita; }
	float get_blood()                { return blood;}
	bool is_frozen()                 { return frozen; }
	bool is_super()                  { return super; }

	void set_next(Enemy* p)          { next = p; }
	void set_prev(Enemy* p)          { prev = p; }
	void set_shoot_frame(int t)      { shoot_frame = t; }
	void set_frozen_frame(int t)     { frozen_frame = t; }
	void set_frozen(bool b)          { frozen = b; }
	void set_super(bool b)           { super = b; }
	void set_blood(float b)          { blood = b;}
	void set_sita(float s)           { sita = s; }
	void set_move_frame(int t)       { move_frame = t; }
	void set_super_frame(int t)      { super_frame = t; }
	void set_move_status(int s)      { move_status = s; }
	void set_shoot_interval(int s)   { shoot_interval = s; }

	void befrozen(int t)             { frozen = true; frozen_frame = t; }
	void benotfrozen()               { frozen = false; }

	Enemy(float xx,float yy,int tp);
};

class Wingman : public Elements
{
	float sita;//角度，用于旋转
	int shoot_interval;//射击间隔
	int shoot_frame;//射击帧数，用于保持一定时间无法射击，从而实现射击间隔
	Wingman *prev,*next;//前后指针
public:      
	float get_sita()                  { return sita; }
	int get_shoot_frame()             { return shoot_frame; }
	int get_shoot_interval()          { return shoot_interval; }
	Wingman* get_prev()               { return prev; }
	Wingman* get_next()               { return next; }
	void set_shoot_frame(int t)       { shoot_frame = t; }
	void set_sita(float s)            { sita = s; }
	void set_next(Wingman *w)         { next = w; }
	void set_prev(Wingman *w)         { prev = w; }

	void increase_sita() //旋转
	{
		if(sita<2*PI)
			sita+=0.03;
		else
			sita = 0;
	}

	Wingman(float xx,float yy,int tp);
};

class Player : public Elements
{
	//子弹的链表
	Bullet*  first; 
	Bullet*  last;
	//僚机的链表
	Wingman* w_first;
	Wingman* w_last;
	float    blood;
	int      life;
	int      bull_num,wingman_num; //弹道个数，僚机数量，弹道个数最多为3,3个时为散弹
	int      move_status;
	int      shoot_frame;
	int      super_frame,frozen_frame,super_bull_frame;//无敌时间,冰冻时间，大招时间
	bool     super_bull;//大招，用于判断大招是否发出，大招发出时无法发射普通子弹
public:
	void restart();//清空玩家状态，回到初始值，子弹僚机都清空，用于游戏重开
	void boom(bool b);//死亡时会发射一圈子弹,并根据原有的弹道数掉落加弹道的power，根据原有僚机数掉落僚机的power

	void add_wingman(int tp);
	void erase_wingman(Wingman* p);
	void move_wingman();
	void wingman_add_bullet(int t,Wingman* p);
	void add_bullet(int t);
	void erase_bullet(Bullet* p);
	void initialize(int t);//初始化状态，用于死亡时，并不会清空子弹
	void add_super_bull(int t);//放大招

	Bullet* get_first()                       { return first; }
	Bullet* get_last()                        { return last;  }
	Wingman* get_w_first()                    { return w_first; }
	Wingman* get_w_last()                     { return w_last;  }
    
	int get_bull_num()                        { return bull_num; }
	int get_wingman_num()                     { return wingman_num; }
	int get_life()                            { return life; }
	int get_move_status()                     { return move_status; }
	int get_shoot_frame()                     { return shoot_frame; }
	int get_super_frame()                     { return super_frame; }
	int get_frozen_frame()                    { return frozen_frame; }
	int get_super_bull_frame()                { return super_bull_frame; }
	float get_blood()                         { return blood; }
	bool get_super_bull()                     { return super_bull; }

	void set_shoot_frame(int t)               { shoot_frame = t; }
	void set_super_frame(int t)               { super_frame = t; }
	void set_frozen_frame(int t)              { frozen_frame = t; }
	void set_life(int li)                     { life = li; }
	void set_blood(float b)                   { blood = b; }
	void set_bull_num(int i)                  { bull_num = i; } 
	void set_wingman_num(int i)               { wingman_num = i; }
	void set_move_status(int i)               { move_status = i; }
	void set_super_bull(bool b)               { super_bull = b; }
	void set_super_bull_frame(int i)          { super_bull_frame = i; }
	
	void bull_num_increase()                  { if(bull_num<3) bull_num++; }//弹道数量最多为3
	void life_increase()                      { life++; }
	void blood_increase()                     { if(PL_BLOOD-blood>=1) blood++;else blood = PL_BLOOD; }
	void life_decrease(int t)                 {	life--;	initialize(t);	}
	void befrozen(int t)                      { status = FROZEN; frozen_frame = t; }//冰冻
	
	Player(float xx,float yy,float ww,float hh,float sp);
	~Player() { delete first;delete w_first; }
};

class Power :public Elements//Power是补给品，即掉落物品，总共8种
{
	Power* prev,*next;
public:
	Power* get_next()               { return next; }
	Power* get_prev()               { return prev; }
	void set_next(Power* p)         { next = p; }
	void set_prev(Power* p)         { prev = p; }

	Power(float xx,float yy,int tp);
};

class Explosion : public Elements//爆炸类，用于画敌人死亡时的动画
{
	Explosion *prev,*next;
	int        frame;//帧数，和游戏即时帧数结合来画一段时间的爆炸动画
public:
	Explosion* get_next()       { return next; }
	Explosion* get_prev()       { return prev; }
	void set_next(Explosion* p) { next = p; }
	void set_prev(Explosion* p) { prev = p; }
	void set_frame(int t)       { frame = t; }
	int  get_frame()            { return frame;}
	
	Explosion(float xx,float yy,int tp);
};


