#include <stdio.h>
#include <malloc.h>

void buff_fill(int** buff, int len)
{
    int num = 1;

    for (int layer = 0; layer < len / 2; layer++) {

        for (int i = layer; i < len - layer; i++)
            buff[layer][i] = num++;

        for (int i = layer + 1; i < len - layer; i++)
            buff[i][len - layer - 1] = num++;

        for (int i = len - layer - 2; i >= layer; i--)
            buff[len - layer - 1][i] = num++;

        for (int i = len - layer - 2; i > layer; i--)
            buff[i][layer] = num++;
    }
    if (len % 2 == 1)
        buff[len / 2][len / 2] = num;

}

int main()
{
    int n, **buff;
    scanf_s("%d", &n);
    buff = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
        buff[i] = (int*)malloc(n * sizeof(int));

    buff_fill(buff, n);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            printf("%d ", (buff[i][j]));
        
        puts("\n");
    }

    for (int i = 0; i < n; i++)
        free(buff[i]);
  
    free(buff);
    return 0;
}
