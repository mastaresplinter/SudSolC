#include "sudokuSolver.h"

int** createBoard(){
    int array[9][9] = {
        {3, 0, 0, 6, 0, 2, 0, 0, 4},
        {0, 0, 0, 0, 7, 9, 8, 0, 3},
        {0, 1, 0, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 6, 0, 0, 0, 2},
        {0, 4, 1, 7, 0, 8, 0, 0, 0},
        {7, 0, 6, 0, 0, 0, 4, 0, 0},
        {9, 0, 7, 2, 8, 5, 3, 4, 0},
        {0, 8, 0, 0, 0, 0, 2, 9, 0},
        {1, 2, 3, 0, 4, 7, 5, 6, 0}
    };
    
    int k, **board;
    board = malloc(9*sizeof(int *));
    for(k = 0 ; k < 9 ; k++)
        board[k] = malloc(9*sizeof(int));

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            board[i][j] = array[i][j];
        }
    }
    return board;
}

void printBoard(int** board){
    printf("\n");
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            if (j == 0 && i ==0)
            {
                printf("------------------------\n");
            }     
            if (j % 3 == 0)
            {
                printf("| ");
            } 
            printf("%d ", board[i][j]);
            if (j == 8 && (i+1) % 3 == 0 && i > 0)
            {
                printf("\n------------------------");
            }
        }
        printf("\n");
    }
    return;
}