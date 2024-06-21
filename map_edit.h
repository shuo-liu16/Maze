#pragma once
#include <graphics.h>
#include <Windows.h>
#include <conio.h>
#include <future>
#include "maze.h"
#include "file_op.h"

// 定义地图格子大小和行列数
const int cellSize = 30;
const int rows = N1;
const int cols = N2;

extern const char* Filename;

// 绘制地图
void drawMap();

// 鼠标点击事件处理
void onMouseClick(int x, int y);

//地图编辑
void MapEdit();

