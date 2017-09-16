#include "Scene.h"
#include "Map.h"
#include "Drawer.h"
#include "menuitem.h"

extern Map map;
extern Drawer drawer;

//由于玩家和敌人都至少有3种动画，所以需要即时选择来用于像素碰撞检测
hgeAnimation* Scene::get_pl_ani(Player* p)
{
	switch(p->get_move_status())
	{
	case STAY:
	case SHOOT:
		return pl_stay_ani;
	case LEFT:
		return pl_left_ani;
	case RIGHT:
		return pl_right_ani;
	}
}

hgeAnimation* Scene::get_enemy_ani(Enemy* e)
{
	switch(e->get_type())
	{
	case BLUE_MIKO:
		switch(e->get_move_status())
		{
		case STAY:
		case SHOOT:
			return bluemiko_stay_ani;
		case LEFT:
			return bluemiko_left_ani;
		case RIGHT:
			return bluemiko_right_ani;
		}
	case RED_MIKO:
		switch(e->get_move_status())
		{
		case STAY:
		case SHOOT:
			return redmiko_stay_ani;
		case LEFT:
			return redmiko_left_ani;
		case RIGHT:
			return redmiko_right_ani;
		}
	case SNAIL:
		return snail_ani;
	case SNOWMAN:
		return snowman_ani;
	case GHOST:
		return ghost_ani;
	case BUTTERFLY:
		switch(e->get_move_status())
		{
		case STAY:
		case SHOOT:
			return butterfly_stay_ani;
		case LEFT:
			return butterfly_left_ani;
		case RIGHT:
			return butterfly_right_ani;
		}
	case BOSS_1:
		switch(e->get_move_status())
		{
		case STAY:
		case SHOOT:
			return boss_1_stay_ani;
		case LEFT:
			return boss_1_left_ani;
		case RIGHT:
			return boss_1_right_ani;
		}
	case BOSS_2:
		switch(e->get_move_status())
		{
		case STAY:
		case SHOOT:
			return boss_2_stay_ani;
		case LEFT:
			return boss_2_left_ani;
		case RIGHT:
			return boss_2_right_ani;
		}
	case BOSS_3:
		switch(e->get_move_status())
		{
		case STAY:
		case SHOOT:
			return boss_3_stay_ani;
		case LEFT:
			return boss_3_left_ani;
		case RIGHT:
			return boss_3_right_ani;
		}
	case BOSS_4:
		switch(e->get_move_status())
		{
		case STAY:
			return boss_4_stay_ani;
		case LEFT:
			return boss_4_left_ani;
		case RIGHT:
			return boss_4_right_ani;
		case SHOOT:
			return boss_4_shoot_ani;
		}
	case BOSS_5:
		switch(e->get_move_status())
		{
		case STAY:
			return boss_5_stay_ani;
		case LEFT:
			return boss_5_left_ani;
		case RIGHT:
			return boss_5_right_ani;
		case SHOOT:
			return boss_5_shoot_ani;
		}
	}
}

hgeSprite* Scene::get_bull_spr(Bullet* b)
{
	switch(b->get_type())
	{
	case PLAYER_BULLET_1:
		return pl_bull_1_spr;
	case SUPER_BULL:
		return super_bull_ani;
	case RED_WINGMAN_BULLET:
		return red_wingman_bull_spr;
	case BLUE_WINGMAN_BULLET:
		return blue_wingman_bull_spr;
	case BLUE_MIKO_BULLET:
		return blue_miko_bull_spr;
	case RED_MIKO_BULLET:
		return red_miko_bull_spr;
	case SNAIL_BULLET:
		return snail_bull_spr;
	case BUTTERFLY_BULLET:
		return butterfly_bull_spr;
	case SNOWMAN_BULLET:
		return snowman_bull_spr;
	case GHOST_BULLET:
		return ghost_bull_spr;
	case BOSS_1_BULLET:
		return boss_1_bull_spr;
	case BOSS_2_BULLET:
		return boss_2_bull_spr;
	case BOSS_3_BULLET:
		return boss_3_bull_spr;
	case BOSS_4_BULLET:
		return boss_4_bull_spr;
	case BOSS_5_BULLET:
		return boss_5_bull_spr;
	}
}

//更新动画
void Scene::update()
{
	float dt = 0.02;
	super_bull_ani->Update(dt);

	pl_stay_ani->Update(dt);
	pl_left_ani->Update(dt);
	pl_right_ani->Update(dt);
	pl_supstay_ani->Update(dt);
	pl_supl_ani->Update(dt);
	pl_supr_ani->Update(dt);

	boss_1_stay_ani->Update(dt);
	boss_1_left_ani->Update(dt);
	boss_1_right_ani->Update(dt);
	
	boss_2_stay_ani->Update(dt);
	boss_2_left_ani->Update(dt);
	boss_2_right_ani->Update(dt);

	boss_3_stay_ani->Update(dt);
	boss_3_left_ani->Update(dt);
	boss_3_right_ani->Update(dt);
	boss_3_supstay_ani->Update(dt);
	boss_3_supl_ani->Update(dt);
	boss_3_supr_ani->Update(dt);

	boss_4_stay_ani->Update(dt);
	boss_4_left_ani->Update(dt);
	boss_4_right_ani->Update(dt);
	boss_4_shoot_ani->Update(dt);

	boss_5_stay_ani->Update(dt);
	boss_5_left_ani->Update(dt);
	boss_5_right_ani->Update(dt);
	boss_5_shoot_ani->Update(dt);
	boss_5_supstay_ani->Update(dt);
	boss_5_supl_ani->Update(dt);
	boss_5_supr_ani->Update(dt);
	boss_5_sups_ani->Update(dt);

	bluemiko_stay_ani->Update(dt);
	bluemiko_left_ani->Update(dt);
	bluemiko_right_ani->Update(dt);

	redmiko_stay_ani->Update(dt);
	redmiko_left_ani->Update(dt);
	redmiko_right_ani->Update(dt);

	butterfly_stay_ani->Update(dt);
	butterfly_left_ani->Update(dt);
	butterfly_right_ani->Update(dt);

	snail_ani->Update(dt);
	snowman_ani->Update(dt);
	ghost_ani->Update(dt);

	enemy_explode_ani->Update(dt);

	set_clouds_quad_tex();
}

