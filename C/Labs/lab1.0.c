#include<stdio.h>
#include<string.h>

/*need to make a buffer which show, how many symbols can we skip*/
void shift_table(int* shift, char sample[], int sam_len){
    for (int i = 0; i < 256; i++)
        shift[i] = sam_len;

    for (int i = 0; i < sam_len - 1; i++)
    {
        int kod = (unsigned char)sample[i];
        shift[kod] = sam_len - 1 - i;
    }
}

/*need to find word in the text*/
int search_word(int sam_len, char sample[], char text[]){
    int shift[256];
    shift_table(shift, sample, sam_len);

    int text_len = strlen(text) - 1; //because of \n
    int sample_pos = sam_len - 1, text_pos = sample_pos;

    int checked_symbols[50];
    for (int i = 0; i < 50; i++)
        checked_symbols[i] = 0;

    for (int i = 0; i < text_len - sam_len; i++)
    {
        if (sample[sample_pos] == text[text_pos])
        {
            checked_symbols[i] = text_pos + 1;

            if (sample_pos == 0)
            {
                for (int i = 0; i < 50; i++)
                    if (checked_symbols[i] != 0)
                        printf("%d ", checked_symbols[i]);

                return 0;
            }
            sample_pos--;
            text_pos--;
        }
        else
        {
            checked_symbols[i] = text_pos + 1;

            int kod = (unsigned char)text[text_pos];
            text_pos += (shift[kod] + (sam_len - sample_pos - 1));
            sample_pos = sam_len - 1;
        }
    }

    for (int i = 0; i < 50; i++)
        if (checked_symbols != 0)
            printf("%d ", checked_symbols[i]);

    return 0;
}

int main()
{
    char sample[16];
    printf("Enter a sample: ");

    for (int i = 0; i < 16; i++)
    {
        sample[i] = ' ';
    }
    fgets(sample, 16, stdin);

    char text[50];
    printf("Enter the text: ");

    for (int i = 0; i < 16; i++)
        text[i] = ' ';


    fgets(text, 50, stdin);

    int sam_len = strlen(sample) - 1;
    search_word(sam_len, sample, text);

    return 0;
}
