#include "Elements.h"
#include "Tools.h"
#include "Map.h"

extern Map map;
extern Tools tool;
//构造函数
Bullet::Bullet(float xx,float yy,int tp)
	: sita(0),power(0),next(NULL),prev(NULL)
{
	x = xx;
	y = yy;
	switch(tp) //子弹有不同的种类
	{
	case BLUE_MIKO_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = BLUE_MIKO_BULL_SPEED;
		type = BLUE_MIKO_BULLET;
		power = 1;
		break;
	case RED_MIKO_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = RED_MIKO_BULL_SPEED;
		type = RED_MIKO_BULLET;
		power = 1.5;
		break;
	case SNAIL_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = SNAIL_BULL_SPEED;
		type = SNAIL_BULLET;
		power = 3;
		break;
	case SNOWMAN_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = SNOWMAN_BULL_SPEED;
		type = SNOWMAN_BULLET;
		power = 3;
		break;
	case BUTTERFLY_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = BUTTERFLY_BULL_SPEED;
		type = BUTTERFLY_BULLET;
		power = 1;
		break;
	case GHOST_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = GHOST_BULL_SPEED;
		type = GHOST_BULLET;
		power = 2;
		break;
	case PLAYER_BULLET_1:
		w = PL_BULL_1_W;
		h = PL_BULL_1_H;
		speed = PL_BULL_SPEED;
		type = PLAYER_BULLET_1;
		power = 1;
		break;
	case SUPER_BULL:
		w = SUPER_BULL_W;
		h = SUPER_BULL_H;
		speed = 0;
		type = SUPER_BULL;
		power = 0.3;
		break;
	case BOSS_1_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = BOSS_1_BULL_SPEED;
		type = BOSS_1_BULLET;
		power = 1;
		break;
	case BOSS_2_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = BOSS_2_BULL_SPEED;
		type = BOSS_2_BULLET;
		power = 1;
		break;
	case BOSS_3_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = BOSS_3_BULL_SPEED;
		type = BOSS_3_BULLET;
		power = 1;
		break;
	case BOSS_4_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = BOSS_4_BULL_SPEED;
		type = BOSS_4_BULLET;
		power = 1;
		break;
	case BOSS_5_BULLET:
		w = ENEMY_BULL_W;
		h = ENEMY_BULL_H;
		speed = BOSS_5_BULL_SPEED;
		type = BOSS_5_BULLET;
		power = 1;
		break;
	case RED_WINGMAN_BULLET:
		w = WINGMAN_BULL_W;
		h = WINGMAN_BULL_H;
		speed = RED_WINGMAN_BULL_SPEED;
		type = RED_WINGMAN_BULLET;
		power = 0.25;
		break;
	case BLUE_WINGMAN_BULLET:
		w = WINGMAN_BULL_W;
		h = WINGMAN_BULL_H;
		speed = BLUE_WINGMAN_BULL_SPEED;
		type = BLUE_WINGMAN_BULLET;
		power = 2;
		break;
	}
	status = NORMAL;
}

