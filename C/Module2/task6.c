#include <stdio.h>

int numb_sum(int number)
{
    if (number < 10)
        return number;
    else
        return  number % 10 + numb_sum(number / 10);
}

int main() 
{
    int number;
  
    scanf_s("%d", &number);
    
    printf("%d", numb_sum(number));
   
    return 0;
}
