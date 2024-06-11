#include<stdio.h>
#include<stdlib.h>
# define max 100

int stack[max];
int top = -1;

void push(int);
void show();

void main()
{
    int num,rem;

    printf("\nEnter the Decimal number : ");
    scanf("%d",&num);

    if (num == 0)
    {
        push(num);
    }

    while (num!=0)
    {
       rem = num % 2;
       push(rem);
       num = num / 2; 
    }

    printf("Binary number : ");
    show();

    
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
    if (top == -1)
    {
        printf("Stack Underflow !!!\n\n");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
    }
}