Enemy::Enemy(float xx,float yy,int tp)
	: frozen(false),super(false),sita(0),move_status(STAY),move_frame(0),super_frame(0),shoot_interval(0),shoot_frame(0),frozen_frame(0),blood(0),next(NULL),prev(NULL)
{
	x = xx;
	y = yy;
	status = NORMAL;
	switch(tp) //敌机有不同种类
	{
	case BLUE_MIKO:
		type = BLUE_MIKO;
		speed = BLUE_MIKO_SPEED;
		blood = BLUE_MIKO_BLOOD;
		shoot_interval = BLUE_MIKO_SHOOT_INTERVAL;
		w = MIKO_W;
		h = MIKO_H;
		break;
	case RED_MIKO:
		type = RED_MIKO;
		speed = RED_MIKO_SPEED;
		blood = RED_MIKO_BLOOD;
		shoot_interval = RED_MIKO_SHOOT_INTERVAL;
		w = MIKO_W;
		h = MIKO_H;
		break;
	case SNAIL:
		type = SNAIL;
		speed = SNAIL_SPEED;
		blood = SNAIL_BLOOD;
		shoot_interval = SNAIL_SHOOT_INTERVAL;
		w = SNAIL_W;
		h = SNAIL_H;
		break;
	case SNOWMAN:
		type = SNOWMAN;
		speed = SNOWMAN_SPEED;
		blood = SNOWMAN_BLOOD;
		shoot_interval = SNOWMAN_SHOOT_INTERVAL;
		w = SNOWMAN_W;
		h = SNOWMAN_H;
		break;
	case BUTTERFLY:
		type = BUTTERFLY;
		speed = BUTTERFLY_SPEED;
		blood = BUTTERFLY_BLOOD;
		shoot_interval = BUTTERFLY_SHOOT_INTERVAL;
		w = BUTTERFLY_W;
		h = BUTTERFLY_H;
		break;
	case GHOST:
		type = GHOST;
		speed = GHOST_SPEED;
		blood = GHOST_BLOOD;
		shoot_interval = GHOST_SHOOT_INTERVAL;
		w = GHOST_W;
		h = GHOST_H;
		break;
	case BOSS_1:
		type = BOSS_1;
		speed = BOSS_1_SPEED;
		blood = BOSS_1_BLOOD;
		shoot_interval = BOSS_1_SHOOT_INTERVAL;
		w = BOSS_1_W;
		h = BOSS_1_H;
		break;
	case BOSS_2:
		type = BOSS_2;
		speed = BOSS_2_SPEED;
		blood = BOSS_2_BLOOD;
		shoot_interval = BOSS_2_SHOOT_INTERVAL;
		w = BOSS_2_W;
		h = BOSS_2_H;
		break;
	case BOSS_3:
		type = BOSS_3;
		speed = BOSS_3_SPEED;
		blood = BOSS_3_BLOOD;
		shoot_interval = BOSS_3_SHOOT_INTERVAL;
		w = BOSS_3_W;
		h = BOSS_3_H;
		break;
	case BOSS_4:
		type = BOSS_4;
		speed = BOSS_4_SPEED;
		blood = BOSS_4_BLOOD;
		shoot_interval = BOSS_4_SHOOT_INTERVAL;
		w = BOSS_4_W;
		h = BOSS_4_H;
		break;
	case BOSS_5:
		type = BOSS_5;
		speed = BOSS_5_SPEED;
		blood = BOSS_5_BLOOD;
		shoot_interval = BOSS_5_SHOOT_INTERVAL;
		w = BOSS_5_W;
		h = BOSS_5_H;
		break;
	}
}

Player::Player(float xx,float yy,float ww,float hh,float sp)
	: blood(PL_BLOOD),move_status(STAY),super_bull(false),
	bull_num(1),wingman_num(0),super_frame(0),frozen_frame(0),shoot_frame(0),
	life(3),super_bull_frame(0),
	first(NULL),last(new Bullet(0,0,0)),
	w_first(NULL),w_last(new Wingman(0,0,RED_WINGMAN))
{
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	speed = sp;
	first = last;
	w_first = w_last;
	status = NORMAL;
	type = PLAYER_1;
}

Wingman::Wingman(float xx,float yy,int tp)
	:shoot_frame(0),sita(0),next(NULL),prev(NULL),shoot_interval(0)
{
	float r = PL_H/2.0;
	x = xx+r*cos(sita);
	y = yy+r*sin(sita);
	switch(tp)
	{
	case RED_WINGMAN:
		type = RED_WINGMAN;
		shoot_interval = RED_WINGMAN_SHOOT_INTERVAL;
		break;
	case BLUE_WINGMAN:
		type = BLUE_WINGMAN;
		shoot_interval = BLUE_WINGMAN_SHOOT_INTERVAL;
		break;
	}
	w = WINGMAN_W;
	h = WINGMAN_H;
	status = NORMAL;
	speed = 0;
}

Power::Power(float xx,float yy,int tp)
	: next(NULL),prev(NULL)
{
	x = xx;
	y = yy;
	w = POWER_W;
	h = POWER_H;
	switch(tp)  //power有不同种类
	{
	case POWER_LIFE:
		type = POWER_LIFE;
		break;
	case POWER_BULL:
		type = POWER_BULL;
		break;
	case POWER_BLOOD:
		type = POWER_BLOOD;
		break;
	case RED_WINGMAN:
		type = RED_WINGMAN;
		break;
	case BLUE_WINGMAN:
		type = BLUE_WINGMAN;
		break;
	case RED_SCORE:
		type = RED_SCORE;
		w = SCORE_W;
		h = SCORE_H;
		break;
	case BLUE_SCORE:
		type = BLUE_SCORE;
		w = SCORE_W;
		h = SCORE_H;
		break;
	case BLACK_SOCRE:
		type = BLACK_SOCRE;
		w = SCORE_W;
		h = SCORE_H;
		break;
	}
	status = NORMAL;
	speed = POWER_SPEED;
}

