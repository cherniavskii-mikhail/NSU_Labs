#include<stdio.h>
#include<math.h>

int main()
{
	int n = 0, x = 0;
	int rez = 1;
	int factorial = 1;

	scanf_s("%d %d", &x, &n);

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			factorial *= i;
			rez += pow(x, i) / factorial;
		}
		else
		{
			factorial *= i;
			rez -= pow(x, i) / factorial;
		}
	}

	printf("%d", rez);

	return 0;
}

По заданным x и n, вычислить сумму n слагаемых: 1 - x + (x^2)/2! - (x^3)/3! + (x^4)/4!


