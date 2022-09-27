#include <stdio.h>
#include <stdlib.h>

/* N개(3 <= N <= 100)의 정수로 이루어진 수열 X를 "뒤집기 정보"에 의해 변환한 최종 결과를 출력하는 프로그램 */
/* ex) (3, 7) --> 3번째 수부터 7번째 수까지 순서가 반대로 바뀐다. */

void reverse(int*, int, int);

int main()
{
    int n, revn, a, b; // 수열 길이, 뒤집기 정보 수, 뒤집기 정보 (a, b)
    int* arr; // 수열
    
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // 수열 값 할당
    }

    scanf("%d", &revn); // 뒤집기 수 입력

    for (int i = 0; i < revn; i++)
    {
        scanf("%d %d", &a, &b); // 뒤집기 정보 입력
        reverse(arr, a, b); // 뒤집기 실행
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); // 수열 출력
    }

    free(arr);
    
    return 0;
}

void reverse(int* arr, int a, int b)
{
    int temp;

    for (int i = a; i <= (a + b) / 2; i++) // 
    {
        temp = arr[i];
        arr[i] = arr[b + a - i];
        arr[b + a - i] = temp;
    }
}

/* missing point: 정수 / 정수 => 정수 */