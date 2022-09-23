#include <stdio.h>

/* 양의 정수 N을 입력 받아, 1부터 N까지의 합을 구하는 프로그램을 작성하시오 */
/* 재귀로 작성 */
int sum(int);

int main()
{
    int n;
    scanf("%d", &n); // 양의 정수 n 입력

    printf("%d\n", sum(n));
}

int sum(int n)
{
    if (n <= 1) 
        return 1;

    return n + sum(n-1);
}