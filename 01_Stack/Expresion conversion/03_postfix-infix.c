#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char stack[max];
char postfix[max], infix[max];
int top = -1;

void push(char);
char pop();

int isEmpty();
int isSpace(char);

void postTOin();

void infix_rev();
void postfix_rev();

int main()
{
    int i;

    printf("Postfix : ");
    gets(postfix);

    postfix_rev();

    postTOin();

    infix_rev();

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

void postTOin()
{
    int i, j = 0;
    char next, symbol;

    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];

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

void postfix_rev()
{
    char str2[100], *ptr1;
    int i, len = 0, j = 0;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        len++;
    }

    len = len - 1;

    ptr1 = &postfix[len];

    for (i = len; i >= 0; i--)
    {
        str2[j] = *ptr1;
        ptr1--;
        j++;
    }

    for (i = 0; i <= len; i++)
    {
        postfix[i] = str2[i];
    }
    postfix[i] = '\0';
}

void infix_rev()
{
    char str2[100], *ptr1;
    int i, len = 0, j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        len++;
    }

    len = len - 1;

    ptr1 = &infix[len];

    for (i = len; i >= 0; i--)
    {
        str2[j] = *ptr1;
        ptr1--;
        j++;
    }

    for (i = 0; i <= len; i++)
    {
        infix[i] = str2[i];
    }
    infix[i] = '\0';
}