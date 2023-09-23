#include <stdio.h>

int number_root(int sum, int numb_root, int shift)
{
    while (sum != 0)
    {
        numb_root += sum % shift;
        sum = sum / shift;
    }

    return numb_root;
}

int numb_sum(int number)
{
    if (number < 10)
        return number;
    else
        return  number % 10 + numb_sum(number / 10);
}

int main()
{
    int number;
    int sum = 0, numb_root = 0, shift = 10;

    scanf_s("%d", &number);

    sum = numb_sum(number);
    
    numb_root = number_root(sum, numb_root, shift);

    printf("%d", numb_root);

    return 0;
}
