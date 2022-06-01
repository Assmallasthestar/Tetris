#include"total.h"

int main()
{
	while (true)
	{
		maininterface();
		buttonhit();
	}
	//“Ù¿÷≤•∑≈≤‚ ‘
	/*char buf[100] = "";
	char buf1[100] = "";
	DWORD m1 = mciSendString("open BGM.mp3", NULL, 0, NULL);
	int temp = mciGetErrorString(m1, buf, 100);
	DWORD m2 = mciSendString("play BGM.mp3", NULL, 0, NULL);
	mciGetErrorString(m2, buf, 100);
	printf("m1-%u,m2-%u temp: %d\n", m1, m2, temp);
	printf("%s\n%s\n", buf, buf1);*/
	return 0;
}
