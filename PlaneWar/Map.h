#include "Elements.h"
#include "Tools.h"
#pragma once
//map�ϴ�������Ԫ�ص����ݣ����������ݺ�drawer����ϵ����ͼ
class Map 
{
	friend    class Logic;
	friend    void Tools::load();
	friend    void Tools::initialize_difficulty();
	Bullet    *b_first,*b_last; //�л����ӵ�һ�������л�һ������powerһ��������ըһ��������ҵ��ӵ�һ������(����ӵ��������������)
	Enemy     *first,*last,*boss;
	Power     *p_first,*p_last;
	Explosion *e_first,*e_last;
	Player    *player;	
	int        pass_frame,boss_dead_frame;//��������ʱ�䣬���ڲ�����һ�ص���Ļ��ʾ��boss����ʱ������������ҳ�boss�������Ʒ
	float      bg_time,bg_time_offset;//����ʱ�䣬���ڱ���ͼƬ���£�����ͼƬ���Ʋ����Ի���ʱ������Ǻ����˶�
	int        system_status,old_system_stauts;//ϵͳ״̬
	int        game_stage,score,old_score;//oldscore�ǵ�ǰ�ؿ���һ�ص��ۼƷ����������4��������ǰ3����ķ���������restartʱ��������
	int        power_num,enemy_num;//��ǰ�Ĳ���Ʒ��������������
	int        bg_order,bgm_order,volume;//������˳�򣬱������ֵ�˳������������ѡ�񱳾��ͱ�������
	float      difficulty;//�Ѷ�
	bool       replay,load;//�Ƿ��ڻطţ��Ƿ��Ƕ���
public:
	void clean();//�������Ԫ��
	void update_elements();//����״̬
	void update_status();
	void collison();//�������Ԫ��֮���Ƿ���ײ������һЩ��������
	void move();//���ܺ������ѵл��ӵ���ҵ�move��������
	void pl_drop_score();//�������ʱ����һЩ�Լ�ԭ�еķ���
	void next_stage();//boss�����������һ�ص��߼�����
	void add_bullet(Enemy* e);//��e��һ���ӵ�
	void enemy_add_bullet();//���ܺ����������еĵ��˼��ӵ�
	void move_bullet();
	void erase_bullet(Bullet* p);

	void add_power(float x,float y,int tp);
	void move_power();
	void erase_power(Power* p);

	void add_enemy(float x,float y,int tp);
	void move_enemy();
	void erase_enemy(Enemy* p);

	void add_explode(float x,float y,int tp);//��������ʱ��ը�����¼��λ����ϢȻ�󻭱�ը����
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