#include "map_edit.h"

void drawMap()
{
    setbkcolor(WHITE);
    cleardevice();  // ���������ͼ�������Ϊ��ɫ����
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
    maze[row][col] = 1 - maze[row][col];  // �л���ͼ����״̬

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

    // ���Ƴ�ʼ��ͼ
    drawMap();

    // ����������¼�
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
        //if (_kbhit()) { // ʹ��ͼ�ο�ļ����¼�������
        //    char ch = _getch(); // ��ȡ���������ַ�
        //    if (ch == 27) // ������� ESC �����˳�ѭ��
        //        flag = 0;
        //}
        Sleep(50);
    }
    clearFile(Filename);
    saveMaze(Filename);
    closegraph();
    system("cls");
}


