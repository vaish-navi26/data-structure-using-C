#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;




void ins_start();
void ins_middel();
void ins_end();

void del_start();
void del_middel();
void del_end();

void show();



void main()
{
    START:

    int choi;
    printf("\n------- Menu -------\n");
    printf(" 1.Insertion\n 2.Deletion\n 3.Display\n 4.Exit\n");
    printf("Enter the opperation : ");
    scanf("%d",&choi);

    switch (choi)
    {
    case 1:

         ins:

        int choi_ins;
        printf("\n----- Insertion -----\n");
        printf(" 1.at start\n 2.at middel\n 3.at end\n 4.exit\n");
        printf("Enter opperation : ");
        scanf("%d",&choi_ins);

        switch (choi_ins)
        {
        case 1:
            ins_start();
            goto ins;
            break;

        case 2:
            ins_middel();
            goto ins;
            break;

        case 3:
            ins_end();    
            goto ins;  
            break;  

        case 4:
            goto START;
            break;    
        
        default:
            printf("Please Input Valid Input !!!\n\n");
            goto ins;
            break;
        }
        goto START;
        break;

    case 2:

       del:

        int choi_del;
        printf("\n----- Deletion -----\n");
        printf(" 1.at start\n 2.at middel\n 3.at end\n 4.exit\n");
        printf("Enter opperation : ");
        scanf("%d",&choi_del);

        switch (choi_del)
        {
        case 1:
            del_start();
            goto del;
            break;

        case 2:
            del_middel();
            goto del;
            break;

        case 3:
            del_end();    
            goto del;
            break;

        case 4:
            goto START;
            break;        
        
        default:
            printf("Please Input Valid Input !!!\n\n");
            goto del;
            break;
        }
        goto START;
        break;

        case 3:
            show();
            goto START;
            break;

        case 4:
            exit(0);
            break;

    default:
        printf("Please input valid input !!!\n\n");
        goto START;
        break;
    }
}




void ins_start()
{
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);

    struct node *n,*temp;
    n = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        head = n;
        n->data = data;
        n->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        n->next = head;
        n->data = data;
        temp->next = n;
        head = n;
        
    }

    printf("Node Inserted Successfully !!\n\n"); 
}

void ins_middel()
{
    printf("ins_middel\n\n");

    int i,loc,data;
    struct node *n,*temp;

    n = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data : ");
    scanf("%d",&data);

    n->data = data;

    printf("Enter the location after which you want to insert the data : ");
    scanf("%d",&loc);

    temp = head;

    for (i=1;i<loc;i++)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    printf("Node Inserted Successfully !!\n\n");
}

void ins_end()
{
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);

    struct node *n,*temp;
    n = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        head = n;
        n->next = head;
        n->data = data;
    }
    else
    {
        temp=head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        n->next = head;
        temp->next = n;
        n->data = data;
    }

    printf("Node Inserted Successfully !!\n\n"); 
}



void del_start()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is Empty !!!\n\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("Node Deleted Successfully !!\n\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp -> next = head->next;
        free(head);
        head = temp->next;
        printf("Node Deleted Successfully !!\n\n");
        
    }
}

void del_middel()
{
    printf("del_middel\n\n");

    struct node *temp,*temp1;
    int loc,i;
    printf("Enter the location of node after which you want to delet node : ");
    scanf("%d",&loc);

    temp = head;
    for ( i = 0; i < loc; i++)
    {
        temp1 = temp;
        temp = temp->next;
    }

    temp1->next = temp->next;
    free(temp);
    printf("Node Deleted Successfully !!\n\n");
    
}

void del_end()
{
    struct node *temp1,*temp2;

    if (head == NULL)
    {
        printf("List is Empty !!!\n\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\n Node Deleted Successfully !!\n\n");
    }
    else
    {
        temp1 = head;
        while (temp1->next != head)
        {
            temp2 = temp1;
            temp1 = temp1 -> next;
        }
        temp2->next = temp1->next;
        free(temp1);
        printf("Node Deleted Successfully !!\n\n");        
    }
}



void show()
{
    printf("Link list :> ");

    struct node *temp;
    temp = head;

    if (temp == NULL)
    {
        printf("List is Empty !!!\n\n");
    }
    else
    {
        while (temp->next != head)
        {
            printf(": %d :",temp->data);
            temp = temp->next;
        }
        printf(": %d :",temp->data);
        }
}