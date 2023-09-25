#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() 
{
    int n, * arr, num = 1, top = 0, left, right, bottom;

    scanf_s("%d", &n);

    arr = (int*)malloc(n * n * sizeof(int));

    left = 0, right = n - 1, bottom = n - 1;

    while (left <= right && top <= bottom) 
    {
        for (int i = left; i <= right; i++)
            arr[top * n + i] = num++;

        top++;

        for (int i = top; i <= bottom; i++)
            arr[i * n + right] = num++;

        right--;

        if (top <= bottom) 
        {
            for (int i = right; i >= left; i--)
                arr[bottom * n + i] = num++;

            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                arr[i * n + left] = num++;

            left++;
        }
    }

    for (int i = 0; i < n * n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
