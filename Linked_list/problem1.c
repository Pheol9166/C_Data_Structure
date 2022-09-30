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
    struct Node* prev; // 이전 노드를 가리키는 포인터
    char data; // 영문자 데이터
    struct Node* next; // 다음 노드를 가리키는 포인터
} Node;

Node* head; // header
Node* tail; // trailer
int count; // 전체 노드 수

Node* makenode(char);
void init();
void add(int, char);
void delete(int);
void get(int);
void print();

int main()
{
    int n; // 연산 수
    int position; 
    char mode; // 연산 종류
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
            case 'A': // add(list, position, item) 
                scanf("%d %c", &position, &data);
                add(position, data);
                getchar();
                break;

            case 'D': // delete(list, position)
                scanf("%d", &position);
                delete(position);
                getchar();
                break;

            case 'G': // get(list, position)
                scanf("%d", &position);
                get(position);
                getchar();
                break;

            case 'P': // print(list)
                print();
                break;
        }

    }

    Node* node = head;

    // 동적 할당 해제
    for (int i = 0; i < count; i++)
    {
        free(node);
        node = node->next;
    }

    return 0;
}

/**
 * @brief 노드를 생성합니다
 *  
 * @param data 영문자 데이터인 char형 변수입니다.
 * @return Node* 노드 포인터를 반환합니다.
 */
Node* makenode(char data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->prev = NULL;
    node->data = data;
    node->next = NULL;

    return node;    
}

/**
 * @brief 영문자 ADT(이중연결리스트) 생성을 위해 header와 trailer를 초기화합니다.
 * 
 */
void init()
{
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->data = '\0';
    tail->data = '\0';

    head->next = tail;
    head->prev = head; // add 함수 사용 시, 오류 발생을 막기 위해 자기 자신을 가리키도록 설정하였습니다.
    tail->next = tail;
    tail->prev = head;    
}

/**
 * @brief 영문자 데이터 추가 함수입니다. 
 * 
 * @param position 데이터 추가 위치입니다.
 * @param data 영문자 데이터입니다.
 */
void add(int position, char data)
{
    // 잘못된 position 입력 시
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

/**
 * @brief 영문자 데이터를 삭제하는 함수입니다.
 * 
 * @param position 삭제할 데이터의 위치입니다.
 */
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

/**
 * @brief position 번째에 위치한 영문자 데이터 값을 출력합니다.
 * 
 * @param position 출력할 데이터의 위치입니다.
 */
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

/**
 * @brief 영문자 ADT를 출력하는 함수입니다.
 * 
 */
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