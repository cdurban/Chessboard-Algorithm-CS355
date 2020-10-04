/*
 * Chase Urban
 * Homework 2 - king.cpp
 * COMPSCI 355-01
 * Due 9/25/2020
 */

#include <iostream>

using namespace std;

/**
 * Dynamic programming function to calculate the number of possible paths to be taken
 * by a king from the first file to the last file of a chessboard of a given row and
 * column count. It does this by using a nested for loop to simulate each possible path
 * through the board, and calculating the sum of all of the number of paths to each
 * cell in the last column, therefore the total number of paths from the first file to
 * the last file
 *
 * @param row - number of rows to this chessboard
 * @param col - number of columns to the chessboard
 * @return - number of paths from the first file to the last file
 */
unsigned long long getNumPaths(int row, int col);

int main() {
    for (int i = 0; i < 100; i++) {
        int row, col;
        std::cout << "Enter chessboard dimensions: ";
        std::cin >> row >> col;
        std::cout << "Paths from first to last file: " << getNumPaths(row, col) << endl
                << endl;
    }
}

unsigned long long getNumPaths(int row, int col){
    /*
     * Creates an two-dimensional array of unsigned long long type, meant for
     * traversing and counting the total number of times each cell is passed through.
     */
    unsigned long long board[row][col];
    // Creates a counter variable for the number of paths to be counted after
    // traversing  the array.
    unsigned long long paths = 0;

    /*
     * Loops through the first file of the board, and sets each cell to one, as there
     * is only one way to get to each
     * cell of the first file
     */
    for (int i = 0; i < row; i++){
        board[i][0] = 1;
    }

    /*
     * Loops through the entire two-dimensional array, and calculates the number of
     * possible paths to get to each cell by finding the sum of the cell to the left,
     * the  cell to the top-left (if current cell is not in the top row),
     * and the cell to the bottom-left (if the cell is not in the bottom row)
     */
    for (int i = 1; i < col; i++){
        for(int j = 0; j < row; j++){

            // If we are in the top row, we will calculate the sum of the left and
            // bottom-left cells
            if (j == 0){
                board[j][i] = board[j][i-1] + board[j+1][i-1];
            }

            // If we are in the bottom row, we will calculate the sum of the left and
            // top-left cells
            else if (j == row-1){
                board[j][i] = board[j][i-1] + board[j-1][i-1];
            }

            //Otherwise, we will calculate the sum of the left, top-left, and
            // bottom-left cells
            else {
                board[j][i] = board[j][i-1] + board[j+1][i-1] + board[j-1][i-1];
            }
        }
    }

    /*
     * Then, we cycle through each cell in the last file, and collect the sum of these
     * cells. This collected sum is the total number of paths to get from the first
     * file to the last file, which is then returned.
     */
    for (int i = 0; i < row; ++i) {
        paths += board[i][col-1];
    }
    return paths;
}