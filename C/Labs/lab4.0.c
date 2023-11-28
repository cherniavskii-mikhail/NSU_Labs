#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1004

struct stack
{
    char value;
    struct sist* next;
};

/* эта функция пихает операторы в стэк операторов*/
void PushStack(struct stack* operator_stack, int symbol)
{
    operator_stack->value = symbol;
    operator_stack->next++;
}

/* эта функция вытаскивает оператор из стека операторов и уменьшает размер стэка*/
int pop_stack(struct stack* operator_stack)
{
    if (operator_stack->value == 0)
    {
        printf("syntax error!");
        return 0;
    }
    operator_stack->value--;
    return operator_stack->value;
}

/* эта функция просто берёт оператор, но не уменьшает размер стэка*/
int pop_stack(struct stack* operator_stack) 
{
    if (operator_stack->value <= 0) {
        printf("syntax error");
        return 0;
    }
    return operator_stack->value;
}

int priority(char c)
{
    if (c == '(' || c == ')')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return -1;
}
int isOperator(char symbol)
{
    int check = 0;

    if (symbol == '+' || symbol == '-')
        check = 1;
    else if (symbol == '*' || symbol == '/')
        check = 1;
    else if (symbol == '(' || symbol == ')')
        check = 1;
        
    
    return check;
}

int proverka_simvolov(char symbol)
{
    return isOperator(symbol) || isdigit(symbol) || symbol == '\n';
}

void postfix(char* str, int size, char* postf)
{
    int postfix_size = 0;
    struct stack operator_stack;
    operator_stack.value = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (isdigit(str[i])) 
        {
            while (!isOperator(str[i])) 
            {
                postf = str[i];
                postfix_size++;
                i++;
                if (i == size) break;
            }
            postf = ' ';
            postfix_size++;
            i--;
        }
        if (isOperator(str[i]))
        {
            if (str[i] == '(') 
            {
                PushStack(&operator_stack, (int)str[i]); 
            }
            else if (str[i] == ')') 
            {
                if (i == 0 || str[i - 1] == '(') 
                {
                    printf("syntax error!");
                    exit(0);
                }
                char s = (int)pop_stack(&operator_stack); 
                while (s != '(')  
                {
                    postf[postfix_size] = s;
                    postf[postfix_size + 1] = ' ';
                    postfix_size += 2;
                    s = (int)pop_stack(&operator_stack);
                }
            }
            else
            {
                if (operator_stack.value > 0 && priority(str[i]) <= priority((char)pop_stack(&operator_stack)))
                {
                    postf[postfix_size] = (char)pop_stack(&operator_stack);
                    postf[postfix_size + 1] = ' ';
                    postfix_size += 2;
                }
                PushStack(&operator_stack, (int)str[i]); 
            }
        }
    }
    while (operator_stack.value > 0)
    {
        postf[postfix_size] = (char)pop_stack(&operator_stack);
        postf[postfix_size + 1] = ' ';
        postfix_size += 2;
    }
    postf[postfix_size] = '\0';
}

int calculate(char* postf)
{
    int resultat = 0;
    struct stack resultat_stack;
    resultat_stack.value = 0;
    /*size_t*/int postf_size = strlen(postf);
    for (int i = 0; i < postf_size; ++i)
    {
        if (isdigit(postf[i]))
        {
            int x = 0;
            while (!isOperator(postf[i]) && postf[i] != ' ') {
                x *= 10;
                x += (int)(postf[i] - '0');
                i++;
                if (i == postf_size) {
                    break;
                }
            }
            PushStack(&resultat_stack, x);
            i--;
        }

        else if (isOperator(postf[i])) {
            int a = pop_stack(&resultat_stack);
            int b = pop_stack(&resultat_stack);
            if (postf[i] == '+') {
                resultat = b + a;
            }
            if (postf[i] == '-') {
                resultat = b - a;
            }
            if (postf[i] == '*') {
                resultat = b * a;
            }
            if (postf[i] == '/') {
                if (a == 0) {
                    printf("division by zero");
                    exit(0);
                }
                resultat = b / a;
            }
            PushStack(&resultat_stack, resultat);
        }
    }
    return peek_stack(&resultat_stack);
}

int main(void)
{
    char str[MAX_LENGTH];
    while (!fgets(str, MAX_LENGTH, stdin))
    {
        printf("syntax error!");    
        exit(0);
    }

    int ammount = strlen(str);
    unsigned int i = 0;

    while (i < (ammount - 1))
    {
        if (!proverka_simvolov(str[i]))
        {
            printf("syntax error");  
            return 0;
        }
        i++;
    }
    str[i] = '\0';
    char postf;
    postfix(str, i, postf);
    printf("%d", calculate(postf));
    return 0;
}
