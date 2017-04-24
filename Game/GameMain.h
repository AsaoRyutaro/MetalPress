//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  �Q�[���֘A�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once
#include "GameBase.h"
#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif


// �萔�̒�` ==============================================================
#include <Windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include "..\DirectXTK.h"
#include "..\Texture.h"


// �Q�[���^�C�g��
#define GAME_TITLE "thousand"

// �Q�[�����
#define SCREEN_WIDTH  800    // ��[pixel]
#define SCREEN_HEIGHT 600    // ����[pixel]


#define MAX_TIP 300
#define MAX_BACK 300
#define MAX_BOX 8


//�@�\���̐錾
typedef struct tag_object
{
	Texture *handle;	//�O���t�B�b�N�n���h�� 
	int grp_x;		//���摜�̂����W 
	int grp_y;		//���摜�̂����W 
	int grp_w;		//���摜�̕� 
	int grp_h;		//���摜�̍��� 
	float pos_x;	//���Wx 
	float pos_y;	//���Wy 
	float spd_x;	//���xx 
	float spd_y;	//���xy 
	int state;		//���
	int type;
}OBJECT;			//�I�u�W�F�N�g�p

//�@�񋓌^�錾
enum SCENE
{
	LOGO,
	TITLE,
	PLAY,
	CLEAR,

};

// �֐��̐錾 ==============================================================

// �Q�[���̏���������
void InitializeGame(void);

// �Q�[���̍X�V����
void UpdateGame(void);

// �Q�[���̕`�揈��
void RenderGame(void);

// �Q�[���̏I������
void FinalizeGame(void);

//�@���l�`�揈��
void DrawNum(int x, int y, int n);


void importData(std::string filename);

// �O���[�o���ϐ��̒�` ====================================================
//EXTERN HGRP g_grpHandle;			//�@�O���t�B�b�N
//EXTERN HGRP g_PongImage;			//�@�|���摜
//
//EXTERN COLOR g_RGB;				//�@�����F
//
//EXTERN HSND g_se;					//�@���ʉ�

EXTERN OBJECT g_tip[MAX_TIP];		//�@�`�b�v
EXTERN OBJECT g_player;				//�@�v���C��
EXTERN OBJECT g_back[MAX_BACK];		//�@�w�i
EXTERN OBJECT g_box[MAX_BOX];		//�@��
EXTERN int g_x;						//�@��
EXTERN int g_y;						//�@�s
EXTERN int g_boxCnt;				//�@���̐�

EXTERN Texture *g_PongImage;
EXTERN Texture *g_grpHandle;
EXTERN Texture *g_logos;
EXTERN Texture *g_press_key;
EXTERN Texture *g_title;
EXTERN Texture *g_clear;
EXTERN Texture *g_yuka;
EXTERN Texture *g_yuka2;
EXTERN Texture *ziki;

//EXTERN int g_key_code;				//�@�L�[���
//EXTERN int g_key_old;				//�@�O�t���[���̃L�[���

EXTERN int g_scene;					//�@�V�[���Ǘ�
EXTERN int g_NextScene;				//�@���̃V�[��
EXTERN int g_init;					//�@�������Ǘ�
EXTERN int g_Time;					//�@�b��
EXTERN int g_map[15][20];
EXTERN int goal;
