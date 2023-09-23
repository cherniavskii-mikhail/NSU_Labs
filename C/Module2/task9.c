#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

int max_element(int* numbers, int n, int max)
{
    if (n >= 0)
    {
        if (*(numbers + n) > max)
        {
            max = *(numbers + n);
            max = max_element(numbers, n - 1, max);
        }
        else
             max = max_element(numbers, n - 1, max);
    }

    return max;
}

int main() 
{
    int n = 0, max = 0; 

    scanf_s("%d", &n);

    int* numbers = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf_s("%d", numbers + i);

    max = max_element(numbers, n-1, max);

    printf("%d", max);
    
    free(numbers);
    return 0;
}
