#include <stdio.h>
#include <stdlib.h>
#include <bits/types.h>
#include <time.h>

void Algo1(int **A, int m, int n)
{
    int Elem,j;
    // main loop
    for (int r = 0; r < n; r++)
    {
        // secondary loop
        for (int i = 1; i < m; i++)
        {
            Elem = A[i][r];
            j = 0;
            // third loop
            while (Elem > A[j][r])
                j = j + 1;
            //fourth loop
            for (int k = i - 1; k >= j; k--)
                A[k + 1][r] = A[k][r];
            A[j][r] = Elem;
        }
    }
}
int main()
{
    int **A;
    int m = 10;
    int n = 10;
    A = (int **)malloc((unsigned long)m*sizeof(int *));
    for (int i = 0; i < m; i++)
        A[i] = (int *)malloc((unsigned long)n*sizeof(int));
    
    srand((unsigned) time(0));
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
            A[i][k] = rand() % (20 + 1);
    }
    printf("\nNot sorted\n");
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
            printf("%d\t", A[i][k]);
        printf("\n");
    }
    Algo1(A, m, n);
    printf("\nSorted\n");
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
            printf("%d\t", A[i][k]);
        printf("\n");
    }
}