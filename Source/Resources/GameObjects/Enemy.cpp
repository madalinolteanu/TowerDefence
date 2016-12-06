#include "Enemy.h"

using namespace std;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::setX(float x) {
	this->x = x;
}

float Enemy::getX() {
	return x;
}


void Enemy::setY(float y) {
	this->y = y;
}

float Enemy::getY() {
	return y;
}


void Enemy::setZ(float z) {
	this->y = y;
}

float Enemy::getZ() {
	return z;
}


void Enemy::setAngle(float angle) {
	this->angle = angle;
}

float Enemy::getAngle() {
	return angle;
}


void Enemy::setNumLifes(int ghiulele) {
	this->numLifes = ghiulele;
}

int Enemy::getNumLifes() {
	return numLifes;
}