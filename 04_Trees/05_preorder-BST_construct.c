#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct node *construct(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if (data < root->data)
        {
            root->left = construct(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = construct(root->right, data);
        }
        return root;
    }
}

struct node *queue[100];
int f = -1;
int r = -1;

void push(struct node *x)
{
    if (r == 99)
    {
        return;
    }

    if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
        queue[r] = x;
    }
    else
    {
        ++r;
        queue[r] = x;
    }
}

struct node *pop()
{
    struct node *x;

    if (f == r)
    {
        x = queue[f];
        f = -1;
        r = -1;
    }
    else
    {
        x = queue[f];
        ++f;
    }
    return x;
}

void display(struct node *root)
{
    struct node *temp = NULL;

    push(root);

    while (f != -1 && r != -1)
    {
        temp = pop();
        printf("%d ",temp->data);

        if (temp->left != NULL)
        {
            push(temp->left);
        }

        if (temp->right != NULL)
        {
            push(temp->right);
        }
    }
}

void main()
{
    int choi, preorder[100], i = 0, x,data;
    struct node *root = NULL;

START:

    printf("\n\n------ MENU ------");
    printf("\n 1.PreOrder Data\n 2.Construct\n 3.Delete (Tree)\n 4.Display (Level wise)\n 5.Exit");
    printf("\nEnter Choice : ");
    scanf("%d", &choi);

    switch (choi)
    {
    case 1:
        do
        {
            printf("\nEnter data (-1 for end) : ");
            scanf("%d", &x);
            preorder[i] = x;
            i++;
        } while (x != -1);

        printf("\nData inputed successfully !!");
        goto START;
        break;

    case 2:
        for (i = 0; preorder[i] != -1; i++)
        {
            data = preorder[i];
            root = construct(root, data);
        }
        
        printf("\nTree Constructed Successfully !!");
        goto START;
        break;

    case 3:
        printf("\nTree Deleted Successfully !!");
        root = NULL;
        i = 0;
        goto START;
        break;

    case 4:
        printf("\nTree (Level wise) : ");
        display(root);
        goto START;
        break;

    case 5:
        exit(0);
        break;

    default:
        printf("\n Invalid Input !!");
        break;
    }
}
