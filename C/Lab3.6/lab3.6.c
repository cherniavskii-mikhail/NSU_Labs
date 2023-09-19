#include<stdio.h>

int main()
{
	float rez = 0;

	for (int i = 201; i > 0; i--)
		rez += 1 / (i + rez);

	printf("%f", rez);

	return 0;
}
