#include<stdio.h>

int main()
{
	int k = 0;
	
	scanf_s("%d", &k);
	int shift = 100;

	printf("%d", k / 3 + shift);

	return 0;
}
