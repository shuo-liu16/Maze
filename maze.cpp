#include "maze.h"

// 定义全局变量来跟踪时间
time_t startTime;
time_t currentTime;

//上下左右控制方向
enum Direction { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };

Pos pos_Mouse;
int flag;

//迷宫地图
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

//初始化
void init() {
    flag = 0;

    pos_Mouse.x = 1;
    pos_Mouse.y = 1;
    maze[pos_Mouse.x][pos_Mouse.y] = MOUSE;
}

//欢迎 
void welcome() {
    string script1 =
        "场景一：汤姆的家\n"
        "\n\n"
        "（汤姆正在家中打盹，突然注意到家里的食物储备似乎减少了一些。）\n"
        "汤姆：“咦？家里的奶酪怎么少了？肯定是那只狡猾的杰瑞又偷吃了！”\n" 
        "（汤姆决定设置一个迷宫陷阱来抓住杰瑞。）"
        "\n\n";
 
    cout << script1 << endl;
    system("pause");
    system("cls");

    string script2 =
        "场景二：迷宫搭建"
        "\n\n"
        "汤姆忙碌地在家中布置迷宫，设置各种障碍和陷阱，迷宫的终点放置了一块诱人的奶酪作为诱饵。"
        "\n\n";
    cout << script2 << endl;
    system("pause");
    system("cls");

    string script3 =
        "（杰瑞闻到了奶酪的香味，悄悄地探出头来寻找来源。）"
        "\n\n"
        "杰瑞（兴奋地）：“哇！奶酪！汤姆这家伙又在搞什么鬼？”"
        "（杰瑞决定冒险进入迷宫，寻找奶酪。）"
        "\n\n"
        "接下来游戏开始，祝你玩的开心！"
        "\n\n";
    cout << script3 << endl;

    cout << "#" << "  围墙" << endl;
    cout << RED_TEXT << "@" << RESET_TEXT << "  杰瑞(MOUSE)" << endl;
    cout << GREEN_TEXT << "●" << RESET_TEXT << "  食物(Food)" << endl;
    system("pause");
    system("cls");

}

//隐藏光标
void HideCursor() {
    CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量

    curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
    curInfo.bVisible = FALSE; //将光标设置为不可见

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
    SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}


/*//光标隐藏
void HideCursor()
{
    ShowCursor(FALSE);
}
*/

//光标跳转
void CursorJump(int x, int y) {
    COORD pos;  // 定义一个 COORD 结构体变量 pos，用来存储光标的位置信息

    pos.X = x;  // 设置 pos 的 X 坐标为传入的 x 参数
    pos.Y = y;  // 设置 pos 的 Y 坐标为传入的 y 参数

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取标准输出的句柄
    SetConsoleCursorPosition(handle, pos);  // 将光标位置设置为 pos 所指定的位置
}


//初步绘制地图 
void drawMaze() {

    CursorJump(47, 1);
    cout << "Welcome to RAT IN MAZE" << endl;

    for (int i = 0; i < N1; ++i) {

        //为了使迷宫居中多次目测出来的 
        CursorJump(48, i + 3);

        for (int j = 0; j < N2; ++j) {
            if (maze[i][j] == WALL) {
                cout << "#";           
            }
            else if (maze[i][j] == ROAD) {
                cout << " ";
            }
            else if (maze[i][j] == MOUSE) {
                cout << RED_TEXT << "@" << RESET_TEXT;  // 使用红色转义码
            }
            else if (maze[i][j] == FOOD) {
                cout << GREEN_TEXT << "●" << RESET_TEXT;
            }
        }
        cout << endl;
    }
}

//移动 
void moveMouse(int dx, int dy) {
    if (maze[pos_Mouse.x + dx][pos_Mouse.y + dy] == WALL)
        return;

    // 将当前位置恢复为道路    
    maze[pos_Mouse.x][pos_Mouse.y] = ROAD;
    CursorJump(48 + pos_Mouse.y, pos_Mouse.x + 3);
    cout << " ";

    pos_Mouse.x += dx;
    pos_Mouse.y += dy;

    // 更新老鼠的新位置
    maze[pos_Mouse.x][pos_Mouse.y] = MOUSE;
    CursorJump(48 + pos_Mouse.y, pos_Mouse.x + 3);
    cout << RED_TEXT << "@" << RESET_TEXT;
}

//胜利判定 
void checkWin() {
    if (pos_Mouse.x == N1 - 2 && pos_Mouse.y == N2 - 2) {
        CursorJump(39, N1 + 3 + 1);
        cout << "Congratulations! 你帮助杰瑞逃脱了追捕，获得了奶酪！" << endl;
        system("pause");

        flag = 1;
    }
}

// 初始化计时器  
void initTimer() {
    startTime = time(nullptr);
}

// 更新并显示倒计时  
void updateTimer() {
    currentTime = time(nullptr);

    int elapsedSeconds = difftime(currentTime, startTime);

    // 输出经过的时间，以分钟和秒的形式  
    int minutes = elapsedSeconds / 60;
    int seconds = elapsedSeconds % 60;

    CursorJump(30, 5);
    cout << "Time: " << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << target_time - seconds << endl;

    if (seconds == target_time) {
        CursorJump(39, N1 + 3 + 1);
        cout << "时间耗尽，你被Tom抓到了! 真是菜啊！！" << endl;
        system("pause");

        flag = 1;
    }
}

void Game() {
    system("cls");

    init();

    HideCursor();

    welcome();

    drawMaze(); // 绘制迷宫

    initTimer();

    // 主循环
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
        Sleep(100); // 控制刷新频率
    }
    system("cls");
}