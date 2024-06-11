#include <stdio.h>
#include <stdlib.h>
#define max 10

void push(int);
int pop();

void add();
void sub();
void multi();
void divi();


int top = -1;
int stack[max];

void main()
{
    int choi, end = 0, n1, n2;

start:

    printf("\n\n----- Menu -----\n");
    printf(" 1.Add\n 2.Sub\n 3.Mul\n 4.Div\n 5.Exit\n");
    printf("Enter opperation : ");
    scanf("%d", &choi);

    switch (choi)
    {
    case 1:
        printf("Enter the first number :");
        scanf("%d", &n1);
        push(n1);
        printf("Enter the Second number :");
        scanf("%d", &n2);
        push(n2);
        add();
        goto start;
        break;

    case 2:
        printf("Enter the first number :");
        scanf("%d", &n1);
        push(n1);
        printf("Enter the Second number :");
        scanf("%d", &n2);
        push(n2);
        sub();
        goto start;
        break;

    case 3:
        printf("Enter the first number :");
        scanf("%d", &n1);
        push(n1);
        printf("Enter the Second number :");
        scanf("%d", &n2);
        push(n2);
        multi();
        goto start;
        break;

    case 4:
        printf("Enter the first number :");
        scanf("%d", &n1);
        push(n1);
        printf("Enter the Second number :");
        scanf("%d", &n2);
        push(n2);
        divi();
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

void push(int x)
{
    if (top == max - 1)
    {
        printf("Stack Overflow !!! \n\n");
    }
    else
    {
        ++top;
        stack[top] = x;
    }
}

int pop()
{
    int n;
    if (top == -1)
    {
        printf("Stack Underflow !!! \n\n");
    }
    else
    {
        n = stack[top];
        --top;
        return n;
    }
}

void add()
{
    int x,y,z;

    y = pop();
    x = pop();

    z = x + y;

    printf("Addition : %d",z);

}

void sub()
{
    int x,y,z;

    y = pop();
    x = pop();

    z = x - y;

    printf("Substraction : %d",z);

}

void multi()
{
    int x,y;
    long int z;

    y = pop();
    x = pop();

    z = x * y;

    printf("Multiplication : %d",z);

}

void divi()
{
    int x,y,z;

    y = pop();
    x = pop();

    z = x / y;

    printf("Division : %d",z);

}