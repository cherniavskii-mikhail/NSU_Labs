#include<stdio.h>
#include<math.h>

int main()
{
	int number = 50;
	int rez = 0;

	for (int i = 0; i < 50; i++)
	{
		rez += sqrt(rez + number);

		number--;
	}

	printf("%d", rez);

	return 0;

}
