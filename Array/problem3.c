#include <stdio.h>
#include <stdlib.h>

/* N * N 행렬에 1 ~ N^2까지의 수를 위에서부터 ->방향과 <-방향을 번갈아 가면서 채우시오. */
/* 
ex) 4 x 4 행렬
 1     2     3     4
 8     7     6     5
 9    10   11   12
16   15   14   13
*/

int main()
{
    int n; // 행렬 크기
    int temp = 1; 
    int** arr; // 행렬 
    scanf("%d", &n); 

    arr = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * n);
        
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = temp; // 행렬에 1 ~ N^2까지의 수 할당
            temp++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) // row index가 짝수면
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", arr[i][j]);
            }
        }
        else // row index가 홀수면
        {
            for (int j = n - 1; j >= 0; j--)
            {
                printf("%d ", arr[i][j]);
            }

        }

        printf("\n");
    }

    for (int i = 0; i < n; i++) 
    {
        free(arr[i]);
    }
    free(arr); // 동적 할당 해제

    return 0;
}