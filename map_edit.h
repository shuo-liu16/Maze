#pragma once
#include <graphics.h>
#include <Windows.h>
#include <conio.h>
#include <future>
#include "maze.h"
#include "file_op.h"

// �����ͼ���Ӵ�С��������
const int cellSize = 30;
const int rows = N1;
const int cols = N2;

extern const char* Filename;

// ���Ƶ�ͼ
void drawMap();

// ������¼�����
void onMouseClick(int x, int y);

//��ͼ�༭
void MapEdit();

