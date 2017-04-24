#pragma once
#include "Texture.h"

class EnemyBase
{
private:
	double x, y;	//���W

	Texture *handle;	//�O���t�B�b�N�n���h�� 

	int w, h;		//�摜�T�C�Y�̕ϐ�

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

