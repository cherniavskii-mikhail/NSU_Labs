#include <stdio.h>
#include <malloc.h>
#include <math.h>


int side_lengh(int x1, int x2, int y1, int y2)
{
    int lengh = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return lengh;
}

int trngl_area(int* x, int* y, int n)
{
    int a = 0, b = 0, c = 0, area = 0, p = 0;
    
    a = side_lengh(*x, *(x + 1), *y, *(y + 1));
    b = side_lengh(*(x + 1), *(x + 2), *(y + 1), *(y + 2));
    c = side_lengh(*(x + 2), *x, *(y + 2), *y);

    p = (a + b + c) / 2;

    area = sqrt(p * (p - a) * (p - b) * (p - c));

    return area;
}

int figure_area(int* x, int* y, int n)
{
    int area = 0, mult1 = 0, mult2 = 0;

    for (int i = 0; i < n - 1; i++)
        mult1 += (x[i] * y[i + 1]);
    
    for (int i = 0; i < n - 1; i++)
        mult2 += (x[i + 1] * y[i]);

    area = (mult1 - mult2)/2;

    return area;
}

int main()
{
    int* x = 0;
    int* y = 0;
    int n = 0, area = 0;
    scanf_s("%d", &n);

    x = (int*)malloc(n * sizeof(int));
    y = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", x + i);

        scanf_s("%d", y + i);
    }
        
    if (n > 3)
        area = figure_area(x, y, n);
    else
        area = trngl_area(x, y, n);

    printf("%d", area);

    free(x);
    free(y);
    return 0;
}
