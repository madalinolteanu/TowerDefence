#pragma once
#include <Resources\GameObjects\Amo\Ammunition\Ghiulea.h>
using namespace std;

class Tun
{
public:
	Tun();
	~Tun();

private:
	vector<Ghiulea*> ghiuleaList;
};