#include <stdio.h>

void printBoard(int[9][9]);

int main()
{
    int game_board[9][9] = {
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
    
    printBoard(game_board);
    
    return 0;
}

void printBoard(int board[9][9]){
    for (size_t i = 0; i < 9; i++)
    {
        printf("{");
        for (size_t j = 0; j < 9; j++)
        {
            if (j == 8)
                printf("%d", board[i][j]);
            else
                printf("%d, ", board[i][j]);
        }
        printf("} \n");
    };
}
    