#include <stdio.h>
#include <stdlib.h>

/* N개의 정수로 이루어진 수열 X를 "위치 바꿈 정보"에 의해 변환한 최종 결과를 출력하는 프로그램을 작성하시오 */
void change(int*, int*, int);
int main()
{
    int n, num;
    int* arr;
    int* order;

    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &num);
    order = (int*)malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &order[i]);
    }

    change(arr, order, num);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

}

void change(int* arr, int* order, int n)
{
    int inter1, inter2, temp;

    for (int i = n - 1; i > 1; i--)
    {
        
        inter1 = order[i];
        inter2 = order[i - 1];

        temp = arr[inter1];
        arr[inter1] = arr[inter2];
        arr[inter2] = temp;
    }
}

