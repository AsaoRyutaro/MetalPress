//----------------------------------------------------
//	GameClear.h
//
//	�Q�[���N���A�ւ̃w�b�_�[�t�@�C��
//
//	2016/12/12
//	
//	K.Yoshikawa
//----------------------------------------------------

// ���d�C���N���[�h�̖h�~ ==================================================
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
	int cnt;					//�J�E���^
public:
	GameClear();
	~GameClear();
	void Update();
	void Render();
};