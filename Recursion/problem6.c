#include <stdio.h>

/* 두 개의 양의 정수를 입력받아 최대공약수를 유클리드 호제법으로 계산, 출력하라 */
int gcd(int, int);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
}

int gcd(int first, int second)
{
    if (second == 0)
        return first;

    gcd(second, first % second);
}