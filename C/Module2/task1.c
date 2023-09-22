#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int numb_square(int numb)
{
    int copy_numb = 0;
    
    copy_numb = sqrt(numb);

    if (pow(copy_numb, 2) == numb)
        return 1;
    else
        return 0;
}

int main() 
{
    int n = 0;
    int count = 0;

    scanf_s("%d", &n);

    int* numbers = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", numbers + i);

        count += numb_square(*(numbers + i));
    }

    printf("%d", count);

    free(numbers);
    return 0;
}

Даны целые числа a1, a2, a3, ... an. Найдите количество чисел, являющихся полными квадратами. Определите функцию, позволяющую распознавать полные квадраты.
  
