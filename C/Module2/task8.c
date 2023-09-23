#include <stdio.h>

int check_number(int number1, int number2) {
    if (number2 <= 1)
        return 0;
    else
        if (number1 % number2 != 0)
            return check_number(number1, number2 - 1);
        else
            return 1;
}


int main() 
{
    int n = 0, check_flag = 0;

    scanf_s("%d", &n);

    check_flag = check_number(n, n - 1);

    if (check_flag == 1)
        printf("It isn't simple number!!!");
    else if (check_flag == 0)
        printf("It is simple number!!!");

    return 0;

}
