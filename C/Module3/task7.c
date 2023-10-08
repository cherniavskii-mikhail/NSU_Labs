#include <stdio.h>
#include<string.h>

int main()
{
    char str[80];
    int str_len = 0, min_len = 100, count = 0;

    gets(str);

    str_len = strlen(str);

    for (int i = 0; i < str_len+1; i++)
    {
        if (str[i] != ' ')
        {
            if (str[i] != '\0')
                count++;
            else
            {
                if (count < min_len)
                {
                    min_len = count;
                    count = 0;
                }
            }
        }
        else
        {
            if (count < min_len)
            {
                min_len = count;
                count = 0;
            }
        }
    }

    printf("%d", min_len);
    return 0;
}