void Scene::load()
{
	pl_tex              = drawer.get_hge()->Texture_Load("player.png");
	super_bull_tex      = drawer.get_hge()->Texture_Load("super_bull.png");
	avatar_tex          = drawer.get_hge()->Texture_Load("avatar.png");
	pl_blood_tex        = drawer.get_hge()->Texture_Load("pl_blood.png");
	pl_life_tex         = drawer.get_hge()->Texture_Load("pl_life.png");
	wingman_tex         = drawer.get_hge()->Texture_Load("wingman.png");
	wingman_bull_tex    = drawer.get_hge()->Texture_Load("wingman_bull.png");
    miko_tex            = drawer.get_hge()->Texture_Load("miko.png");
	snail_tex           = drawer.get_hge()->Texture_Load("snail.png");
	butterfly_tex       = drawer.get_hge()->Texture_Load("butterfly.png");
	snowman_tex         = drawer.get_hge()->Texture_Load("snowman.png");
	ghost_tex           = drawer.get_hge()->Texture_Load("ghost.png");
	pl_bull_1_tex       = drawer.get_hge()->Texture_Load("bullet_1.png");
	enemy_bulls_tex     = drawer.get_hge()->Texture_Load("enemy_bullets.png");
	boss_blood_tex      = drawer.get_hge()->Texture_Load("boss_blood.png");
	boss_1_at_tex       = drawer.get_hge()->Texture_Load("boss_1_at.png");
	boss_1_tex          = drawer.get_hge()->Texture_Load("boss_1.png");
	boss_2_at_tex       = drawer.get_hge()->Texture_Load("boss_2_at.png");
	boss_2_tex          = drawer.get_hge()->Texture_Load("boss_2.png");
	boss_3_at_tex       = drawer.get_hge()->Texture_Load("boss_3_at.png");
	boss_3_tex          = drawer.get_hge()->Texture_Load("boss_3.png");
	boss_4_at_tex       = drawer.get_hge()->Texture_Load("boss_4_at.png");
	boss_4_tex          = drawer.get_hge()->Texture_Load("boss_4.png");
	boss_5_at_tex       = drawer.get_hge()->Texture_Load("boss_5_at.png");
	boss_5_tex          = drawer.get_hge()->Texture_Load("boss_5.png");
	enemy_explode_tex   = drawer.get_hge()->Texture_Load("enemy_explode.png");
	boss_explode_tex    = drawer.get_hge()->Texture_Load("boss_explode.png");
	power_life_tex      = drawer.get_hge()->Texture_Load("power_life.png");
	power_bull_tex      = drawer.get_hge()->Texture_Load("power_bull.png");
	power_wingman_tex   = drawer.get_hge()->Texture_Load("power_wingman.png");
	power_blood_tex     = drawer.get_hge()->Texture_Load("power_blood.png");
	score_tex           = drawer.get_hge()->Texture_Load("score.png");
	bg_tex              = drawer.get_hge()->Texture_Load("background.png");
	bg1_tex             = drawer.get_hge()->Texture_Load("bg1.png");
	bg2_tex             = drawer.get_hge()->Texture_Load("bg2.png");
	clouds_quad.tex     = drawer.get_hge()->Texture_Load("clouds.png");

	clouds_quad.blend=BLEND_ALPHABLEND | BLEND_COLORMUL | BLEND_NOZWRITE;

	for(int i=0;i<4;i++)
	{
		// Set up z-coordinate of vertices
		clouds_quad.v[i].z=0.3f;
		// Set up color. The format of DWORD col is 0xAARRGGBB
		clouds_quad.v[i].col=0xB0FFEAD0;
	}

	clouds_quad.v[0].x=0;   clouds_quad.v[0].y=0; 
	clouds_quad.v[1].x=600; clouds_quad.v[1].y=0; 
	clouds_quad.v[2].x=600; clouds_quad.v[2].y=600; 
	clouds_quad.v[3].x=0;   clouds_quad.v[3].y=600; 
}

void Scene::set_font()
{
	fnt1     = new hgeFont("font1.fnt");
	fnt2     = new hgeFont("font2.fnt");
}

