#include <stdio.h>
#define N 4
int board[N][N];

int is_safe(int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return 0;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return 0;
    }
    for (i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
            return 0;
    }
    return 1;
}

void print_board()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            if(board[i][j]==1)
            printf("Q %d\t", i+1);
            else
            printf("*\t");
        printf("\n");
    }
    printf("\n");
}

void solve(int col)
{
    int i;
    if (col == N)
    {
        print_board();
        return;
    }
    for (i = 0; i < N; i++)
    {
        if (is_safe(i, col))
        {
            board[i][col] = 1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
}

int main()
{
    printf("Possible solutions : \n");   
    solve(0);
    return 0;
}