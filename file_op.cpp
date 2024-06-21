#include "file_op.h"

void saveMaze(const char* filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open file for writing: " << filename << endl;
        return;
    }

    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            file << maze[i][j] << " ";
        }
        file << endl;
    }

    file.close();
}

void loadMaze(const char* filename) {
    // 打开文件流，使用 ifstream 类来读取文件
    ifstream file(filename);

    // 检查文件是否成功打开
    if (!file.is_open()) {
        // 如果文件打开失败，输出错误信息并返回
        cerr << "Failed to open file for reading: " << filename << endl;
        return;
    }

    // 从文件中读取迷宫数据到迷宫数组
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            file >> maze[i][j];
        }
    }

    // 关闭文件流
    file.close();
}

void clearFile(const char* filename) {
    std::ofstream file(filename, std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Failed to open file for clearing: " << filename << std::endl;
        return;
    }
}