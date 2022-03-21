#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudokuSolver.h"

int main()
{
    int** board;    //empty Board
    board = generateBoard();  //Generate random puzzle

    printf("Generating puzzle:\n");
    printBoard(board);

    if (verify_state(board))
        printf("Puzzle generated\n");
    else
        printf("Error generating board");

    printf("Solving puzzle: \n");
    
    if(solveSudoku2(board))
        printBoard(board);
    else
        printf("Couldnt solve the board");
        
    free(board);
    return 0;
}

    