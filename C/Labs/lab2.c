#include <stdio.h>

int max_index(int* text, int text_lenght)
{
	for (int i = (text_lenght - 1) - 1; i >= 0; i--)
	{
		if (text[i] < text[i + 1])
			return i;
	}

	return -1;
}

int bigger_index(int* text,int swap_index1, int text_lenght)
{
	for (int i = text_lenght - 1; i >= 0; i--)
	{
		if (text[swap_index1] < text[i])
		{
			return i;
		}
	}

	return -1;
}

void swap(int* text,int swap_index1, int j_index, int text_lenght)
{
	int t = 0;

	t = text[swap_index1];
	text[swap_index1] = text[j_index];
	text[j_index] = t;

	for (int i = swap_index1 + 1, j = text_lenght - 1; i < j; i++, j--)
	{
		t = text[i];
		text[i] = text[j];
		text[j] = t;
	}

	for (int i = 0; i < text_lenght; i++)
		printf("%d", text[i]);
		
	printf("%c", '\n');
}

int main()
{
	int text[16] = { 0, 1, 2, 3, 4 };
	int number = 0;

    scanf_s("%d", &number);

	int swap_index1 = 0, swap_index2 = 0;

	int text_lenght = 5;

	while (number > 0){
		swap_index1 = max_index(text, text_lenght);

		swap_index2 = bigger_index(text, swap_index1, text_lenght);

		swap(text, swap_index1, swap_index2, text_lenght);

		number--;
	}

	return 0;
}
