#include <stdio.h>
#include <string.h>

/* 공백 없는 영어 문자열 하나를 입력받아 특정 문자가 몇 번 나타나는지 검사하는 프로그램 */
/* 문자열 길이는 최대 100, 대소문자 구별 */
int charcheck(char*, char);

int main()
{
    char string[100];
    char c;

    scanf("%s", string);
    getchar();
    scanf("%c", &c);

    printf("%d\n", charcheck(string, c));

    return 0;
}

int charcheck(char* arr, char c)
{
    if (*arr == '\0')
        return 0;
   
    else
    {
        if (*arr == c)
            return 1 + charcheck(arr + 1, c);
        
        else
            return 0 + charcheck(arr + 1, c);
    }
}