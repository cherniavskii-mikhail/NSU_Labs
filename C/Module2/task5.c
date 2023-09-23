#include <stdio.h>
#include <malloc.h>

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
        
    area = figure_area(x, y, n);
   
    printf("%d", area);
    return 0;
}
