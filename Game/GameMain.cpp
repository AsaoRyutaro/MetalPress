//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   2016/11/21
//!
//! @author Y�EKanata
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#define _GAMEMAIN_

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

#include <time.h>

#include "GameBase.h"
#include "GameLogo.h"
#include "GameTitle.h"
#include "GamePlay.h"
#include "GameClear.h"


#include "GameMain.h"
#include "..\ADX2Le.h"
#include "CueSheet_0.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")



using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

// �v���g�^�C�v�錾 ====================================================
void importData(string filename);

//// �O���[�o���ϐ��̒�` ====================================================

GameBase *base;

// �֐��̒�` ==============================================================

//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void InitializeGame(void)
{


	

	//�@�摜�̓ǂݍ��� 
	g_grpHandle = new Texture(L"Resources\\Images\\TridentLogo.png");
	g_PongImage = new Texture(L"Resources\\Images\\rokku.png");
	g_logos = new Texture(L"Resources\\Images\\logo.png");
	g_press_key= new Texture(L"Resources\\Images\\zimaku.png");
	g_title = new Texture(L"Resources\\Images\\title.png");
	g_clear = new Texture(L"Resources\\Images\\kedama.png");
	g_yuka = new Texture(L"Resources\\Images\\yuka.png");
	g_yuka2 = new Texture(L"Resources\\Images\\yuka.png");
	ziki=new Texture(L"Resources\\Images\\ziki.png");


	


	/*ADX2Le::Initialize("Resources\\Sounds\\NewProject.acf");

	ADX2Le::LoadAcb("Resources\\Sounds\\CueSheet_0.acb");*/

	/*ADX2Le::Play(CRI_CUESHEET_0__CUE_ID_0);*/

	
	g_boxCnt = 0;


	
	base = new GamePlay();

}




//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void UpdateGame(void)
{
	

	//�V�[���Ǘ�
	if (g_NextScene != g_scene)
	{
		g_scene = g_NextScene;
		//�V�[���폜
		delete base;

		//�V�[������
		
		switch (g_scene)
		{
		case LOGO:
			base = new GameLogo();
			break;
		case TITLE:
			base = new GameTitle();
			break;
		case PLAY:
			base = new GamePlay();
			break;
		case CLEAR:
			base = new GameClear();
			break;
		}

	}
	base->Update();

}



//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void RenderGame(void)
{

	base->Render();
	/*DrawFormatString(0, 0, g_RGB, "%2.0f", GetFrameRate());*/

}



//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void FinalizeGame(void)
{

	delete	g_PongImage;
	delete	g_grpHandle;
	delete	g_logos;
	delete	g_press_key;
	delete	base;
	delete g_title;
	delete g_clear;
	delete g_yuka;
	delete g_yuka2;
	
}


//----------------------------------------------------------------------
//! @brief ���l�`�揈��
//!
//! @param[in] xy���W�C���lw
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void DrawNum(int x, int y, int n)
{
	int w = n;		//�v�Z�p
	int i = 0;		//������

	if (w == 0)
	{
		/*DrawRectGraph(x, y, 0, 48, 25, 32, g_PongImage, TRUE, FALSE);*/
	}
	else
	{
		while (w)
		{
			/*DrawRectGraph(x - i * 25, y,
				(w % 10) * 25, 48, 25, 32, g_PongImage, TRUE, FALSE);*/
			w = w / 10;
			i++;
		}
	}
}



// �t�@�C���ǂݍ��݊֐�
void importData(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;

	if (!ifs)
	{
		for (i = 0; i < MAX_TIP; i++)
		{
			g_map[i / 20][i % 20] = 4;
		}
		return;
	}


	i = 0;
	while (getline(ifs, str))
	{
		string token;
		istringstream steam(str);

		// 1�s�̂����A������ƃR���}�𕪊�����
		while (getline(steam, token, ','))
		{
			// ���ׂĕ�����Ƃ��ēǂݍ��܂�邽��
			// ���l�͕ϊ����K�v
			g_map[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
		
	}
}
