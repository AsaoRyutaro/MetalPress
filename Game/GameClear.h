//----------------------------------------------------
//	GameClear.h
//
//	ゲームクリアへのヘッダーファイル
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



class GameClear :public GameBase
{
private:
	int cnt;					//カウンタ
public:
	GameClear();
	~GameClear();
	void Update();
	void Render();
};