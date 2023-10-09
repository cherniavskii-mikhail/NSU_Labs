#include <stdio.h>
#include <string.h>

int play_game(char* str, int str_len)
{
    int flag = 1; //1 = Petya, -1 = Vasya

    for (int i = 0; i < str_len + 1; i++)
    {
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                if (str[i - 1] == str[i + 1])
                {
                    flag *= -1;
                }
                else
                {
                    if (flag == 1)
                        return 1;
                    else
                        return -1;
                }
            }
            
            i++;
        }
    }
}

int main() 
{
    char str[80];
    int str_len = 0, flag = 1;

    gets(str);
    
    str_len = strlen(str);

    flag = play_game(str, str_len);

    if (flag == 1)
        printf("Petya");
    else
        printf("Vasya");

    return 0;
}
