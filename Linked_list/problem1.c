#include <stdio.h>
#include <stdlib.h>

/*
doubly linked list

영문자 ADT 구현, 네 가지 연산 지원 (위치는 1번째)

- add(list, position, item) : list의 position번째에 item을 추가한다.
- delete(list, position) : list의 position번째 위치한 item을 삭제한다.
- get(list, position) : list의 position번째 위치한 item 값을 리턴한다.
- print(list) : list의 모든 item을 list에 저장된 순서대로 공백없이 출력한다.

※ position 정보가 유효하지 않으면 화면에 에러 메시지 "invalid position" 출력하고, 해당 연산은 무시
*/

typedef struct Node
{
    struct Node* prev;
    char data;
    struct Node* next;
} Node;

Node* head;
Node* tail;
int count;

Node* makenode(char);
void init();
void add(int, char);
void delete(int);
void get(int);
void print();

int main()
{
    int n;
    int position; 
    char mode;
    char data;

    init();
    
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        scanf("%c", &mode);
        getchar();
        switch(mode)
        {
            case 'A':
                scanf("%d %c", &position, &data);
                // printf("%d %c\n", position, data);
                add(position, data);
                getchar();
                break;

            case 'D':
                scanf("%d", &position);
                delete(position);
                getchar();
                break;

            case 'G':
                scanf("%d", &position);
                get(position);
                getchar();
                break;

            case 'P':
                print();
                break;
        }

    }

    Node* node = head;
    for (int i = 0; i < count; i++)
    {
        free(node);
        node = node->next;
    }

    return 0;
}

Node* makenode(char data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->prev = NULL;
    node->data = data;
    node->next = NULL;

    return node;    
}

void init()
{
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->data = '\0';
    tail->data = '\0';

    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;    
}

void add(int position, char data)
{
    if (position - 1 > count)
    {
        printf("invalid position\n");
        return;
    }

    Node* new = makenode(data);
    Node* n;
    n = head;

    for (int i = 0; i < position - 1; i++)
        n = n->next;
    
    new->prev = n;
    new->next = n->next;
    n->next->prev = new;
    n->next = new;

    count++;

}

void delete(int position)
{
    if (position > count)
    {
        printf("invalid position\n");
        return;
    }

    Node* n;
    n = head;

    for (int i = 0; i < position; i++)
        n = n->next;
    
    n->prev->next = n->next;
    n->next->prev = n->prev;
    n->next = NULL;
    n->prev = NULL;

    count--;
}

void get(int position)
{
    if (position > count)
    {
        printf("invalid position\n");
        return;
    }

    Node* n;
    n = head;
    
    for (int i = 0; i < position; i++)
        n = n->next;

    printf("%c\n", n->data);
}

void print()
{
    Node* n;
    n = head;

    while (n->next != tail)
    {
        n = n->next;
        printf("%c", n->data);
        
    }
    printf("\n");
}