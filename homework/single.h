#pragma once
#include "point.h"
#define GRIDNUMX 11
#define GRIDNUMY 19
#define BLOCKSIZE 30

extern int beginx;
extern int beginy;
extern int beginy1;//网格与上界面的距离
extern int nowscore;//当前分数
extern int grade;//等级
extern int nextindex;//下一个方块
extern int nowcolor;
extern int nextcolor;
extern int nowindex;//当前方块
extern int speed;//速度
extern int gridnum[GRIDNUMX + EXTRA][GRIDNUMY + EXTRA];//格子数
extern int gridcolor[GRIDNUMX + EXTRA][GRIDNUMY + EXTRA];//格子方块颜色
extern int continuex;//继续游戏方块x，y
extern int continuey;

//初始化
void initializegrid();
//排行榜输入
int rank();
//画已保存的方块
void savedblock();
//分数增加,消灭行数以及显示
void scoregrade(int x, int y, int w, int h, int flag);
//清除下一个方块
void clearnextblock(int left, int top, int right, int bottom);
//判断当前方块是否可以移动
int removable(int x0, int y0, block_direct removedirect);
//判断当前方块是否可以转向
int turnto(int x0, int y0);
//在block中标记方块最后位置
void mark(int x0, int y0);
//判断游戏结束,结束返回true，不结束返回false
BOOL end(int x, int y);
//判断是否满行以及消除所满行
void down();
//画显示区方块
void drawblock(int x, int y, int index, int color);
//存档函数
void archive(int x0, int y0);
//读档函数
void loadfile();
//移动方块,返回或者结束返回true,x0，y0代表方块已走格子
BOOL move(int x0, int y0);
//下一个方块
void nextblock();
//创建新方块，返回或者结束返回true
BOOL nowblock();
//新游戏继续游戏,true为新游戏
BOOL newcontinue();
//单人模式界面
void singlemode();