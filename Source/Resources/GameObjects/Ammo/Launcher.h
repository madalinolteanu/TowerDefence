#pragma once
#include <Resources\GameObjects\Ammo\Ammunition\Ghiulea.h>
#include <vector>

using namespace std;

class Launcher
{
public:
	Launcher();
	~Launcher();

private:
	vector <Ghiulea*> ghiuleaList;
};