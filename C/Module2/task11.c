#include <stdio.h>
#include <malloc.h>

int buffer_check(int numb, int* numbers, int i)
{
    for (int j = 0; j < i; j++)
    {
        if (numb == numbers[j])
            return -1;
    }

    return 1;
}

int main() 
{
    int* numbers;
    int* new_numb;
    int n = 0, j = 0; 

    scanf_s("%d", &n);

    numbers = (int*)malloc(n * sizeof(int));
    new_numb = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf_s("%d", numbers + i);

    for (int i = 0; i < n; i++) 
    {
        if (buffer_check(*(numbers + i), numbers, i) == 1) 
        {
            *(new_numb + j) = *(numbers + i);
            j++;
        }
    }

    for (int i = 0; i < j; i++)
        printf("%d", *(new_numb + i));

    free(numbers);
    free(new_numb);
    return 0;
}