void Scene::set_sprite()
{
	pl_bull_1_spr=new hgeSprite(pl_bull_1_tex,0,0,PL_BULL_1_W,PL_BULL_1_H);
	pl_bull_1_spr->SetHotSpot(PL_BULL_1_W/2.0,PL_BULL_1_H/2.0);

	pl_blood_spr=new hgeSprite(pl_blood_tex,0,0,PL_BLOOD_W,PL_BLOOD_H);
	pl_blood_spr->SetHotSpot(PL_BLOOD_W,0);
	boss_blood_spr=new hgeSprite(boss_blood_tex,0,0,BOSS_BLOOD_W,BOSS_BLOOD_H);
	pl_life_spr =new hgeSprite(pl_life_tex,0,0,PL_LIFE_W,PL_LIFE_H);
	pl_life_spr->SetHotSpot(PL_LIFE_W/2.0,PL_LIFE_H/2.0);
	avatar_spr  =new hgeSprite(avatar_tex,0,0,AVATAR_W,AVATAR_H);
	boss_1_at_spr=new hgeSprite(boss_1_at_tex,0,0,AVATAR_W,AVATAR_H);
	boss_2_at_spr=new hgeSprite(boss_2_at_tex,0,0,AVATAR_W,AVATAR_H);
	boss_3_at_spr=new hgeSprite(boss_3_at_tex,0,0,AVATAR_W,AVATAR_H);
	boss_4_at_spr=new hgeSprite(boss_4_at_tex,0,0,AVATAR_W,AVATAR_H);
	boss_5_at_spr=new hgeSprite(boss_5_at_tex,0,0,AVATAR_W,AVATAR_H);

	blue_miko_bull_spr=new hgeSprite(enemy_bulls_tex,5*ENEMY_BULL_W,3*ENEMY_BULL_H,ENEMY_BULL_W,ENEMY_BULL_H);
	blue_miko_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	red_miko_bull_spr=new hgeSprite(enemy_bulls_tex,2*ENEMY_BULL_W,3*ENEMY_BULL_H,ENEMY_BULL_W,ENEMY_BULL_H);
	red_miko_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	snail_bull_spr=new hgeSprite(enemy_bulls_tex,15*ENEMY_BULL_W,4*ENEMY_BULL_H,ENEMY_BULL_W,ENEMY_BULL_H);
	snail_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	butterfly_bull_spr=new hgeSprite(enemy_bulls_tex,ENEMY_BULL_W,2*ENEMY_BULL_H,ENEMY_BULL_W,ENEMY_BULL_H);
    butterfly_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	snowman_bull_spr=new hgeSprite(enemy_bulls_tex,5*ENEMY_BULL_W,4*ENEMY_BULL_H,ENEMY_BULL_W,ENEMY_BULL_H);
	snowman_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	ghost_bull_spr=new hgeSprite(enemy_bulls_tex,15*ENEMY_BULL_W,2*ENEMY_BULL_H,ENEMY_BULL_W,ENEMY_BULL_H);
	ghost_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	blue_wingman_spr=new hgeSprite(wingman_tex,0,0,WINGMAN_W,WINGMAN_H);
	blue_wingman_spr->SetColor(0xB0FFFFFF);
	blue_wingman_spr->SetHotSpot(WINGMAN_W/2.0,WINGMAN_H/2.0);

	red_wingman_spr=new hgeSprite(wingman_tex,WINGMAN_W,0,WINGMAN_W,WINGMAN_H);
	red_wingman_spr->SetColor(0xB0FFFFFF);
	red_wingman_spr->SetHotSpot(WINGMAN_W/2.0,WINGMAN_H/2.0);

	blue_wingman_bull_spr=new hgeSprite(wingman_bull_tex,WINGMAN_BULL_W,0,WINGMAN_BULL_W,WINGMAN_BULL_H);
	blue_wingman_bull_spr->SetHotSpot(WINGMAN_BULL_W/2.0,WINGMAN_BULL_H/2.0);

	red_wingman_bull_spr=new hgeSprite(wingman_bull_tex,0,0,WINGMAN_BULL_W,WINGMAN_BULL_H);
	red_wingman_bull_spr->SetHotSpot(WINGMAN_BULL_W/2.0,WINGMAN_BULL_H/2.0);

	power_life_spr=new hgeSprite(power_life_tex,0,0,POWER_W,POWER_H);
	power_life_spr->SetColor(0xFF00FF00);
	power_life_spr->SetHotSpot(POWER_W/2.0,POWER_H/2.0);

	power_bull_spr=new hgeSprite(power_bull_tex,0,0,POWER_W,POWER_H);
	power_bull_spr->SetColor(0xFF0000FF);
	power_bull_spr->SetHotSpot(POWER_W/2.0,POWER_H/2.0);
	power_bull_spr=new hgeSprite(power_bull_tex,0,0,POWER_W,POWER_H);
	power_bull_spr->SetColor(0xFF0000FF);
	power_bull_spr->SetHotSpot(POWER_W/2.0,POWER_H/2.0);

	power_blood_spr=new hgeSprite(power_blood_tex,0,0,POWER_W,POWER_H);
	power_blood_spr->SetHotSpot(POWER_W/2.0,POWER_H/2.0);

	power_redwingman_spr=new hgeSprite(power_wingman_tex,POWER_W,0,POWER_W,POWER_H);
	power_redwingman_spr->SetHotSpot(POWER_W/2.0,POWER_H/2.0);
	
	power_bluewingman_spr=new hgeSprite(power_wingman_tex,3*POWER_W,0,POWER_W,POWER_H);
	power_bluewingman_spr->SetHotSpot(POWER_W/2.0,POWER_H/2.0);

	red_score_spr=new hgeSprite(score_tex,0,0,SCORE_W,SCORE_H);
	red_score_spr->SetHotSpot(SCORE_W/2.0,SCORE_H/2.0);

	blue_score_spr=new hgeSprite(score_tex,SCORE_W,0,SCORE_W,SCORE_H);
	blue_score_spr->SetHotSpot(SCORE_W/2.0,SCORE_H/2.0);

	black_score_spr=new hgeSprite(score_tex,2*SCORE_W,0,SCORE_W,SCORE_H);
	black_score_spr->SetHotSpot(SCORE_W/2.0,SCORE_H/2.0);

	boss_1_bull_spr=new hgeSprite(enemy_bulls_tex,14*ENEMY_BULL_W,0,ENEMY_BULL_W,ENEMY_BULL_H);
	boss_1_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	boss_2_bull_spr=new hgeSprite(enemy_bulls_tex,9*ENEMY_BULL_W,0,ENEMY_BULL_W,ENEMY_BULL_H);
	boss_2_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	boss_3_bull_spr=new hgeSprite(enemy_bulls_tex,5*ENEMY_BULL_W,0,ENEMY_BULL_W,ENEMY_BULL_H);
	boss_3_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	boss_4_bull_spr=new hgeSprite(enemy_bulls_tex,4*ENEMY_BULL_W,0,ENEMY_BULL_W,ENEMY_BULL_H);
	boss_4_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	boss_5_bull_spr=new hgeSprite(enemy_bulls_tex,0,0,ENEMY_BULL_W,ENEMY_BULL_H);
	boss_5_bull_spr->SetHotSpot(ENEMY_BULL_W/2.0,ENEMY_BULL_H/2.0);

	boss_explode_spr=new hgeSprite(boss_explode_tex,0,0,EXPLODE_BOSS_W,EXPLODE_BOSS_H);
	boss_explode_spr->SetHotSpot(EXPLODE_BOSS_W/2.0,EXPLODE_BOSS_H/2.0);

	bg_spr=new hgeSprite(bg_tex,0,0,BG_W,BG_H);
	bg1_spr=new hgeSprite(bg1_tex,0,0,BG_W,BG_H);
	bg2_spr=new hgeSprite(bg2_tex,0,0,BG_W,BG_H);
}

