#include "Tower.h"

using namespace std;

Tower::Tower()
{
}

Tower::~Tower()
{
}

void Tower::setX(float x) {
	this->x = x;
}

float Tower::getX() {
	return x;
}


void Tower::setY(float y) {
	this->y = y;
}

float Tower::getY() {
	return y;
}


void Tower::setZ(float z) {
	this->y = y;
}

float Tower::getZ() {
	return z;
}


void Tower::setAngle(float angle) {
	this->angle = angle;
}

float Tower::getAngle() {
	return angle;
}


void Tower::setNGhiulea(int ghiulele) {
	this->numGhiulele = ghiulele;
}

int Tower::getNGhiulea() {
	return numGhiulele;
}


//void Bullet::setName(std::string name) {
//	this->name = name;
//}
//
//std::string Bullet::getName() {
//	return name;
//}
//
//
//void Bullet::setBulletSpeed(float speed) {
//	this->speed = speed;
//}
//
//float Bullet::getBulletSpeed() {
//	return speed;
//}
//
//
//void Bullet::setDim(float dim) {
//	this->dim = dim;
//}
//
//float Bullet::getDim() {
//	return dim;
//}
//
//
//void Bullet::setColor(glm::vec3 color) {
//	this->color = color;
//}
//
//glm::vec3 Bullet::getColor() {
//	return color;
//}