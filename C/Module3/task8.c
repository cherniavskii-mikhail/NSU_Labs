#include <stdio.h>
#include<string.h>

void make_rez(char* str, char* rez, int min_len, int str_len)
{
    int start = 0, fin = 0, count = 0, k = 0;

    for (int i = 0; i < str_len + 1; i++)
    {
        if (str[i] != ' ')
        {
            if (str[i] != '\0')
                count++;
            else
            {
                if (count == min_len)
                {
                    start = i - count;
                    fin = i - 1;

                    for (int j = start; j <= fin; j++)
                    {
                        rez[k] = str[j];
                        k++;
                    }
                    k++;
                }

                count = 0;
            }
        }
        else
        {
            if (count == min_len)
            {
                start = i - count;
                fin = i - 1;

                for (int j = start; j <= fin; j++)
                {
                    rez[k] = str[j];
                    k++;
                }
                k++;
            }

            count = 0;
        }
    }
}

void min_lengh(char* str, int str_len, char* rez, int min_len, int lengh)
{
    int count = 0, len = 0; 

    for (int i = 0; i < str_len + 1; i++)
    {
        if (str[i] != ' ')
        {
            if (str[i] != '\0')
                count++;
            else
            {
                if ((count < min_len) && (count > lengh))
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

            count = 0;
        }
    }

    make_rez(str, rez, min_len, str_len);

    min_lengh(str, str_len, rez, min_len);
}

int main()
{
    char str[80], rez[80];
    int str_len = 0, min_len;

    gets(str);

    str_len = strlen(str);

    min_lengh(str, str_len, rez, 100, -100);

    for (int i = 0; i < str_len; i++)
        printf("%d", rez[i]);

    return 0;
}
