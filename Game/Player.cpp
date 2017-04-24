#include "Player.h"


#include "..\Direct3D.h"
#include "..\DirectXTK.h"
#include <SimpleMath.h>
#include "..\Texture.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;

//������
Player::Player()
{
	
	Remainingmachine = 5;
	Bom = 3;
	Power = 0;
	BULLET = 200;
}

Player::~Player()
{
}
//���񂾏���
void Player::Died()
{
	//�c�@��1����
	Remainingmachine -= 1;

	

	//�{�����⋋�����B
	Bomreset();
}
//�c�@��Ԃ�
int Player::ReturnRemainingmachine()
{
	return Remainingmachine;
}
//�{���̎g�p
void Player::Usebom()
{
	Bom -= 1;
}
//�{���̌���Ԃ�
int Player::Returnbom()
{
	return Bom;
}
//�{���̃��Z�b�g
void Player::Bomreset()
{
	Bom = 3;
}
//�c�@�𑝂₷
void Player::Extend()
{
	if (Remainingmachine < 6)
	{
		Remainingmachine += 1;
	}
}
//�p���[��Ԃ�
int Player::GetPower()
{
	return Power;
}
