# include<stdio.h>
# include<stdlib.h>
# define max 10

int Queue[max];
int f=-1,r=-1;

void Enqueue();
void Dequeue();
void show();


void main()
{
    int choi;

    start:

    printf("\n------ Menu ------\n");
    printf(" 1.add\n 2.Delet\n 3.Display\n 4.Exit\n");
    printf("Enter Choiche : ");
    scanf("%d",&choi);

    switch (choi)
    {
    case 1:
        Enqueue();
        goto start;
        break;

    case 2:
        Dequeue();
        goto start;
        break;

    case 3:
        show();
        goto start;
        break;

    case 4:
        exit(0);
        break;    
    default:
        printf("Please enter valid input !!!\n\n");
        break;
    }
}


void Enqueue()
{
    int x;
    if(r == max-1)
    {
        printf("Overflow !!!\n\n");
    }
    else if (f == -1 && r == -1)
    {
        printf("Enter the data : ");
        scanf("%d",&x);

        f = 0;
        r = 0;
        Queue[r] = x;
    }
    else
    {
        printf("Enter the data : ");
        scanf("%d",&x);
        r++;
        Queue[r] = x;
    }   
}


void Dequeue()
{
    if (f == -1 && r == -1)
    {
        printf("Underflow !!!\n\n");
    }
    else if (f == r)
    {
        printf("\nDequeued data : %d",Queue[f]);
        f = -1;
        r = -1;
    }
    else
    {
        printf("\nDequeued data : %d",Queue[f]);
        f++;
    }
}


void show()
{
    int i=f;
    if (f == -1 && r == -1)
    {
        printf("Underflow !!!\n\n");
    }
    else
    {
        printf("Queue :> ");
        while (i<=r)
        {
            printf(": %d :",Queue[i]);
            i++;
        }
        
    }
}
