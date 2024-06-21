#pragma once
#include <iostream>
#include <fstream>
#include "maze.h"
// π”√N1 N2 maze[][]
using namespace std;

void saveMaze(const char* filename);
void loadMaze(const char* filename);
void clearFile(const char* filename);
