#pragma once
#include"ObjectBase.h"

#include <SimpleMath.h>


class Player :public ObjectBase
{
protected:
//	自機
	int Remainingmachine;			//残機
	int Bom;						//ボム
	int Power;						//パワー
	int Scrollwheelvalue;			//オプションの位置

//自機のオプション（周りを飛ぶアレ）



	
	



//その他
	int scrollwheel;							
	int  BULLET;
	ObjectBase Bullets[200];

public:
	Player();
	~Player();

	void Died();								//死んだ処理
	int	ReturnRemainingmachine();				//残機を返す
	void Usebom();								//ボムの使用
	int Returnbom();							//ボムの個数を返す
	void Bomreset();							//ボムのリセット
	void Extend();								//残機を増やす

	int GetPower();								//パワーを返す


	


};
