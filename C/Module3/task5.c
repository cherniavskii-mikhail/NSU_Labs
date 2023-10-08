#include <stdio.h>
#include<string.h>
#include <stdbool.h> 

void make_rez(char c, char* str, char* rez, int str_lh, int j)
{
    bool flag = true;
    for (int i = 0; i < str_lh; i++)
    {
        if (c == str[i])
            flag = false;
    }

    if (flag == true)
        rez[j] = c;
}

int max_lengh(char* str1, char* str2, char* str3)
{
    int len1 = 0, len2 = 0, len3 = 0, max = 0;

    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = strlen(str3);

    if (len1 >= len2)
        max = len1;
    else
        max = len2;

    if (len3 >= max)
        return len3;
    else
        return max;
}

bool symb_check(char c, char* str2, char* str3, int max_lh)
{
    for (int i = 0; i < max_lh; i++)
    {
        if ((c == str2[i]) || (c == str3[i]))
            return false;
    }

    return true;
}


int main()
{
    char str1[80], str2[80], str3[80], rez[80], c = ' ';
    int str_lh = 0, max_lh = 0, j = 0;
    bool flag = false;

    gets(str1);
    gets(str2);
    gets(str3);

    for (int i = 0; i < 80; i++)
        rez[i] = ' ';

    max_lh = max_lengh(str1, str2, str3);
    str_lh = strlen(str1);

    for (int i = 0; i < str_lh; i++)
    {
       flag = symb_check(str1[i], str2, str3, max_lh);

       if (flag == true)
       {
          make_rez(str1[i], str1, rez, i, j);
          j++;
       }
    }

    str_lh = strlen(str2);

    for (int i = 0; i < str_lh; i++)
    {
        flag = symb_check(str2[i], str1, str3, max_lh);

        if (flag == true)
        {
            make_rez(str2[i], str2, rez, i, j);
            j++;
        }
    }

    str_lh = strlen(str3);

    for (int i = 0; i < str_lh; i++)
    {
        flag = symb_check(str3[i], str1, str2, max_lh);

        if (flag == true)
        {
            make_rez(str3[i], str3, rez, i, j);
            j++;
        }
    }

    for (int i = 0; i < 80; i++)
        printf("%c", rez[i]);
    
    return 0;
}
