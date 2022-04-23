#include "main.h"
#include "control.h"

char key[256];

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)

{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	ChangeWindowMode(TRUE);


	if (DxLib_Init() == -1) {
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	CONTROL* control = new CONTROL;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {

		if (control->All()) {
			control->Init( );
		}

		if ( control->getClearFlag( ) ) {
			control->Init( );
		}

	}

	DxLib_End();

	delete control;

	return 0;
}