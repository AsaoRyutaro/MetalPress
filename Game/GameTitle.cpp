//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  タイトル処理のソースファイル
//!
//! @date   日付		
//!
//! @author 制作者名	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameTitle.h"
#include "..\ADX2Le.h"
#include "CueSheet_0.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")

using namespace DirectX::SimpleMath;
using namespace DirectX;


//----------------------------------------------------------------------
//! @brief タイトルのコンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameTitle::GameTitle()
{
	cnt = 0;
	t_cnt = 0;
	games = 0;
	bgtime = 0;
	bgeffect = 0;
}
//----------------------------------------------------------------------
//! @brief タイトルのデストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameTitle::~GameTitle()
{
}



//----------------------------------------------------------------------
//! @brief タイトル処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameTitle::Update()
{
	if (g_init == 0)
	{
		g_init = 1;

		cnt = 0;

		/*PlaySoundMem(g_se, DX_PLAYTYPE_BACK);*/

		/*ADX2Le::Play(CRI_CUESHEET_0__CUE_ID_1);*/
	}

	cnt++;
	if (cnt > 60)
	{
		t_cnt += 1;
		cnt = 0;
	}

	if (g_key.Enter)
	{
		games = 1;
		t_cnt = 0;

	}
	if (games == 1)
	{
		if (t_cnt > 3)
		{
			g_NextScene = PLAY;
		}
		
			bgeffect+=0.01;
		
	}
}

//----------------------------------------------------------------------
//! @brief タイトル描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameTitle::Render()
{
	/*swprintf_s(buf, 256, L"GAME TITLE");*/
	RECT rect;
	RECT crect;
	//wchar_t buf[256];

	//g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(500, 0));
	rect = { 0, 0, 640,480 };
	//crect = { bgeffect,255,255,255 };

	g_spriteBatch->Draw(g_title->m_pTexture, Vector2(0, 0),
		&rect, Colors::White, /*回転のradian値*/0.0f, /*中心の回転座標*/Vector2(0, 0), /*拡大倍率*/Vector2(1, 1));

	if ((t_cnt%2==0)&&(games==0))
	{
		g_spriteBatch->Draw(g_press_key->m_pTexture, Vector2(0, 0),
		&rect, Colors::White, /*回転のradian値*/0.0f, /*中心の回転座標*/Vector2(0, 0), /*拡大倍率*/Vector2(1, 1));
	}
	if ((games == 1)&&(cnt % 10 == 0))
	{
			g_spriteBatch->Draw(g_press_key->m_pTexture, Vector2(0, 0),
				&rect, Colors::White, /*回転のradian値*/0.0f, /*中心の回転座標*/Vector2(0, 0), /*拡大倍率*/Vector2(1, 1));
	}
	//g_spriteBatch->Draw(g_fout->m_pTexture, Vector2(0, 0),
	//	&rect, Vector4(1.0f,1.0f,1.0f,bgeffect), /*回転のradian値*/0.0f, /*中心の回転座標*/Vector2(0, 0), /*拡大倍率*/Vector2(1, 1));
}