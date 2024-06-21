#include <iostream>
#include <Windows.h>
#include "maze.h"
#include "file_op.h"
#include "map_edit.h"
#include "diagram.h"

using namespace std;

const char* Filename = "maze.txt";

void menu() {
    cout << "这里是迷宫求解，请选择（1-4）:" << endl;
    cout << "1.进行迷宫游戏" << endl;
    cout << "2.迷宫编辑(左键选择，右键退出)" << endl;
    cout << "3.迷宫图解" << endl;
    cout << "4.exit" << endl;
}

int main() {
   /* loadMaze("maze.txt");
    Game();
    saveMaze("maze.txt");*/
    int choice;

    do{
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            loadMaze(Filename);
            Game();
            break;
        case 2:
            loadMaze(Filename);
            MapEdit();
            break;
        case 3:
            loadMaze(Filename);
            Diagram();
            break;
        case 4:
            break;
        default:
            cout << "选择错误，请重新选择！" << endl;
            system("pause");
        }
    } while (choice != 4);

	return 0;
}

//1.光标的隐藏与移动
//2.文件操作
//3.dfs