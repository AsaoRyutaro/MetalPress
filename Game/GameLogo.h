//----------------------------------------------------
//	GameLogo.h
//
//	�Q�[�����S�ւ̃w�b�_�[�t�@�C��
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


class GameLogo :public GameBase
{
private:
	int cnt;					//�J�E���^
public:
	GameLogo();
	~GameLogo();
	void Update();
	void Render();

};
