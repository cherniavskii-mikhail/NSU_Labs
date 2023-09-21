#include <stdio.h>

int main() 
{
    int num1, num2;

    scanf_s("%d", &num1);

    scanf_s("%d", &num2);

    printf("num1 = %d, num2 = %d\n", num1, num2);

  //  swap(&num1, &num2);
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

Составить программу обмена значениями двух переменных величин без использования третьей величины.