void Scene::set_animition()
{
	super_bull_ani = new hgeAnimation(super_bull_tex,4,12,0,0,SUPER_BULL_W,SUPER_BULL_H);
	super_bull_ani->SetHotSpot(SUPER_BULL_W/2.0,SUPER_BULL_H);
	super_bull_ani->Play();

	pl_stay_ani = new hgeAnimation(pl_tex, 8, 10, 0, 0, PL_W, PL_H);  
	pl_stay_ani->SetHotSpot(PL_W/2.0,PL_H/2.0);  
	pl_stay_ani->Play();
	pl_left_ani = new hgeAnimation(pl_tex, 5, 10, 3*PL_W, PL_H, PL_W, PL_H);  
	pl_left_ani->SetHotSpot(PL_W/2.0,PL_H/2.0);  
	pl_left_ani->Play();
	pl_right_ani = new hgeAnimation(pl_tex, 5, 10, 3*PL_W, 2*PL_H, PL_W, PL_H);  
	pl_right_ani->SetHotSpot(PL_W/2.0,PL_H/2.0);  
	pl_right_ani->Play();
	
	pl_supstay_ani = new hgeAnimation(pl_tex, 8, 16, 0, 3*PL_H, PL_W, PL_H);  
	pl_supstay_ani->SetHotSpot(PL_W/2.0,PL_H/2.0);  
	pl_supstay_ani->Play();
	pl_supl_ani = new hgeAnimation(pl_tex, 5, 10, 3*PL_W, 4*PL_H, PL_W, PL_H);  
	pl_supl_ani->SetHotSpot(PL_W/2.0,PL_H/2.0);  
	pl_supl_ani->Play();
	pl_supr_ani = new hgeAnimation(pl_tex, 5, 10, 3*PL_W, 5*PL_H, PL_W, PL_H);  
	pl_supr_ani->SetHotSpot(PL_W/2.0,PL_H/2.0);  
	pl_supr_ani->Play();

	bluemiko_stay_ani = new hgeAnimation(miko_tex,5,12,0,0,MIKO_W,MIKO_H);  
	bluemiko_stay_ani->SetHotSpot(MIKO_W/2.0,MIKO_H/2.0);  
	bluemiko_stay_ani->Play();
	bluemiko_left_ani = new hgeAnimation(miko_tex,4,10,9*MIKO_W,0,MIKO_W,MIKO_H);  
	bluemiko_left_ani->SetHotSpot(MIKO_W/2.0,MIKO_H/2.0);  
	bluemiko_left_ani->Play();
	bluemiko_right_ani = new hgeAnimation(miko_tex,4,10,5*MIKO_W,0,MIKO_W,MIKO_H);  
	bluemiko_right_ani->SetHotSpot(MIKO_W/2.0,MIKO_H/2.0);  
	bluemiko_right_ani->Play();

	redmiko_stay_ani = new hgeAnimation(miko_tex,5,12,0,MIKO_H,MIKO_W,MIKO_H);  
	redmiko_stay_ani->SetHotSpot(MIKO_W/2.0,MIKO_H/2.0);  
	redmiko_stay_ani->Play();
	redmiko_left_ani = new hgeAnimation(miko_tex,4,10,9*MIKO_W,MIKO_H,MIKO_W,MIKO_H);  
	redmiko_left_ani->SetHotSpot(MIKO_W/2.0,MIKO_H/2.0);  
	redmiko_left_ani->Play();
	redmiko_right_ani = new hgeAnimation(miko_tex,4,10,5*MIKO_W,MIKO_H,MIKO_W,MIKO_H);  
	redmiko_right_ani->SetHotSpot(MIKO_W/2.0,MIKO_H/2.0);  
	redmiko_right_ani->Play();

	butterfly_stay_ani = new hgeAnimation(butterfly_tex,5,12,0,0,BUTTERFLY_W,BUTTERFLY_H);  
	butterfly_stay_ani->SetHotSpot(BUTTERFLY_W/2.0,BUTTERFLY_H/2.0);  
	butterfly_stay_ani->Play();
	butterfly_left_ani = new hgeAnimation(butterfly_tex,2,5,7*BUTTERFLY_W,0,BUTTERFLY_W,BUTTERFLY_H);  
	butterfly_left_ani->SetHotSpot(BUTTERFLY_W/2.0,BUTTERFLY_H/2.0);  
	butterfly_left_ani->Play();
	butterfly_right_ani = new hgeAnimation(butterfly_tex,2,5,5*BUTTERFLY_W,0,BUTTERFLY_W,BUTTERFLY_H);  
	butterfly_right_ani->SetHotSpot(BUTTERFLY_W/2.0,BUTTERFLY_H/2.0);  
	butterfly_right_ani->Play();

	snail_ani = new hgeAnimation(snail_tex,4,4,0,0,SNAIL_W,SNAIL_H);  
	snail_ani->SetHotSpot(SNAIL_W/2.0,SNAIL_H/2.0);  
	snail_ani->Play();

	snowman_ani = new hgeAnimation(snowman_tex,4,10,0,0,SNOWMAN_W,SNOWMAN_H);  
	snowman_ani->SetHotSpot(SNOWMAN_W/2.0,SNOWMAN_H/2.0);  
	snowman_ani->Play();

	ghost_ani = new hgeAnimation(ghost_tex,4,10,0,0,GHOST_W,GHOST_H);  
	ghost_ani->SetHotSpot(GHOST_W/2.0,GHOST_H/2.0);  
	ghost_ani->Play();

	boss_1_stay_ani = new hgeAnimation(boss_1_tex,4,6,0,0,BOSS_1_W,BOSS_1_H);
	boss_1_stay_ani->SetHotSpot(BOSS_1_W/2.0,BOSS_1_H/2.0);  
	boss_1_stay_ani->Play();
	boss_1_left_ani = new hgeAnimation(boss_1_tex,1,1,3*BOSS_1_W,2*BOSS_1_H,BOSS_1_W,BOSS_1_H);
	boss_1_left_ani->SetHotSpot(BOSS_1_W/2.0,BOSS_1_H/2.0);  
	boss_1_left_ani->Play();
	boss_1_right_ani = new hgeAnimation(boss_1_tex,1,1,3*BOSS_1_W,BOSS_1_H,BOSS_1_W,BOSS_1_H);
	boss_1_right_ani->SetHotSpot(BOSS_1_W/2.0,BOSS_1_H/2.0);  
	boss_1_right_ani->Play();

	boss_2_stay_ani = new hgeAnimation(boss_2_tex,4,10,0,0,BOSS_2_W,BOSS_2_H);
	boss_2_stay_ani->SetHotSpot(BOSS_2_W/2.0,BOSS_2_H/2.0);  
	boss_2_stay_ani->Play();
	boss_2_right_ani = new hgeAnimation(boss_2_tex,8,24,0,BOSS_2_H,BOSS_2_W,BOSS_2_H);
	boss_2_right_ani->SetHotSpot(BOSS_2_W/2.0,BOSS_2_H/2.0);  
	boss_2_right_ani->Play();
	boss_2_left_ani = new hgeAnimation(boss_2_tex,8,24,0,3*BOSS_2_H,BOSS_2_W,BOSS_2_H);
	boss_2_left_ani->SetHotSpot(BOSS_2_W/2.0,BOSS_2_H/2.0);  
	boss_2_left_ani->Play();

	boss_3_stay_ani = new hgeAnimation(boss_3_tex,4,10,0,0,BOSS_3_W,BOSS_3_H);
	boss_3_stay_ani->SetHotSpot(BOSS_3_W/2.0,BOSS_3_H/2.0);  
	boss_3_stay_ani->Play();
	boss_3_right_ani = new hgeAnimation(boss_3_tex,2,6,2*BOSS_3_W,BOSS_3_H,BOSS_3_W,BOSS_3_H);
	boss_3_right_ani->SetHotSpot(BOSS_3_W/2.0,BOSS_3_H/2.0);  
	boss_3_right_ani->Play();
	boss_3_left_ani = new hgeAnimation(boss_3_tex,2,6,2*BOSS_3_W,4*BOSS_3_H,BOSS_3_W,BOSS_3_H);
	boss_3_left_ani->SetHotSpot(BOSS_3_W/2.0,BOSS_3_H/2.0);  
	boss_3_left_ani->Play();
	boss_3_supstay_ani = new hgeAnimation(boss_3_tex,4,10,0,2*BOSS_3_H,BOSS_3_W,BOSS_3_H);
	boss_3_supstay_ani->SetHotSpot(BOSS_3_W/2.0,BOSS_3_H/2.0);  
	boss_3_supstay_ani->Play();
	boss_3_supr_ani = new hgeAnimation(boss_3_tex,2,6,2*BOSS_3_W,3*BOSS_3_H,BOSS_3_W,BOSS_3_H);
	boss_3_supr_ani->SetHotSpot(BOSS_3_W/2.0,BOSS_3_H/2.0);  
	boss_3_supr_ani->Play();
	boss_3_supl_ani = new hgeAnimation(boss_3_tex,2,6,2*BOSS_3_W,5*BOSS_3_H,BOSS_3_W,BOSS_3_H);
	boss_3_supl_ani->SetHotSpot(BOSS_3_W/2.0,BOSS_3_H/2.0);  
	boss_3_supl_ani->Play();

	boss_4_stay_ani = new hgeAnimation(boss_4_tex,4,10,0,0,BOSS_4_W,BOSS_4_H);
	boss_4_stay_ani->SetHotSpot(BOSS_4_W/2.0,BOSS_4_H/2.0);  
	boss_4_stay_ani->Play();
	boss_4_right_ani = new hgeAnimation(boss_4_tex,2,6,2*BOSS_4_W,3*BOSS_4_H,BOSS_4_W,BOSS_4_H);
	boss_4_right_ani->SetHotSpot(BOSS_4_W/2.0,BOSS_4_H/2.0);  
	boss_4_right_ani->Play();
	boss_4_left_ani = new hgeAnimation(boss_4_tex,2,6,2*BOSS_4_W,BOSS_4_H,BOSS_4_W,BOSS_4_H);
	boss_4_left_ani->SetHotSpot(BOSS_4_W/2.0,BOSS_4_H/2.0);  
	boss_4_left_ani->Play();
	boss_4_shoot_ani = new hgeAnimation(boss_4_tex,4,16,0,2*BOSS_4_H,BOSS_4_W,BOSS_4_H);
	boss_4_shoot_ani->SetHotSpot(BOSS_4_W/2.0,BOSS_4_H/2.0);  
	boss_4_shoot_ani->Play();

	boss_5_stay_ani = new hgeAnimation(boss_5_tex,4,10,0,0,BOSS_5_W,BOSS_5_H);
	boss_5_stay_ani->SetHotSpot(BOSS_5_W/2.0,BOSS_5_H/2.0);  
	boss_5_stay_ani->Play();
	boss_5_right_ani = new hgeAnimation(boss_5_tex,2,6,2*BOSS_5_W,BOSS_5_H,BOSS_5_W,BOSS_5_H);
	boss_5_right_ani->SetHotSpot(BOSS_5_W/2.0,BOSS_5_H/2.0);  
	boss_5_right_ani->Play();
	boss_5_left_ani = new hgeAnimation(boss_5_tex,2,6,0,BOSS_5_H,BOSS_5_W,BOSS_5_H);
	boss_5_left_ani->SetHotSpot(BOSS_5_W/2.0,BOSS_5_H/2.0);  
	boss_5_left_ani->Play();
	boss_5_shoot_ani = new hgeAnimation(boss_5_tex,8,8,0,2*BOSS_5_H,BOSS_5_W,BOSS_5_H);
	boss_5_shoot_ani->SetHotSpot(BOSS_5_W/2.0,BOSS_5_H/2.0);  
	boss_5_shoot_ani->Play();
	boss_5_supstay_ani = new hgeAnimation(boss_5_tex,4,10,0,4*BOSS_5_H,BOSS_5_W,BOSS_5_H);
	boss_5_supstay_ani->SetHotSpot(BOSS_5_W/2.0,BOSS_5_H/2.0);  
	boss_5_supstay_ani->Play();
	boss_5_supr_ani = new hgeAnimation(boss_5_tex,2,6,2*BOSS_5_W,5*BOSS_5_H,BOSS_5_W,BOSS_5_H);
	boss_5_supr_ani->SetHotSpot(BOSS_5_W/2.0,BOSS_5_H/2.0);  
	boss_5_supr_ani->Play();
	boss_5_supl_ani = new hgeAnimation(boss_5_tex,2,6,0,5*BOSS_5_H,BOSS_5_W,BOSS_5_H);
	boss_5_supl_ani->SetHotSpot(BOSS_5_W/2.0,BOSS_5_H/2.0);  
	boss_5_supl_ani->Play();
	boss_5_sups_ani = new hgeAnimation(boss_5_tex,8,8,0,6*BOSS_5_H,BOSS_5_W,BOSS_5_H);
	boss_5_sups_ani->SetHotSpot(BOSS_5_W/2.0,BOSS_5_H/2.0);  
	boss_5_sups_ani->Play();

	enemy_explode_ani = new hgeAnimation(enemy_explode_tex,8,32,0,0,EXPLODE_ENEMY_W,EXPLODE_ENEMY_H);
	enemy_explode_ani->SetHotSpot(EXPLODE_ENEMY_W/2.0,EXPLODE_ENEMY_H/2.0);
	enemy_explode_ani->Play();
}
//设置云彩
void Scene::set_clouds_quad_tex()
{
	float t = map.get_bg_time();
	float tx=cosf(t/60);
	float ty=sinf(t/60);

	clouds_quad.v[0].tx=tx;         clouds_quad.v[0].ty=ty;
	clouds_quad.v[1].tx=tx+1; clouds_quad.v[1].ty=ty;
	clouds_quad.v[2].tx=tx+1; clouds_quad.v[2].ty=ty+1;
	clouds_quad.v[3].tx=tx;         clouds_quad.v[3].ty=ty+1;
}

