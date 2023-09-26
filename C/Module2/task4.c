#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int numbers_lengh(int* numbers, int n)
{
    int len = 0, max_len = 0;

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] % 2 != 0)
            len++;
        else
        {
            if (max_len < len)
                max_len = len;
            len = 0;
        }
    }

    if (max_len < len)
        max_len = len;

    return max_len;
}

int main()
{
    int *numbers, n = 0, len = 0;

    scanf_s("%d", &n);
    numbers = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf_s("%d", numbers + i);

    len = numbers_lengh(numbers, n);

    printf("%d", len);

    free(numbers);
    return 0;
}
