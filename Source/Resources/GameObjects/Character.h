#pragma once
#include <Resources\GameObjects\Ammo\Pistol.h>
#include <Resources\GameObjects\Ammo\Launcher.h>
#include <Resources\GameObjects\Ammo\Gun.h>

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
	Launcher* getLauncher();
	Gun* getGun();


private:
	float posX;
	float posY;
	float posZ;
	float angle;
	int life;
	Pistol* pistol;
	Gun* gun;
	Launcher* launcher;


};