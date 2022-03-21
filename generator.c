#include <time.h>
#include "sudokuSolver.h"

#define N 9     //Length of array
#define EMPTY 0
int counter;
int timeflag = 0;   //Flag for srand
int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};   //Array to be shuffled

/**
 * @brief Generate a solvable sudokupuzzle layout using backtracking.
 * 
 * @return int** 
 */
int** generateBoard(){
    //Init null array
    int array[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int k, **board, **boardCopy;    
    board = malloc(9*sizeof(int *));    //Allocate memory
    for(k = 0 ; k < 9 ; k++)
        board[k] = malloc(9*sizeof(int));

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            board[i][j] = array[i][j];
        }
    }

    if (!fillSudoku(board))
    {
        return 0;
    }

    int attempts = 10, row, col, backup;
    while(attempts > 0)
    {
        row = rand() % 9;
        col = rand() % 9;
        while (board[row][col] == 0)
        {
            row = rand() % 9;
            col = rand() % 9;
        }
        backup = board[row][col];
        board[row][col] = 0;

        boardCopy = malloc(9*sizeof(int *));
        for(k = 0 ; k < 9 ; k++)
            boardCopy[k] = malloc(9*sizeof(int));

        for (size_t i = 0; i < 9; i++)
        {
            for (size_t j = 0; j < 9; j++)
            {
                boardCopy[i][j] = board[i][j];
            }
        }
        counter = 0;
        solveSudoku(boardCopy);

        if (counter != 1)
        {
            board[row][col] = backup;
            attempts = attempts - 1;
        }
    }
    free(boardCopy);
    return board;
}

int checkBoard(int** board){
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
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
            if (checkBoard(board))
            {
                counter = counter + 1;
                break;
            }
            else
            {
                if (solveSudoku(board))
                {
                    return 1;
                }
            }
            board[row][col] = EMPTY;
        }
    }
    return 0;
}


int fillSudoku(int** board){
    int row, col;
    shuffle(num, N);
    
    if(!FindUnassignedLocation(board, &row, &col))
        return 1;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, row, col, num[i]))
        {
            board[row][col] = num[i];
            if (fillSudoku(board))
            {
                return 1;
            }
            board[row][col] = EMPTY;
        }
    }
    return 0;
}

void shuffle(int *array, size_t n)
{
    if (!timeflag)
    {
        srand(time(NULL));
        timeflag = 1;
    }
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}