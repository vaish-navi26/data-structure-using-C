#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char stack[max];
char prefix[max], infix[max];
int top = -1;

void push(char);
char pop();

int isEmpty();
int isSpace(char);

void preTOin();

int main()
{
    int i;

    printf("Prefix : ");
    gets(prefix);

    preTOin();

    printf("Infix : ");

    i = 0;
    while (infix[i] != '\0')
    {
        printf("%c", infix[i]);
        i++;
    }
    printf("\n\n\n");
}

void push(char x)
{
    if (top == max - 1)
    {
        printf("Stack Overflow !!!\n\n");
    }
    else
    {
        ++top;
        stack[top] = x;
    }
}

char pop()
{
    char x;
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        x = stack[top];
        top = top - 1;
        return x;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isSpace(char x)
{
    if (x == ' ' || x == '\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void preTOin()
{
    int i, j = 0;
    char next, symbol;

    for (i = 0; i < strlen(prefix); i++)
    {
        symbol = prefix[i];

        if (!isSpace(symbol))
        {
            if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
            {
                push(symbol);
            }
            else
            {
                infix[j++] = symbol;
                infix[j++] = pop();
            }
        }
    }
    infix[j++] = '\0';
}