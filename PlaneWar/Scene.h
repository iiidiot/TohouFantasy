#include "include\hgesprite.h"
#include "include\hgefont.h"
#include "include\hgeanim.h"
#include "include\hgeparticle.h"
#include "Elements.h"
#pragma once

class Scene//画游戏场景的类，存放了所有游戏元素的贴图和精灵，并提供相关操作
{
	hgeQuad	             clouds_quad;
	hgeAnimation        *pl_stay_ani,*pl_left_ani,*pl_right_ani,*super_bull_ani,
		                *pl_supstay_ani,*pl_supl_ani,*pl_supr_ani,
		                *bluemiko_stay_ani,*bluemiko_left_ani,*bluemiko_right_ani,
						*redmiko_stay_ani,*redmiko_left_ani,*redmiko_right_ani,
					    *butterfly_stay_ani,*butterfly_left_ani,*butterfly_right_ani,
						*snail_ani,*snowman_ani,*ghost_ani,
						*boss_1_stay_ani,*boss_1_left_ani,*boss_1_right_ani,
						*boss_2_stay_ani,*boss_2_left_ani,*boss_2_right_ani,
						*boss_3_stay_ani,*boss_3_left_ani,*boss_3_right_ani,
						*boss_3_supstay_ani,*boss_3_supl_ani,*boss_3_supr_ani,
						*boss_4_stay_ani,*boss_4_left_ani,*boss_4_right_ani,*boss_4_shoot_ani,
						*boss_5_stay_ani,*boss_5_left_ani,*boss_5_right_ani,*boss_5_shoot_ani,
						*boss_5_supstay_ani,*boss_5_supl_ani,*boss_5_supr_ani,*boss_5_sups_ani,
						*enemy_explode_ani;
	HTEXTURE	         pl_bull_1_tex,pl_tex,pl_blood_tex,pl_life_tex,avatar_tex,super_bull_tex,
		                 wingman_tex,wingman_bull_tex,
		                 miko_tex,snail_tex,butterfly_tex,ghost_tex,snowman_tex,
						 enemy_bulls_tex,
	                     power_life_tex,power_bull_tex,power_wingman_tex,power_blood_tex,score_tex,
						 boss_blood_tex,
						 boss_1_tex,boss_1_at_tex,
						 boss_2_tex,boss_2_at_tex,
						 boss_3_tex,boss_3_at_tex,
						 boss_4_tex,boss_4_at_tex,
						 boss_5_tex,boss_5_at_tex,
	        	         enemy_explode_tex,boss_explode_tex,
	        	         bg_tex,bg1_tex,bg2_tex;
	hgeFont	            *fnt1,*fnt2;
	hgeSprite           *pl_bull_1_spr,*pl_blood_spr,*pl_life_spr,*avatar_spr,
		                *red_wingman_spr,*red_wingman_bull_spr,
						*blue_wingman_spr,*blue_wingman_bull_spr,
	         	        *blue_miko_bull_spr,*red_miko_bull_spr,
						*snail_bull_spr,*butterfly_bull_spr,
						*snowman_bull_spr,*ghost_bull_spr,
	        	        *power_life_spr,*power_bull_spr,*power_blood_spr,*power_redwingman_spr,*power_bluewingman_spr,
						*red_score_spr,*blue_score_spr,*black_score_spr,
						*boss_blood_spr,
	                	*boss_1_bull_spr,*boss_1_at_spr,
						*boss_2_bull_spr,*boss_2_at_spr,
						*boss_3_bull_spr,*boss_3_at_spr,
						*boss_4_bull_spr,*boss_4_at_spr,
						*boss_5_bull_spr,*boss_5_at_spr,
	                	*boss_explode_spr,
		                *bg_spr,*bg1_spr,*bg2_spr;
public:
	void load();//load图片
	void set_sprite();
	void set_animition();//设置动画精灵
	void set_font();
	void set_clouds_quad_tex();//设置背景云彩的纹理，使其按时间的三角函数移动
	void update();//更新动画精灵

	//画图
	void draw();
	void draw_background();
	void draw_information();
	void draw_player();
	void draw_wingman();
	void draw_enermies();
	void draw_bullets();
	void draw_powers();
	void draw_explosion();
	void draw_font();
	void draw_volume();

	//对指针和资源进行释放
	void end_up();

	hgeSprite* get_bull_spr(Bullet* b);
	hgeAnimation* get_pl_ani(Player* p);          
	hgeAnimation* get_enemy_ani(Enemy* e);
	hgeSprite* get_bg0() { return bg_spr; };
	hgeSprite* get_bg1() { return bg1_spr; };
	hgeSprite* get_bg2() { return bg2_spr; };
	hgeFont*   get_fnt2(){ return fnt2; }
};