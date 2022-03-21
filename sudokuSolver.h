#ifndef sudokuSolver
#define sudokuSolver
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 9;

int ** createBoard();
void printBoard(int** board);
int verify_line(int* arr);
int verify_state(int** board);

int isSafe(int** board, int row, int col, int num);
int solveSudoku(int** board);
int notInRow(int** board, int row, int num);
int notInCol(int** board, int col, int num);
int notInBox(int** board, int startRow, int startCol, int num);
int FindUnassignedLocation(int** board, int *row, int *col);
void changeval(int*);

#endif