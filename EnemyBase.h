#pragma once
#include "Texture.h"

class EnemyBase
{
private:
	double x, y;	//座標

	Texture *handle;	//グラフィックハンドル 

	int w, h;		//画像サイズの変数

	int in_time, stop_time, out_time;

	int count;

	int e_time;
	int t_cnt;

	int endflag;
	
	RECT Rect;
	
	 
public:
	
	void SetHandle(Texture *pi);

	void Move();

	//void Draw();

	void Control();

	void Update();

	void Render();

	int SetX();



	EnemyBase();

	~EnemyBase();




};

