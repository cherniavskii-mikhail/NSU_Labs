#include <stdio.h>
#include<string.h>

int symb_comp(char c, char* str, int i)
{
    int check = 1;

    for (int j = 0; j < i; j++)
    {
        if (c == str[j])
            check++;
    }

    if (check == 3)
        return 1;
    else
        return 0;
}

int main()
{
    char str[80], c = ' ';
    int str_lh = 0, flag = 0;

    gets(str);

    str_lh = strlen(str);

 
    for (int i = 2; i < str_lh; i++)
    {
        c = str[i];

        flag += symb_comp(c, str, i);

        if (flag == 1)
            printf("%c", c);
    }

    return 0;
}
