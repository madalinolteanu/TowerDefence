#pragma once

class DrawObjects {

public:
	DrawObjects::DrawObjects() {
	}

	DrawObjects::~DrawObjects() {
	}

	void drawObjects() {
		drawEnemy();
		drawCharacter();
		drawTower();
	}

	void drawEnemy();
	void drawCharacter();
	void drawTower();


};
