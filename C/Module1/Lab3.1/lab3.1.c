#include<stdio.h>
#include<math.h>

int main()
{
	int start_number = 0;
	int rez = 0;

	scanf_s("%d", &start_number);

	rez += pow(start_number, 2);

	for (int i = start_number - 1; i > 0; i--)
	{
		rez -= pow(i, 2);
	}

	printf("Rezult: %d", rez);
	return 0;
}

Вычислить значение выражения:((..(20^2 - 19^2) - 18^2)- ... - 1^2)
