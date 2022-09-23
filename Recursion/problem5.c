#include <stdio.h>

/* 하노이 탑 문제 */
/* 말뚝은 각각 A, B, C (A에서 C로 옮겨야 함) */
void rHanoi(int, char, char, char);

int main()
{
    int n;
    scanf("%d", &n);

    rHanoi(n, 'A', 'B', 'C');
}

void rHanoi(int n, char from, char aux, char to)
{
    if (n == 1)
    {
        printf("%c %c\n", from, to);
        return;
    }

    rHanoi(n - 1, from, to, aux);
    printf("%c %c\n", from, to); // 가장 큰 원반을 C로
    rHanoi(n - 1, aux, from, to);
}
