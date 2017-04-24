#include "objectbase.h"
#include "..\Direct3D.h"
#include "..\DirectXTK.h"
#include <SimpleMath.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;

void ObjectBase::SetPosX(float x)
{
	pos_x = x;
}

float ObjectBase::GetPosX()
{
	return pos_x;
}

void ObjectBase::SetPosY(float y)
{
	pos_y = y;
}

float ObjectBase::GetPosY()
{
	return pos_y;
}

void ObjectBase::SetSpdX(float x)
{
	spd_x = x;
}

float ObjectBase::GetSpdX()
{
	return spd_x;
}

void ObjectBase::SetSpdY(float y)
{
	spd_y = y;
}

float ObjectBase::GeSpdY()
{
	return spd_y;
}

void ObjectBase::Updata()
{
	//Å‘åˆÚ“®‘¬“x‚Ì”»’è
	if (spd_x > 8)
	{
		spd_x = 8;
	}
	if (spd_x < -8)
	{
		spd_x = -8;
	}
	if (spd_y > 8)
	{
		spd_y = 8;
	}
	if (spd_y < -8)
	{
		spd_y = -8;
	}
	pos_x += spd_x;
	pos_y += spd_y;
}

void ObjectBase::Render()
{
	RECT rects;
	rects = {grp_x,grp_y,
		grp_x + grp_w,
		grp_y + grp_h };
	g_spriteBatch->Draw(handle->m_pTexture,
		Vector2(pos_x, pos_y),
		&rects, Colors::White, 0.0f,
		Vector2(grp_w / 2, grp_h / 2), 1.0f);

}

ObjectBase::ObjectBase()
{

}

ObjectBase::~ObjectBase()
{

}

void ObjectBase::SetHandle(Texture * p)
{
	handle = p;
}

void ObjectBase::SetGrpX(float x)
{
	grp_x = x;
}

int ObjectBase::GetGrpX()
{
	return grp_x;
}

void ObjectBase::SetGrpY(float y)
{
	grp_y = y;
}

int ObjectBase::GetGrpY()
{
	return grp_y;
}

void ObjectBase::SetGrpW(float w)
{
	grp_w = w;
}

int ObjectBase::GetGrpW()
{
	return grp_w;
}

void ObjectBase::SetGrpH(float h)
{
	grp_h = h;
}

int ObjectBase::GetGrpH()
{
	return grp_h;
}
