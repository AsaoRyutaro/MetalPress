#include "Player.h"


#include "..\Direct3D.h"
#include "..\DirectXTK.h"
#include <SimpleMath.h>
#include "..\Texture.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;

//初期化
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
//死んだ処理
void Player::Died()
{
	//残機が1減る
	Remainingmachine -= 1;

	

	//ボムが補給される。
	Bomreset();
}
//残機を返す
int Player::ReturnRemainingmachine()
{
	return Remainingmachine;
}
//ボムの使用
void Player::Usebom()
{
	Bom -= 1;
}
//ボムの個数を返す
int Player::Returnbom()
{
	return Bom;
}
//ボムのリセット
void Player::Bomreset()
{
	Bom = 3;
}
//残機を増やす
void Player::Extend()
{
	if (Remainingmachine < 6)
	{
		Remainingmachine += 1;
	}
}
//パワーを返す
int Player::GetPower()
{
	return Power;
}
