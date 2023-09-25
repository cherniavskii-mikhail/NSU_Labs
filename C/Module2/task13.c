#include <stdio.h>
#include <malloc.h>
#include <math.h>

void make_buffer(int number)
{
    int n = 0, copy_numb = number;
    int* rez;

    while (copy_numb != 0)
    {
        n++;
        copy_numb /= 10;
    }

    rez = (int*)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--)
    {
        rez[i] = number % 10;
        number /= 10;
    }

    for (int i = 0; i < n; i++)
        printf("%d", rez[i]);

    free(rez);
}

int count_factorial(int numb)
{
    int rez = 1;

    for (int i = 1; i <= numb; i++)
        rez *= i;

    return rez;
}

int make_numb(int* number, int n)
{
    int numb = 0, shift = 1;
    

    for (int i = n - 1; i >= 0; i--)
    {
        numb += number[i] * shift;
        shift *= 10;
    }

    return numb;
}

int main()
{
    int* number;
    int n = 0, numb = 0, numb_rez = 0;

    scanf_s("%d", &n);

    number = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf_s("%d", number + i);

    numb = make_numb(number, n);

    numb_rez = count_factorial(numb);

    make_buffer(numb_rez);
 
    free(number);
    return 0;
}
