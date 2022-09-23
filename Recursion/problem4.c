#include <stdio.h>
#include <stdlib.h>

/* 정수 n <= 20을 입력 받아 최댓값을 구하는 프로그램을 작성하시오 */
int maxone(int*, int);

int main()
{
    int n;
    int* arr;
    scanf("%d", &n);

    arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxone(arr, n));

    return 0;
}

int maxone(int* arr, int n)
{  
    int max_num;

    if (n == 1)
        return arr[n - 1];
    
    max_num = maxone(arr, n - 1);

    if (max_num > arr[n - 1])
        return max_num;

    else
        return arr[n - 1];

}