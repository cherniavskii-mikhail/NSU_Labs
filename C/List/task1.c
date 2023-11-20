#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct List
{
    int value;
    struct List* next;
};

void push(struct List** head, int new_key)
{
    struct List* new_list = (struct List*)malloc(sizeof(struct List));

    new_list->value = new_key;

    new_list->next = (*head);

    (*head) = new_list;
}

bool search(struct List* head, int x)
{

    struct List* current = head;

    while (current != NULL)
    {
        if (current->value == x)
            return true;
        current = current->next;
    }

    return false;
}


int main()
{
    // Start with the empty list 
    struct List* head = NULL;

    int n = 0, number = 0;
    bool find = true;

    scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &number);
        push(&head, number);
    }

    scanf_s("%d", &number);
    find = search(head, number);

    if (find)
        printf("Yes");
    else
        printf("No");

    return 0;
}
