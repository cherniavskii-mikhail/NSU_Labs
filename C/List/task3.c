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
    struct List* new_List = (struct List*)malloc(sizeof(struct List));

    new_List->value = new_key;

    new_List->next = (*head);

    (*head) = new_List;
}

void delete(struct List** head)
{
    struct List* current = *head;
    struct List* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);

        current = next;
    }
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

    delete(&head);
  
    free(head);
    return 0;
}
