#include <stdio.h>
#include<string.h>
#include <stdbool.h> 

bool is_char(char c)
{
    if ((c == ' ') ||(c == '\0'))
        return false;
    else
        return true;
}

int main()
{
    char str[80], copy_str[80];
    int str_lh = 0, word_lh = 0, start = 0, end = 0, k = 0;
    bool flag = true;

    for (int i = 0; i < 80; i++)
    {
        str[i] = ' ';
        copy_str[i] = ' ';
    }
  
    gets(str);

    str_lh = strlen(str);

    for (int i = 0; i <= str_lh; i++)
    { 
        flag  = is_char(str[i]);

        if (flag == false)
        {
            k = start;
            start += word_lh;
          
            for (int j = str_lh - start; j < str_lh - end; j++)
            {
                if ((str[k] != ' ') || (str[k] != '\0'))
                {
                    copy_str[j] = str[k];
                    k++;
                }
            }
             
            end += (word_lh + 1);
            start++;
            word_lh = 0;   
        }
        else
          word_lh++;
    }
    
    for (int i = 0; i < str_lh; i++)
        printf("%c", copy_str[i]);
  
    return 0;
}
