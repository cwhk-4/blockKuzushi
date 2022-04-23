#include "main.h"
#include "control.h"

void CONTROL::HitCheckBallAndBar() {
	boundflag=false;
	
	boundflag=ball->GetSoundflag();

	bdx=bar->GetX();
	bdy=bar->GetY();

	blx=ball->GetX();
	bly=ball->GetY();

	if(abs(bdy-bly)<blheight/2+bdheight/2) {
		if(bdx+bdwidth/2>blx &&
			bdx-bdwidth/2<blx) {
			PeforateFlag = false;

			if ( blx > bdx - 20 && blx < bdx + 10 ) {
				PeforateFlag = true;
			}

				if(blx<bdx-bdwidth/2*2/3) {
					ball->SetDX(-1*ball->GetDX());
					ball->SetDY(ball->GetDY()*-1);
					boundflag=true;
				}
				else if(blx>bdx+bdwidth/2*2/3) {
					ball->SetDX(-1*ball->GetDX());
					ball->SetDY(ball->GetDY()*-1);
					boundflag=true;
				}
				else {
					ball->SetDY(ball->GetDY()*-1);
					boundflag=true;
				}
		}
	}
}

void CONTROL::HitCheckBallAndBlock() {
	demolishflag=false;
	
	blx=ball->GetX();
	bly=ball->GetY();

	for(int i=0;i<25;++i) {
		if(!block[i]->GetFlag()) {
			bkx=block[i]->GetX();
			bky=block[i]->GetY();

			if(blx<bkx+bkwidth/2 && blx>bkx-bkwidth/2 &&
				bly+blheight/2>bky-bkheight/2 && bly+blheight/2<bky+bkheight/2) {
					
				block[i]->SetFlag(true);
				demolishflag=true;

				if (!PeforateFlag) {
					ball->SetDY(ball->GetDY()*-1);					
				}

			}
			else if(blx<bkx+bkwidth/2 && blx>bkx-bkwidth/2 &&
					bly-blheight/2>bky-bkheight/2 && bly-blheight/2<bky+bkheight/2) {
					
					block[i]->SetFlag(true);
					demolishflag=true;

					if ( !PeforateFlag ) {
						ball->SetDY( ball->GetDY( ) * -1 );
					}

			}
			else if(blx+blwidth/2<bkx-bkwidth/2+blwidth && blx+blwidth/2>bkx-bkwidth/2 &&
					bly>bky-bkheight/2 && bly<bky+bkheight/2) {
					
					block[i]->SetFlag(true);
					demolishflag=true;

					if ( !PeforateFlag ) {
						ball->SetDX( ball->GetDX( ) * -1 );
					}

			}
			else if(blx-blwidth/2<bkx+bkwidth/2 && blx-blwidth/2>bkx+bkwidth/2-blwidth &&
					bly>bky-bkheight/2 && bly<bky+bkheight/2) {
					
					block[i]->SetFlag(true);
					demolishflag=true;
					if ( !PeforateFlag ) {
						ball->SetDX( ball->GetDX( ) * -1 );
					}

			}
		}
	}
}



void CONTROL::SoundPlay() {
	
	if(boundflag) {
		PlaySoundMem(bh,DX_PLAYTYPE_BACK);
	}

	if(demolishflag) {
		PlaySoundMem(dh,DX_PLAYTYPE_BACK);
	}

}

void CONTROL::CheckBlock( ) {
	
	setClearFlag( false );

	bool flag = false;

	for ( int i = 0; i < 25; ++i ) {
		flag = block[ i ]->GetFlag( );

		if ( !flag ) {
			return;
		}
	}

	setClearFlag( true );
}

void CONTROL::setClearFlag( bool flag ) {
	ClearFlag = flag;
}


bool CONTROL::All() {
	bool back;

	for(int i=0;i<25;++i) {
		block[i]->All();
	}

	bar->All();

	back=ball->All();

	HitCheckBallAndBar();

	HitCheckBallAndBlock();

	CheckBlock( );

	SoundPlay();

	return back;
}

bool CONTROL::getClearFlag( ) {
	return ClearFlag;
}

void CONTROL::Init( ) {

	if ( CheckHitKey( KEY_INPUT_SPACE ) == 0 ) {
		DrawString( WIDTH / 2 - 100, HEIGHT / 2 + 100, "Space‚ðƒNƒŠƒbƒN‚µ‚Ä‚â‚è’¼‚µ", GetColor( 255, 255, 255 ) );
	}
	else {
		for ( int i = 0; i < 25; i++ ) {
			block[ i ]->SetFlag( false );
		}

		ball->Init( );

		ClearFlag = false;

		PeforateFlag = false;
	}

}


CONTROL::CONTROL() {

	bar = new BAR;
	ball = new BALL;

	boundflag=false;
	demolishflag=false;

	bdwidth=bar->GetWidth();
	bdheight=bar->GetHeight();

	blwidth=ball->GetWidth();
	blheight=ball->GetHeight();

	bh = LoadSoundMem("bound.wav");
	dh = LoadSoundMem("demolish.wav");

	int row = 0;

	for ( int i = 0; i < 25; ++i ) {
		if ( i % 5 == 0 ) {
			row += 1;
		}

		block[ i ] = new BLOCK( "block.bmp", 60 + ( 25 + 100 ) * ( i % 5 ), 50 * row );
	}

	bkwidth=block[0]->GetWidth();
	bkheight=block[0]->GetHeight();

	ClearFlag = false;

}

CONTROL::~CONTROL() {

	delete bar;
	delete ball;

	for(int i=0;i<12;++i) {
		delete block[i];
	}

}
