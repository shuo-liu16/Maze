#pragma once
#include <iostream>
#include <Windows.h>
#include "maze.h"

extern const int N1;
extern const int N2;
extern int maze[N1][N2];

using namespace std;

void print_path();

void print_shortest_path();

void view();

void dfs(int x, int y, int path_length);

void Diagram();


