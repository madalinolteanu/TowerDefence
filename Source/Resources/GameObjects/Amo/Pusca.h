#pragma once
#include <Resources\GameObjects\Amo\Ammunition\Bullet.h>

using namespace std;

class Pusca
{
public:
	Pusca();
	~Pusca();

private:
	vector<Bullet*> bulletList;
};