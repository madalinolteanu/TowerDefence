#pragma once
#include <Resources\GameObjects\Character.h>

Character::Character()
{
}

Character::~Character()
{
}

void Character::setLife(int life)
{
	this->life = life;
}

void Character::setX(float posX)
{
	this->posX = posX;
}

void Character::setY(float posY)
{
	this->posY = posY;
}

void Character::setZ(float posZ)
{
	this->posZ = posZ;
}

void Character::setAngle(float angle)
{
	this->angle = angle;
}

int Character::getLife()
{
	return life;
}

float Character::getPosX()
{
	return posX;
}

float Character::getPosY()
{
	return posY;
}

float Character::getPosZ()
{
	return posZ;
}

float Character::getAngle()
{
	return angle;
}

Pistol * Character::getPistol()
{
	return pistol;
}

Tun * Character::getTun()
{
	return tun;
}

Pusca * Character::getPusca()
{
	return pusca;
}
