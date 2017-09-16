#include "Elements.h"
#include "Tools.h"
#pragma once
//map上存有所有元素的数据，用它的数据和drawer相联系来绘图
class Map 
{
	friend    class Logic;
	friend    void Tools::load();
	friend    void Tools::initialize_difficulty();
	Bullet    *b_first,*b_last; //敌机的子弹一个链表，敌机一个链表，power一个链表，爆炸一个链表，玩家的子弹一个链表(玩家子弹链表在玩家类里)
	Enemy     *first,*last,*boss;
	Power     *p_first,*p_last;
	Explosion *e_first,*e_last;
	Player    *player;	
	int        pass_frame,boss_dead_frame;//过场动画时间，用于播放下一关的字幕提示，boss死亡时间用于留给玩家吃boss掉落的物品
	float      bg_time,bg_time_offset;//背景时间，用于背景图片更新，背景图片的云彩是以基于时间的三角函数运动
	int        system_status,old_system_stauts;//系统状态
	int        game_stage,score,old_score;//oldscore是当前关卡上一关的累计分数，比如第4关它就是前3关你的分数，用于restart时保留分数
	int        power_num,enemy_num;//当前的补给品数量，敌人数量
	int        bg_order,bgm_order,volume;//背景的顺序，背景音乐的顺序，音量，用于选择背景和背景音乐
	float      difficulty;//难度
	bool       replay,load;//是否在回放，是否是读档
public:
	void clean();//清空所有元素
	void update_elements();//更新状态
	void update_status();
	void collison();//检测所有元素之间是否碰撞并进行一些消除操作
	void move();//汇总函数，把敌机子弹玩家的move函数汇总
	void pl_drop_score();//玩家死亡时掉落一些自己原有的分数
	void next_stage();//boss死亡后进入下一关的逻辑处理
	void add_bullet(Enemy* e);//给e加一发子弹
	void enemy_add_bullet();//汇总函数，给所有的敌人加子弹
	void move_bullet();
	void erase_bullet(Bullet* p);

	void add_power(float x,float y,int tp);
	void move_power();
	void erase_power(Power* p);

	void add_enemy(float x,float y,int tp);
	void move_enemy();
	void erase_enemy(Enemy* p);

	void add_explode(float x,float y,int tp);//敌人死亡时爆炸链表记录其位置信息然后画爆炸动画
	void erase_explode(Explosion* p);

	float get_bg_time()               { return bg_time; }
	float get_difficulty()            { return difficulty; }
	int   get_pass_frame()            { return pass_frame; }
	int   get_bossdead_frame()        { return boss_dead_frame; }
	int   get_system_status()         { return system_status; }
	int   get_old_system_status()     { return old_system_stauts; }  
	int   get_game_stage()            { return game_stage; }
	int   get_score()                 { return score;}
	int   get_old_score()             { return old_score; }
	int   get_power_num()             { return power_num; }
	int   get_enemy_num()             { return enemy_num; }
	int   get_bg_order()              { return bg_order; }
	int   get_bgm_order()             { return bgm_order; }
	int   get_volume()                { return volume; }
	bool  get_replay()                { return replay; }
	bool  get_load()                  { return load; }

	Bullet* get_b_first()         { return b_first; }
	Bullet* get_b_last()          { return b_last;  }
	Power*  get_p_first()         { return p_first; }
	Power*  get_p_last()          { return p_last;  }
	Explosion* get_e_first()      { return e_first; }
	Explosion* get_e_last()       { return e_last; }
	Enemy* get_first()            { return first; }
	Enemy* get_last()             { return last;  }
	Enemy* get_boss()             { return boss; }
	Player* get_player()          { return player;}

	Map();
	~Map();
};