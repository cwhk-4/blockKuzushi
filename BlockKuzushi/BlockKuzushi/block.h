#include "main.h"


class BLOCK{
private:
	int x,y;
	int width,height;
	bool endflag;
	static	int gh;
	int count;

private:
	void Draw();

public:
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	void SetFlag(bool);
	bool GetFlag();
	BLOCK(const char *,int,int);
	void All();
};
