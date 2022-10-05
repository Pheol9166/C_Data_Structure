#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* 다음의 스택 ADT를 배열로 구현하고 테스트하는 프로그램을 작성하세요 */
/* 데이터: 영문자, 다음 연산 지원 */
/*
- push(stack, ‘c’) : 
  stack의 top에 데이터를 추가한다. 

- pop (stack) : 
  stack의 top에 있는 데이터를 반환하고 stack에서 제거한다. 

- peek(stack): 
  stack의 top에 있는 데이터를 화면에 출력한다. stack은 변화하지 않는다.

- duplicate(stack): 
  stack의 top에 있는 데이터를 pop해서 두 번 push 한다. 

- upRotate(stack, n): 
  stack의 맨 위 n 개의 데이터를 회전시킨다. 
  단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.

- downRotate(stack, n): 
  stack의 맨 위 n 개의 데이터를 회전시킨다. 
  단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.

- print(stack) : 
  stack의 모든 데이터를 top에서부터 순서대로 공간없이 출력한다.
*/

/* 연산 종류: POP, PUSH, PEEK, DUP, UpR, DownR, PRINT로 주어짐 */
typedef struct 
{
    char* stack;
    int top;
    int n; 
} Stack;

bool isStackFull(Stack*);
bool isStackEmpty(Stack*);
void push(Stack*, char);
char pop(Stack*);
void peek(Stack*);
void duplicate(Stack*);
void upRotate(Stack*, int);
void downRotate(Stack*, int);
void print(Stack*);

int main()
{
  Stack s;
  s.top = -1;
  char answer[6];
  int cal;

  scanf("%d", &s.n);
  scanf("%d", &cal);

  s.stack = (char*)malloc(sizeof(char) * s.n);

  for (int i = 0; i < cal; i++)
  {
    scanf("%s", answer);
    getchar();
    if (strcmp(answer, "PUSH") == 0)
    {
      char c;

      scanf("%c", &c);
      push(&s, c);
    }

    else if (strcmp(answer, "POP") == 0)
    {
      pop(&s);
    }
    else if (strcmp(answer, "PEEK") == 0)
    {
      peek(&s);
    }
    else if (strcmp(answer, "DUP") == 0)
    {
      duplicate(&s);
    }
    else if (strcmp(answer, "UpR") == 0)
    {
      int n;
      scanf("%d", &n);
      upRotate(&s, n);
    }

    else if (strcmp(answer, "DownR") == 0)
    {
      int n;
      scanf("%d", &n);
      downRotate(&s, n);
    }

    else if (strcmp(answer, "PRINT") == 0)
    {
      print(&s);
    }
    else
    {
      printf("잘못 입력하였습니다.\n");
    }
  }

}

bool isStackFull(Stack* s)
{
  if (s->top + 1 == s->n)
      return true;
  return false;
}

bool isStackEmpty(Stack* s)
{
  if (s->top == -1)
      return true;
  return false;
}

void push(Stack* s, char c)
{
  if (isStackFull(s))
  {
    printf("Stack FULL\n");
    return; 
  }
  s->top ++;
  s->stack[s->top] = c;
}

char pop(Stack* s)
{
  char result;
  if (isStackEmpty(s))
  {
    printf("Stack Empty\n");
    return '\0';
  }

  result = s->stack[s->top];
  s->top --;
  return result;
}

void peek(Stack* s)
{
  if (isStackEmpty(s))
  {
    printf("Stack Empty\n");
    return;
  }

  printf("%c\n", s->stack[s->top]);
}

void duplicate(Stack* s)
{
  char top1;

  if (isStackEmpty(s))
  {
    printf("Stack Empty\n");
    return;
  }
  top1 = pop(s);
  push(s, top1);
  push(s, top1);
}

void upRotate(Stack* s, int n)
{
  if (n > s->top + 1)
    return;
  
  char temp = s->stack[s->top];

  for (int i = s->top; i > s->top - n; i--)
  {
      s->stack[i] = s->stack[i - 1];
  }

  s->stack[s->top - n + 1] = temp;
}

void downRotate(Stack* s, int n)
{
  if (n > s->top + 1)
    return;
  
  char temp = s->stack[s->top - n + 1];

  for (int i = s->top - n + 1; i < s->top; i++)
  {
    s->stack[i] = s->stack[i + 1];
  }

  s->stack[s->top] = temp;
}

void print(Stack* s)
{
  for (int i = s->top; i >= 0; i--)
  {
    printf("%c", s->stack[i]);
  }

  printf("\n");
}