void Scene::draw_background()
{
	switch(map.get_bg_order())
	{
	case 0:
		bg_spr->Render(0,0);
		break;
	case 1:
		bg1_spr->Render(0,0);
		break;
	case 2:
		bg2_spr->Render(0,0);
		break;
	}
}

void Scene::draw_information()
{
	pl_blood_spr->RenderEx(WIN_W-AVATAR_W-0.5,WIN_H-AVATAR_H+15,0,map.get_player()->get_blood()/PL_BLOOD,1);
	avatar_spr->Render(WIN_W-AVATAR_W,WIN_H-AVATAR_H);
	for(int i=0;i<map.get_player()->get_life();i++)
	{
		pl_life_spr->RenderEx(WIN_W-AVATAR_W-1-PL_LIFE_W/2.0-i*1.2*PL_LIFE_W,WIN_H-PL_LIFE_H,0.3,1);
	}
	if(map.get_boss())
	{
		float blood = 0;
		switch(map.get_boss()->get_type())
		{
		case BOSS_1:
			boss_blood_spr->RenderEx(AVATAR_W,BOSS_BLOOD_H,0,map.get_boss()->get_blood()/BOSS_1_BLOOD,1);
			boss_1_at_spr->Render(0,0);
			break;
		case BOSS_2:
			boss_blood_spr->RenderEx(AVATAR_W,BOSS_BLOOD_H,0,map.get_boss()->get_blood()/BOSS_2_BLOOD,1);
			boss_2_at_spr->Render(0,0);
			break;
		case BOSS_3:
			boss_blood_spr->RenderEx(AVATAR_W,BOSS_BLOOD_H,0,map.get_boss()->get_blood()/BOSS_3_BLOOD,1);
			boss_3_at_spr->Render(0,0);
			break;
		case BOSS_4:
			boss_blood_spr->RenderEx(AVATAR_W,BOSS_BLOOD_H,0,map.get_boss()->get_blood()/BOSS_4_BLOOD,1);
			boss_4_at_spr->Render(0,0);
			break;
		case BOSS_5:
			boss_blood_spr->RenderEx(AVATAR_W,BOSS_BLOOD_H,0,map.get_boss()->get_blood()/BOSS_5_BLOOD,1);
			boss_5_at_spr->Render(0,0);
			break;
		}
	}
}

