#include <windows.h>

#define MSG(m) {\
	MessageBox(NULL,m,"���b�Z�[�W",MB_OK);}


#define MSGPLUS(m,...) {\
	char buf[100];\
	sprintf(buf,m,__VA_ARGS__);\
	MessageBox(NULL,buf,"���b�Z�[�W",MB_OK);}


#define WIDTH 640
#define HEIGHT 480

extern char key[256];