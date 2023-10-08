#include <stdio.h>
#include<string.h>

int main()
{
    char str[80];
    int shift_numb = 0, str_lh = 0;

    gets(str);

    str_lh = strlen(str);

    for (int i = 0; i < str_lh; i++)
    {
        if (str[i] == ' ')
            shift_numb++;
    }

    printf("%d", shift_numb);
    return 0;
}
