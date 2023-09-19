#include<stdio.h>

int main() 
{
    int a, b, c, d;

    scanf_s("%d %d %d %d", &a, &b, &c, &d);

    if ((a / c) * (b / d) >= (a / d) * (b / c)) //solution with branching
    {
        printf("Long side to long side");
    }
    else 
    {
        printf("Long side to short side");
    }

    return 0;
}
