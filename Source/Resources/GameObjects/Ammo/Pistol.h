#pragma once
#include <Resources\GameObjects\Ammo\Ammunition\Bullet.h>
#include <vector>
using namespace std;

class Pistol
{
public:
	Pistol();
	~Pistol();

private:
	vector<Bullet*> bulletList;
	
};