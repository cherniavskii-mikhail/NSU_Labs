#include <stdio.h>
#include <malloc.h>

int NOD(int a, int b) {
    if (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
        NOD(a, b);
    }
    else
        return a + b;
}

int main() {
    int* a, n, nod;

    scanf_s("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf_s("%d", a + i);

    nod = NOD(*(a), *(a + 1));

    for (int i = 2; i < n; i++)
        nod = NOD(nod, *(a + i));

    printf("%d", nod);
    return 0;
}
