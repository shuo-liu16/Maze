#include "maze.h"

// ����ȫ�ֱ���������ʱ��
time_t startTime;
time_t currentTime;

//�������ҿ��Ʒ���
enum Direction { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };

Pos pos_Mouse;
int flag;

//�Թ���ͼ
int maze[N1][N2];
//int maze[N1][N2] = {
//    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
//    {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
//    {1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
//    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
//    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
//    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
//    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1},
//    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//};

//��ʼ��
void init() {
    flag = 0;

    pos_Mouse.x = 1;
    pos_Mouse.y = 1;
    maze[pos_Mouse.x][pos_Mouse.y] = MOUSE;
}

//��ӭ 
void welcome() {
    string script1 =
        "����һ����ķ�ļ�\n"
        "\n\n"
        "����ķ���ڼ��д��ͻȻע�⵽�����ʳ�ﴢ���ƺ�������һЩ����\n"
        "��ķ�����ף������������ô���ˣ��϶�����ֻ�ƻ��Ľ�����͵���ˣ���\n" 
        "����ķ��������һ���Թ�������ץס���𡣣�"
        "\n\n";
 
    cout << script1 << endl;
    system("pause");
    system("cls");

    string script2 =
        "���������Թ��"
        "\n\n"
        "��ķæµ���ڼ��в����Թ������ø����ϰ������壬�Թ����յ������һ�����˵�������Ϊ�ն���"
        "\n\n";
    cout << script2 << endl;
    system("pause");
    system("cls");

    string script3 =
        "�������ŵ������ҵ���ζ�����ĵ�̽��ͷ��Ѱ����Դ����"
        "\n\n"
        "�����˷ܵأ������ۣ����ң���ķ��һ����ڸ�ʲô����"
        "���������ð�ս����Թ���Ѱ�����ҡ���"
        "\n\n"
        "��������Ϸ��ʼ��ף����Ŀ��ģ�"
        "\n\n";
    cout << script3 << endl;

    cout << "#" << "  Χǽ" << endl;
    cout << RED_TEXT << "@" << RESET_TEXT << "  ����(MOUSE)" << endl;
    cout << GREEN_TEXT << "��" << RESET_TEXT << "  ʳ��(Food)" << endl;
    system("pause");
    system("cls");

}

//���ع��
void HideCursor() {
    CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����

    curInfo.dwSize = 1; //���û��ֵ�Ļ������������Ч
    curInfo.bVisible = FALSE; //���������Ϊ���ɼ�

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
    SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}


/*//�������
void HideCursor()
{
    ShowCursor(FALSE);
}
*/

//�����ת
void CursorJump(int x, int y) {
    COORD pos;  // ����һ�� COORD �ṹ����� pos�������洢����λ����Ϣ

    pos.X = x;  // ���� pos �� X ����Ϊ����� x ����
    pos.Y = y;  // ���� pos �� Y ����Ϊ����� y ����

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ��׼����ľ��
    SetConsoleCursorPosition(handle, pos);  // �����λ������Ϊ pos ��ָ����λ��
}


//�������Ƶ�ͼ 
void drawMaze() {

    CursorJump(47, 1);
    cout << "Welcome to RAT IN MAZE" << endl;

    for (int i = 0; i < N1; ++i) {

        //Ϊ��ʹ�Թ����ж��Ŀ������� 
        CursorJump(48, i + 3);

        for (int j = 0; j < N2; ++j) {
            if (maze[i][j] == WALL) {
                cout << "#";           
            }
            else if (maze[i][j] == ROAD) {
                cout << " ";
            }
            else if (maze[i][j] == MOUSE) {
                cout << RED_TEXT << "@" << RESET_TEXT;  // ʹ�ú�ɫת����
            }
            else if (maze[i][j] == FOOD) {
                cout << GREEN_TEXT << "��" << RESET_TEXT;
            }
        }
        cout << endl;
    }
}

//�ƶ� 
void moveMouse(int dx, int dy) {
    if (maze[pos_Mouse.x + dx][pos_Mouse.y + dy] == WALL)
        return;

    // ����ǰλ�ûָ�Ϊ��·    
    maze[pos_Mouse.x][pos_Mouse.y] = ROAD;
    CursorJump(48 + pos_Mouse.y, pos_Mouse.x + 3);
    cout << " ";

    pos_Mouse.x += dx;
    pos_Mouse.y += dy;

    // �����������λ��
    maze[pos_Mouse.x][pos_Mouse.y] = MOUSE;
    CursorJump(48 + pos_Mouse.y, pos_Mouse.x + 3);
    cout << RED_TEXT << "@" << RESET_TEXT;
}

//ʤ���ж� 
void checkWin() {
    if (pos_Mouse.x == N1 - 2 && pos_Mouse.y == N2 - 2) {
        CursorJump(39, N1 + 3 + 1);
        cout << "Congratulations! ���������������׷������������ң�" << endl;
        system("pause");

        flag = 1;
    }
}

// ��ʼ����ʱ��  
void initTimer() {
    startTime = time(nullptr);
}

// ���²���ʾ����ʱ  
void updateTimer() {
    currentTime = time(nullptr);

    int elapsedSeconds = difftime(currentTime, startTime);

    // ���������ʱ�䣬�Է��Ӻ������ʽ  
    int minutes = elapsedSeconds / 60;
    int seconds = elapsedSeconds % 60;

    CursorJump(30, 5);
    cout << "Time: " << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << target_time - seconds << endl;

    if (seconds == target_time) {
        CursorJump(39, N1 + 3 + 1);
        cout << "ʱ��ľ����㱻Tomץ����! ���ǲ˰�����" << endl;
        system("pause");

        flag = 1;
    }
}

void Game() {
    system("cls");

    init();

    HideCursor();

    welcome();

    drawMaze(); // �����Թ�

    initTimer();

    // ��ѭ��
    while (true) {

        checkWin();
        if (flag == 1)
            break;

        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
            case LEFT:
                moveMouse(0, -1);
                break;
            case UP:
                moveMouse(-1, 0);
                break;
            case RIGHT:
                moveMouse(0, 1);
                break;
            case DOWN:
                moveMouse(1, 0);
                break;
            default:
                break;
            }
        }
        updateTimer();
        Sleep(100); // ����ˢ��Ƶ��
    }
    system("cls");
}