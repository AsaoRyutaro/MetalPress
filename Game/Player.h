#pragma once
#include"ObjectBase.h"

#include <SimpleMath.h>


class Player :public ObjectBase
{
protected:
//	���@
	int Remainingmachine;			//�c�@
	int Bom;						//�{��
	int Power;						//�p���[
	int Scrollwheelvalue;			//�I�v�V�����̈ʒu

//���@�̃I�v�V�����i������ԃA���j



	
	



//���̑�
	int scrollwheel;							
	int  BULLET;
	ObjectBase Bullets[200];

public:
	Player();
	~Player();

	void Died();								//���񂾏���
	int	ReturnRemainingmachine();				//�c�@��Ԃ�
	void Usebom();								//�{���̎g�p
	int Returnbom();							//�{���̌���Ԃ�
	void Bomreset();							//�{���̃��Z�b�g
	void Extend();								//�c�@�𑝂₷

	int GetPower();								//�p���[��Ԃ�


	


};
