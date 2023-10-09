#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

bool srch_word(char* str, int start, int fin, int str_len, int count)
{
    int k = start, copy = count;

    for (int i = 0; i < str_len + 1; i++)
    {
        if (i < start || i > fin)
        {
            if (count != 0)
            {
                if (str[i] != str[k])
                {
                    k = start;
                    count = copy;
                }
                else
                {
                    k++;
                    count--;
                }
            }
            else
                return true;
        }
    }
    return false;
}

int main() 
{
    char str[80];
    int str_len = 0, start = 0, fin = 0, count = 0;
    bool flag = false, first = true;

    gets(str);
    
    str_len = strlen(str);

    for (int i = 0; i < str_len; i++)
    {
        if ((str[i] != ' ') && (str[i] != '\0'))
        {
            start = i - count;
            count++;
        }
        else
        {
            fin = start + count-1;

            flag = srch_word(str, start, fin, str_len, count);

            count = 0;
        }

        if (flag == true && first == true)
        {
            for (int j = start; j <= fin; j++)
                printf("%c", str[j]);

            first == false;
        }
    }

    return 0;
}
