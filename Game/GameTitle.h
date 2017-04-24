//----------------------------------------------------
//	GameTitle.h
//
//	ゲームタイトルへのヘッダーファイル
//
//	2016/12/12
//
//	K.Yoshikawa
//----------------------------------------------------

// 多重インクルードの防止 ==================================================
#pragma once
#include "GameBase.h"
#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif

class GameTitle :public GameBase
{
private:
	int cnt;					//カウンタ
	int t_cnt;					//時間
	int games;
	int bgtime;
	float bgeffect;

public:
	GameTitle();
	~GameTitle();
	void Update();
	void Render();
};