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

// Check if a value is valid for a given cell
bool is_valid(const Board& board, int row, int col, int value) {
    // Check row and column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == value || board[i][col] == value) {
            return false;
        }
    }
    // Check subgrid
    int subgrid_row = (row / SUBGRID_SIZE) * SUBGRID_SIZE;
    int subgrid_col = (col / SUBGRID_SIZE) * SUBGRID_SIZE;
    for (int i = 0; i < SUBGRID_SIZE; i++) {
        for (int j = 0; j < SUBGRID_SIZE; j++) {
            if (board[subgrid_row + i][subgrid_col + j] == value) {
                return false;
            }
        }
    }
    // If all checks passed, the value is valid
    return true;
}

// Find the next empty cell on the board
bool find_empty_cell(const Board& board, int& row, int& col) {
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY) {
                return true;
            }
        }
    }
    // If no empty cell was found, the board is full
    return false;
}

// Solve the Sudoku board using backtracking
bool solve_board(Board& board) {
    int row, col;
    // Find the next empty cell
    if (!find_empty_cell(board, row, col)) {
        return true; // The board is full and solved
    }
    // Try values for the empty cell and backtrack if they are not valid
    for (int value = 1; value <= BOARD_SIZE; value++) {
        if (is_valid(board, row, col, value)) {
            board[row][col] = value;
            if (solve_board(board)) {
                return true;
            }
            board[row][col] = EMPTY;
        }
    }
    // If no valid value was found, backtrack
    return false;
}

// Generate a random Sudoku board
void generate_board(Board& board)