//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   2016/11/21
//!
//! @author Y・Kanata
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#define _GAMEMAIN_

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

#include <time.h>

#include "GameBase.h"
#include "GameLogo.h"
#include "GameTitle.h"
#include "GamePlay.h"
#include "GameClear.h"


#include "GameMain.h"
#include "..\ADX2Le.h"
#include "CueSheet_0.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")



using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

// プロトタイプ宣言 ====================================================
void importData(string filename);

//// グローバル変数の定義 ====================================================

GameBase *base;

// 関数の定義 ==============================================================

//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializeGame(void)
{


	

	//　画像の読み込み 
	g_grpHandle = new Texture(L"Resources\\Images\\TridentLogo.png");
	g_PongImage = new Texture(L"Resources\\Images\\rokku.png");
	g_logos = new Texture(L"Resources\\Images\\logo.png");
	g_press_key= new Texture(L"Resources\\Images\\zimaku.png");
	g_title = new Texture(L"Resources\\Images\\title.png");
	g_clear = new Texture(L"Resources\\Images\\kedama.png");
	g_yuka = new Texture(L"Resources\\Images\\yuka.png");
	g_yuka2 = new Texture(L"Resources\\Images\\yuka.png");
	ziki=new Texture(L"Resources\\Images\\ziki.png");


	


	/*ADX2Le::Initialize("Resources\\Sounds\\NewProject.acf");

	ADX2Le::LoadAcb("Resources\\Sounds\\CueSheet_0.acb");*/

	/*ADX2Le::Play(CRI_CUESHEET_0__CUE_ID_0);*/

	
	g_boxCnt = 0;


	
	base = new GamePlay();

}




//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void UpdateGame(void)
{
	

	//シーン管理
	if (g_NextScene != g_scene)
	{
		g_scene = g_NextScene;
		//シーン削除
		delete base;

		//シーン生成
		
		switch (g_scene)
		{
		case LOGO:
			base = new GameLogo();
			break;
		case TITLE:
			base = new GameTitle();
			break;
		case PLAY:
			base = new GamePlay();
			break;
		case CLEAR:
			base = new GameClear();
			break;
		}

	}
	base->Update();

}



//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderGame(void)
{

	base->Render();
	/*DrawFormatString(0, 0, g_RGB, "%2.0f", GetFrameRate());*/

}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void FinalizeGame(void)
{

	delete	g_PongImage;
	delete	g_grpHandle;
	delete	g_logos;
	delete	g_press_key;
	delete	base;
	delete g_title;
	delete g_clear;
	delete g_yuka;
	delete g_yuka2;
	
}


//----------------------------------------------------------------------
//! @brief 数値描画処理
//!
//! @param[in] xy座標，数値w
//!
//! @return なし
//----------------------------------------------------------------------
void DrawNum(int x, int y, int n)
{
	int w = n;		//計算用
	int i = 0;		//文字数

	if (w == 0)
	{
		/*DrawRectGraph(x, y, 0, 48, 25, 32, g_PongImage, TRUE, FALSE);*/
	}
	else
	{
		while (w)
		{
			/*DrawRectGraph(x - i * 25, y,
				(w % 10) * 25, 48, 25, 32, g_PongImage, TRUE, FALSE);*/
			w = w / 10;
			i++;
		}
	}
}



// ファイル読み込み関数
void importData(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;

	if (!ifs)
	{
		for (i = 0; i < MAX_TIP; i++)
		{
			g_map[i / 20][i % 20] = 4;
		}
		return;
	}


	i = 0;
	while (getline(ifs, str))
	{
		string token;
		istringstream steam(str);

		// 1行のうち、文字列とコンマを分割する
		while (getline(steam, token, ','))
		{
			// すべて文字列として読み込まれるため
			// 数値は変換が必要
			g_map[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
		
	}
}
