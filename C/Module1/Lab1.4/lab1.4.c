#include<stdio.h>

int main()
{
	int k = 0;
	
	scanf_s("%d", &k);
	int shift = 100;

	printf("%d", k / 3 + shift);

	return 0;
}

На бумаге записали последовательность цифр 101102103...149150, в которой идут подряд все трехзначные числа от 101 до 150.
Напишите программу, которая по заданному целому числу k (1 ≤ k ≤ 150) определяет k-ю цифру этой последовательности, если известно, что k = 3,6,9.... 
Программа не должна хранить в памяти саму эту последовательность.
