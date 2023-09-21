#include<stdio.h>

int main()
{
	float rez = 0;

	for (int i = 201; i > 0; i-=2)
		rez += 1 / (i + rez);

	printf("%f", rez);

	return 0;
}

Вычислить: 1/(3 + 1/(5+1/(... + (1/201))...))
