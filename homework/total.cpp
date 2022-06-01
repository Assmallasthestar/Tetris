#include "total.h"

void singlemodeoperate(bool flag)
{
	initializegrid();
	if (flag == TRUE)
	{
		srand((unsigned)time(NULL));
		int z = rand() % 7;
		nowcolor = z;
		nextcolor = z;
		nextblock();
		Sleep(1000);
		memset(gridnum, 0, sizeof(gridnum));
	}
	else {
		loadfile();
		clearnextblock(390, 330, 590, 510);
		drawblock(420, 360, nextindex, nextcolor);
		drawblock(beginx+(continuex-EXTRA)*BLOCKSIZE, beginy+continuey*BLOCKSIZE, nowindex, nowcolor);
		Sleep(100);
		move(continuex-EXTRA- (GRIDNUMX - EXTRA) / 2,continuey);
	}
	BeginBatchDraw();
	while (true)
	{
		FlushBatchDraw();
		if (nowblock() == TRUE)
		{
			break;
		}
	}
	EndBatchDraw();
}
void doublemodeoperate()
{
	doubleinitialize();
	srand((unsigned)time(NULL));
	int z = rand() % 7;
	doublenowcolor1 = z;
	doublenextcolor1 = z;
	srand((unsigned)time(NULL));
	z = rand() % 7;
	doublenowcolor2 = z;
	doublenextcolor2 = z;
	doublenextblock(2);
	Sleep(1000);
	memset(doublegridnum1, 0, sizeof(doublegridnum1));
	memset(doublegridnum2, 0, sizeof(doublegridnum2));
	BeginBatchDraw();
	int flag=2;
	while (true)
	{
		FlushBatchDraw();
		int flag1 = doublenowblock(flag);
		if (flag1 == 1)
		{
			flag = 1;
		}
		else if(flag1==0) {
			flag = 0;
		}
		else if (flag1 == 2)
		{
			flag = 2;
		}
		else if (flag1 == 3)
		{
			break;
		}
	}
	EndBatchDraw();
}
void listoperate() 
{
	readrank();
	ExMessage msg;
	while (true)
	{
		if(peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN && msg.x > 0 && msg.y > 0 && msg.x < 55 && msg.y < 55)
		{
			return;
		}
	}
}
void maininterface()
{
	initgraph(640, 360, SHOWCONSOLE);	// 创建绘图窗口，大小为 640x360 像素
	setbkmode(TRANSPARENT);
	BGM();
	BACKGROUND();
	button(242, 150, 150, 40, "单人模式");
	button(242, 200, 150, 40, "双人模式");
	button(242, 250, 150, 40, "排行榜");
}
void buttonhit()
{
	int flag = 1;//flag为0时为mute，为1时为sound
	//FlushBatchDraw();
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (msg.message == WM_LBUTTONDOWN && msg.x > 242 && msg.y > 150 && msg.x < 392 && msg.y < 190)
			{
				BOOL flag1 = newcontinue();
				//背景
				initgraph(640, 720, SHOWCONSOLE);
				setbkmode(TRANSPARENT);
				setbkcolor(WHITE);
				clearcliprgn();
				singlemode();
				singlemodeoperate(flag1);
				return;
			}
			else if (msg.message == WM_LBUTTONDOWN && msg.x > 242 && msg.y > 200 && msg.x < 392 && msg.y < 240)
			{
				//背景
				initgraph(1280, 720, SHOWCONSOLE);
				setbkmode(TRANSPARENT);
				setbkcolor(WHITE);
				clearcliprgn();
				doublemode();
				doublemodeoperate();
				IMAGE victory, failure;
				loadimage(&victory, "VICTORY.jpg", 350, 200);
				loadimage(&failure, "FAILURE.jpg", 350, 200);
				if (winflag == 1)
				{
					doublemode();
					doubledrawgrid();
					putimage(40, 260, &victory);
					putimage(890, 260, &failure);
					Sleep(3000);
				}
				else if (winflag == 2)
				{
					doublemode();
					doubledrawgrid();
					putimage(40, 260, &failure);
					putimage(890, 260, &victory);
					Sleep(3000);
				}
				return;
			}
			else if (msg.message == WM_LBUTTONDOWN && msg.x > 242 && msg.y > 250 && msg.x < 392 && msg.y < 290)
			{
				initgraph(320, 720, SHOWCONSOLE);
				setbkmode(TRANSPARENT);
				setbkcolor(WHITE);
				clearcliprgn();
				list();
				listoperate();
				return;
			}
			else if (msg.message == WM_LBUTTONDOWN && msg.x > 580 && msg.y > 0 && msg.x < 640 && msg.y < 60 && flag == 1)
			{
				mciSendString("stop BGM.mp3", NULL, 0, NULL);
				IMAGE mute;
				loadimage(&mute, "mute.png", 40, 40);
				putimage(600, 0, &mute);
				flag = 0;
			}
			else if (msg.message == WM_LBUTTONDOWN && msg.x > 580 && msg.y > 0 && msg.x < 640 && msg.y < 60 && flag == 0)
			{
				mciSendString("play BGM.mp3 repeat", NULL, 0, NULL);
				IMAGE sound;
				loadimage(&sound, "sound.png", 40, 40);
				putimage(600, 0, &sound);
				flag = 1;
			}
		}
	}
}