Explosion::Explosion(float xx,float yy,int tp)
	: frame(0),next(NULL),prev(NULL)
{
	x = xx;
	y = yy;
	switch(tp) //爆炸根据不同的种类选择不同的爆炸图片
	{
	case BLUE_MIKO:	
		type = BLUE_MIKO;
		break;
	case RED_MIKO:
		type = RED_MIKO;
		break;
	case SNAIL:	
		type = SNAIL;
		break;
	case SNOWMAN:
		type = SNOWMAN;
		break;
	case BUTTERFLY:	
		type = BUTTERFLY;
		break;
	case GHOST:
		type = GHOST;
		break;
	case BOSS_1:
		type = BOSS_1;
		break;
	case BOSS_2:
		type = BOSS_2;
		break;
	case BOSS_3:
		type = BOSS_3;
		break;
	case BOSS_4:
		type = BOSS_4;
		break;
	case BOSS_5:
		type = BOSS_5;
		break;
	}
	speed = 0;
	status = NORMAL;
}
//沿特定角度移动特定距离
void Elements::move(float ds,float a)
{
	set_x(get_x()+ds*cos(a));
	set_y(get_y()+ds*sin(a));
}
//矩形碰撞检测
bool Elements::collision_test(Elements &a)
{
	float dx = abs(a.get_x()-get_x());
	float dy = abs(a.get_y()-get_y());
	if((dx < ((a.get_w()+get_w())/2.0)) && (dy < ((a.get_h()+get_h())/2.0)))
		return true;
	else
		return false;
}

//将玩家初始化，用于死亡时
void Player::initialize(int t)
{
	x = WIN_W/2.0;
	y = WIN_H-PL_H/2.0;
	status = SUPER;
	super_frame = t;
	type = PLAYER_1;
	bull_num = 1;
	blood = PL_BLOOD;
	frozen_frame = 0;
	shoot_frame = 0;

	Wingman* p = w_first->get_next();
	while(p)
	{
		p = p->get_prev();
		erase_wingman(p->get_next());
		p = p->get_next();
	}
}
//死亡时放大招
void Player::boom(bool b)
{
	if(wingman_num>0)
	{
		last = first;
		while(last->get_next())
			last = last->get_next();
		for(float i=0;i<2*PI;i+=PI/(4*wingman_num))
		{
			Bullet* bull = new Bullet(x,y,PLAYER_BULLET_1);
			bull->set_sita(i);
			float ran;
			if(b)
				tool.rand_fin>>ran;
			else
			{
				ran = (float)((rand()%300)/1000.0+0.2)*PL_BULL_SPEED;
				tool.rand_fout<<ran<<" ";
			}
			bull->set_speed(ran);

			last->set_next(bull);
			bull->set_prev(last);
			bull->set_next(NULL);
			last = bull;
		}
	}
	for(int i=0;i<wingman_num-1;++i)
	{
		int ran;
		if(b)
			tool.rand_fin>>ran;
		else
		{
			ran = rand()%100-50;
			tool.rand_fout<<ran<<" ";
		}
		map.add_power(x+ran,y+ran,RED_WINGMAN);
	}
	for(int i=0;i<bull_num-1;++i)
	{
		int ran;
		if(b)
			tool.rand_fin>>ran;
		else
		{
			ran = rand()%60-30;
			tool.rand_fout<<ran<<" ";
		}
		map.add_power(x+ran,y+ran,POWER_BULL);
	}
}
//根据弹道数量加子弹
void Player::add_bullet(int t)
{
	int bull_tp = 0;
	Bullet* bull = 0;

	switch(type)
	{
	case PLAYER_1:
		bull_tp = PLAYER_BULLET_1;
		break;
	}
	last = first;
	while(last->get_next())
		last = last->get_next();
	switch(bull_num) 
	{
	case 1:
		bull = new Bullet(x,y-h/2.0,bull_tp);
		bull->set_sita(-PI/2.0);
		last->set_next(bull);
		bull->set_prev(last);
		bull->set_next(NULL);
		break;
	case 2:
		for(int i=1-bull_num;i<bull_num;i+=2)
		{
			bull = new Bullet(x+i*PL_W/1.5,y-h/2.0,bull_tp);
			bull->set_sita(-PI/2.0);
			last->set_next(bull);
			bull->set_prev(last);
			bull->set_next(NULL);
			last = bull;
		}
		break;
	case 3:
		for(int i=(1-bull_num)/2;i<(bull_num+1)/2;++i)
		{
		    bull = new Bullet(x+i*PL_W/1.5,y-h/2.0,bull_tp);
			bull->set_sita(-PI/2.0+i*PI/12.0);
			last->set_next(bull);
			bull->set_prev(last);
			bull->set_next(NULL);
			last = bull;
		}
		break;
	}
	shoot_frame = t;
}
//放大招
void Player::add_super_bull(int t)
{
	last = first;
	while(last->get_next())
		last = last->get_next();
	erase_wingman(w_first->get_next());
	Bullet* bull = 0;
	for(int i=-1;i<2;i+=2)
	{
		bull = new Bullet(x+i*PL_W/1.5,y-h/2.0,SUPER_BULL);
		bull->set_sita(-PI/2.0);
		last->set_next(bull);
		bull->set_prev(last);
		bull->set_next(NULL);
		last = bull;
	}
	super_bull_frame = t;
	super_bull = true;
}

