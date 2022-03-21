#ifndef sudokuSolver
#define sudokuSolver
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 9;
//BOARD.C
int ** createBoard();
void printBoard(int** board);
//SOLVER.C
int solveSudoku2(int** board);
int verify_line(int* arr);
int verify_state(int** board);
int isSafe(int** board, int row, int col, int num);
int notInRow(int** board, int row, int num);
int notInCol(int** board, int col, int num);
int notInBox(int** board, int startRow, int startCol, int num);
int FindUnassignedLocation(int** board, int *row, int *col);
//GENERATOR.C
int** generateBoard();
int fillSudoku(int** board);
void shuffle(int* arr, size_t n);
int checkBoard(int** board);
int solveSudoku(int** board);

#endif