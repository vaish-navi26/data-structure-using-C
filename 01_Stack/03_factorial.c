#include<stdio.h>
#include<stdlib.h>
# define max 100

int stack[max];
int top = -1;

void push(int);
void show();

void main()
{
    int num,fac = 1;
    printf("Enter the number : ");
    scanf("%d",&num);

    if (num == 0)
    {
        fac = 1;
        push(fac);
    }

    while (num!=0)
    {
        push(num);
        fac = fac * num;
        num--;
    }

    printf("Factorial : ");
    show();
    printf(" :> %d \n",fac);
    
}

void push(int x)
{
    if(top == max-1)
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
        for (i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
    }
}