#include <stdio.h>
#include<stdlib.h>
# define max 10

void push();
void pop();
void show();
void peek();

int top = -1;
int stack[max];

void main()
{
    int choi,end=0;

    start:

    printf("\n\n----- Menu -----\n");
    printf(" 1.Push\n 2.Pop\n 3.Peek\n 4.Display\n 5.Exit\n");
    printf("Enter opperation : ");
    scanf("%d",&choi);

    
        switch (choi)
        {
        case 1:
            push();
            goto start;
            break;

        case 2:
            pop();
            goto start;
            break;

        case 3:
            peek();
            goto start;
            break;

        case 4:
            show();
            goto start;
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid opperation\n");
            break;
        }

    
}


void push()
{
    int x;
    if (top == max-1)
    {
        printf("Stack Overflow !!! \n\n");
    }
    else
    {
        printf("Enter the data : ");
        scanf("%d",&x);
        ++top;
        stack[top]=x;
    }
}


void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow !!! \n\n");
    }
    else
    {
        printf("Pop data : %d\n",stack[top]);
        --top;
    }
}


void peek()
{
    if(top == -1)
    {
        printf("Stack Underflow !!!\n\n");
    }
    else
    {
        printf("Stack Peek : %d\n",stack[top]);
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
        printf("Stack >> ");
        for(i=top;i>=0;i--)
        {
            printf(": %d :",stack[i]);
        }
        
    }
}