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

// Print the Sudoku board to the console
void print_board(const Board& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % SUBGRID_SIZE == 0 && j < BOARD_SIZE - 1) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % SUBGRID_SIZE == 0 && i < BOARD_SIZE - 1) {
            cout << "------+-------+------" << endl;
        }
    }
}