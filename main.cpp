#include <iostream>
#include <Windows.h>
#include "maze.h"
#include "file_op.h"
#include "map_edit.h"
#include "diagram.h"

using namespace std;

const char* Filename = "maze.txt";

void menu() {
    cout << "�������Թ���⣬��ѡ��1-4��:" << endl;
    cout << "1.�����Թ���Ϸ" << endl;
    cout << "2.�Թ��༭(���ѡ���Ҽ��˳�)" << endl;
    cout << "3.�Թ�ͼ��" << endl;
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
            cout << "ѡ�����������ѡ��" << endl;
            system("pause");
        }
    } while (choice != 4);

	return 0;
}

//1.�����������ƶ�
//2.�ļ�����
//3.dfs