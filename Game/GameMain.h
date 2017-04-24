//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  ゲーム関連のヘッダファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once
#include "GameBase.h"
#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif


// 定数の定義 ==============================================================
#include <Windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include "..\DirectXTK.h"
#include "..\Texture.h"


// ゲームタイトル
#define GAME_TITLE "thousand"

// ゲーム画面
#define SCREEN_WIDTH  800    // 幅[pixel]
#define SCREEN_HEIGHT 600    // 高さ[pixel]


#define MAX_TIP 300
#define MAX_BACK 300
#define MAX_BOX 8


//　構造体宣言
typedef struct tag_object
{
	Texture *handle;	//グラフィックハンドル 
	int grp_x;		//元画像のｘ座標 
	int grp_y;		//元画像のｙ座標 
	int grp_w;		//元画像の幅 
	int grp_h;		//元画像の高さ 
	float pos_x;	//座標x 
	float pos_y;	//座標y 
	float spd_x;	//速度x 
	float spd_y;	//速度y 
	int state;		//状態
	int type;
}OBJECT;			//オブジェクト用

//　列挙型宣言
enum SCENE
{
	LOGO,
	TITLE,
	PLAY,
	CLEAR,

};

// 関数の宣言 ==============================================================

// ゲームの初期化処理
void InitializeGame(void);

// ゲームの更新処理
void UpdateGame(void);

// ゲームの描画処理
void RenderGame(void);

// ゲームの終了処理
void FinalizeGame(void);

//　数値描画処理
void DrawNum(int x, int y, int n);


void importData(std::string filename);

// グローバル変数の定義 ====================================================
//EXTERN HGRP g_grpHandle;			//　グラフィック
//EXTERN HGRP g_PongImage;			//　ポン画像
//
//EXTERN COLOR g_RGB;				//　文字色
//
//EXTERN HSND g_se;					//　効果音

EXTERN OBJECT g_tip[MAX_TIP];		//　チップ
EXTERN OBJECT g_player;				//　プレイヤ
EXTERN OBJECT g_back[MAX_BACK];		//　背景
EXTERN OBJECT g_box[MAX_BOX];		//　箱
EXTERN int g_x;						//　列
EXTERN int g_y;						//　行
EXTERN int g_boxCnt;				//　箱の数

EXTERN Texture *g_PongImage;
EXTERN Texture *g_grpHandle;
EXTERN Texture *g_logos;
EXTERN Texture *g_press_key;
EXTERN Texture *g_title;
EXTERN Texture *g_clear;
EXTERN Texture *g_yuka;
EXTERN Texture *g_yuka2;
EXTERN Texture *ziki;

//EXTERN int g_key_code;				//　キー情報
//EXTERN int g_key_old;				//　前フレームのキー情報

EXTERN int g_scene;					//　シーン管理
EXTERN int g_NextScene;				//　次のシーン
EXTERN int g_init;					//　初期化管理
EXTERN int g_Time;					//　秒数
EXTERN int g_map[15][20];
EXTERN int goal;
