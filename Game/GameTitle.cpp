//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  �^�C�g�������̃\�[�X�t�@�C��
//!
//! @date   ���t		
//!
//! @author ����Җ�	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameTitle.h"
#include "..\ADX2Le.h"
#include "CueSheet_0.h"

#pragma comment(lib, "cri_ware_pcx86_LE_import.lib")

using namespace DirectX::SimpleMath;
using namespace DirectX;


//----------------------------------------------------------------------
//! @brief �^�C�g���̃R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GameTitle::GameTitle()
{
	cnt = 0;
	t_cnt = 0;
	games = 0;
	bgtime = 0;
	bgeffect = 0;
}
//----------------------------------------------------------------------
//! @brief �^�C�g���̃f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GameTitle::~GameTitle()
{
}



//----------------------------------------------------------------------
//! @brief �^�C�g������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameTitle::Update()
{
	if (g_init == 0)
	{
		g_init = 1;

		cnt = 0;

		/*PlaySoundMem(g_se, DX_PLAYTYPE_BACK);*/

		/*ADX2Le::Play(CRI_CUESHEET_0__CUE_ID_1);*/
	}

	cnt++;
	if (cnt > 60)
	{
		t_cnt += 1;
		cnt = 0;
	}

	if (g_key.Enter)
	{
		games = 1;
		t_cnt = 0;

	}
	if (games == 1)
	{
		if (t_cnt > 3)
		{
			g_NextScene = PLAY;
		}
		
			bgeffect+=0.01;
		
	}
}

//----------------------------------------------------------------------
//! @brief �^�C�g���`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameTitle::Render()
{
	/*swprintf_s(buf, 256, L"GAME TITLE");*/
	RECT rect;
	RECT crect;
	//wchar_t buf[256];

	//g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(500, 0));
	rect = { 0, 0, 640,480 };
	//crect = { bgeffect,255,255,255 };

	g_spriteBatch->Draw(g_title->m_pTexture, Vector2(0, 0),
		&rect, Colors::White, /*��]��radian�l*/0.0f, /*���S�̉�]���W*/Vector2(0, 0), /*�g��{��*/Vector2(1, 1));

	if ((t_cnt%2==0)&&(games==0))
	{
		g_spriteBatch->Draw(g_press_key->m_pTexture, Vector2(0, 0),
		&rect, Colors::White, /*��]��radian�l*/0.0f, /*���S�̉�]���W*/Vector2(0, 0), /*�g��{��*/Vector2(1, 1));
	}
	if ((games == 1)&&(cnt % 10 == 0))
	{
			g_spriteBatch->Draw(g_press_key->m_pTexture, Vector2(0, 0),
				&rect, Colors::White, /*��]��radian�l*/0.0f, /*���S�̉�]���W*/Vector2(0, 0), /*�g��{��*/Vector2(1, 1));
	}
	//g_spriteBatch->Draw(g_fout->m_pTexture, Vector2(0, 0),
	//	&rect, Vector4(1.0f,1.0f,1.0f,bgeffect), /*��]��radian�l*/0.0f, /*���S�̉�]���W*/Vector2(0, 0), /*�g��{��*/Vector2(1, 1));
}