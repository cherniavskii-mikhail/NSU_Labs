#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

bool is_char(char c)
{
    int kod = (int)c;

    if (((kod >= 65) && (kod <= 90)) ||((kod >= 97) && (kod <= 122)))
        return true;
    else
        return false;
}

bool is_number(char c)
{
    int kod = (int)c;

    if ((kod >= 48) && (kod <= 57))
        return true;
    else
        return false;
}

bool is_underline(char c)
{
    int kod = (int)c;

    if (kod == 95)
        return true;
    else
        return false;
}

bool is_keywords(char* str, int str_len)
{
    int key_len = 0, count = 0;
    bool flag = true;

    char key1[15] = "False";
    char key2[15] = "True";
    char key3[15] = "lambda";

    key_len = strlen(key1);

    if (key_len == str_len)
    {
        for (int i = 0; i < str_len; i++)
        {
            if (str[i] != key1[i])
                flag = false;
            else
                count++;
        }
    }
    else
        flag = false;

    if (count == str_len)
        return true;

    if (flag == false)
    {
        count = 0;
        flag == true;
      
        key_len = strlen(key2);

        if (key_len == str_len)
        {
            for (int i = 0; i < str_len; i++)
            {
                if (str[i] != key2[i])
                    flag = false;
                else
                    count++;
            }
        }
        else
            flag = false;

        if (count == str_len)
            return true;
    }

    if (flag == false)
    {
        flag == true;
        count = 0;
      
        key_len = strlen(key3);

        if (key_len == str_len)
        {
            for (int i = 0; i < str_len; i++)
            {
                if (str[i] != key3[i])
                    flag = false;
                else
                    count++;
            }
        }
        else
            flag = false;

        if (count == str_len)
            return true;
    }

    return flag;
}

int main() 
{
    char str[80];
    int str_len = 0;
    bool flag1 = true, flag2 = true;

    gets(str);
    
    str_len = strlen(str);

    for (int  i = 0; i < str_len; i++)
    {
        flag1 = is_char(str[i]);

        if (flag1 == false)
            flag1 = is_number(str[i]);

        if (flag1 == false)
            flag1 = is_underline(str[i]);
    }

    flag2 = is_number(str[0]);

    flag2 = is_keywords(str, str_len);

    if (flag1 == false || flag2 == true)
        printf("Bad input!!!");
    else
        printf("Good input!!!");

    return 0;
}
