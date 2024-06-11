#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

char stack[max];
char infix[max],postfix[max];
int top = -1;

void push(char);
char pop();

int isEmpty();
int isSpace(char);

int precedence(char);
void inTOpo();

int main()
{
    int i;

    printf("Infix : ");
    gets(infix);
    
    inTOpo();

    printf("Postfix : ");
    i = 0;
    while (postfix[i] != '\0')
    {
        printf("%c",postfix[i]);
        i++;
    }
    printf("\n\n\n");
}


void push(char x)
{
    if (top == max-1)
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


void inTOpo()
{
    int i,j=0;
    char next,symbol;

    for (i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];

        if (!isSpace(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;

            case ')':
                while ((next = pop()) != '(')
                {
                    postfix[j++]=next;
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(symbol) <= precedence(stack[top]))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
                    
            default:
            postfix[j++] = symbol;
                break;
            }
        }
    }

    while (!isEmpty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    
}