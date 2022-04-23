#include "main.h"
#include "ball.h"

BALL::BALL() {

	gh = LoadGraph("ball.bmp");

	GetGraphSize(gh,&width,&height);

	y=410-height/2;
	x=WIDTH/2;

	dx=3;
	dy=-3;

	endflag=false;
	soundflag=false;

}

void BALL::Draw() {
	DrawGraph(x-width/2,y-height/2,gh,TRUE);
}

void BALL::Move() {

	soundflag=false;

	x+=dx;
	y+=dy;


	if(x<width/2) {
		x=width/2;
		dx*=-1;
		soundflag=true;
	}

	if(x>WIDTH-width/2) {
		x=WIDTH-width/2;
		dx*=-1;
		soundflag=true;
	}

	if(y<height/2) {
		y=height/2;
		dy*=-1;
		soundflag=true;
	}

	if(y>HEIGHT) {
		endflag=true;
	}

}

int BALL::GetX() {
	return x;
}

int BALL::GetY() {
	return y;
}

void BALL::SetDX(int x) {
	dx = x;
}

void BALL::SetDY(int y) {
	dy= y;
}

int BALL::GetDX() {
	return dx;
}


int BALL::GetDY() {
	return dy;
}


int BALL::GetWidth() {
	return width;
}

int BALL::GetHeight() {
	return height;
}

bool BALL::GetSoundflag() {
	return soundflag;
}

void BALL::Init( ) {

	y = 410 - height / 2;

	x = WIDTH / 2;

	dx = 3;
	dy = -3;

	endflag = false;

}

bool BALL::All() {

	Move();

	Draw();

	return endflag;

}


void BALL::Destroy() {

}


BALL::~BALL() {
	Destroy();
}
