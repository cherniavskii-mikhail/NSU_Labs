#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <stdbool.h> 

int char_to_dig(char a){
	int x = 0;

	if ((a >= 'A') && (a <= 'Z'))
		x = 10 + a - 'A';

	if ((a >= '0') && (a <= '9'))
		x = a - '0';

	return x;
}

double trans_nfract_in_10(char* symb, int frst_not, int symbols){
	int f = 0, t = 0;

	if (frst_not != 10){
		for (int i = symbols - 1; i >= 0; i--){
			f += (char_to_dig(symb[i]) * pow(frst_not, t)); //число в 10 системе
			t += 1;
		}
	}

	return f;
}

double trans_fract_in_10(char* a, int frst_not, int symbols, int pocle_drob)
{
	double f = 0, t = -(pocle_drob);

	if (frst_not != 10){
		for (int i = symbols - 1; i >= 0; i--){
			if (a[i] != '.'){
				f = f + (char_to_dig(a[i]) * pow(frst_not, t));
				t++;
			}
		}
	}

	return f;
}

double int_part_mult(double number, int sec_not){
	double operate_rez;

    operate_rez = number * sec_not;

	return (int)operate_rez;
}

char dig_to_char(int operate_rez){
	char b;

	if (operate_rez >= 10)
		b = 'A' + operate_rez - 10;
	else
		b = '0' + operate_rez;


	return b;
}

double rem_of_div(int integer_part, int sec_not)
{
	int operate_rez = 0;

    operate_rez = integer_part % sec_not;

	return operate_rez;
}

int main()
{
    int frst_not, sec_not, symbols = 0, drob = 0;
    char symb[13];
    bool end = false;

    for (int i = 0; i < 13; i++)
        symb[i] = ' ';

    //Data enter
    printf("Enter your number:");
    fgets(symb, 13, stdin);

    printf("Enter the first notation: ");
    scanf_s("%d", &frst_not);

    printf("Enter the second notation: ");
    scanf_s("%d", &sec_not);

    char* pa = symb;

    //Check first number
    if (*pa == '.'){
        printf("There is no such number!");
        return 0;
    }

    //count numbers
    for (int i = 0; i < 13; ++i){
        if ((symb[i] != '\n') && (!end))
            symbols++;
        else
            end = true;
    }

    int after_dot = 0;
    int h = 0; // найти номер точк


    while (*pa != NULL){
        // numbers should be less than notation
        if ((char_to_dig(*pa) >= frst_not) && (char_to_dig(*pa) != '.')){
            printf("There is no such number!");
            return 0;
        }

        h += 1; // dot position

        // check for dot
        if (*pa == '.'){
            drob += 1;
            after_dot = symbols - h; //number of symbols after dot
        }

        ++pa;
    }

    if (drob > 0)
        symbols--;

    if (frst_not == sec_not){
        printf("It is the same number!");

        return 0;
    }

    double number = 0;

    if (frst_not != 10){
        if (drob)
            number = trans_fract_in_10(symb, frst_not, symbols, after_dot);
        else
            number = trans_nfract_in_10(symb, frst_not, symbols);
    }
    else {
        int shift = pow(10, after_dot);
        double numb = 0;

        for (int i = 0; i <= symbols - after_dot - 1; i++) {
            number += char_to_dig(symb[i]);
            number *= 10;
        }

        number /= 10;

        for (int i = symbols; i > symbols - after_dot; i--) {
            numb = char_to_dig(symb[i]);
            number += (numb / shift);
            shift /= 10;

        }
    }

    if (sec_not == 10){
        printf("%lf", number);
        return 0;
    }

    int operate_rez = 0;
    int char_numb = 0;
    char final_number[100];
    int int_part = (int)number;

    for (int i = 0; i < 100; i++)
        final_number[i] = '*';

    if (drob){
        number = number - (int)number;

        for (int i = 0; i < 100; i++)
            if (char_numb < 5){
                operate_rez = int_part_mult(number, sec_not);

                number = (number * sec_not) - (int)(number * sec_not);
                final_number[i] = dig_to_char(operate_rez);

                char_numb++;
            }
    }

    if (drob){
        final_number[char_numb] = '.';
        char_numb++;
    }

    for (int i = char_numb; i < 100; i++){
        if (int_part > 0){
            operate_rez = rem_of_div(int_part, sec_not);
            int_part /= sec_not;
            final_number[i] = dig_to_char(operate_rez);
        }
        else{
            final_number[char_numb] = '0';
            break;
        }
    }

    char_numb = 0;

    for (int i = 0; i < 100; i++)
        if (final_number[i] != '*')
            char_numb++;

    int i = char_numb - 1;

    while ((final_number[i] != '.') && (i != -1)){
        printf("%c", final_number[i]);

        i--;
    }

    if (final_number[i] == '.'){
        printf(".");

        for (int j = 0; j < i; j++)
            printf("%c", final_number[j]);
    }

    printf("\n");
	return 0;
}
