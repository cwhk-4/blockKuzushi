#pragma once

#include "main.h"

#define SPEED 4

class BAR {
private:
	int x, y;
	int width, height;
	bool endflag;
	int gh;

private:
	void Draw();
	void KeyGet();
	void Destroy();

public:
	BAR();
	~BAR();
	bool All();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
};

