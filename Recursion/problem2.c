#include <stdio.h>

/* 양의 정수를 입력 받아, 각 자리의 수를 높은 자릿수부터 차례로 출력하는 프로그램을 작성하시오 */
/* %d로 입력받아 저장 */
void printbyOne(int);

int main()
{
    int n;
    scanf("%d", &n);

    printbyOne(n);

    return 0;
}

void printbyOne(int n)
{   
    if (n < 10)
    {
        printf("%d\n", n); 
        return;
    }
    printbyOne(n / 10);

    printf("%d\n", n % 10);
}