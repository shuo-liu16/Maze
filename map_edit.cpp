#include "map_edit.h"

void drawMap()
{
    setbkcolor(WHITE);
    cleardevice();  // 清空整个绘图区域并填充为白色背景
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] == 1) {
                setfillcolor(DARKGRAY);
                fillrectangle(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
                setlinecolor(BLACK);
                rectangle(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
            }
            else {
                setfillcolor(WHITE);
                fillrectangle(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
                setlinecolor(BLACK);
                rectangle(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
            }
        }
    }
}

void onMouseClick(int x, int y)
{
    int row = y / cellSize;
    int col = x / cellSize;
    maze[row][col] = 1 - maze[row][col];  // 切换地图格子状态

    if (maze[row][col] == 1) {
        setfillcolor(DARKGRAY);
        fillrectangle(col * cellSize, row * cellSize, (col + 1) * cellSize, (row + 1) * cellSize);
        setlinecolor(BLACK);
        rectangle(col * cellSize, row * cellSize, (col + 1) * cellSize, (row + 1) * cellSize);
    }
    else {
        setfillcolor(WHITE);
        fillrectangle(col * cellSize, row * cellSize, (col + 1) * cellSize, (row + 1) * cellSize);
        setlinecolor(BLACK);
        rectangle(col * cellSize, row * cellSize, (col + 1) * cellSize, (row + 1) * cellSize);
    }
}

void MapEdit()
{
    int flag = 1;

    initgraph(cols * cellSize, rows * cellSize);

    // 绘制初始地图
    drawMap();

    // 监听鼠标点击事件
    ExMessage mouse;
    
    while (flag) {
        mouse = getmessage();
        if (mouse.message == WM_LBUTTONDOWN) {
            onMouseClick(mouse.x, mouse.y);
        }
        if (mouse.message == WM_RBUTTONDOWN) {
            flag = 0;
            break;
        }
        //if (_kbhit()) { // 使用图形库的键盘事件处理函数
        //    char ch = _getch(); // 获取键盘输入字符
        //    if (ch == 27) // 如果按下 ESC 键，退出循环
        //        flag = 0;
        //}
        Sleep(50);
    }
    clearFile(Filename);
    saveMaze(Filename);
    closegraph();
    system("cls");
}


