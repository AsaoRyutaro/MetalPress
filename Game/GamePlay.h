//----------------------------------------------------
//	GamePlay.h
//
//	ゲームプレイへのヘッダーファイル
//
//	2016/12/12
//
//	K.Yoshikawa
//----------------------------------------------------

// 多重インクルードの防止 ==================================================
#pragma once
#include "GameBase.h"
#include "Player.h"
#include "..\EnemyBase.h"
#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif



class GamePlay :public GameBase
{
private:
	int cnt;//カウンタ
	int mx;
	int my;
	int ml;
	int bgX;
	int bgY;
	int m_memoryi;
	Player *player;
	EnemyBase *Enemy1;


public:
	GamePlay();
	~GamePlay();
	void Update();
	void Render();
	
};