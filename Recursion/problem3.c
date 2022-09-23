#include <stdio.h>

/* problem2의 출력을 역순으로 만들어라 */

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

    printf("%d\n", n % 10);
    
    printbyOne(n / 10);
} 