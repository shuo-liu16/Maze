#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
//格式化打印时间

using namespace std;

// 定义文本颜色的 ANSI 转义码
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

const int N1 = 10; // 迷宫大小
const int N2 = 20;
const int WALL = 1;
const int ROAD = 0;
const int MOUSE = 2;
const int FOOD = 3;

const int target_time = 20; //死亡倒计时20s

struct Pos {
    int x;
    int y;
};

extern int maze[N1][N2];
extern Pos pos_Mouse;

//初始化
void init();
//游戏背景
void welcome();
//光标的隐藏和跳转
void HideCursor();
void CursorJump(int x, int y);
//地图初步绘制
void drawMaze();
//杰瑞的移动
void moveMouse(int dx, int dy);
//胜利检测
void checkWin();
//时间的初始化与更新
void initTimer();
void updateTimer();
//游戏主函数
void Game();
