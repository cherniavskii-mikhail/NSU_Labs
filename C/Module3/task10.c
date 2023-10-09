#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

bool check_char(char* str, int w_start,int  w_fin)
{
    char c = ' ';

    for (int i = w_start + 1; i < w_fin; i++)
    {
        c = str[i];

        for (int j = w_start+1; j < w_fin; j++)
        {
            if (i != j)
            {
                if (c == str[j])
                    return false;
            }
        }
    }

    return true;
}

void find_word(char* str, int fw_fin, int str_len, int fw_len)
{
    int len = 0, k = 0;
    bool flag = true;

    for (int i = fw_fin + 2; i < str_len + 1; i++)
    {
        if ((str[i] != ' ') && (str[i] != '\0'))
            len++;
        else
        {
            if (len != fw_len)
            {
                flag = check_char(str, i - fw_len - 1, i);
              
                len = 0;

                if (flag == true)
                {
                    for (int j = i - fw_len - 1; j < i; j++)
                        printf("%c", str[j]);
                }
            }
            else
            {
                k = i - len;
                len = 0;

                for (int j = 0; j < fw_fin; j++)
                {
                    if (str[j] != str[k])
                        flag = true;

                    k++;
                }

                k = 0;

                if (flag == true)
                {
                    flag = check_char(str, i - fw_len - 1, i);

                    if (flag == true)
                    {
                        for (int j = i - fw_len; j < i; j++)
                            printf("%c", str[j]);
                    }
                }
            }
        }
    }
}

int main() 
{
    char str[80];
    int str_len = 0, fw_fin = 0, count = 0;
    bool flag = true;

    gets(str);
    
    str_len = strlen(str);

    for (int i = 0; i < str_len; i++)
    {
        if (flag == true)
        {
            if ((str[i] != ' ') && (str[i] != '\0') && flag == true)
            {
                fw_fin = i;
                count++;
            }
            else
                flag = false;
        }
    }

    find_word(str, fw_fin, str_len, count);
    return 0;
}
