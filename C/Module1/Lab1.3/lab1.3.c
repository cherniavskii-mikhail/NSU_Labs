#include<stdio.h>

int main()
{
	int a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, rez1 = 0, rez2 = 0, rez3 = 0;

	scanf_s("%d", &a1);
	scanf_s("%d", &a2);
	scanf_s("%d", &a3);
	scanf_s("%d", &b1);
	scanf_s("%d", &b2);

	rez1 = (a1 + b1) % 10;
	rez2 = ((a2 + b2) % 10) + ((a1 + b1) / 10);
	rez3 = a3 + ((a2 + b2) / 10);

	printf("%d%d%d", rez3,rez2,rez1);
	return 0;
}

Даны цифры двух десятичных целых чисел: трехзначного a3a2a1 и двузначного b2b1 , где a1 и b1 — число единиц, a2 и b2 — число десятков, a3 — число сотен. 
Получить цифры числа, равного сумме заданных чисел (известно, что это число трехзначное). 
Числа-слагаемые и число-результат не определять и условный оператор не использовать.
