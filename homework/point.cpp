#include "point.h"

int block[28][5][5]{
	//l�η���
		{0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,0,0,0,
		1,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0
	},
		{0,0,0,0,0,
		0,0,0,0,0,
		1,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
	//���η���
		{0,0,0,0,0,
		0,0,1,1,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,1,1,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,1,1,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,1,1,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
	//S�η���
		{0,0,0,0,0,
		0,0,1,1,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,1,0,
		0,0,0,1,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,1,1,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,1,0,
		0,0,0,1,0,
		0,0,0,0,0
	},
	//Z�η���
		{0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,0,1,0,
		0,0,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{0,0,0,0,0,
		0,0,0,1,0,
		0,0,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0
	},
	//L�η���
		{0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0
	},
		{ 0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,1,0,0,0,
		0,0,0,0,0
	},
		{ 0,0,0,0,0,
		0,0,1,1,0,
		0,0,0,1,0,
		0,0,0,1,0,
		0,0,0,0,0
		},
		{ 0,0,0,0,0,
		0,0,0,1,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
		},
	//J�η���
		{ 0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0
	},
		{ 0,0,0,0,0,
		0,1,0,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{ 0,0,0,0,0,
		0,0,1,1,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	},
		{ 0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,1,0,
		0,0,0,0,0
	},
	//T�η���
		{ 0,0,0,0,0,
		0,1,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{ 0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	},
		{ 0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},
		{ 0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0
	}
};
int blockcolor[COLORNUM]{ RED,GREEN,CYAN,ORANGE,YELLOW,PINK,PURPLE };

void BGM()
{
	//�����֣���������
	mciSendString("open BGM.mp3", NULL, 0, NULL);

	mciSendString("play BGM.mp3 repeat", NULL, 0, NULL);
}
void BACKGROUND()
{
	//����ͼƬ
	IMAGE background;
	loadimage(&background, "background.jpg", 640, 360);
	putimage(0, 0, &background);
	//����
	settextstyle(70, 0, FONT);
	settextcolor(RGB(65, 105, 225));
	outtextxy(160, 50, "����˹����");
	//����ͼƬ
	IMAGE sound;
	loadimage(&sound, "sound.png", 40, 40);
	putimage(600, 0, &sound);
}
void button(int x, int y, int w, int h, const char* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(240, 248, 255));
	fillroundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(20, 0, FONT);
	settextcolor(RGB(105, 147, 211));
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}
int readrank()
{
	info temp;
	int n = 0;
	FILE* fp;
	int flag = 0;
	//��������
	char buf[100];
	FILE* p;
	flag = fopen_s(&p, "rank.txt", "rb");
	if (flag != 0)
	{
		printf("cannot open the files\n");
		system("pause");
		return -1;
	}
	else {
		while (!feof(p))
		{
			memset(buf, 0, sizeof(buf));//ÿ�ζ�ȡһ��֮ǰ�������buf���
			fgets(buf, sizeof(buf), p);//���ļ��ж�ȡһ��
			n++;
		}
		fclose(p);
	}
	n /= 2;
	info* array = (info*)malloc(n * sizeof(temp));//����һ����̬���飬��̬����ĳ�Ա������.txt�ļ�����һ����
	flag = fopen_s(&fp, "rank.txt", "rb");
	if (flag != 0)
	{
		printf("cannot open rank.txt\n");
		system("pause");
		return -1;
	}
	for (int i = 0;i < n;i++)
	{
		fgets(array[i].name, 30, fp);
		char* tmp = NULL;
		if ((tmp = strstr(array[i].name, "\n")))
		{
			*tmp = '\0';
		}
		fscanf_s(fp, "%d", &array[i].score);
		fgets(buf, sizeof(buf), fp);//��ȡ�������һ��
	}
	for (int i = 0;i < n - 1;i++)
	{
		int k = i;
		for (int j = i + 1;j < n;j++)
		{
			if (array[j].score > array[i].score)
			{
				k = j;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	fclose(fp);
	for (int i = 0;i < n;i++)
	{
		char str1[30];
		sprintf_s(str1, "%d", i + 1);//�����ָ�ʽ�����Ϊ�ַ���
		outtextxy(20 + textwidth("����") / 2 - textwidth(str1) / 2, 130 + i * textheight(str1), str1);
		outtextxy(135 + textwidth("����") / 2 - textwidth(array[i].name) / 2, 130 + i * textheight(array[i].name), array[i].name);
		char str2[30];
		sprintf_s(str2, "%d", array[i].score);//�����ָ�ʽ�����Ϊ�ַ���
		outtextxy(250 + textwidth("�÷�") / 2 - textwidth(str2) / 2, 130 + i * textheight(str2), str2);
	}
	free(array);
	return 0;
}
void list()
{
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, "���а�");
	IMAGE background;
	loadimage(&background, "background4.jpg", 320, 720);
	putimage(0, 0, &background);
	settextstyle(80, 0, FONT);
	settextcolor(RGB(240, 248, 255));
	int tx = 160 - textwidth("���а�") / 2;
	outtextxy(tx, 20, "���а�");
	settextstyle(30, 0, FONT);
	outtextxy(20, 100, "����");
	outtextxy(135, 100, "����");
	outtextxy(250, 100, "����");
	IMAGE backimage1, backimage2;
	loadimage(&backimage1, "back1.png", 50, 50);
	loadimage(&backimage2, "back2.png", 50, 50);
	putimage(0, 0, &backimage2, SRCAND);
	putimage(0, 0, &backimage1, SRCPAINT);
}
void wait(int interval) {
	int count = interval / 10;
	for (int i = 0; i < count; i++) {
		Sleep(10);
		if (_kbhit()) {
			return;
		}
	}
}
