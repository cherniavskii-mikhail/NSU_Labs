#include <stdio.h>
#include <math.h>

int main() {
    int a;
    int a1, a2, a3;
    int a4, a5, a6;

    scanf_s("%d", &a);

    a1 = a * a;     // a^2
    a2 = a1 * a1; // a**4
    a3 = a2 * a2; // a**8
    a4 = a3 * a3; // a**16
    a5 = a4 * a3; // a**24
    a6 = a5 * a2; // a**28

    printf("%d", a6);

    return 0;
}

Дано вещественное число а. Получите значение pow(a, 28)  за шесть операций умножения, не используя функцию pow().
