#include <stdio.h>
#include <stdlib.h>

void print_queens(int *queens, int n)
{
    int i = 0;
	int j =0;
    i = 0;
    while (i < n)
    {
		j = 0;
		while (j < n)
		{
			if (j == queens[i])
				printf("Q ");
			else
				printf(". ");
			j++;
		}
		i++;
		printf("\n");
    }
    printf("\n");
    return;
}
// void print_queens(int *queens, int n)
// {
//     int i;
//     i = 0;
//     while (i < n)
//     {
//         fprintf(stdout, "%d", queens[i]);
//         i++;
//     }
//     fprintf(stdout, "\n");
//     return;
// }

int is_safe(int *queens, int row, int col)
{
    int i;
    int placed_col;
    i = 0;
    while(i < row)
    {
        placed_col = queens[i];
        if (placed_col == col
            || (placed_col - i == col - row)
            || (placed_col + i == col + row))
        return (0);
        i++;
    }
    return(1);
}

void solve_nq(int *queens, int row, int n)
{
    int col;
    col = 0;
    if (row == n)
    {
        print_queens(queens, n);
        return;
    }
    while( col < n)
    {
        if (is_safe(queens, row, col))
        {
            queens[row] = col;
            solve_nq(queens, row + 1, n);
        }
        col++;
    }
    return;
}

int  main(int argc, char **argv)
{
    int n;
    int *queens;
    if (argc !=2 )
    {
        fprintf(stderr, "Usage:%s should with a number\n", argv[0]);
        return (1);
    }
    n = atoi(argv[1]);
    if (n <= 3)
    {
        fprintf(stderr, "Input number must be greater than 3\n");
        return (1);
    }
    queens = (int *)malloc(sizeof(int) * n);
    if(queens < 0)
    {
        fprintf(stderr, "Malloc is failed\n");
        return (1);
    }
    solve_nq(queens, 0, n);
    free(queens);
    return (0);
}