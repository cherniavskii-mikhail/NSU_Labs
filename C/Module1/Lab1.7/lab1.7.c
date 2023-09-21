#include <stdio.h>
#include <math.h>


int main() {
    int a, b;
    scanf_s("%d %d", &a, &b);
    printf("%d", (int)(ceil(((float)(ceil((float)(a % b) / a) + ceil((float)(b % a) / b) + 1)) / 2))); 
}
// ceil((float)(a%b)/a) -  остаток деления а от b (т.е может быть два случая: 0 при a%b = 0, 1 при а%b = остатку от деления.
//ceil(...+1))/2 - нужно для выполнения условия задачи при a=b, т.к. при таких условиях a%b = b%a = 0 => нам нужно прибавить 1,затем разделить, ведь иначе при а!=b результат будет 2, а не 1.
//А при a%b != 0 сумма до деления на 2 будет больше 2 => функция ceil вернет число большее 2.

Даны два целых числа a и b. Если a делится на b или b делится на a, то вывести 1, иначе — любое другое число. 
Условные операторы и операторы цикла не использовать.
