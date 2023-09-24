#include <stdio.h>
#include <malloc.h>

int symmetry(int* numbers, int start, int end)
{
    while (start <= end)
    {
        if (*(numbers + start) == *(numbers + end))
            return symmetry(numbers, start + 1, end - 1);
        else
            return -1;
    }

    return 1;
}

int main() 
{
    int n = 0, start = 0, end = 0, flag = 0; 
    int* numbers;

    scanf_s("%d", &n);

    numbers = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf_s("%d", numbers + i);

    end = n - 1;

    flag = symmetry(numbers, start, end);

    if (flag == 1)
        printf("The buffer is symmetric!!!");
    else 
        printf("The buffer isn't symmetric!!!");

    free(numbers);
    return 0;
}