void Scene::draw_player()
{
	int move_status = map.get_player()->get_move_status();
	int status = map.get_player()->get_status();
	switch(move_status)
	{
	case STAY:
	case SHOOT:
		switch(status)
		{
		case SUPER:
			pl_supstay_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		case FROZEN:
			pl_stay_ani->SetColor(0xFF0000FF);
			pl_stay_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		default:
			pl_stay_ani->SetColor(0xFFFFFFFF);
			pl_stay_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		}
		break;
	case LEFT:
		switch(status)
		{
		case SUPER:
			pl_supl_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		case FROZEN:
			pl_left_ani->SetColor(0xFF0000FF);
			pl_left_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		default:
			pl_left_ani->SetColor(0xFFFFFFFF);
			pl_left_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		}
		break;
	case RIGHT:
		switch(status)
		{
		case SUPER:
			pl_supr_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		case FROZEN:
			pl_right_ani->SetColor(0xFF0000FF);
			pl_right_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		default:
			pl_right_ani->SetColor(0xFFFFFFFF);
			pl_right_ani->Render(map.get_player()->get_x(), map.get_player()->get_y());
			break;
		}
		break;
	}
}

void Scene::draw_wingman()
{
	Wingman* p = map.get_player()->get_w_first()->get_next();
	while(p)
	{
		switch(p->get_type())
		{
		case RED_WINGMAN:
			red_wingman_spr->RenderEx(p->get_x(),p->get_y(),7*p->get_sita());
			break;
		case BLUE_WINGMAN:
			blue_wingman_spr->RenderEx(p->get_x(),p->get_y(),7*p->get_sita());
			break;
		}
		p = p->get_next();
	}
}

