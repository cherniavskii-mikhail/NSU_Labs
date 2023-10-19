#include <stdio.h>
#include <stdbool.h>

bool check_text(char* text, int text_lenght){
    for (int i = 0; i < text_lenght; i++)
        for (int j = 0; j < text_lenght; j++)
            if(i != j)
                if (text[i] == text[j])
                    return false;

    return true;
}

int char_to_dig(char a){ //translate char to digital
    int x = 0;

    if ((a >= '0') && (a <= '9'))
        x = a - '0';

    return x;
}

int max_index(char* text, int text_lenght)
{
	for (int i = (text_lenght - 1) - 1; i >= 0; i--)
	{
		if (char_to_dig(text[i]) < char_to_dig(text[i + 1]))
			return i;
	}

	return -1;
}

int bigger_index(char* text,int swap_index1, int text_lenght)
{
	for (int i = text_lenght - 1; i >= 0; i--)
		if (char_to_dig(text[swap_index1]) < char_to_dig(text[i]))
			return i;

	return -1;
}

void swap(char* text,int swap_index1, int swap_index2, int text_lenght)
{
	int t = 0;

	t = text[swap_index1];
	text[swap_index1] = text[swap_index2];
	text[swap_index2] = t;

	for (int i = swap_index1 + 1, j = text_lenght - 1; i < j; i++, j--)
	{
		t = text[i];
		text[i] = text[j];
		text[j] = t;
	}

	for (int i = 0; i < text_lenght; i++)
		printf("%c", text[i]);
		
	printf("%c", '\n');
}

int main()
{
	char text[16];
	int number = 0, text_lenght = 0, i = 0;
    bool check = true;

    fgets(text, 16, stdin);
    scanf_s("%d", &number);

	int swap_index1 = 0, swap_index2 = 0;

	while (text[i] != '\n') {
        text_lenght++;
        i++;
    }

    check = check_text(text, text_lenght);
    if(check)
	    while (number > 0){
		    swap_index1 = max_index(text, text_lenght);

		    swap_index2 = bigger_index(text, swap_index1, text_lenght);

		    swap(text, swap_index1, swap_index2, text_lenght);

		    number--;
	    }
    else
        printf("Bad input");

	return 0;
}
