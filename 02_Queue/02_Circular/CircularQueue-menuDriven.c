#include <stdio.h>
#include <stdlib.h>
#define max 10

int Cqueue[max];
int f = -1;
int r = -1;

void CQadd();
void CQdelet();
void CQshow();

void main()
{
    int choi;

start:

    printf("\n------ Menu ------\n");
    printf(" 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
    printf("Enter Choiche : ");
    scanf("%d", &choi);

    switch (choi)
    {
    case 1:
        CQadd();
        goto start;
        break;

    case 2:
        CQdelet();
        goto start;
        break;

    case 3:
        CQshow();
        goto start;
        break;

    case 4:
        exit(0);
        break;

    default:
        printf("Please Enter valid input !!!\n\n");
        break;
    }
}

void CQadd()
{
    int x;

    if (((r + 1) % max) == f)
    {
        printf("Overflow !!!\n\n");
    }
    else if (f == -1 && r == -1)
    {
        printf("Enter data : ");
        scanf("%d", &x);
        f = 0;
        r = 0;
        Cqueue[r] = x;
    }
    else
    {
        printf("Enter data : ");
        scanf("%d", &x);
        r = (r + 1) % max;
        Cqueue[r] = x;
    }
}

void CQdelet()
{
    if (f == -1 && r == -1)
    {
        printf("Underflow !!!\n\n");
    }
    else if (f == r)
    {
        printf("Dequeued Data : %d :\n", Cqueue[f]);
        f = -1;
        r = -1;
    }
    else
    {
        printf("Dequeued Data : %d :\n", Cqueue[f]);
        f = (f + 1) % max;
    }
}

void CQshow()
{
    int i = f;
    if (f == -1 && r == -1)
    {
        printf("Underflow !!!\n\n");
    }
    else
    {
        printf("Circular Queue :> ");
        while (i != r)
        {
            printf(": %d :", Cqueue[i]);
            i = (i+1)%max;
        }
        printf(": %d :",Cqueue[i]);
    }
}
