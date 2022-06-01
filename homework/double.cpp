#include"double.h"

int doublenowscore1;
int doublenowscore2;
int doublenextindex1;
int doublenowcolor1;
int doublenextcolor1;
int doublenowindex1;
int doublenextindex2;
int doublenowcolor2;
int doublenextcolor2;
int doublenowindex2;
int doublespeed;
int doublegridnum1[DOUBLEGRIDNUMX + EXTRA][DOUBLEGRIDNUMY + EXTRA];
int doublegridcolor1[DOUBLEGRIDNUMX + EXTRA][DOUBLEGRIDNUMY + EXTRA];
int doublegridnum2[DOUBLEGRIDNUMX + EXTRA][DOUBLEGRIDNUMY + EXTRA];
int doublegridcolor2[DOUBLEGRIDNUMX + EXTRA][DOUBLEGRIDNUMY + EXTRA];
int x11;
int y11;
int nowspeed1 ;
int k1;
block_direct nowdirect1;
block_direct nextdirect1 ;
int x22;
int y22 ;
int nowspeed2 ;
int k2;
int winflag;
block_direct nowdirect2;
block_direct nextdirect2 ;
//queue<int> B1;
//queue<int> B2;

void doubledrawgrid()
{
	for (int i = EXTRA;i < DOUBLEGRIDNUMX + EXTRA;i++)
	{
		for (int j = EXTRA;j < DOUBLEGRIDNUMY + EXTRA;j++)
		{
			if (doublegridnum1[i][j])
			{
				setfillcolor(doublegridcolor1[i][j]);
				int x1 = (i - EXTRA) * 20 + DOUBLEBEGINX1;
				int y1 = (j - EXTRA) * 20 + DOUBLEBEGINY1;
				int x2 = (i + 1 - EXTRA) * 20 + DOUBLEBEGINX1;
				int y2 = (j + 1 - EXTRA) * 20 + DOUBLEBEGINY1;
				fillrectangle(x1, y1, x2, y2);
			}
			if (doublegridnum2[i][j])
			{
				setfillcolor(doublegridcolor2[i][j]);
				int x1 = (i - EXTRA) * 20 + DOUBLEBEGINX2;
				int y1 = (j - EXTRA) * 20 + DOUBLEBEGINY1;
				int x2 = (i + 1 - EXTRA) * 20 + DOUBLEBEGINX2;
				int y2 = (j + 1 - EXTRA) * 20 + DOUBLEBEGINY1;
				fillrectangle(x1, y1, x2, y2);
			}
			setlinecolor(MYWHITE);
			int x1 = (i - EXTRA) * 20 + DOUBLEBEGINX1;
			int y1 = (j - EXTRA) * 20 + DOUBLEBEGINY1;
			int x2 = (i + 1 - EXTRA) * 20 + DOUBLEBEGINX1;
			int y2 = (j + 1 - EXTRA) * 20 + DOUBLEBEGINY1;
			rectangle(x1, y1, x2, y2);
			x1 = (i - EXTRA) * 20 + DOUBLEBEGINX2;
			y1 = (j - EXTRA) * 20 + DOUBLEBEGINY1;
			x2 = (i + 1 - EXTRA) * 20 + DOUBLEBEGINX2;
			y2 = (j + 1 - EXTRA) * 20 + DOUBLEBEGINY1;
			rectangle(x1, y1, x2, y2);
		}
	}
}
void doubleinitialize()
{
	doublenowscore1 = 0;
	doublenowscore2 = 0;
	doublenextindex1=-1;
	doublenowcolor1=-1;
	doublenextcolor1=-1;
	doublenowindex1=-1;
	doublenextindex2=-1;
	doublenowcolor2=-1;
	doublenextcolor2=-1;
	doublenowindex2=-1;
	doublespeed = 100;
	x11 = DOUBLEBEGINX1 + DOUBLEBLOCKSIZE*9;
	y11 = DOUBLEBEGINY;
	nowspeed1 = doublespeed;
	k1 = 0;
	nowdirect1 = BLOCK_UP;
	nextdirect1 = BLOCK_RIGHT;
	x22 = DOUBLEBEGINX2 + DOUBLEBLOCKSIZE*9;
	y22= DOUBLEBEGINY;
	nowspeed2 = doublespeed;
	k2 = 0;
	nowdirect2 = BLOCK_UP;
	nextdirect2 = BLOCK_RIGHT;
	for (int i = EXTRA;i < DOUBLEGRIDNUMX + EXTRA;i++)
	{
		for (int j = EXTRA;j < DOUBLEGRIDNUMY + EXTRA;j++)
		{
			doublegridcolor1[i][j] = MYWHITE;
			doublegridnum1[i][j] = 0;
			doublegridcolor2[i][j] = MYWHITE;
			doublegridnum2[i][j] = 0;
			setlinecolor(doublegridcolor1[i][j]);
			int x1 = (i - EXTRA) * 20 + DOUBLEBEGINX1;
			int y1 = (j - EXTRA) * 20 + DOUBLEBEGINY1;
			int x2 = (i+1 - EXTRA) * 20 + DOUBLEBEGINX1;
			int y2 = (j+1 - EXTRA) * 20 + DOUBLEBEGINY1;
			rectangle(x1,y1,x2,y2);
			x1 = (i - EXTRA) * 20 + DOUBLEBEGINX2;
			y1 = (j - EXTRA) * 20 + DOUBLEBEGINY1;
			x2 = (i + 1 - EXTRA) * 20 + DOUBLEBEGINX2;
			y2 = (j + 1 - EXTRA) * 20 + DOUBLEBEGINY1;
			rectangle(x1, y1, x2, y2);
		}
	}
	for (int i = 0;i < DOUBLEGRIDNUMX + EXTRA;i++)
	{
		for (int j = 0;j < DOUBLEGRIDNUMY + EXTRA;j++)
		{
			doublegridcolor1[i][j] = MYWHITE;
			doublegridnum1[i][j] = 0;
			doublegridcolor2[i][j] = MYWHITE;
			doublegridnum2[i][j] = 0;
		}
	}
}
BOOL doubleremovable(int x0, int y0, block_direct removedirect,int index,const int flag0)
{
	int x;
	if (flag0 == 0)
	{
		x = (x0 - DOUBLEBEGINX1) / DOUBLEBLOCKSIZE;
	}
	else {
		x = (x0 - DOUBLEBEGINX2) / DOUBLEBLOCKSIZE;
	}
	int y = (y0 - DOUBLEBEGINY1) / DOUBLEBLOCKSIZE;
	int flag = 1;
	if (removedirect == BLOCK_LEFT)
	{
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				if (flag0 == 0)
				{
					if (block[index][i][j] == 1 && (x + i == 0 || doublegridnum1[x + i - 1 + EXTRA][y + j + EXTRA] == 1))
					{
						flag = 0;
					}
				}
				else if(flag0==1)
				{
					if (block[index][i][j] == 1 && (x + i == 0 || doublegridnum2[x + i - 1 + EXTRA][y + j + EXTRA] == 1))
					{
						flag = 0;
					}
				}
				
			}
		}
	}
	else if (removedirect == BLOCK_RIGHT)
	{
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				if (flag0 == 0) 
				{
					if (block[index][i][j] == 1 && (x + i >= DOUBLEGRIDNUMX-1 || doublegridnum1[x + i + 1 + EXTRA][y + j + EXTRA] == 1))
					{
						flag = 0;
					}
				}
				else if (flag0 == 1)
				{
					if (block[index][i][j] == 1 && (x + i >= DOUBLEGRIDNUMX - 1 || doublegridnum2[x + i + 1 + EXTRA][y + j + EXTRA] == 1))
					{
						flag = 0;
					}
				}
				
			}
		}
	}
	else if (removedirect == BLOCK_DOWN)
	{
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				if (flag0 == 0)
				{
					if (block[index][i][j] == 1 && (y + j + 1 >= DOUBLEGRIDNUMY || doublegridnum1[x + i + EXTRA][y + j + 1 + EXTRA] == 1))
					{
						return 0;
					}
				}
				else if (flag0 == 1)
				{
					if (block[index][i][j] == 1 && (y + j + 1 >= DOUBLEGRIDNUMY || doublegridnum2[x + i + EXTRA][y + j + 1 + EXTRA] == 1))
					{
						return 0;
					}
				}
				
			}
		}
	}
	return flag;
}
BOOL doubleturnto(int x0, int y0,int index,const int flag0)
{
	int x ;
	if (flag0 == 0)
	{
		x = (x0 - DOUBLEBEGINX1) / DOUBLEBLOCKSIZE;
	}
	else {
		x = (x0 - DOUBLEBEGINX2) / DOUBLEBLOCKSIZE;
	}
	int y = (y0 - DOUBLEBEGINY1) / DOUBLEBLOCKSIZE;
	int flag = 1;
	if (!doubleremovable(x0, y0, BLOCK_DOWN,index,flag0))
	{
		return 0;
	}
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (flag0 == 0)
			{
				if (block[(index + 1) % 4 + index / 4 * 4][i][j] == 1 && (x + i < 0 || x + i >= DOUBLEGRIDNUMX || y + j < 0 || y + j >= DOUBLEGRIDNUMY || doublegridnum1[x + i + EXTRA][y + j + EXTRA] == 1))
				{
					flag = 0;
				}
			}
			else if (flag0 == 1)
			{
				if (block[(index + 1) % 4 + index / 4 * 4][i][j] == 1 && (x + i < 0 || x + i >= DOUBLEGRIDNUMX || y + j < 0 || y + j >= DOUBLEGRIDNUMY || doublegridnum2[x + i + EXTRA][y + j + EXTRA] == 1))
				{
					flag = 0;
				}
			}
			
		}
	}
	return flag;
}
void doublemark(int x0, int y0,const int flag0)
{
	int x;
	if (flag0 == 0)
	{
		x = (x0 - DOUBLEBEGINX1) / DOUBLEBLOCKSIZE;
	}
	else {
		x = (x0 - DOUBLEBEGINX2) / DOUBLEBLOCKSIZE;
	}
	int y = (y0 - DOUBLEBEGINY1) / DOUBLEBLOCKSIZE;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (flag0==0&&block[doublenowindex1][i][j] == 1)
			{
				doublegridnum1[x + i + EXTRA][y + j + EXTRA] = 1;
				doublegridcolor1[x + i + EXTRA][y + j + EXTRA] = blockcolor[doublenowcolor1];
			}
			else if (flag0 == 1 && block[doublenowindex2][i][j] == 1)
			{
				doublegridnum2[x + i + EXTRA][y + j + EXTRA] = 1;
				doublegridcolor2[x + i + EXTRA][y + j + EXTRA] = blockcolor[doublenowcolor2];
			}
		}
	}
}
BOOL doubleend()
{
	int flag1 = doubleremovable(x11, y11, BLOCK_DOWN, doublenowindex1, 0);
	int flag2 = doubleremovable(x22, y22, BLOCK_DOWN, doublenowindex2, 1);
	//IMAGE victory, failure;
	//loadimage(&victory, "VICTORY.jpg", 350, 200);
	//loadimage(&failure, "FAILURE.jpg", 350, 200);
	if (flag1==0)
	{
		//putimage(40, 260, &failure);
		//putimage(890, 260, &victory);
		winflag = 2;
		return TRUE;
	}
	else if (flag2 == 0)
	{
		//putimage(40, 260, &victory);
		//putimage(890, 260, &failure);
		winflag = 1;
		return TRUE;
	}
	return FALSE;
}
void doublenextblock(const int flag0)
{
	if (flag0 == 0)
	{
		srand((unsigned)time(NULL));
		doublenextindex1 = rand() % 28;
		setfillcolor(blockcolor[doublenextcolor1]);
		for (int i = 0;i <= 4;i++)
		{
			for (int j = 0;j <= 4;j++)
			{
				if (block[doublenextindex1][i][j] == 1 && (360 + j * 30) >= 100)
				{
					int x1 = 465 + i * DOUBLEBLOCKSIZE;
					int y1 = 160 + j * DOUBLEBLOCKSIZE;
					int x2 = 465 + (i + 1) * DOUBLEBLOCKSIZE;
					int y2 = 160 + (j + 1) * DOUBLEBLOCKSIZE;
					fillrectangle(x1, y1, x2, y2);
				}
			}
		}
	}
	else if (flag0 == 1)
	{
		srand((unsigned)time(NULL));
		doublenextindex2 = rand() % 28;
		setfillcolor(blockcolor[doublenextcolor2]);
		for (int i = 0;i <= 4;i++)
		{
			for (int j = 0;j <= 4;j++)
			{
				if (block[doublenextindex2][i][j] == 1 && (360 + j * 30) >= 100)
				{
					int x1 = 735 + i * DOUBLEBLOCKSIZE;
					int y1 = 160 + j * DOUBLEBLOCKSIZE;
					int x2 = 735 + (i + 1) * DOUBLEBLOCKSIZE;
					int y2 = 160 + (j + 1) * DOUBLEBLOCKSIZE;
					fillrectangle(x1, y1, x2, y2);
				}
			}
		}
	}
	else if (flag0 == 2)
	{
		srand((unsigned)time(NULL));
		doublenextindex1 = rand() % 28;
		setfillcolor(blockcolor[doublenextcolor1]);
		for (int i = 0;i <= 4;i++)
		{
			for (int j = 0;j <= 4;j++)
			{
				if (block[doublenextindex1][i][j] == 1 && (360 + j * 30) >= 100)
				{
					int x1 = 465 + i * DOUBLEBLOCKSIZE;
					int y1 = 160 + j * DOUBLEBLOCKSIZE;
					int x2 = 465 + (i + 1) * DOUBLEBLOCKSIZE;
					int y2 = 160 + (j + 1) * DOUBLEBLOCKSIZE;
					fillrectangle(x1, y1, x2, y2);
				}
			}
		}
		srand((unsigned)time(NULL));
		doublenextindex2 = rand() % 28;
		setfillcolor(blockcolor[doublenextcolor2]);
		for (int i = 0;i <= 4;i++)
		{
			for (int j = 0;j <= 4;j++)
			{
				if (block[doublenextindex2][i][j] == 1 && (360 + j * 30) >= 100)
				{
					int x1 = 735 + i * DOUBLEBLOCKSIZE;
					int y1 = 160 + j * DOUBLEBLOCKSIZE;
					int x2 = 735 + (i + 1) * DOUBLEBLOCKSIZE;
					int y2 = 160 + (j + 1) * DOUBLEBLOCKSIZE;
					fillrectangle(x1, y1, x2, y2);
				}
			}
		}
	}
}
void doublemode()
{
	//标题
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, "双人模式");
	IMAGE background2;
	loadimage(&background2, "background2.jpg", 1280, 720);
	putimage(0, 0, &background2);
	//字
	settextstyle(20, 0, FONT);
	settextcolor(RGB(255, 215, 0));
	outtextxy(20, 20, "当前积分");
	outtextxy(1280 - 20 - textwidth("当前积分"), 20, "当前积分");
	settextcolor(RGB(105, 147, 211));
	settextstyle(50, 0, FONT);
	outtextxy(440, 120, "下一个");
	outtextxy(1280 - 440 - textwidth("下一个"), 120, "下一个");
	IMAGE integral11, integral12, integral21, integral22;
	loadimage(&integral21, "integral21.png", 50, 40);
	loadimage(&integral22, "integral22.png", 50, 40);
	putimage(30, 45, &integral22, SRCAND);
	putimage(30, 45, &integral21, SRCPAINT);
	putimage(1280 - 30 - 30 - 20, 45, &integral22, SRCAND);
	putimage(1280 - 30 - 30 - 20, 45, &integral21, SRCPAINT);
	//setfillcolor(BLACK);
	//fillrectangle(390, 170, 590, 370);
	//fillrectangle(1280-590, 170, 1280-390, 370);
	//setfillcolor(BLACK);
	//fillrectangle(100, 15, 180, 85);
	//fillrectangle(1280-180, 15, 1280-100, 85);
	settextstyle(80, 0, FONT);
	settextcolor(RGB(240, 248, 255));
	char str1[30];
	sprintf_s(str1, "%d", doublenowscore2);//将数字格式化输出为字符串
	int tx = 1280 - 180 + (1280 - 100 - (1280 - 180)) / 2 - textwidth(str1) / 2;
	int ty = 50 - textheight(str1) / 2;
	outtextxy(tx + 10, ty + 10, str1);
	sprintf_s(str1, "%d", doublenowscore1);//将数字格式化输出为字符串
	tx = 140 - textwidth(str1) / 2;
	ty = 50 - textheight(str1) / 2;
	outtextxy(tx - 10, ty + 10, str1);
	settextcolor(RGB(240, 248, 255));
	settextstyle(40, 0, FONT);
	outtextxy(195, 15, "左移:A");
	outtextxy(195, 50, "右移:D");
	outtextxy(350, 15, "加速:S");
	outtextxy(350, 50, "旋转:W");
	outtextxy(1280 - 195 - textwidth("左移:←"), 15, "左移:←");
	outtextxy(1280 - 195 - textwidth("右移:→"), 50, "右移:→");
	outtextxy(1280 - 350 - textwidth("加速:↓"), 15, "加速:↓");
	outtextxy(1280 - 350 - textwidth("旋转:↑"), 50, "旋转:↑");
	outtextxy(640 - textwidth("暂停:空格") / 2, 15, "暂停:空格");
	outtextxy(640 - textwidth("返回:Esc") / 2, 50, "返回:Esc");
}
void doubledown(const int flag0)
{
	for (int i = DOUBLEGRIDNUMY + EXTRA - 1;i >= EXTRA;i--)
	{
		int flag = 1;
		for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
		{
			if (flag0==0&&doublegridnum1[j][i] != 1)
			{
				flag = 0;
			}
			if (flag0 == 1 && doublegridnum2[j][i] != 1)
			{
				flag = 0;
			}
		}
		if (flag0==0&&flag == 1)
		{
			doublenowscore1 += 10;
			for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
			{
				doublegridnum1[j][i] = 0;
				doublegridcolor1[j][i] = MYWHITE;
				FlushBatchDraw();
				doublemode();
				doubledrawgrid();
			}
			for (int y = i;y >= EXTRA;y--)
			{
				for (int x = EXTRA;x < DOUBLEGRIDNUMX + EXTRA;x++)
				{
					doublegridnum1[x][y] = doublegridnum1[x][y - 1];
					doublegridnum1[x][y - 1] = 0;
					doublegridcolor1[x][y] = doublegridcolor1[x][y - 1];
					doublegridcolor1[x][y - 1] = MYWHITE;
					if (doublegridnum1)
					{
						setfillcolor(doublegridcolor1[x][y]);
						fillrectangle((x - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX1, (y - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1, (x - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX1 + DOUBLEBLOCKSIZE, (y - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1 + DOUBLEBLOCKSIZE);
					}
				}
			}
			for (int y = EXTRA;y <DOUBLEGRIDNUMY+EXTRA-1;y++)
			{
				for (int x = EXTRA;x < DOUBLEGRIDNUMX + EXTRA;x++)
				{
					doublegridnum2[x][y] = doublegridnum2[x][y + 1];
					doublegridcolor2[x][y] = doublegridcolor2[x][y + 1];
					if (doublegridnum2[x][y])
					{
						setfillcolor(doublegridcolor2[x][y]);
						fillrectangle((x - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX2, (y - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1, (x - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX2 + DOUBLEBLOCKSIZE, (y - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1 + DOUBLEBLOCKSIZE);
					}
				}
			}
			for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
			{
				srand((unsigned)time(NULL));
				doublegridnum2[j][DOUBLEGRIDNUMY+EXTRA-1] = rand()%2;
				doublegridcolor2[j][DOUBLEGRIDNUMY + EXTRA - 1] = RGB(112, 128, 114);
			}
			int flag1 = 1;
			int flag2 = 1;
			for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
			{
				if (doublegridnum2[j][DOUBLEGRIDNUMY + EXTRA - 1]==0)
				{
					flag1=0;
				}
				if (doublegridnum2[j][DOUBLEGRIDNUMY + EXTRA - 1] == 1)
				{
					flag2 = 0;
				}
			}
			srand((unsigned)time(NULL));
			if (flag1 == 1)
			{
				int p = rand() % (DOUBLEGRIDNUMX + EXTRA);
				doublegridnum2[p][DOUBLEGRIDNUMY + EXTRA - 1] = 0;
				doublegridcolor2[p][DOUBLEGRIDNUMY + EXTRA - 1] = RGB(112, 128, 114);
			}
			if (flag2 == 1)
			{
				int p = rand() % (DOUBLEGRIDNUMX + EXTRA);
				doublegridnum2[p][DOUBLEGRIDNUMY + EXTRA - 1] = 1;
				doublegridcolor2[p][DOUBLEGRIDNUMY + EXTRA - 1] = RGB(112, 128, 114);
			}
			for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
			{
				if (doublegridnum2[j][DOUBLEGRIDNUMY + EXTRA - 1] == 1)
				{
					doublegridcolor2[j][0] = RGB(112, 128, 114);
					setfillcolor(doublegridcolor2[j][0]);
					fillrectangle((j - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX2, (DOUBLEGRIDNUMY + EXTRA - 1 - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1, (j - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX2 + DOUBLEBLOCKSIZE, (DOUBLEGRIDNUMY + EXTRA - 1 - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1 + DOUBLEBLOCKSIZE);
				}
				else {
					doublegridcolor2[j][DOUBLEGRIDNUMY + EXTRA - 1] = MYWHITE;
				}
			}
			i++;
		}
		if (flag0 == 1 && flag == 1)
		{
			doublenowscore2 += 10;
			FlushBatchDraw();
			doublemode();
			doubledrawgrid();
			//scoregrade(100, 15, 80, 70, 0);
			//scoregrade(410, 170, 150, 100, 1);
			for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
			{
				doublegridnum2[j][i] = 0;
				doublegridcolor2[j][i] = MYWHITE;
				FlushBatchDraw();
				doublemode();
				doubledrawgrid();
			}
			for (int y = i;y >= EXTRA;y--)
			{
				for (int x = EXTRA;x < DOUBLEGRIDNUMX + EXTRA;x++)
				{
					doublegridnum2[x][y] = doublegridnum2[x][y - 1];
					doublegridnum2[x][y - 1] = 0;
					doublegridcolor2[x][y] = doublegridcolor2[x][y - 1];
					doublegridcolor2[x][y - 1] = MYWHITE;
					if (doublegridnum2[x][y])
					{
						setfillcolor(doublegridcolor2[x][y]);
						fillrectangle((x - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX2, (y - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1, (x - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX2 + DOUBLEBLOCKSIZE, (y - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1 + DOUBLEBLOCKSIZE);
					}
				}
			}
			for (int y = EXTRA;y < DOUBLEGRIDNUMY + EXTRA - 1;y++)
			{
				for (int x = EXTRA;x < DOUBLEGRIDNUMX + EXTRA;x++)
				{
					doublegridnum1[x][y] = doublegridnum1[x][y + 1];
					doublegridcolor1[x][y] = doublegridcolor1[x][y + 1];
					if (doublegridnum1[x][y])
					{
						setfillcolor(doublegridcolor1[x][y]);
						fillrectangle((x - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX1, (y - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1, (x - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX1 + DOUBLEBLOCKSIZE, (y - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1 + DOUBLEBLOCKSIZE);
					}
				}
			}
			for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
			{
				srand((unsigned)time(NULL));
				doublegridnum1[j][DOUBLEGRIDNUMY + EXTRA - 1] = rand() % 2;
				doublegridcolor2[j][DOUBLEGRIDNUMY + EXTRA - 1] = RGB(112, 128, 114);
			}
			int flag1 = 1;
			int flag2 = 1;
			for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
			{
				if (doublegridnum1[j][DOUBLEGRIDNUMY + EXTRA - 1] == 0)
				{
					flag1 = 0;
				}
				if (doublegridnum1[j][DOUBLEGRIDNUMY + EXTRA - 1] == 1)
				{
					flag2 = 0;
				}
			}
			srand((unsigned)time(NULL));
			if (flag1 == 1)
			{
				int p = rand() % (DOUBLEGRIDNUMX + EXTRA);
				doublegridnum1[p][DOUBLEGRIDNUMY + EXTRA - 1] = 0;
				doublegridcolor1[p][DOUBLEGRIDNUMY + EXTRA - 1] = RGB(112, 128, 114);
			}
			if (flag2 == 1)
			{
				int p = rand() % (DOUBLEGRIDNUMX + EXTRA);
				doublegridnum1[p][DOUBLEGRIDNUMY + EXTRA - 1] = 1;
				doublegridcolor1[p][DOUBLEGRIDNUMY + EXTRA - 1] = RGB(112, 128, 114);
			}
			for (int j = EXTRA;j < DOUBLEGRIDNUMX + EXTRA;j++)
			{
				if (doublegridnum1[j][DOUBLEGRIDNUMY + EXTRA - 1] == 1)
				{
					doublegridcolor1[j][DOUBLEGRIDNUMY + EXTRA - 1] = RGB(112, 128, 114);
					setfillcolor(doublegridcolor1[j][0]);
					fillrectangle((j - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX2, (DOUBLEGRIDNUMY + EXTRA - 1 - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1, (j - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINX2 + DOUBLEBLOCKSIZE, (DOUBLEGRIDNUMY + EXTRA - 1 - EXTRA) * DOUBLEBLOCKSIZE + DOUBLEBEGINY1 + DOUBLEBLOCKSIZE);
				}
				else {
					doublegridcolor1[j][DOUBLEGRIDNUMY + EXTRA - 1] = MYWHITE;
				}
			}
			i++;
		}
	}
}
void doubledrawblock(int x, int y, int index, int color,const int flag0)
{
	setfillcolor(blockcolor[color]);
	for (int i = 0;i <= 4;i++)
	{
		for (int j = 0;j <= 4;j++)
		{
			if (flag0 == 0)
			{
				if (block[index][i][j] == 1 && (y + j * 20) >= 100)
				{
					int x1 = x + i * DOUBLEBLOCKSIZE;
					int y1 = y + j * DOUBLEBLOCKSIZE;
					int x2= x + (i+1) * DOUBLEBLOCKSIZE;
					int y2 = y + (j+1) * DOUBLEBLOCKSIZE;
					fillrectangle(x1, y1, x2, y2);
				}
			}
			else if (flag0 == 1)
			{
				if (block[index][i][j] == 1 && (y + j * 20) >= 100)
				{
					int x1 = x + i * DOUBLEBLOCKSIZE;
					int y1 = y + j * DOUBLEBLOCKSIZE;
					int x2 = x + (i + 1) * DOUBLEBLOCKSIZE;
					int y2 = y + (j + 1) * DOUBLEBLOCKSIZE;
					fillrectangle(x1, y1, x2, y2);
				}
			}
			
		}
	}
}
int doublemove()
{
	int flag = 0;
	while (true)
	{
		if (doubleend() == TRUE)
		{
			return 3;
		};
		if (flag != 0)
		{
			FlushBatchDraw();
			doublemode();
			doubledrawgrid();
		}
		flag = 1;
		doubledrawblock(465, 160 , doublenextindex1, doublenextcolor1, 0);
		doubledrawblock(735, 160 , doublenextindex2, doublenextcolor2, 1);
		if (GetAsyncKeyState(VK_UP))
		{
			nextdirect2 = BLOCK_UP;
			if (doubleturnto(x22, y22 + k2,doublenowindex2,1) == 1)
			{
				nowdirect2 = nextdirect2;
				doublenowindex2 = (doublenowindex2 + 1) % 4 + doublenowindex2 / 4 * 4;
				k2 -= DOUBLEBLOCKSIZE;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			nextdirect2 = BLOCK_LEFT;
			if (doubleremovable(x22, y22 + k2, nextdirect2,doublenowindex2,1))
			{
				nowdirect2 = nextdirect2;
				x22 = x22 - DOUBLEBLOCKSIZE;
				k2 -= DOUBLEBLOCKSIZE;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			nextdirect2 = BLOCK_RIGHT;
			if (doubleremovable(x22, y22 + k2, nextdirect2, doublenowindex2, 1))
			{
				nowdirect2 = nextdirect2;
				x22 = x22 + DOUBLEBLOCKSIZE;
				k2 -= DOUBLEBLOCKSIZE;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			nextdirect2 = BLOCK_DOWN;
			if (doubleremovable(x22, y22 + k2 + 20, nextdirect2, doublenowindex2, 1))
			{
				nowdirect2 = nextdirect2;
				k2+=DOUBLEBLOCKSIZE;
			}
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			HWND hwnd = GetHWnd();
			if (!MessageBox(hwnd, "游戏已经暂停\n继续点击确定", "提示", MB_OK))
			{
				printf("pause error");
			}
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			return 3;
		}
		if (GetAsyncKeyState('A') || GetAsyncKeyState('a') )
		{
			nextdirect1 = BLOCK_LEFT;
			if (doubleremovable(x11, y11 + k1, nextdirect1, doublenowindex1, 0))
			{
				nowdirect1 = nextdirect1;
				x11 = x11 - DOUBLEBLOCKSIZE;
				k1 -= DOUBLEBLOCKSIZE;
			}
		}
		else if (GetAsyncKeyState('W') || GetAsyncKeyState('w') )
		{
			nextdirect1 = BLOCK_UP;
			if (doubleturnto(x11, y11 + k1, doublenowindex1, 0) == 1)
			{
				nowdirect1 = nextdirect1;
				doublenowindex1 = (doublenowindex1 + 1) % 4 + doublenowindex1 / 4 * 4;
				k1 -= DOUBLEBLOCKSIZE;
			}
		}
		else if (GetAsyncKeyState('S') || GetAsyncKeyState('s'))
		{
			nextdirect1 = BLOCK_DOWN;
			if (doubleremovable(x11, y11 + k1 + 30, nextdirect1, doublenowindex1, 0))
			{
				nowdirect1 = nextdirect1;
				k1+=DOUBLEBLOCKSIZE;
			}
		}
		else if (GetAsyncKeyState('D') || GetAsyncKeyState('d') )
		{
			nextdirect1 = BLOCK_RIGHT;
			if (doubleremovable(x11, y11 + k1, nextdirect1, doublenowindex1, 0))
			{
				nowdirect1 = nextdirect1;
				x11 = x11 + DOUBLEBLOCKSIZE;
				k1 -= DOUBLEBLOCKSIZE;
			}
		}
		k1 += DOUBLEBLOCKSIZE;
		doubledrawblock(x11, y11 + k1, doublenowindex1, doublenowcolor1, 0);
		k2 += DOUBLEBLOCKSIZE;
		doubledrawblock(x22, y22 + k2, doublenowindex2, doublenowcolor2, 1);
		Sleep(nowspeed1);
		nowspeed1 = doublespeed;
		nowspeed2 = doublespeed;
		if (!doubleremovable(x11, y11 + k1, BLOCK_DOWN, doublenowindex1, 0) && !doubleremovable(x22, y22 + k2, BLOCK_DOWN, doublenowindex2, 1))
		{
			doublemark(x11, y11 + k1, 0);
			x11 = DOUBLEBEGINX1+DOUBLEBLOCKSIZE*9;
			y11 = DOUBLEBEGINY;
			nowspeed1 = doublespeed;
			k1 = 0;
			nowdirect1 = BLOCK_UP;
			nextdirect1 = BLOCK_RIGHT;
			doublemark(x22, y22 + k2, 1);
			x22 = DOUBLEBEGINX2 + DOUBLEBLOCKSIZE *9;
			y22 = DOUBLEBEGINY;
			nowspeed2 = doublespeed;
			k2 = 0;
			nowdirect2 = BLOCK_UP;
			nextdirect2 = BLOCK_RIGHT;
			doubledown(0);
			doubledown(1);
			return 2;
		}
		if (!doubleremovable(x11, y11 + k1, BLOCK_DOWN,doublenowindex1,0))
		{
			doublemark(x11, y11 + k1,0);
			x11 = DOUBLEBEGINX1 + DOUBLEBLOCKSIZE *9;
			y11 = DOUBLEBEGINY;
			nowspeed1 = doublespeed;
			k1 = 0;
			nowdirect1 = BLOCK_UP;
			nextdirect1 = BLOCK_RIGHT;
			doubledown(0);
			return 0;
		}
		if (!doubleremovable(x22, y22 + k2, BLOCK_DOWN, doublenowindex2, 1))
		{
			doublemark(x22, y22 + k2, 1);
			x22 = DOUBLEBEGINX2 + DOUBLEBLOCKSIZE *9;
			y22= DOUBLEBEGINY;
			nowspeed2 = doublespeed;
			k2 = 0;
			nowdirect2 = BLOCK_UP;
			nextdirect2 = BLOCK_RIGHT;
			doubledown(1);
			return 1;
		}
	}
}
/*void* move1(void* argc)
{
	while (true)
	{
		FlushBatchDraw();
		doublemode();
		doubledrawgrid();
		doubledrawblock(465, 160, doublenextindex1, doublenextcolor1, 0);
		doubledrawblock(735, 160, doublenextindex2, doublenextcolor2, 1);
		if (_kbhit())
		{
			char key = _getch();
			if (key == KEYA || key == KEYa)
			{
				nextdirect1 = BLOCK_LEFT;
				if (doubleremovable(x11, y11 + k1, nextdirect1, doublenowindex1, 0))
				{
					nowdirect1 = nextdirect1;
					x11 = x11 - DOUBLEBLOCKSIZE;
					k1 -= DOUBLEBLOCKSIZE;
				}
			}
			else if (key == KEYW || key == KEYw)
			{
				nextdirect1 = BLOCK_UP;
				if (doubleturnto(x11, y11 + k1, doublenowindex1, 0) == 1)
				{
					nowdirect1 = nextdirect1;
					doublenowindex1 = (doublenowindex1 + 1) % 4 + doublenowindex1 / 4 * 4;
					k1 -= DOUBLEBLOCKSIZE;
				}
			}
			else if (key == KEYS || key == KEYs)
			{
				nextdirect1 = BLOCK_DOWN;
				if (doubleremovable(x11, y11 + k1 + 30, nextdirect1, doublenowindex1, 0))
				{
					nowdirect1 = nextdirect1;
					nowspeed1 = 50;
				}
			}
			else if (key == KEYD || key == KEYd)
			{
				nextdirect1 = BLOCK_RIGHT;
				if (doubleremovable(x11, y11 + k1, nextdirect1, doublenowindex1, 0))
				{
					nowdirect1 = nextdirect1;
					x11 = x11 + DOUBLEBLOCKSIZE;
					k1 -= DOUBLEBLOCKSIZE;
				}
			}
		}
		k1 += DOUBLEBLOCKSIZE;
		doubledrawblock(x11, y11 + k1, doublenowindex1, doublenowcolor1, 0);
		wait(nowspeed1);
		nowspeed1 = doublespeed;
		if (!doubleremovable(x11, y11 + k1, BLOCK_DOWN, doublenowindex1, 0))
		{
			doublemark(x11, y11 + k1, 0);
			x11 = DOUBLEBEGINX1;
			y11 = DOUBLEBEGINY;
			nowspeed1 = doublespeed;
			k1 = 0;
			nowdirect1 = BLOCK_UP;
			nextdirect1 = BLOCK_RIGHT;
			//down();
			return 0;
		}
	}
}*/
/*void* move2(void* argc)
{
	while (true)
	{
		FlushBatchDraw();
		doublemode();
		doubledrawgrid();
		doubledrawblock(465, 160, doublenextindex1, doublenextcolor1, 0);
		doubledrawblock(735, 160, doublenextindex2, doublenextcolor2, 1);
		if (_kbhit())
		{
			char key = _getch();
			if (key == 0 || key == -32)
			{
				key = _getch();
				if (key == KEYUP)
				{
					nextdirect2 = BLOCK_UP;
					if (doubleturnto(x22, y22 + k2, doublenowindex2, 1) == 1)
					{
						nowdirect2 = nextdirect2;
						doublenowindex2 = (doublenowindex2 + 1) % 4 + doublenowindex2 / 4 * 4;
						k2 -= DOUBLEBLOCKSIZE;
					}
				}
				else if (key == KEYLEFT)
				{
					nextdirect2 = BLOCK_LEFT;
					if (doubleremovable(x22, y22 + k2, nextdirect2, doublenowindex2, 1))
					{
						nowdirect2 = nextdirect2;
						x22 = x22 - DOUBLEBLOCKSIZE;
						k2 -= DOUBLEBLOCKSIZE;
					}
				}
				else if (key == KEYRIGHT)
				{
					nextdirect2 = BLOCK_RIGHT;
					if (doubleremovable(x22, y22 + k2, nextdirect2, doublenowindex2, 1))
					{
						nowdirect2 = nextdirect2;
						x22 = x22 + DOUBLEBLOCKSIZE;
						k2 -= DOUBLEBLOCKSIZE;
					}
				}
				else if (key == KEYDOWN)
				{
					nextdirect2 = BLOCK_DOWN;
					if (doubleremovable(x22, y22 + k2 + 20, nextdirect2, doublenowindex2, 1))
					{
						nowdirect2 = nextdirect2;
						nowspeed2 = 50;
					}
				}
			}
			else if (key == KEYSPACE)
			{
				HWND hwnd = GetHWnd();
				if (!MessageBox(hwnd, "游戏已经暂停\n继续点击确定", "提示", MB_OK))
				{
					printf("error");
				}
			}
		}
		k2 += DOUBLEBLOCKSIZE;
		doubledrawblock(x22, y22 + k2, doublenowindex2, doublenowcolor2, 1);
		wait(nowspeed2);
		nowspeed2 = doublespeed;
		if (!doubleremovable(x22, y22 + k2, BLOCK_DOWN, doublenowindex2, 1))
		{
			doublemark(x22, y22 + k2, 1);
			for (int i = EXTRA;i < DOUBLEGRIDNUMX + EXTRA;i++)
			{
				for (int j = EXTRA;j < DOUBLEGRIDNUMY + EXTRA;j++)
				{
					printf("%d", doublegridnum2[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			x22 = DOUBLEBEGINX2;
			y22 = DOUBLEBEGINY;
			nowspeed2 = doublespeed;
			k2 = 0;
			nowdirect2 = BLOCK_UP;
			nextdirect2 = BLOCK_RIGHT;
			//mark(x, y + k);
			//down();
			return 0;
		}
	}
}*/
/*DWORD WINAPI move1(LPVOID lpParameter)
{
	while (true)
	{
		FlushBatchDraw();
		doublemode();
		doubledrawgrid();
		doubledrawblock(465, 160, doublenextindex1, doublenextcolor1, 0);
		doubledrawblock(735, 160, doublenextindex2, doublenextcolor2, 1);
		if (_kbhit())
		{
			char key = _getch();
			if (key == 0 || key == -32)
			{
				key = _getch();
				if (key == KEYUP)
				{
					nextdirect2 = BLOCK_UP;
					if (doubleturnto(x22, y22 + k2, doublenowindex2, 1) == 1)
					{
						nowdirect2 = nextdirect2;
						doublenowindex2 = (doublenowindex2 + 1) % 4 + doublenowindex2 / 4 * 4;
						k2 -= DOUBLEBLOCKSIZE;
					}
				}
				else if (key == KEYLEFT)
				{
					nextdirect2 = BLOCK_LEFT;
					if (doubleremovable(x22, y22 + k2, nextdirect2, doublenowindex2, 1))
					{
						nowdirect2 = nextdirect2;
						x22 = x22 - DOUBLEBLOCKSIZE;
						k2 -= DOUBLEBLOCKSIZE;
					}
				}
				else if (key == KEYRIGHT)
				{
					nextdirect2 = BLOCK_RIGHT;
					if (doubleremovable(x22, y22 + k2, nextdirect2, doublenowindex2, 1))
					{
						nowdirect2 = nextdirect2;
						x22 = x22 + DOUBLEBLOCKSIZE;
						k2 -= DOUBLEBLOCKSIZE;
					}
				}
				else if (key == KEYDOWN)
				{
					nextdirect2 = BLOCK_DOWN;
					if (doubleremovable(x22, y22 + k2 + 20, nextdirect2, doublenowindex2, 1))
					{
						nowdirect2 = nextdirect2;
						nowspeed2 = 50;
					}
				}
			}
			else if (key == KEYSPACE)
			{
				HWND hwnd = GetHWnd();
				if (!MessageBox(hwnd, "游戏已经暂停\n继续点击确定", "提示", MB_OK))
				{
					printf("error");
				}
			}
		}
		k2 += DOUBLEBLOCKSIZE;
		doubledrawblock(x22, y22 + k2, doublenowindex2, doublenowcolor2, 1);
		wait(nowspeed2);
		nowspeed2 = doublespeed;
		if (!doubleremovable(x22, y22 + k2, BLOCK_DOWN, doublenowindex2, 1))
		{
			doublemark(x22, y22 + k2, 1);
			for (int i = EXTRA;i < DOUBLEGRIDNUMX + EXTRA;i++)
			{
				for (int j = EXTRA;j < DOUBLEGRIDNUMY + EXTRA;j++)
				{
					printf("%d", doublegridnum2[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			x22 = DOUBLEBEGINX2;
			y22 = DOUBLEBEGINY;
			nowspeed2 = doublespeed;
			k2 = 0;
			nowdirect2 = BLOCK_UP;
			nextdirect2 = BLOCK_RIGHT;
			//mark(x, y + k);
			//down();
			return 0;
		}
	}
}*/
/*DWORD WINAPI move2(LPVOID lpParameter)
{
	while (true)
	{
		FlushBatchDraw();
		doublemode();
		doubledrawgrid();
		doubledrawblock(465, 160, doublenextindex1, doublenextcolor1, 0);
		doubledrawblock(735, 160, doublenextindex2, doublenextcolor2, 1);
		if (_kbhit())
		{
			char key = _getch();
			if (key == KEYA || key == KEYa)
			{
				nextdirect1 = BLOCK_LEFT;
				if (doubleremovable(x11, y11 + k1, nextdirect1, doublenowindex1, 0))
				{
					nowdirect1 = nextdirect1;
					x11 = x11 - DOUBLEBLOCKSIZE;
					k1 -= DOUBLEBLOCKSIZE;
				}
			}
			else if (key == KEYW || key == KEYw)
			{
				nextdirect1 = BLOCK_UP;
				if (doubleturnto(x11, y11 + k1, doublenowindex1, 0) == 1)
				{
					nowdirect1 = nextdirect1;
					doublenowindex1 = (doublenowindex1 + 1) % 4 + doublenowindex1 / 4 * 4;
					k1 -= DOUBLEBLOCKSIZE;
				}
			}
			else if (key == KEYS || key == KEYs)
			{
				nextdirect1 = BLOCK_DOWN;
				if (doubleremovable(x11, y11 + k1 + 30, nextdirect1, doublenowindex1, 0))
				{
					nowdirect1 = nextdirect1;
					nowspeed1 = 50;
				}
			}
			else if (key == KEYD || key == KEYd)
			{
				nextdirect1 = BLOCK_RIGHT;
				if (doubleremovable(x11, y11 + k1, nextdirect1, doublenowindex1, 0))
				{
					nowdirect1 = nextdirect1;
					x11 = x11 + DOUBLEBLOCKSIZE;
					k1 -= DOUBLEBLOCKSIZE;
				}
			}
		}
		k1 += DOUBLEBLOCKSIZE;
		doubledrawblock(x11, y11 + k1, doublenowindex1, doublenowcolor1, 0);
		wait(nowspeed1);
		nowspeed1 = doublespeed;
		if (!doubleremovable(x11, y11 + k1, BLOCK_DOWN, doublenowindex1, 0))
		{
			doublemark(x11, y11 + k1, 0);
			x11 = DOUBLEBEGINX1;
			y11 = DOUBLEBEGINY;
			nowspeed1 = doublespeed;
			k1 = 0;
			nowdirect1 = BLOCK_UP;
			nextdirect1 = BLOCK_RIGHT;
			//down();
			return 0;
		}
	}
}*/
int doublenowblock(const int flag0)
{
	FlushBatchDraw();
	if (flag0 == 0)
	{
		doublenowindex1 = doublenextindex1;
		srand((unsigned)time(NULL));
		doublenowcolor1 = doublenextcolor1;
		doublenextcolor1 = rand() % COLORNUM;
		doublemode();
		doublenextblock(flag0);
		doubledrawgrid();
	}
	else if (flag0 == 1)
	{
		doublenowindex2 = doublenextindex2;
		srand((unsigned)time(NULL));
		doublenowcolor2 = doublenextcolor2;
		doublenextcolor2 = rand() % COLORNUM;
		doublemode();
		doublenextblock(flag0);
		doubledrawgrid();
	}
	else if (flag0 == 2)
	{
		doublenowindex1 = doublenextindex1;
		srand((unsigned)time(NULL));
		doublenowcolor1 = doublenextcolor1;
		doublenextcolor1 = rand() % COLORNUM;
		doublenowindex2 = doublenextindex2;
		srand((unsigned)time(NULL));
		doublenowcolor2 = doublenextcolor2;
		doublenextcolor2 = rand() % COLORNUM;
		doublemode();
		doublenextblock(flag0);
		doubledrawgrid();
	}
	//HANDLE hThread1 = CreateThread(NULL, 0, move1, NULL, 0, NULL);
	//HANDLE hThread2 = CreateThread(NULL, 0, move2, NULL, 0, NULL);
	//CloseHandle(hThread1);
	//CloseHandle(hThread2);
	//pthread_t th1;
	//pthread_t th2;
	//pthread_create(&th1, NULL, move1, NULL);
	//pthread_create(&th2, NULL, move2, NULL);
	int flag = doublemove();
	if (flag == 0)
	{
		return 0;
	}
	else if(flag==1) {
		return 1;
	}
	else if (flag == 2)
	{
		return 2;
	}
	else if (flag == 3)
	{
		return 3;
	}
}