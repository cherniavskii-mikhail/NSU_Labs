#include <stdio.h>

int main() {
    int t = 0;
    scanf_s("%d", &t);
    if ((t % 10 == 0) || (t % 10 == 4) || (t % 10 == 5) || (t % 10 == 9))
        printf("Green");
    else
        printf("Red");
    return 0;
}

Работа светофора для пешеходов запрограммирована следующим образом: в начале каждого часа в течение трех минут горит зеленый сигнал, затем в течение двух минут — красный, в течение трех минут — опять зеленый и т. д.
Дано вещественное число t, означающее время в минутах, прошедшее с начала очередного часа.
Определить, сигнал какого цвета горит для пешеходов в этот момент.
