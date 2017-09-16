#include "include\hge.h"
#include "include\hgefont.h"
#include "include\hgegui.h"
#include "include\hgecolor.h"
#pragma once

//用于定义开始菜单
class hgeGUIMenuItem : public hgeGUIObject
{
public:
	hgeGUIMenuItem(int id, hgeFont *fnt, HEFFECT snd, float x, float y, float delay, char *title);

	virtual void	Render();
	virtual void	Update(float dt);

	virtual void	Enter();
	virtual void	Leave();
	virtual bool	IsDone();
	virtual void	Focus(bool bFocused);

	virtual bool	MouseLButton(bool bDown);
	virtual bool	KeyClick(int key, int chr);

private:
	hgeFont		*fnt;
	HEFFECT		snd;
	float		delay;
	char		*title;

	hgeColor	scolor, dcolor, scolor2, dcolor2, sshadow, dshadow;
	hgeColor	color, shadow;
	float		soffset, doffset, offset;
	float		timer, timer2;
};
//定义胜利菜单，与hge提供的原有菜单的颜色稍有不同
class hgeGUIWinMenu : public hgeGUIObject
{
public:
	hgeGUIWinMenu(int id, hgeFont *fnt, HEFFECT snd, float x, float y, float delay, char *title);

	virtual void	Render();
	virtual void	Update(float dt);

	virtual void	Enter();
	virtual void	Leave();
	virtual bool	IsDone();
	virtual void	Focus(bool bFocused);

	virtual bool	MouseLButton(bool bDown);
	virtual bool	KeyClick(int key, int chr);

private:
	hgeFont		*fnt;
	HEFFECT		snd;
	float		delay;
	char		*title;

	hgeColor	scolor, dcolor, scolor2, dcolor2, sshadow, dshadow;
	hgeColor	color, shadow;
	float		soffset, doffset, offset;
	float		timer, timer2;
};
//定义背景菜单，在focus时会展示背景图片
class hgeGUIBGMenu : public hgeGUIObject
{
public:
	hgeGUIBGMenu(int id, int order, hgeFont *fnt, HEFFECT snd, float x, float y, float delay, char *title);

	virtual void	Render();
	virtual void	Update(float dt);

	virtual void	Enter();
	virtual void	Leave();
	virtual bool	IsDone();
	virtual void	Focus(bool bFocused);

	virtual bool	MouseLButton(bool bDown);
	virtual bool	KeyClick(int key, int chr);

private:
	hgeFont		*fnt;
	HEFFECT      snd;
	float		 delay;
	char		*title;
	int          order;

	hgeColor	scolor, dcolor, scolor2, dcolor2, sshadow, dshadow;
	hgeColor	color, shadow;
	float		soffset, doffset, offset;
	float		timer, timer2;
};
