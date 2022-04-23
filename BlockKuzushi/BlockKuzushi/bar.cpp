#include "bar.h"

BAR::BAR() {

	gh = LoadGraph("bar.bmp");

	GetGraphSize(gh, &width, &height);

	y = 460;

	x = WIDTH / 2;

	endflag = false;

}

void BAR::Draw() {
	DrawGraph(x - width / 2, y - height / 2, gh, TRUE);
}

void BAR::KeyGet() {
	
	if (key[KEY_INPUT_LEFT] == 1) {
		x -= SPEED;
	}

	if (key[KEY_INPUT_RIGHT] == 1) {
		x += SPEED;
	}

	if (key[KEY_INPUT_ESCAPE] == 1) {
		endflag = true;
	}

	if (x < width / 2){
		x = width / 2;
	}
	
	if (x > WIDTH - width / 2){
		x = WIDTH - width / 2;
	}
		
}

int BAR::GetX() {
	return x;
}

int BAR::GetY() {
	return y;
}

int BAR::GetWidth() {
	return width;

}

int BAR::GetHeight() {
	return height;
}

bool BAR::All() {

	KeyGet();

	Draw();

	return endflag;

}


void BAR::Destroy() {

}


BAR::~BAR() {
	Destroy();
}
