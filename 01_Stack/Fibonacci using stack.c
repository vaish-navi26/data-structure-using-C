#include<stdio.h>
#include<stdlib.h>
#define max 100

int stack[max];
int top = -1;

void push(int);
int fibo(int);
void show();

void main()
{
    int n,i,result;
    printf("Enter Length : ");
    scanf("%d",&n);
    push(0);
    for (i=0;i<n;i++)
    {
        result = fibo(i);
        push(result);
    }
    printf("Fibonacci series : ");
    show();
}

int fibo(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return (fibo(n-1)+fibo(n-2));
    }
}

void push(int x)
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


void show()
{
    int i;
    if(top == -1)
    {
        printf("Stack Underflow !!!\n\n");
    }
    else
    {
        for(i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
    }
}
