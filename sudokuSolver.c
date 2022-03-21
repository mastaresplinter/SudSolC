#include <stdio.h>
#include <stdlib.h>
#include "sudokuSolver.h"

int main()
{
    int** board;
    board = createBoard();
    //printBoard(board);
    //int val = 1;
    //changeval(&val);
    //printf("%d\n", val);

    int row, col;

    //printf("%d\n", FindUnassignedLocation(board, &row, &col));
    solveSudoku(board);
    printBoard(board);
    if (verify_state(board))
        printf("It is verified!");
    else
        printf("It was not verifed");
    free(board);
    return 0;
}

    