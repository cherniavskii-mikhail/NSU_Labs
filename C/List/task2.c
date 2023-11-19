#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include<string.h>

struct List
{
    char value;
    struct List* next;
};

void push(struct List** head_ref, char new_value)
{
    struct List* new_list = (struct List*)malloc(sizeof(struct List));

    new_list->value = new_value;

    new_list->next = (*head_ref);

    (*head_ref) = new_list;
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

    int c = 0;
    char number = ' ';
    bool dig = true;

    while(dig)
    {
        scanf_s("%c", &number);

        dig = isdigit(number);

        if (dig)
            push(&head, number);
    }

    c = count(head);

    printf("%d", c);
    return 0;
}
