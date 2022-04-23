#include "main.h"


class BALL{
private:
	int x,y;
	int dx,dy;
	int width,height;

	bool endflag;
	bool soundflag;

	int gh;

private:
	void Draw();
	void Destroy();
	void Move();

public:
	BALL();
	~BALL();
	bool All();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	void SetDX(int);
	void SetDY(int);
	int GetDX();
	int GetDY();
	bool GetSoundflag();
	void Init( );
};