void Scene::draw_enermies()
{
	Enemy* enmy_tmp = map.get_first()->get_next();

	while(enmy_tmp)
	{
		switch(enmy_tmp->get_type())
		{
		case BLUE_MIKO:
			if(enmy_tmp->is_frozen())
			{
				bluemiko_stay_ani->SetColor(0xFF0000FF);
				bluemiko_left_ani->SetColor(0xFF0000FF);
				bluemiko_right_ani->SetColor(0xFF0000FF);
			}
			else
			{
				bluemiko_stay_ani->SetColor(0xFFFFFFFF);
				bluemiko_left_ani->SetColor(0xFFFFFFFF);
				bluemiko_right_ani->SetColor(0xFFFFFFFF);
			}
			switch(enmy_tmp->get_move_status())
			{
			case STAY:
			case SHOOT:
				bluemiko_stay_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			case LEFT:
				bluemiko_left_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			case RIGHT:
				bluemiko_right_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			}
			break;
		case RED_MIKO:
			if(enmy_tmp->is_frozen())
			{
				redmiko_stay_ani->SetColor(0xFF0000FF);
				redmiko_left_ani->SetColor(0xFF0000FF);
				redmiko_right_ani->SetColor(0xFF0000FF);
			}
			else
			{
				redmiko_stay_ani->SetColor(0xFFFFFFFF);
				redmiko_left_ani->SetColor(0xFFFFFFFF);
				redmiko_right_ani->SetColor(0xFFFFFFFF);
			}
			switch(enmy_tmp->get_move_status())
			{
			case STAY:
			case SHOOT:
				redmiko_stay_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			case LEFT:
				redmiko_left_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			case RIGHT:
				redmiko_right_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			}
			break;
		case SNAIL:
			if(enmy_tmp->is_frozen())
				snail_ani->SetColor(0xFF0000FF);
			else
				snail_ani->SetColor(0xFFFFFFFF);

			snail_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
			break;
		case SNOWMAN:
			if(enmy_tmp->is_frozen())
				snowman_ani->SetColor(0xFF0000FF);
			else
				snowman_ani->SetColor(0xFFFFFFFF);

			snowman_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
			break;
		case GHOST:
			if(enmy_tmp->is_frozen())
				ghost_ani->SetColor(0xFF0000FF);
			else
				ghost_ani->SetColor(0xFFFFFFFF);

			ghost_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
			break;
		case BUTTERFLY:
			if(enmy_tmp->is_frozen())
			{
				butterfly_stay_ani->SetColor(0xFF0000FF);
				butterfly_right_ani->SetColor(0xFF0000FF);
				butterfly_left_ani->SetColor(0xFF0000FF);
			}
			else
			{
				butterfly_stay_ani->SetColor(0xFFFFFFFF);
				butterfly_right_ani->SetColor(0xFFFFFFFF);
				butterfly_left_ani->SetColor(0xFFFFFFFF);
			}
			switch(enmy_tmp->get_move_status())
			{
			case STAY:
			case SHOOT:
				butterfly_stay_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			case LEFT:
				butterfly_left_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			case RIGHT:
				butterfly_right_ani->Render(enmy_tmp->get_x(),enmy_tmp->get_y());
				break;
			}
			break;
		case BOSS_1:
			if(enmy_tmp->is_frozen())
			{
				boss_1_stay_ani->SetColor(0xFF0000FF);
				boss_1_left_ani->SetColor(0xFF0000FF);
				boss_1_right_ani->SetColor(0xFF0000FF);
			}
			else
			{
				boss_1_stay_ani->SetColor(0xFFFFFFFF);
				boss_1_left_ani->SetColor(0xFFFFFFFF);
				boss_1_right_ani->SetColor(0xFFFFFFFF);
			}
			switch(enmy_tmp->get_move_status())
			{
			case STAY:
			case SHOOT:
				boss_1_stay_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case LEFT:
				boss_1_left_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case RIGHT:
				boss_1_right_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			}
			break;
		case BOSS_2:
			if(enmy_tmp->is_frozen())
			{
				boss_2_stay_ani->SetColor(0xFF0000FF);
				boss_2_left_ani->SetColor(0xFF0000FF);
				boss_2_right_ani->SetColor(0xFF0000FF);
			}
			else
			{
				boss_2_stay_ani->SetColor(0xFFFFFFFF);
				boss_2_left_ani->SetColor(0xFFFFFFFF);
				boss_2_right_ani->SetColor(0xFFFFFFFF);
			}
			switch(enmy_tmp->get_move_status())
			{
			case STAY:
			case SHOOT:
				boss_2_stay_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case LEFT:
				boss_2_left_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case RIGHT:
				boss_2_right_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			}
			break;
		case BOSS_3:
			if(enmy_tmp->is_frozen())
			{
				boss_3_stay_ani->SetColor(0xFF0000FF);
				boss_3_left_ani->SetColor(0xFF0000FF);
				boss_3_right_ani->SetColor(0xFF0000FF);
			}
			else
			{
				boss_3_stay_ani->SetColor(0xFFFFFFFF);
				boss_3_left_ani->SetColor(0xFFFFFFFF);
				boss_3_right_ani->SetColor(0xFFFFFFFF);
			}
			switch(enmy_tmp->get_move_status())
			{
			case STAY:
			case SHOOT:
				if(enmy_tmp->is_super())
					boss_3_supstay_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				else
					boss_3_stay_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case LEFT:
				if(enmy_tmp->is_super())
					boss_3_supl_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				else
					boss_3_left_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case RIGHT:
				if(enmy_tmp->is_super())
					boss_3_supr_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				else
					boss_3_right_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			}
			break;
		case BOSS_4:
			if(enmy_tmp->is_frozen())
			{
				boss_4_stay_ani->SetColor(0xFF0000FF);
				boss_4_shoot_ani->SetColor(0xFF0000FF);
				boss_4_left_ani->SetColor(0xFF0000FF);
				boss_4_right_ani->SetColor(0xFF0000FF);
			}
			else
			{
				boss_4_stay_ani->SetColor(0xFFFFFFFF);
				boss_4_shoot_ani->SetColor(0xFFFFFFFF);
				boss_4_left_ani->SetColor(0xFFFFFFFF);
				boss_4_right_ani->SetColor(0xFFFFFFFF);
			}
			switch(enmy_tmp->get_move_status())
			{
			case STAY:
				boss_4_stay_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case SHOOT:
				boss_4_shoot_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case LEFT:
				boss_4_left_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case RIGHT:
				boss_4_right_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			}
			break;
		case BOSS_5:
			if(enmy_tmp->is_frozen())
			{
				boss_5_stay_ani->SetColor(0xFF0000FF);
				boss_5_shoot_ani->SetColor(0xFF0000FF);
				boss_5_left_ani->SetColor(0xFF0000FF);
				boss_5_right_ani->SetColor(0xFF0000FF);
			}
			else
			{
				boss_5_stay_ani->SetColor(0xFFFFFFFF);
				boss_5_shoot_ani->SetColor(0xFFFFFFFF);
				boss_5_left_ani->SetColor(0xFFFFFFFF);
				boss_5_right_ani->SetColor(0xFFFFFFFF);
			}
			switch(enmy_tmp->get_move_status())
			{
			case STAY:
				if(enmy_tmp->is_super())
					boss_5_supstay_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				else
					boss_5_stay_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case SHOOT:
				if(enmy_tmp->is_super())
					boss_5_sups_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				else
					boss_5_shoot_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case LEFT:
				if(enmy_tmp->is_super())
					boss_5_supl_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				else
					boss_5_left_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			case RIGHT:
				if(enmy_tmp->is_super())
					boss_5_supr_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				else
					boss_5_right_ani->Render(map.get_boss()->get_x(), map.get_boss()->get_y());
				break;
			}
			break;
		}	
		enmy_tmp = enmy_tmp->get_next();
	}
}

void Scene::draw_bullets()
{
	Bullet* p = map.get_player()->get_first()->get_next();
	//player bullets
	while(p)
	{
		switch(p->get_type())
		{
		case RED_WINGMAN_BULLET:
			red_wingman_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case BLUE_WINGMAN_BULLET:
			blue_wingman_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case PLAYER_BULLET_1:
			pl_bull_1_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case SUPER_BULL:
			super_bull_ani->Render(p->get_x(),p->get_y());
			break;
		}
		p = p->get_next();
	}

	p = map.get_b_first()->get_next();
	//enemy bullets
	while(p)
	{
		switch(p->get_type())
		{
		case BLUE_MIKO_BULLET:
			blue_miko_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case RED_MIKO_BULLET:
			red_miko_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case SNAIL_BULLET:
			snail_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case BUTTERFLY_BULLET:
			butterfly_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case SNOWMAN_BULLET:
			snowman_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case GHOST_BULLET:
			ghost_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case BOSS_1_BULLET:
			boss_1_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case BOSS_2_BULLET:
			boss_2_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case BOSS_3_BULLET:
			boss_3_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case BOSS_4_BULLET:
			boss_4_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		case BOSS_5_BULLET:
			boss_5_bull_spr->RenderEx(p->get_x(),p->get_y(),p->get_sita()+PI/2.0);
			break;
		}
		p = p->get_next();
	}
}

void Scene::draw_powers()
{
	Power* power_tmp = map.get_p_first()->get_next();

	while(power_tmp)
	{
		switch(power_tmp->get_type())
		{
		case POWER_LIFE:
			power_life_spr->Render(power_tmp->get_x(),power_tmp->get_y());
			break;
		case POWER_BULL:
			power_bull_spr->Render(power_tmp->get_x(),power_tmp->get_y());
			break;
		case POWER_BLOOD:
			power_blood_spr->Render(power_tmp->get_x(),power_tmp->get_y());
			break;
		case RED_WINGMAN:
			power_redwingman_spr->Render(power_tmp->get_x(),power_tmp->get_y());
			break;
		case BLUE_WINGMAN:
			power_bluewingman_spr->Render(power_tmp->get_x(),power_tmp->get_y());
			break;
		case RED_SCORE:
			red_score_spr->Render(power_tmp->get_x(),power_tmp->get_y());
			break;
		case BLUE_SCORE:
			blue_score_spr->Render(power_tmp->get_x(),power_tmp->get_y());
			break;
		case BLACK_SOCRE:
			black_score_spr->Render(power_tmp->get_x(),power_tmp->get_y());
			break;
		}
		power_tmp = power_tmp->get_next();
	}
}

