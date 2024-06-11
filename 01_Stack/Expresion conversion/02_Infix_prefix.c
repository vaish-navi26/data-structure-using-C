#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char stack[max];
char infix[max], prefix[max];
int top = -1;

void push(char);
char pop();

int isEmpty();
int isSpace(char);

int precedence(char);
void inTOpre();

void infix_rev();
void prefix_rev();

int main()
{
    int i;

    printf("Infix : ");
    gets(infix);

    infix_rev();

    inTOpre();

    prefix_rev();

    printf("Prefix : ");

    i = 0;
    while (prefix[i] != '\0')
    {
        printf("%c", prefix[i]);
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
        printf("Stack UnderFlow\n\n");
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

int precedence(char x)
{
    switch (x)
    {
    case '^':
        return 3;
        break;

    case '/':
    case '*':
        return 2;
        break;

    case '+':
    case '-':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}

void inTOpre()
{
    int i, j = 0;
    char next, symbol;

    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        if (!isSpace(symbol))
        {
            switch (symbol)
            {
            case ')':
                push(symbol);
                break;

            case '(':
                while ((next = pop()) != ')')
                {
                    prefix[j++] = next;
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(symbol) < precedence(stack[top]))
                {
                    prefix[j++] = pop();
                }
                push(symbol);
                break;

            default:
                prefix[j++] = symbol;
                break;
            }
        }
    }

    while (!isEmpty())
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
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

void prefix_rev()
{
    char str2[100], *ptr1;
    int i, len = 0, j = 0;

    for (i = 0; prefix[i] != '\0'; i++)
    {
        len++;
    }

    len = len - 1;

    ptr1 = &prefix[len];

    for (i = len; i >= 0; i--)
    {
        str2[j] = *ptr1;
        ptr1--;
        j++;
    }

    for (i = 0; i <= len; i++)
    {
        prefix[i] = str2[i];
    }
    prefix[i] = '\0';
}