void Player::erase_bullet(Bullet* p)
{
	if(p->get_next())
	{
		p->get_prev()->set_next(p->get_next());
		p->get_next()->set_prev(p->get_prev()); 
	}
	else
		p->get_prev()->set_next(NULL);
	delete p;	
}
//加僚机
void Player::add_wingman(int tp)
{
	Wingman* wm  = 0;
	switch(wingman_num)
	{
	case 0:
	    wm = new Wingman(x,y,tp);
		w_last->set_next(wm);
		wm->set_prev(w_last);
		wm->set_next(NULL);
		w_last = wm;
		wingman_num++;
		break;
	case 1:
		wm = new Wingman(x,y,tp);
		wm->set_sita(PI);
		w_last->set_sita(0);
		w_last->set_next(wm);
		wm->set_prev(w_last);
		wm->set_next(NULL);
		w_last = wm;
		wingman_num++;
		break;
	case 2:
		wm = new Wingman(x,y,tp);
		wm->set_sita(4*PI/3.0);
		w_first->get_next()->set_sita(0);
		w_last->set_sita(2*PI/3.0);
		w_last->set_next(wm);
		wm->set_prev(w_last);
		wm->set_next(NULL);
		w_last = wm;
		wingman_num++;
		break;
	default:
		wm = new Wingman(x,y,tp);
		wm->set_sita(w_first->get_next()->get_sita());
		w_last->set_next(wm);
		wm->set_prev(w_last);
		wm->set_next(NULL);
		w_last = wm;
		erase_wingman(w_first->get_next());
		wingman_num++;
		break;
	}
}

void Player::erase_wingman(Wingman* p)
{
	if(p->get_next())
	{
		p->get_prev()->set_next(p->get_next());
		p->get_next()->set_prev(p->get_prev()); 
	}
	else
	{
		p->get_prev()->set_next(NULL);
		w_last = w_last->get_prev();
	}
	wingman_num--;
	delete p;	
}

void Player::move_wingman()
{
	Wingman* p = w_first->get_next();

	while(p)
	{
		p->set_x(x+PL_H/1.2*cos(p->get_sita()));
		p->set_y(y+PL_H/1.2*sin(p->get_sita()));
		p->increase_sita();
		p = p->get_next();
	}
}
//僚机加子弹
void Player::wingman_add_bullet(int t,Wingman* p)
{
	last = first;
	while(last->get_next())
		last = last->get_next();

	int tp = 0;
	switch(p->get_type())
	{
	case BLUE_WINGMAN:
		tp = BLUE_WINGMAN_BULLET;
		break;
	case RED_WINGMAN:
		tp = RED_WINGMAN_BULLET;
		break;
	}
	Bullet* bull = new Bullet(p->get_x(),p->get_y()-WINGMAN_H/2.0,tp);
	bull->set_next(NULL);
	bull->set_prev(last);
	last->set_next(bull);
	bull->set_sita(-PI/2.0);
	p->set_shoot_frame(t);
}

//更加深入的初始化，用于游戏重开时
void Player::restart()
{
	initialize(0);
	life = 3;

	Bullet* p = first->get_next();

	while(p)
	{	
		p = p->get_prev();
		erase_bullet(p->get_next());
		p = p->get_next();
	}
}
