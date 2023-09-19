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
