#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>

struct List
{
    int value;
    struct List* next;
};

void push(struct List** head_ref, int new_key)
{
    struct List* new_List = (struct List*)malloc(sizeof(struct List));

    new_List->value = new_key;

    new_List->next = (*head_ref);

    (*head_ref) = new_List;
}

int count(struct List* head)
{
    int count = 0;

    struct List* current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

int main()
{
    // Start with the empty list 
    struct List* head = NULL;

    int number = 0, c = 0;
    bool flag = 0;

    scanf_s("%d", &number);
    flag = isdigit(number);

    while(isdigit(number))
    {
        push(&head, number);
        scanf_s("%d", &number);
    }

    c = count(head);

    printf("%d", c);
    return 0;
}
