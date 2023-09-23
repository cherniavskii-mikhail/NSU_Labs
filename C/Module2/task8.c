#include <stdio.h>

int check_number(int number)
{
    int check_flag = 0;
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
            check_flag++;
    }

    if (check_flag != 0)
        return 1;
    else
        return -1;

}

int main()
{
    int number;
    int check_flag = 0;

    scanf_s("%d", &number);

    check_flag = check_number(number);

    if (check_flag == 1)
        printf("It isn't simple number!!!");
    else if (check_flag == -1)
        printf("It is simple number!!!");

    return 0;
}