void Scene::draw_explosion()
{
	Explosion* exp_tmp = map.get_e_first()->get_next();
	int frame_num = drawer.get_logic()->get_frame_num();

	while(exp_tmp)
	{
		if(frame_num-exp_tmp->get_frame()<30) //爆炸效果持续0.6秒
		{
			switch(exp_tmp->get_type())
			{
			case BLUE_MIKO:
				enemy_explode_ani->SetColor(0xFF000020);
				enemy_explode_ani->Render(exp_tmp->get_x(),exp_tmp->get_y());
				break;
			case RED_MIKO:
				enemy_explode_ani->SetColor(0xFFFF0000);
				enemy_explode_ani->Render(exp_tmp->get_x(),exp_tmp->get_y());
				break;
			case SNAIL:
				enemy_explode_ani->SetColor(0xFFAABB88);
				enemy_explode_ani->Render(exp_tmp->get_x(),exp_tmp->get_y());
				break;
			case SNOWMAN:
				enemy_explode_ani->SetColor(0xFFAAAAFF);
				enemy_explode_ani->Render(exp_tmp->get_x(),exp_tmp->get_y());
				break;
			case BUTTERFLY:
				enemy_explode_ani->SetColor(0xFFAABBCC);
				enemy_explode_ani->Render(exp_tmp->get_x(),exp_tmp->get_y());
				break;
			case GHOST:
				enemy_explode_ani->SetColor(0xFF000000);
				enemy_explode_ani->Render(exp_tmp->get_x(),exp_tmp->get_y());
				break;
			default:
				break;
			}
		}
		else
		{
			exp_tmp = exp_tmp->get_prev();
			map.erase_explode(exp_tmp->get_next());
		}
		exp_tmp = exp_tmp->get_next();
	}
}

void Scene::draw_font()
{
	int frame_num = drawer.get_logic()->get_frame_num();
	fnt1->SetColor(0xFFFFFFFF);
	if(map.get_system_status()==PASS)
		fnt1->printf(5, WIN_H-55, HGETEXT_LEFT, "time:%0.1f",0.0);
	else
		fnt1->printf(5, WIN_H-55, HGETEXT_LEFT, "time:%0.1f",frame_num/50.0);
	fnt1->printf(5, WIN_H-33, HGETEXT_LEFT, "score:%d",map.get_score());
	char* s = 0;
	if(map.get_system_status()==PASS) 
	{
		switch(map.get_game_stage())
		{
		case STAGE_1:
			if(frame_num>BOSS_APPEAR_FRAME)
				s = "Stage 2";
			else
				s = "Stage 1";
			break;
		case STAGE_2:
			if(frame_num>BOSS_APPEAR_FRAME)
				s = "Stage 3";
			else
				s = "Stage 2";
			break;
		case STAGE_3:
			if(frame_num>BOSS_APPEAR_FRAME)
				s = "Stage 4";
			else
				s = "Stage 3";
			break;
		case STAGE_4:
			if(frame_num>BOSS_APPEAR_FRAME)
				s = "Stage 5";
			else
				s = "Stage 4";
			break;
		case STAGE_5:
			if(frame_num>BOSS_APPEAR_FRAME)
			    s = " ";
			else
				s = "Stage 5";
			break;
		default:
			break;
		}
			fnt2->printf(WIN_W/2.0-fnt2->GetStringWidth(s),WIN_H/2.0-fnt2->GetHeight(),HGETEXT_LEFT,s);
	}
}

void Scene::draw_volume()
{
	boss_blood_spr->RenderEx(50,280,0,map.get_volume()/100.0,1);
	fnt1->SetColor(0xFFAA0000);
	fnt1->printf(50,240,HGETEXT_LEFT,"volume: %d",map.get_volume());
	fnt1->SetColor(0xFFFFFFFF);
}

void Scene::draw()
{
	draw_background();
	drawer.get_hge()->Gfx_RenderQuad(&clouds_quad);
	draw_font();
	draw_information();
	draw_wingman();
	draw_powers();
	draw_enermies();
	draw_player();
	draw_bullets();
	draw_explosion();
}

void Scene::end_up()
{
	delete fnt1;
	delete fnt2;
	delete pl_stay_ani;
	delete pl_right_ani;
	delete pl_left_ani;
	delete pl_bull_1_spr;
	delete bluemiko_stay_ani;;
	delete bluemiko_left_ani;
	delete bluemiko_right_ani;
	delete redmiko_stay_ani;;
	delete redmiko_left_ani;
	delete redmiko_right_ani;
	delete butterfly_stay_ani;;
	delete butterfly_right_ani;
	delete butterfly_left_ani;
	delete snowman_ani;
	delete snail_ani;;
	delete ghost_ani;
	delete blue_miko_bull_spr;
	delete red_miko_bull_spr;
	delete snail_bull_spr;
	delete snowman_bull_spr;
	delete butterfly_bull_spr;
	delete ghost_bull_spr;
	delete enemy_explode_ani;
	delete boss_explode_spr;
	delete power_life_spr;
	delete power_bull_spr;
	delete power_redwingman_spr;
	delete power_bluewingman_spr;
	delete red_score_spr;
	delete blue_score_spr;
	delete black_score_spr;
	delete bg_spr;
	drawer.get_hge()->Texture_Free(pl_bull_1_tex);
	drawer.get_hge()->Target_Free(pl_tex);
	drawer.get_hge()->Texture_Free(miko_tex);
	drawer.get_hge()->Texture_Free(snail_tex);
	drawer.get_hge()->Texture_Free(butterfly_tex);
	drawer.get_hge()->Texture_Free(snowman_tex);
	drawer.get_hge()->Texture_Free(ghost_tex);
	drawer.get_hge()->Texture_Free(enemy_explode_tex);
	drawer.get_hge()->Texture_Free(boss_explode_tex);
	drawer.get_hge()->Texture_Free(boss_1_tex);
	drawer.get_hge()->Texture_Free(power_bull_tex);
	drawer.get_hge()->Texture_Free(power_life_tex);
	drawer.get_hge()->Texture_Free(power_wingman_tex);
	drawer.get_hge()->Target_Free(score_tex);
	drawer.get_hge()->Texture_Free(bg_tex);
}