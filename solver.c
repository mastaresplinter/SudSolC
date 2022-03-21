#include "sudokuSolver.h"
#define N 9
#define EMPTY 0

int verify_line(int *array){

    for (int i = 0; i < N -1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (array[i] != 0 && array[i] == array[j])
            {   
                return 0;
            }
        }
    }
    return 1;
}

int verify_state(int **board){
    int arr[N], box[N];
    int k = 0;

    for (int i = 0; i < N; i++)
    {
        if (!verify_line(board[i]))
            return 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[j] = board[i][j];
        }
        
        if (!verify_line(arr))
            return 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                box[k] = board[(i % 3) * 3 + row][(i / 3 % 3) * 3 + col];
                k = k + 1;
            }
        }
        if(!verify_line(box))
            return 0;
        k = 0;
    }
    return 1;
}

int notInRow(int** board, int row, int num){
    for (int col = 0; col < N; col++)
    {
        if (board[row][col] == num)
        {
            return 0;
        }
    }
    return 1;
}

int notInCol(int** board, int col, int num){
    for (int row = 0; row < N; row++)
    {
        if (board[row][col] == num)
        {
            return 0;
        }
    }
    return 1;
}

int notInBox(int** board, int startRow, int startCol, int num){
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[startRow + row][startCol + col] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}

int isSafe(int** board, int row, int col, int num){
    return (notInRow(board, row, num) 
    && notInCol(board, col, num) 
    && notInBox(board, row - (row%3), col - (col%3), num) 
    && (board[row][col] == EMPTY));
}

int FindUnassignedLocation(int** board, int *row, int *col){

    for (*row = 0; *row < N; *row = *row +1)
    {
        for (*col = 0; *col < N; *col = *col +1)
        {
            if (board[*row][*col] == EMPTY)
            {
                return 1;
            }
        }
    }
    return 0;
}

int solveSudoku(int** board){
    int row, col;

    if(!FindUnassignedLocation(board, &row, &col))
        return 1;

    for (int num = 1; num < 10; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku(board))
            {
                return 1;
            }
            board[row][col] = EMPTY;
        }
    }
    return 0;
}

void changeval(int* val){
    *val = *val +10;
    return;
}