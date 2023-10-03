#include <stdio.h>
#include<string.h>

int main()
{
    char str[10], c = ' ';
    int str_lh = 0, symb_numb = 1;

    gets(str);

    str_lh = strlen(str);

    c = str[0];

    for (int i = 0; i < str_lh - 1; i++)
    {
        if (str[i + 1] == c)
            symb_numb++;
        else
            c = str[i + 1];
    }

    printf("%d", symb_numb);
    return 0;
}
