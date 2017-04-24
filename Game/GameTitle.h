//----------------------------------------------------
//	GameTitle.h
//
//	�Q�[���^�C�g���ւ̃w�b�_�[�t�@�C��
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

class GameTitle :public GameBase
{
private:
	int cnt;					//�J�E���^
	int t_cnt;					//����
	int games;
	int bgtime;
	float bgeffect;

public:
	GameTitle();
	~GameTitle();
	void Update();
	void Render();
};