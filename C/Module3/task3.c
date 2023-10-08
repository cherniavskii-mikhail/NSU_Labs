#include <stdio.h>
#include<string.h>

int symb_comp(char c, char* str, int i)
{
    for (int j = 0; j < i; j++)
    {
        if ((c == str[j]) || (c == ' '))
            return -1;
    }

    return 1;
}

int main()
{
    char str[10], c = ' ';
    int str_lh = 0, symb_numb = 1, flag = 0;

    gets(str);

    str_lh = strlen(str);

 
    for (int i = 1; i < str_lh; i++)
    {
        c = str[i];

        flag = symb_comp(c, str, i);

        if (flag == 1)
            symb_numb++;

    }

    printf("%d", symb_numb);
    return 0;
}
