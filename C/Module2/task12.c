#include <stdio.h>
#include <malloc.h>

int numb_sum(int* number1,int* number2, int fin, int max_lh, int min_lh, int flag)
{
    int rez = 0, rem = 0;
    int shift = 1, j = min_lh;
         
    for (int i = max_lh; i >= fin; i--)
    {
        rez += ((number1[i] + number2[j] + rem) % 10) * shift;
        rem = (number1[i] + number2[j] + rem) / 10;
        shift *= 10;
        j--;
    }

    for (int i = fin - 1; i >= 0; i--)
    {
        if (flag == 1)
        {
            rez += ((number1[i] + rem) % 10) * shift;
            rem = (number1[i] + rem) / 10;
            shift *= 10;
        }
        else if (flag == 2)
        {
            rez += ((number1[i] + rem) % 10) * shift;
            rem = (number1[i] + rem) / 10;
            shift *= 10;
        }
    }

    return rez;
}

int main() 
{
    int* number1;
    int* number2;
    int n1 = 0, n2 = 0, fin = 0, rez = 0, max_lh = 0, min_lh = 0;
    int flag = 0;

    scanf_s("%d", &n1);
    scanf_s("%d", &n2);

    number1 = (int*)malloc(n1 * sizeof(int));
    number2 = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        scanf_s("%d", number1 + i);

    for (int i = 0; i < n2; i++)
        scanf_s("%d", number2 + i);

    if (n1 > n2)
    {
        fin = n1 - n2;
        max_lh = n1 - 1;
        min_lh = n2 - 1;
        flag = 1;
        rez = numb_sum(number1, number2, fin, max_lh, min_lh, flag);
    }
    else if (n2 > n1)
    {
        fin = n2 - n1;
        max_lh = n2 - 1;
        min_lh = n1 - 1;
        flag = 2;
        rez = numb_sum(number2, number1, fin, max_lh, min_lh, flag);
    }
    else
    {
        fin = 0;
        max_lh = n1 - 1;
        min_lh = n2 - 1;
        rez = numb_sum(number1, number2, fin, max_lh, min_lh, flag);
    }

    printf("%d", rez);

    free(number1);
    free(number2);
    return 0;
}
