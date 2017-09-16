
//������Elements�֮࣬����඼�Ǵ����м̳ж���

#include <math.h>
#include "Definition.h"
#include <iostream>
using namespace std;
#pragma once

class Elements
{
protected:   //�ٶȣ�λ�ã�����״̬������
	float speed;
	float x,y;
	float w,h;
	int   status;
	int   type;
public:
	void move(float ds,float a);      //move��������ָ���Ƕ��ƶ�
	bool collision_test(Elements &a); //���м򻯵ľ�����ײ���

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
	float power;//����
	float sita; //����Ƕ�
    Bullet *prev, *next;//ǰ��ָ��
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
	Enemy*  next;//ǰ��ָ��
	Enemy*  prev;
	int     move_status;//�ƶ�״̬����Ϊ���ң������ǰ�����ڻ���Ӧ�Ķ���
	int     move_frame;//�ƶ�֡��������Ϸʱ�ļ�ʱ֡�������ʵ�ֱ���һ��ʱ����ƶ�״̬����
	int     shoot_frame,frozen_frame,super_frame;//״̬֡��������Ϸʱ�ļ�ʱ֡�������ʵ�ֶ�ʱ���ܣ����籣���޵�2�룬���ֱ���2���
	int     shoot_interval;//������
	float   blood;
	float   sita;//�ƶ�����
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
	float sita;//�Ƕȣ�������ת
	int shoot_interval;//������
	int shoot_frame;//���֡�������ڱ���һ��ʱ���޷�������Ӷ�ʵ��������
	Wingman *prev,*next;//ǰ��ָ��
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

	void increase_sita() //��ת
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
	//�ӵ�������
	Bullet*  first; 
	Bullet*  last;
	//�Ż�������
	Wingman* w_first;
	Wingman* w_last;
	float    blood;
	int      life;
	int      bull_num,wingman_num; //�����������Ż������������������Ϊ3,3��ʱΪɢ��
	int      move_status;
	int      shoot_frame;
	int      super_frame,frozen_frame,super_bull_frame;//�޵�ʱ��,����ʱ�䣬����ʱ��
	bool     super_bull;//���У������жϴ����Ƿ񷢳������з���ʱ�޷�������ͨ�ӵ�
public:
	void restart();//������״̬���ص���ʼֵ���ӵ��Ż�����գ�������Ϸ�ؿ�
	void boom(bool b);//����ʱ�ᷢ��һȦ�ӵ�,������ԭ�еĵ���������ӵ�����power������ԭ���Ż��������Ż���power

	void add_wingman(int tp);
	void erase_wingman(Wingman* p);
	void move_wingman();
	void wingman_add_bullet(int t,Wingman* p);
	void add_bullet(int t);
	void erase_bullet(Bullet* p);
	void initialize(int t);//��ʼ��״̬����������ʱ������������ӵ�
	void add_super_bull(int t);//�Ŵ���

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
	
	void bull_num_increase()                  { if(bull_num<3) bull_num++; }//�����������Ϊ3
	void life_increase()                      { life++; }
	void blood_increase()                     { if(PL_BLOOD-blood>=1) blood++;else blood = PL_BLOOD; }
	void life_decrease(int t)                 {	life--;	initialize(t);	}
	void befrozen(int t)                      { status = FROZEN; frozen_frame = t; }//����
	
	Player(float xx,float yy,float ww,float hh,float sp);
	~Player() { delete first;delete w_first; }
};

class Power :public Elements//Power�ǲ���Ʒ����������Ʒ���ܹ�8��
{
	Power* prev,*next;
public:
	Power* get_next()               { return next; }
	Power* get_prev()               { return prev; }
	void set_next(Power* p)         { next = p; }
	void set_prev(Power* p)         { prev = p; }

	Power(float xx,float yy,int tp);
};

class Explosion : public Elements//��ը�࣬���ڻ���������ʱ�Ķ���
{
	Explosion *prev,*next;
	int        frame;//֡��������Ϸ��ʱ֡���������һ��ʱ��ı�ը����
public:
	Explosion* get_next()       { return next; }
	Explosion* get_prev()       { return prev; }
	void set_next(Explosion* p) { next = p; }
	void set_prev(Explosion* p) { prev = p; }
	void set_frame(int t)       { frame = t; }
	int  get_frame()            { return frame;}
	
	Explosion(float xx,float yy,int tp);
};


