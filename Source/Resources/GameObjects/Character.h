#pragma once
#include <Resources\GameObjects\Amo\Pistol.h>
#include <Resources\GameObjects\Amo\Tun.h>
#include <Resources\GameObjects\Amo\Pusca.h>

class Character
{
public:
	Character();
	~Character();

	void setLife(int life);
	void setX(float posX);
	void setY(float posY);
	void setZ(float posZ);
	void setAngle(float angle);

	int getLife();
	float getPosX();
	float getPosY();
	float getPosZ();
	float getAngle();

	Pistol* getPistol();
	Tun* getTun();
	Pusca* getPusca();


private:
	float posX;
	float posY;
	float posZ;
	float angle;
	int life;
	Pistol* pistol;
	Pusca* pusca;
	Tun* tun;


};