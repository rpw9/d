#include <stdio.h>
#include <stdbool.h>

#define N 4  // You can change this to any number to represent the size of the chessboard

// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper diagonal on right side
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive utility function to solve N-Queens problem
bool solveNQUtil(int board[N][N], int row) {
    // Base case: If all queens are placed
    if (row >= N) {
        return true;
    }

    // Try placing a queen in each column
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Place this queen on board[row][col]
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(board, row + 1)) {
                return true;
            }

            // If placing queen in board[row][col] doesn't lead to a solution
            board[row][col] = 0; // Backtrack
        }
    }

    return false; // Backtrack if no column works
}

// Main function to solve the N-Queens problem
bool solveNQ() {
    int board[N][N] = {0}; // Initialize the chessboard

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    printBoard(board);
    return true;
}

// Entry point of the program
int main() {
    solveNQ();
    return 0;
}