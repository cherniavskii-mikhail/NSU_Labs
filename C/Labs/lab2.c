#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* necessary to check the text for errors */
bool check_text(char* text, int text_len){
    for (int i = 0; i < text_len; i++)
        for (int j = 0; j < text_len; j++)
            if(i != j)
                if (text[i] == text[j])
                    return false;

    int code = 0;

    for (int i = 0; i < text_len; i++){
        code = (int)text[i];

        if (code < 48 || code > 57)
            return false;
    }

    return true;
}

/* need to translate char to digital*/
int char_to_dig(char numb){
    int x = 0;

    if ((numb >= '0') && (numb <= '9'))
        x = numb - '0';

    return x;
}

/* need to find first number bigger than previous*/
int max_index(char* text, int text_len){
    for (int i = (text_len - 1) - 1; i >= 0; i--)
        if (char_to_dig(text[i]) < char_to_dig(text[i + 1]))
            return i;

    return -1;
}

/* need to find number bigger then previous*/
int bigger_index(char* text,int swap_i1, int text_len){
    for (int i = text_len - 1; i >= 0; i--)
        if (char_to_dig(text[swap_i1]) < char_to_dig(text[i]))
            return i;

    return -1;
}

/*need to change positions of two numbers*/
void swap(char* text,int swap_i1, int swap_index2, int text_len){
    int t = 0;

    t = text[swap_i1];
    text[swap_i1] = text[swap_index2];
    text[swap_index2] = t;

    for (int i = swap_i1 + 1, j = text_len - 1; i < j; i++, j--)
    {
        t = text[i];
        text[i] = text[j];
        text[j] = t;
    }

    for (int i = 0; i < text_len; i++)
        printf("%c", text[i]);

}

int main()
{
    char* text;
    int number = 0, text_len = 0, swap_i1 = 0, swap_i2 = 0, i = 0;
    bool check = true;

    gets(text);
    scanf_s("%d", &number);

    text_len = strlen(text);

    check = check_text(text, text_len);

    if(check)
        while (number > 0){
            swap_i1 = max_index(text, text_len);

            if(swap_i1 == -1)
                return 0;

            swap_i2 = bigger_index(text, swap_i1, text_len);

            swap(text, swap_i1, swap_i2, text_len);

            number--;

            if (number != 0)
                printf("%c", '\n');
        }
    else
        printf("bad input");

    return 0;
}
