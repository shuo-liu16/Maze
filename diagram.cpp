#include "diagram.h"

// ���巽�����飬���ڿ����ƶ�����
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // �ҡ��¡�����

// ����Թ��е�λ���Ƿ񱻷��ʹ�
int visited[N1][N2];

// �ֶ�ʵ�ֵ�ջ���洢�����
int st[N1 * N2][2];

int shortest_path_length = INT_MAX;  // ��ʼ�����·������Ϊһ���ܴ��ֵ
int shortest_path[N1 * N2][2];  // �������·��

// ջ��ָ��
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
    cout << "���·����Ϊ: " << shortest_path_length << endl;
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
                cout << RED_TEXT << "@" << RESET_TEXT;  // ʹ�ú�ɫת����
            }
            else if (maze[i][j] == FOOD) {
                cout << GREEN_TEXT << "��" << RESET_TEXT;
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
            // ����ǰ·�����浽���·��������
            for (int i = 0; i <= top; ++i) {
                shortest_path[i][0] = st[i][0];
                shortest_path[i][1] = st[i][1];
            }
        }
        // �ҵ���һ��·������������߼�
        print_path();
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int new_x = x + dir[i][0];
        int new_y = y + dir[i][1];
        if (new_x >= 0 && new_x < N1 && new_y >= 0 && new_y < N2 && maze[new_x][new_y] != 1 && !visited[new_x][new_y]) {
            // ����λ����ջ
            st[++top][0] = new_x;
            st[top][1] = new_y;
            visited[new_x][new_y] = 1;

            // �ݹ�������λ��
            dfs(new_x, new_y, path_length + 1);

            // ���ݣ�����λ�ó�ջ�������Ϊδ����
            top -= 1;
            visited[new_x][new_y] = 0;
        }
    }
}

void Diagram()
{
    system("cls");
    // ��ʼ���Թ���ͼ���������ݽṹ
    // ����趨��һ��Ϊ�Թ�����ڣ����� (1, 1)
    int start_x = 1;
    int start_y = 1;

    // �������ջ�����Ϊ�ѷ���
    st[++top][0] = start_x;
    st[top][1] = start_y;
    visited[start_x][start_y] = 1;

    // ����㿪ʼ�����������
    dfs(start_x, start_y, 0);

    print_shortest_path();
    view();
    
    cout << endl;
    cout << "������������ز˵���" << endl;
    system("pause");
    system("cls");
}
