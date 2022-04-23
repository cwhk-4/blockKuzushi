#include "main.h"
#include "bar.h"
#include "ball.h"
#include "block.h"

class CONTROL {
private:
	BAR *bar;
	BALL *ball;
	BLOCK *block[25];

	int bdx,bdy,blx,bly,bkx,bky;
	int bdwidth,bdheight,blwidth,blheight,bkwidth,bkheight;
	bool boundflag,demolishflag;
	int bh,dh;
	bool ClearFlag;
	bool PeforateFlag;

private:
	void HitCheckBallAndBar();
	void HitCheckBallAndBlock();
	void SoundPlay();
	void CheckBlock( );
	void setClearFlag( bool flag );
	
public:
	bool All();
	bool getClearFlag( );
	void Init( );
	CONTROL();
	~CONTROL();
};


	