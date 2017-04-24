#include"EnemyBase.h"
#include "Direct3D.h"
#include "DirectXTK.h"
#include <SimpleMath.h>
#include <time.h>
//#include "Texture.h"


using namespace std;

using namespace DirectX;
using namespace DirectX::SimpleMath;

//敵のコンストラクタ
//引数　　なし
//戻り値　なし
EnemyBase::EnemyBase()
{
	
	
	w = 35;
	h = 35;

	x = SetX();
	y = -50;

	in_time = 5;

	stop_time = 8;

	out_time = 11;

	count = 0;

	e_time = 0;
	t_cnt = 0;

	endflag = false;

}

int EnemyBase::SetX()
{
	srand((unsigned int)time(NULL));
	return rand() % 600 + 100;
}

void EnemyBase::Move()
{
	
	if ((in_time < e_time) && (e_time < stop_time))
	{
		y += 2;
	}
	if ((e_time >= stop_time) && (e_time <= out_time))
	{
		y += 0.1;
	}
	
	if (e_time > out_time)
	{
		
		if (x <= 300)
		{
			x -= 3;
			y += 1;
		}
		else if(x>=500)
		{
			y -= 1;
			x += 3;
		}
		else
		{
			y -= 2;
		}
		if (x < -40)
		{
			x = SetX();
			y = -50;
			e_time = 0;
			t_cnt = 0;
		}
		if (y < -40)
		{
			x = SetX();
			y = -50;
			e_time = 0;
			t_cnt = 0;
		}
		if (x > 840)
		{
			x = SetX();
			y = -50;
			e_time = 0;
			t_cnt = 0;
		}
	}

	//時間処理/////////////////////////////

	t_cnt++;
	if (t_cnt >= 60)
	{
		e_time++;
		t_cnt = 0;
	}
}



//void EnemyBase::Draw()
//{
//	int temp;
//
//	if (!endflag)
//	{
//		temp = count % 40 / 10;
//		if (temp == 3)
//			temp = 1;
//	}
//	
//}



void EnemyBase::SetHandle(Texture *pi)
{
	handle =pi;
}




void EnemyBase::Update()
{

}



void EnemyBase::Render()
{
	Rect = {0,0,w,h};

	g_spriteBatch->Draw(handle->m_pTexture,
		Vector2(x, y),
		&Rect, Colors::White, 0.0f,
		Vector2(w / 2, h / 2), 1.0f);


}



EnemyBase::~EnemyBase()
{

}