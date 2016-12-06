#pragma once
#include <Resources\GameObjects\Ammo\Ammunition\Bullet.h>
#include <vector>

using namespace std;

class Gun
{
public:
	Gun();
	~Gun();

private:
	vector<Bullet*> bulletList;
};