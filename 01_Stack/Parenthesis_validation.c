#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define max 100

void push(char);
void pop();
char peek();
char validation(char);

char stack[max];
int top = -1;

void main()
{
    char str[100];
    int len,i;
    printf("Enter Parenthesis : ");
    gets(str);

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        char ch = str[i];

        if (ch == '{' || ch == '[' || ch == '(')
        {
            push(ch);
        }
        else if (top == -1)
        {
            printf("Stack Underflow !!!\n\n");
        }
        else
        {
            char x = peek();
            char v = validation(ch);
            if (x == v || x == v || x == v)
            {
                pop();

                if (top == -1)
                {
                    printf("Parenyhesis Valid !!!\n\n");
                }
            }
            else
            {
                printf("Unbalance !!!\n\n");
                break;
            }
        }
    }

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
        stack[top]=x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow !!!\n\n");
    }
    else
    {
        --top;
    }
}


char peek()
{
    if (top == -1)
    {
        printf("Stack Underflow !!!\n\n");
    }
    else
    {
        char x = stack[top];
        return x;
    }
}

char validation(char x)
{
    switch (x)
    {
    case ')':
        return '(';
        break;

    case ']':
        return '[';
        break;

    case '}':
        return '{';
        break;

    default:
        break;
    }
}
