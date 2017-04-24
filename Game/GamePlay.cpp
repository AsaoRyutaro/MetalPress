//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  ゲームプレイ処理のソースファイル
//!
//! @date   日付		
//!
//! @author 制作者名	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include"GamePlay.h"
#include "Player.h"
#include "..\Direct3D.h"
#include "..\DirectXTK.h"
#include <SimpleMath.h>
#include "..\EnemyBase.h"
#include "..\Texture.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;


//void CheckMove(int dir);		//移動できるかチェック

//----------------------------------------------------------------------
//! @brief ゲームプレイのコンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GamePlay::GamePlay()
{
	//マウスのカーソル
	ShowCursor(FALSE);

	//player = new ;
	
	
	cnt = 0;

	g_boxCnt = 0; 
	bgX = 0;
	bgY = 0;

	m_memoryi = 0;
	ml = 0;
	player = new Player();
	player->SetGrpX(0);
	player->SetGrpY(0);
	player->SetGrpW(64);
	player->SetGrpH(64);
	player->SetHandle(g_PongImage);

	Enemy1 = new EnemyBase();
	Enemy1->SetHandle(g_clear);

}

//----------------------------------------------------------------------
//! @brief ゲームプレイのデストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GamePlay::~GamePlay()
{
	delete player;
	
}


//----------------------------------------------------------------------
//! @brief ゲームプレイ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GamePlay::Update()
{
	//シーンの最初に一回だけ行う初期化処理
	if (g_init == 0)
	{
		g_init = 1;
	}

	//入力系処理/////////////////////////////
	mx = player->GetPosX();
	player->SetSpdX(g_mouse.x - mx);
	my = player->GetPosY();
	player->SetSpdY(g_mouse.y - my);
	ml = g_mouse.scrollWheelValue;
		//座標変更処理/////////////////////////////

	player->Updata();

	Enemy1->Move();



}




//----------------------------------------------------------------------
//! @brief ゲームプレイ描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GamePlay::Render()
{
	RECT rect;
	wchar_t buf[256];

	RECT m_rects;
	m_rects = { 0,0,800,600 };
	g_spriteBatch->Draw(g_yuka->m_pTexture,
		Vector2(bgX, bgY),
		&m_rects, Colors::White, 0.0f,
		Vector2(0, 0), 1.0f);

	g_spriteBatch->Draw(g_yuka2->m_pTexture,
		Vector2(bgX, bgY - 600),
		&m_rects, Colors::White, 0.0f,
		Vector2(0, 0), 1.0f);
	

	Enemy1->Render();
	player->Render();
	//秒数描画
	DrawNum(300, 10, g_Time);

	swprintf_s(buf, 256, L"");

	bgY++;
	if (bgY > 600)
	{
		bgY = 0;
	}
	
	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(550, 0));

}


