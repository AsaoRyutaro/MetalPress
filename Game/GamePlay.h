//----------------------------------------------------
//	GamePlay.h
//
//	�Q�[���v���C�ւ̃w�b�_�[�t�@�C��
//
//	2016/12/12
//
//	K.Yoshikawa
//----------------------------------------------------

// ���d�C���N���[�h�̖h�~ ==================================================
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
	int cnt;//�J�E���^
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