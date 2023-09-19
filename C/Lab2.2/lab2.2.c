#include <stdio.h>

int main() {
    int x1, x2, x3, x4, y1, y2, y3, y4;
    scanf_s("%d %d %d %d %d %d %d %d", &x1, &x2, &x3, &x4, &y1, &y2, &y3, &y4);

    if (x1 < x3)
        printf("%d", x1);
    else
        printf("%d", x3);

    if (y1 < y3)
        printf("%d", y1);
    else
        printf("%d", y3);

    if (x2 < x4)
        printf("%d", x2);
    else
        printf("%d", x4);

    if (y2 < y4)
        printf("%d", y2);
    else
        printf("%d", y4);
    return 0;
