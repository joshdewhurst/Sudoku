#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// Define the size of the Sudoku board
const int BOARD_SIZE = 9;
const int SUBGRID_SIZE = 3;

// Define the empty cell value
const int EMPTY = 0;

// Define the board type
typedef vector<vector<int>> Board;