#pragma once

class GameBase
{
public:

	virtual ~GameBase(){};
	//�������z�֐�
	virtual void Update() = 0;
	virtual void Render() = 0;


};
