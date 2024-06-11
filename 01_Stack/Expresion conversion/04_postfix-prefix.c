#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char stack[max];
char postfix[max],prefix[max],temp[max];
int top = -1;

void push(char x[]);
char pop();

int isEmpty();
int isSpace(char);

void postTOin();

int main()
{
    int i;

    printf("Postfix : ");
    gets(postfix);

    postTOin();

    printf("Prefix : ");

    i = 0;
    while (prefix[i] != '\0')
    {
        printf("%c", prefix[i]);
        i++;
    }
    printf("\n\n\n");
}

void push(char x[])
{
    if (top == max - 1)
    {
        printf("Stack Overflow !!!\n\n");
    }
    else
    {
        ++top;
        strcpy(stack[top],x);
    }
}

char pop()
{
    char x[max];
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        strcpy(x,stack[top]);
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
    int i=0;
    char symbol[20],t1[20],t2[20];

    while (i < strlen(postfix))
    {
        strcpy(symbol,postfix[i]);
        if (!isSpace(symbol))
        {
            if (symbol == "+" || symbol == "-" ||  symbol == "/" ||  symbol == "*")
            {
                while (z)
                {
                    /* code */
                }
                
            }
            else
            {
                push(symbol);
            }
        }
    }
    
}


