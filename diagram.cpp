#include "diagram.h"

// 定义方向数组，用于控制移动方向
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 右、下、左、上

// 标记迷宫中的位置是否被访问过
int visited[N1][N2];

// 手动实现的栈，存储坐标对
int st[N1 * N2][2];

int shortest_path_length = INT_MAX;  // 初始化最短路径长度为一个很大的值
int shortest_path[N1 * N2][2];  // 保存最短路径

// 栈顶指针
int top = -1;

void print_path()
{
    cout << "Path:" << endl;
    for (int i = 0; i <= top; ++i) {
        cout << "(" << st[i][0] << ", " << st[i][1] << ")";
        if (i < top) cout << " -> ";
    }
    cout << endl;
}

void print_shortest_path()
{
    cout << endl << endl;
    cout << "最短路径长为: " << shortest_path_length << endl;
    cout << "Shortest Path:" << endl;
    for (int i = 0; i <= shortest_path_length; ++i) {
        cout << "(" << shortest_path[i][0] << ", " << shortest_path[i][1] << ")";
        maze[shortest_path[i][0]][shortest_path[i][1]] = 5;
        if (i < shortest_path_length) cout << " -> ";
    }
    cout << endl;
}

void view() {
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            if (maze[i][j] == WALL) {
                cout << "#";
            }
            else if (maze[i][j] == ROAD) {
                cout << " ";
            }
            else if (maze[i][j] == MOUSE || maze[i][j] == 5) {
                cout << RED_TEXT << "@" << RESET_TEXT;  // 使用红色转义码
            }
            else if (maze[i][j] == FOOD) {
                cout << GREEN_TEXT << "●" << RESET_TEXT;
            }
        }
        cout << endl;
    }
}

void dfs(int x, int y, int path_length)
{
    if (maze[x][y] == 3) {
        if (path_length < shortest_path_length) {
            shortest_path_length = path_length;
            // 将当前路径保存到最短路径数组中
            for (int i = 0; i <= top; ++i) {
                shortest_path[i][0] = st[i][0];
                shortest_path[i][1] = st[i][1];
            }
        }
        // 找到了一条路径，处理相关逻辑
        print_path();
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int new_x = x + dir[i][0];
        int new_y = y + dir[i][1];
        if (new_x >= 0 && new_x < N1 && new_y >= 0 && new_y < N2 && maze[new_x][new_y] != 1 && !visited[new_x][new_y]) {
            // 将新位置入栈
            st[++top][0] = new_x;
            st[top][1] = new_y;
            visited[new_x][new_y] = 1;

            // 递归搜索新位置
            dfs(new_x, new_y, path_length + 1);

            // 回溯，将新位置出栈，并标记为未访问
            top -= 1;
            visited[new_x][new_y] = 0;
        }
    }
}

void Diagram()
{
    system("cls");
    // 初始化迷宫地图和其他数据结构
    // 起点设定，一般为迷宫的入口，例如 (1, 1)
    int start_x = 1;
    int start_y = 1;

    // 将起点入栈并标记为已访问
    st[++top][0] = start_x;
    st[top][1] = start_y;
    visited[start_x][start_y] = 1;

    // 从起点开始深度优先搜索
    dfs(start_x, start_y, 0);

    print_shortest_path();
    view();
    
    cout << endl;
    cout << "点击继续将返回菜单！" << endl;
    system("pause");
    system("cls");
}
