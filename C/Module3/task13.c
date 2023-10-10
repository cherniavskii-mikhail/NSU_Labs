#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

int char_to_dig(char char_numb, char c)
{
    return (int)char_numb - (int)c;
}

int main() 
{
    char str[80], c ='0';
    int str_len = 0, count = 0, sum1 = 0, sum2 = 0, number = 0;
    bool flag = false;

    while (flag != true)
    {
        gets(str);

        str_len = strlen(str);

        count++;

        if (str_len % 2 == 0)
        {
            for (int i = 0; i < str_len / 2; i++)
            {
                number = char_to_dig(str[i], c);
                sum1 += number;
            }

            for (int i = str_len / 2; i < str_len; i++)
            {
                number = char_to_dig(str[i], c);
                sum2 += number;
            }

            if (sum1 == sum2)
                flag = true;

            if (flag == true)
                printf("%d", count);
        }
    }

    return 0;
}
