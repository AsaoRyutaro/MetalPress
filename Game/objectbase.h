#pragma once
#include "..\Texture.h"


class ObjectBase
{
protected:
	Texture *handle;	//�O���t�B�b�N�n���h�� 
	int grp_x;			//���摜�̂����W 
	int grp_y;			//���摜�̂����W 
	int grp_w;			//���摜�̕� 
	int grp_h;			//���摜�̍��� 
	float pos_x;		//���Wx 
	float pos_y;		//���Wy 
	float spd_x;		//���xx 
	float spd_y;		//���xy 
	int state;			//���
	
public:
	ObjectBase();
	~ObjectBase();
	void SetHandle(Texture *p);
	void SetGrpX(float x);
	int GetGrpX();
	void SetGrpY(float y);
	int GetGrpY();
	void SetGrpW(float w);
	int GetGrpW();
	void SetGrpH(float h);
	int GetGrpH();
	void SetPosX(float x);
	float GetPosX();
	void SetPosY(float y);
	float GetPosY();
	void SetSpdX(float x);
	float GetSpdX();
	void SetSpdY(float y);
	float GeSpdY();
	void Updata();
	void Render();
};

