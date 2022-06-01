#include"single.h"

int beginx;
int beginy;
int beginy1;
int nowscore;
int grade;
int nextindex;
int nowcolor;
int nextcolor;
int nowindex;
int speed;
int continuex;
int continuey;

int gridnum[GRIDNUMX + EXTRA][GRIDNUMY + EXTRA];
int gridcolor[GRIDNUMX + EXTRA][GRIDNUMY + EXTRA];

void initializegrid()
{
	nowscore = 0;
	grade = 1;
	nextindex = -1;
	nowcolor = -1;
	nextcolor = -1;
	nowindex = -1;
	speed = 500;
	beginx = 30;
	beginy = -50;
	beginy1 = 100;
	//setfillstyle(BS_NULL);
	for (int i = EXTRA;i < GRIDNUMX + EXTRA;i++)
	{
		for (int j = EXTRA;j < GRIDNUMY + EXTRA;j++)
		{
			gridcolor[i][j] = BLACK;
			gridnum[i][j] = 0;
			setfillcolor(gridcolor[i][j]);
			fillrectangle((i - EXTRA) * 30 + beginx, (j - EXTRA) * 30 + beginy1, (i - EXTRA) * 30 + beginx + 30, (j - EXTRA) * 30 + beginy1 + 30);
		}
	}
	for (int i = 0;i < GRIDNUMX + EXTRA;i++)
	{
		for (int j = 0;j < GRIDNUMY + EXTRA;j++)
		{
			gridcolor[i][j] = BLACK;
			gridnum[i][j] = 0;
		}
	}
}
int rank()
{
	info tmp;
	FILE* fp;
	int flag = 0;
	printf("大侠请输入您的大名：");
	fgets(tmp.name, 30, stdin);
	tmp.score = nowscore;
	flag = fopen_s(&fp, "rank.txt", "a");
	if (flag != 0)
	{
		printf("cannot open rank.txt\n");
		system("pause");
		return -1;
	}
	fprintf(fp, "%s%d\n", tmp.name, tmp.score);
	fclose(fp);
	return 0;
}
void savedblock()
{
	for (int i = EXTRA;i < EXTRA + GRIDNUMX; i++)
	{
		for (int j = EXTRA;j < EXTRA + GRIDNUMY;j++)
		{
			if (gridnum[i][j])
			{
				setfillcolor(gridcolor[i][j]);
				fillrectangle((i - EXTRA) * BLOCKSIZE + beginx, (j - EXTRA) * BLOCKSIZE + beginy1, (i - EXTRA + 1) * BLOCKSIZE + beginx, (j - EXTRA + 1) * BLOCKSIZE + beginy1);
			}
		}
	}
}
void scoregrade(int x, int y, int w, int h, int flag)
{
	int add = 0;
	if (flag == 0)
	{
		add = nowscore;
	}
	else if (flag == 1)
	{
		add = grade;
	}
	setfillcolor(BLACK);
	fillrectangle(x, y, x + w, y + h);
	char str[50];
	sprintf_s(str, "%d", add);//将数字格式化输出为字符串
	settextstyle(80, 0, FONT);
	int tx = x + w / 2 - textwidth(str) / 2;
	int ty = y + h / 2 - textheight(str) / 2;
	outtextxy(tx, ty, str);
}
void clearnextblock(int left, int top, int right, int bottom)
{
	setfillcolor(BLACK);
	fillrectangle(left, top, right, bottom);
}
int removable(int x0, int y0, block_direct removedirect)
{
	int x = (x0 - 30) / 30;
	int y = (y0 - 100) / 30;
	int flag = 1;
	if (removedirect == BLOCK_LEFT)
	{
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				if (block[nowindex][i][j] == 1 && (x + i == 0 || gridnum[x + i - 1 + EXTRA][y + j + EXTRA] == 1))
				{
					flag = 0;
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
				if (block[nowindex][i][j] == 1 && (x + i >= 10 || gridnum[x + i + 1 + EXTRA][y + j + EXTRA] == 1))
				{
					flag = 0;
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
				if (block[nowindex][i][j] == 1 && (y + j + 1 >= 19 || gridnum[x + i + EXTRA][y + j + 1 + EXTRA] == 1))
				{
					//printf("%d %d %d\n",x+i, y + j + 1, gridnum[x + i][y + j + 1]);
					return 0;
				}
			}
		}
	}
	return flag;
}
int turnto(int x0, int y0)
{
	int x = (x0 - 30) / 30;
	int y = (y0 - 100) / 30;
	int flag = 1;
	if (!removable(x0, y0, BLOCK_DOWN))
	{
		return 0;
	}
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (block[(nowindex + 1) % 4 + nowindex / 4 * 4][i][j] == 1 && (x + i < 0 || x + i >= 11 || y + j < 0 || y + j >= 19 || gridnum[x + i + EXTRA][y + j + EXTRA] == 1))
			{
				flag = 0;
			}
		}
	}
	return flag;
}
void mark(int x0, int y0)
{
	int x = (x0 - 30) / 30;
	int y = (y0 - 100) / 30;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (block[nowindex][i][j] == 1)
			{
				gridnum[x + i + EXTRA][y + j + EXTRA] = 1;
				gridcolor[x + i + EXTRA][y + j + EXTRA] = blockcolor[nowcolor];
			}
		}
	}
}
BOOL end(int x, int y)
{
	HWND hwnd = GetHWnd();
	if (!removable(x, y, BLOCK_DOWN))
	{
		int isok = MessageBox(hwnd, "分数是否记录成绩\n如果确定，请输入名字\n如果取消，分数将不被记录\n游戏将重新开始", "游戏结束了", MB_OKCANCEL);
		if (isok == IDOK)
		{
			rank();
		}
		return TRUE;
	}
	return FALSE;
}
void down()
{
	for (int i = 19 + EXTRA - 1;i >= EXTRA;i--)
	{
		int flag = 1;
		for (int j = EXTRA;j < 11 + EXTRA;j++)
		{
			if (gridnum[j][i] != 1)
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			nowscore += 10;
			grade = nowscore / 50 + 1;
			scoregrade(100, 15, 80, 70, 0);
			scoregrade(410, 170, 150, 100, 1);
			for (int j = EXTRA;j < 11 + EXTRA;j++)
			{
				gridnum[j][i] = 0;
				gridcolor[j][i] = BLACK;
				clearnextblock((j - EXTRA) * 30 + beginx, (i - EXTRA) * 30 + beginy1, (j - EXTRA) * 30 + beginx + 30, (i - EXTRA) * 30 + 30 + beginy1);
			}
			for (int y = i;y >= EXTRA;y--)
			{
				for (int x = EXTRA;x < 11 + EXTRA;x++)
				{
					gridnum[x][y] = gridnum[x][y - 1];
					gridnum[x][y - 1] = 0;
					gridcolor[x][y] = gridcolor[x][y - 1];
					gridcolor[x][y - 1] = BLACK;
					setfillcolor(gridcolor[x][y]);
					fillrectangle((x - EXTRA) * 30 + beginx, (y - EXTRA) * 30 + beginy1, (x - EXTRA) * 30 + beginx + 30, (y - EXTRA) * 30 + beginy1 + 30);
				}
			}
			i++;
		}
	}
}
void drawblock(int x, int y, int index, int color)
{
	setfillcolor(blockcolor[color]);
	for (int i = 0;i <= 4;i++)
	{
		for (int j = 0;j <= 4;j++)
		{
			if (block[index][i][j] == 1 && (y + j * 30) >= 100)
			{
				int x1 = x + i * 30;
				int y1 = y + j * 30;
				fillrectangle(x1, y1, x1 + 30, y1 + 30);
			}
		}
	}
}
void archive(int x0, int y0) {
	int x = (x0 - beginx) / 30;
	int y = (y0 - beginy1) / 30;
	HWND hwnd = GetHWnd();
	FILE* p;
	if (!fopen_s(&p, "gamefile.txt", "r"))
	{
		fclose(p);
		if (MessageBox(hwnd, "已经存在游戏进度，是否删除", "提示", MB_OKCANCEL) == IDCANCEL)
		{
			return;
		}
	}
	int flag = fopen_s(&p, "gamefile.txt", "w");
	if (flag != 0)
	{
		printf("cannot creat rank.txt\n");
		system("pause");
	}
	else {
		fprintf(p, "%d %d\n", nextindex, nextcolor);
		fprintf(p, "%d %d %d %d\n", x + EXTRA, y + EXTRA, nowindex, nowcolor);
		for (int i = EXTRA;i < GRIDNUMX + EXTRA;i++)
		{
			for (int j = EXTRA;j < GRIDNUMY + EXTRA;j++)
			{
				fprintf(p, "%d %d\n", gridnum[i][j], gridcolor[i][j]);
			}
		}
		fclose(p);
	}
}
void loadfile()
{
	char buf[100];
	FILE* fp;
	int flag1 = fopen_s(&fp, "gamefile.txt", "rb");
	if (flag1 != 0)
	{
		printf("cannot open gamefile.txt\n");
		system("pause");
	}
	else {
		fscanf_s(fp, "%d %d", &nextindex, &nextcolor);
		fgets(buf, sizeof(buf), fp);//读取完这一行
		fscanf_s(fp, "%d %d %d %d", &continuex, &continuey, &nowindex, &nowcolor);
		fgets(buf, sizeof(buf), fp);//读取完这一行
		for (int i = EXTRA;i < GRIDNUMX + EXTRA;i++)
		{
			for (int j = EXTRA;j < GRIDNUMY + EXTRA;j++)
			{
				fscanf_s(fp, "%d %d", &gridnum[i][j], &gridcolor[i][j]);
				fgets(buf, sizeof(buf), fp);//读取完这一行
			}
		}
		fclose(fp);
	}
	savedblock();
}
BOOL move(int x0, int y0)
{
	int x = beginx + x0 * BLOCKSIZE+(GRIDNUMX-EXTRA)/2*30;
	int y = beginy + y0 * BLOCKSIZE;
	int nowspeed = speed / grade;
	int k = 0;
	block_direct nowdirect = BLOCK_UP;
	block_direct nextdirect = BLOCK_RIGHT;
	while (true)
	{
		if (end(x, y + k) == TRUE)
		{
			return TRUE;
		};
		FlushBatchDraw();
		for (int i = 0;i < 5;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				if (block[nowindex][i][j] == 1 && (y + k + j * 30) >= 100)
				{
					clearnextblock(x + i * 30, y + j * 30 + k, x + 30 + i * 30, y + j * 30 + k + 30);
				}
			}
		}
		if (_kbhit())//https://blog.csdn.net/weixin_43919932/article/details/102234892?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165336768816782184623611%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165336768816782184623611&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-1-102234892-null-null.142^v10^pc_search_result_control_group,157^v8^control&utm_term=_getch%28%29%E8%BF%94%E5%9B%9E%E5%80%BC&spm=1018.2226.3001.4187
		{
			char key = _getch();
			if (key == 0 || key == -32)
			{
				key = _getch();
				if (key == KEYUP)
				{
					nextdirect = BLOCK_UP;
					if (turnto(x, y + k) == 1)
					{
						nowdirect = nextdirect;
						nowindex = (nowindex + 1) % 4 + nowindex / 4 * 4;
						k -= 30;
					}
				}
				else if (key == KEYLEFT)
				{
					nextdirect = BLOCK_LEFT;
					if (removable(x, y + k, nextdirect))
					{
						nowdirect = nextdirect;
						x = x - 30;
						k -= 30;
					}
				}
				else if (key == KEYRIGHT)
				{
					nextdirect = BLOCK_RIGHT;
					if (removable(x, y + k, nextdirect))
					{
						nowdirect = nextdirect;
						x = x + 30;
						k -= 30;
					}
				}
				else if (key == KEYDOWN)
				{
					nextdirect = BLOCK_DOWN;
					if (removable(x, y + k + 30, nextdirect))
					{
						nowdirect = nextdirect;
						nowspeed = 50;
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
			else if (key == KEYEsc)
			{
				HWND hwnd = GetHWnd();
				if (MessageBox(hwnd, "是否保存当前游戏\n", "提示", MB_OKCANCEL) == IDOK)
				{
					archive(x, y + k);
				}
				return TRUE;
			}
		}
		k += 30;
		drawblock(x, y + k, nowindex, nowcolor);
		wait(nowspeed);
		nowspeed = speed / grade;
		if (!removable(x, y + k, BLOCK_DOWN))
		{
			mark(x, y + k);
			down();
			break;
		}
	}
	return FALSE;
}
void nextblock() {
	clearnextblock(390, 330, 590, 510);
	srand((unsigned)time(NULL));
	nextindex = rand() % 28;
	drawblock(420, 360, nextindex, nextcolor);
}
BOOL nowblock()
{
	nowindex = nextindex;
	srand((unsigned)time(NULL));
	nowcolor = nextcolor;
	nextcolor = rand() % COLORNUM;
	nextblock();
	drawblock(beginx, beginy, nowindex, nowcolor);
	if (move(0, 0) == TRUE)
	{
		return TRUE;
	}
	return FALSE;
}
BOOL newcontinue()
{
	BOOL flag = false;
	//背景图片
	IMAGE background;
	loadimage(&background, "background.jpg", 640, 360);
	putimage(0, 0, &background);
	//字体
	settextstyle(70, 0, FONT);
	settextcolor(RGB(65, 105, 225));
	outtextxy(320 - textwidth("单人模式") / 2, 50, "单人模式");
	FILE* p;
	if (!fopen_s(&p, "gamefile.txt", "r"))
	{
		fclose(p);
		flag = TRUE;
		settextstyle(20, 0, FONT);
		settextcolor(RGB(240, 248, 255));
		int tx = 242 + (150 - textwidth("继续游戏")) / 2;
		int ty = 150 + (40 - textheight("继续游戏")) / 2;
		outtextxy(tx, ty, "继续游戏");
		tx = 242 + (150 - textwidth("新游戏")) / 2;
		ty = 200 + (40 - textheight("新游戏")) / 2;
		outtextxy(tx, ty, "新游戏");
		setlinecolor(RGB(176, 196, 222));
		rectangle(242, 150, 392, 190);
		rectangle(242, 200, 392, 240);
	}
	else {
		settextstyle(20, 0, FONT);
		settextcolor(RGB(240, 248, 255));
		int tx = 242 + (150 - textwidth("新游戏")) / 2;
		int ty = 175 + (40 - textheight("新游戏")) / 2;
		outtextxy(tx, ty, "新游戏");
		setlinecolor(RGB(176, 196, 222));
		rectangle(242, 175, 392, 215);
	}
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (flag == TRUE && msg.x > 242 && msg.x < 392 && msg.y>150 && msg.y < 190)
			{
				setlinecolor(RGB(240, 248, 255));
				rectangle(242, 150, 392, 190);
				if (msg.message == WM_LBUTTONDOWN)
				{
					return FALSE;
				}
			}
			else if (flag == TRUE && msg.x > 242 && msg.x < 392 && msg.y>200 && msg.y < 240)
			{
				setlinecolor(RGB(240, 248, 255));
				rectangle(242, 200, 392, 240);
				if (msg.message == WM_LBUTTONDOWN)
				{
					return TRUE;
				}
			}
			else if (flag == FALSE && msg.x > 242 && msg.x < 392 && msg.y>175 && msg.y < 215)
			{
				setlinecolor(RGB(240, 248, 255));
				rectangle(242, 175, 392, 215);
				if (msg.message == WM_LBUTTONDOWN)
				{
					return TRUE;
				}
			}
			else if (flag == TRUE) {
				setlinecolor(RGB(176, 196, 222));
				rectangle(242, 150, 392, 190);
				rectangle(242, 200, 392, 240);
			}
			else if (flag == FALSE)
			{
				setlinecolor(RGB(176, 196, 222));
				rectangle(242, 175, 392, 215);
			}
		}
	}
}
void singlemode()
{
	//标题
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, "单人模式");
	IMAGE background1;
	loadimage(&background1, "background1.jpg", 640, 720);
	putimage(0, 0, &background1);
	//底图位运算 https://blog.csdn.net/m0_60777643/article/details/122833558
	//字
	settextstyle(20, 0, FONT);
	settextcolor(RGB(255, 215, 0));
	outtextxy(20, 20, "当前积分");
	settextcolor(RGB(105, 147, 211));
	settextstyle(50, 0, FONT);
	outtextxy(440, 120, "等级");
	outtextxy(425, 280, "下一个");
	//积分图标
	IMAGE integral11, integral12, integral21, integral22;
	loadimage(&integral21, "integral21.png", 50, 40);
	loadimage(&integral22, "integral22.png", 50, 40);
	putimage(30, 45, &integral22, SRCAND);
	putimage(30, 45, &integral21, SRCPAINT);
	setfillcolor(BLACK);
	fillrectangle(390, 330, 590, 480);
	setfillcolor(BLACK);
	fillrectangle(100, 15, 180, 85);
	settextstyle(80, 0, FONT);
	settextcolor(RGB(240, 248, 255));
	char str1[30];
	sprintf_s(str1, "%d", nowscore);//将数字格式化输出为字符串
	int tx = 140 - textwidth(str1) / 2;
	int ty = 50 - textheight(str1) / 2;
	outtextxy(tx, ty, str1);
	setfillcolor(BLACK);
	fillrectangle(410, 170, 560, 270);
	settextstyle(80, 0, FONT);
	char str2[30];
	sprintf_s(str2, "%d", grade);//将数字格式化输出为字符串
	tx = 485 - textwidth(str2) / 2;
	ty = 220 - textheight(str2) / 2;
	outtextxy(tx, ty, str2);
	settextcolor(RGB(240, 248, 255));
	settextstyle(40, 0, FONT);
	outtextxy(200, 15, "左移:←");
	outtextxy(200, 50, "右移:→");
	outtextxy(350, 15, "加速:↓");
	outtextxy(350, 50, "旋转:↑");
	outtextxy(480, 15, "暂停:空格");
	outtextxy(480, 50, "返回:Esc");
}