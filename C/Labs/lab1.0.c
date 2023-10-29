#include<stdio.h>
#include<string.h>

void shift_table(int* shift, char sample[], int sample_lenght)
{
    for (int i = 0; i < 256; i++)
        shift[i] = sample_lenght;

    for (int i = 0; i < sample_lenght - 1; i++)
    {
        int kod = (unsigned char)sample[i];
        shift[kod] = sample_lenght - 1 - i;
    }

}

int search_the_word(int sample_lenght, char sample[], char text[])
{
    int shift[256];
    shift_table(shift, sample, sample_lenght);

    int text_lenght = strlen(text) - 1; //because of \n
    int position_in_sample = sample_lenght - 1, position_in_text = position_in_sample;

    int checked_symbols[50];
    for (int i = 0; i < 50; i++)
        checked_symbols[i] = 0;

    for (int i = 0; i < text_lenght - sample_lenght; i++)
    {
        if (sample[position_in_sample] == text[position_in_text])
        {
            checked_symbols[i] = position_in_text + 1;

            if (position_in_sample == 0)
            {
                for (int i = 0; i < 50; i++)
                {
                    if (checked_symbols[i] != 0)
                        printf("%d", checked_symbols[i]);
                }

                return 0;
            }
            position_in_sample--;
            position_in_text--;
        }
        else
        {
            checked_symbols[i] = position_in_text + 1;

            int kod = (unsigned char)text[position_in_text];
            position_in_text += (shift[kod] + (sample_lenght - position_in_sample - 1));
            position_in_sample = sample_lenght - 1;
        }
    }

    for (int i = 0; i < 50; i++)
        if (checked_symbols != 0)
            printf("%d", checked_symbols[i]);

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
    {
        text[i] = ' ';
    }

    fgets(text, 50, stdin);

    int sample_lenght = strlen(sample) - 1; //becouse of \n

    search_the_word(sample_lenght, sample, text);

    return 0;
}
