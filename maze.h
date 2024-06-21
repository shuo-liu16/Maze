#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
//��ʽ����ӡʱ��

using namespace std;

// �����ı���ɫ�� ANSI ת����
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

const int N1 = 10; // �Թ���С
const int N2 = 20;
const int WALL = 1;
const int ROAD = 0;
const int MOUSE = 2;
const int FOOD = 3;

const int target_time = 20; //��������ʱ20s

struct Pos {
    int x;
    int y;
};

extern int maze[N1][N2];
extern Pos pos_Mouse;

//��ʼ��
void init();
//��Ϸ����
void welcome();
//�������غ���ת
void HideCursor();
void CursorJump(int x, int y);
//��ͼ��������
void drawMaze();
//������ƶ�
void moveMouse(int dx, int dy);
//ʤ�����
void checkWin();
//ʱ��ĳ�ʼ�������
void initTimer();
void updateTimer();
//��Ϸ������
void Game();
