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
    // ���ļ�����ʹ�� ifstream ������ȡ�ļ�
    ifstream file(filename);

    // ����ļ��Ƿ�ɹ���
    if (!file.is_open()) {
        // ����ļ���ʧ�ܣ����������Ϣ������
        cerr << "Failed to open file for reading: " << filename << endl;
        return;
    }

    // ���ļ��ж�ȡ�Թ����ݵ��Թ�����
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            file >> maze[i][j];
        }
    }

    // �ر��ļ���
    file.close();
}

void clearFile(const char* filename) {
    std::ofstream file(filename, std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Failed to open file for clearing: " << filename << std::endl;
        return;
    }
}