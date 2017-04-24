//----------------------------------------------------
//	GameLogo.h
//
//	ゲームロゴへのヘッダーファイル
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


class GameLogo :public GameBase
{
private:
	int cnt;					//カウンタ
public:
	GameLogo();
	~GameLogo();
	void Update();
	void Render();

};
