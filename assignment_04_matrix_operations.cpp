// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "Enter element [" << r << "][" << c << "]: ";
            cin >> matrix[r][c];
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << setw(5) << matrix[r][c];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], int rows, int cols,
                     int result[][MAX_SIZE]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            result[c][r] = matrix[r][c];
        }
    }
}

void addMatrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int rows, int cols,
                 int result[][MAX_SIZE]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            result[r][c] = a[r][c] + b[r][c];
        }
    }
}

void multiplyMatrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int m, int n, int p,
                      int result[][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int total = 0;
            for (int k = 0; k < n; k++) {
                total = total + a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

bool isValidSize(int size) {
    return size > 0 && size <= MAX_SIZE;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int a[MAX_SIZE][MAX_SIZE];
    int b[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows, cols, m, n, p;

    cout << "PART A - TRANSPOSE" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (!isValidSize(rows) || !isValidSize(cols)) {
        cout << "Error: Size must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }

    readMatrix(matrix, rows, cols);
    transposeMatrix(matrix, rows, cols, result);

    cout << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(matrix, rows, cols);
    cout << endl;
    cout << "Transposed Matrix:" << endl;
    printMatrix(result, cols, rows);

    cout << endl;
    cout << "PART B - ADDITION" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (!isValidSize(rows) || !isValidSize(cols)) {
        cout << "Error: Size must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }

    cout << "Matrix A:" << endl;
    readMatrix(a, rows, cols);
    cout << "Matrix B:" << endl;
    readMatrix(b, rows, cols);
    addMatrices(a, b, rows, cols, result);

    cout << endl;
    cout << "Sum Matrix:" << endl;
    printMatrix(result, rows, cols);

    cout << endl;
    cout << "PART C - MULTIPLICATION" << endl;
    cout << "Enter rows in A: ";
    cin >> m;
    cout << "Enter columns in A (also rows in B): ";
    cin >> n;
    cout << "Enter columns in B: ";
    cin >> p;

    if (!isValidSize(m) || !isValidSize(n) || !isValidSize(p)) {
        cout << "Error: Size must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }

    cout << "Matrix A:" << endl;
    readMatrix(a, m, n);
    cout << "Matrix B:" << endl;
    readMatrix(b, n, p);
    multiplyMatrices(a, b, m, n, p, result);

    cout << endl;
    cout << "Product Matrix:" << endl;
    printMatrix(result, m, p);

    return 0;
}

