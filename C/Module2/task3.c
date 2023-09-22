#include <malloc.h>
#include <stdlib.h>

void zap(int* numbers, int n)
{
    for (int i = 0; i < n; i++) 
    {
        *(numbers + i) = rand();
    }
}

int main()
{
    int* numbers = 0, n;

    scanf_s("%d", &n);
    numbers = (int*)malloc(n * sizeof(int));

    zap(numbers, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", *(numbers + i));

    return 0;
}

Есть вероятность что числа повторятся
