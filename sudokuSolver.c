
#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main()
{
    int** board;
    board = createBoard();
    printBoard(board);
    free(board);
    return 0;
}

    