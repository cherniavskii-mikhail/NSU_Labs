#include<stdio.h>

int main()
{
	int number = 0;
	int back_number[5];
	int shift = 10;

	scanf_s("%d", &number);

	for (int i = 0; i < 5; i++)
	{
		back_number[i] = number % shift;
		number /= 10;
	}

	for (int i = 0; i < 5; i++)
		printf("%d", back_number[i]);

	return 0;

}
