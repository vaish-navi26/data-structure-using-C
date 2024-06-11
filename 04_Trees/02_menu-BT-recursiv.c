#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *create()
{
    int data;
    struct node *new;

    printf("Enter Data (-1 for no data) : ");
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    printf("Enter the Left child of [%d] \n", data);
    new->left = create();

    printf("Enter the Right child of [%d] \n", data);
    new->right = create();

    return new;
}

void inordered(struct node *root)
{
    if (root != NULL)
    {
        inordered(root->left);
        printf("%d", root->data);
        inordered(root->right);
    }
}

void priordered(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        priordered(root->left);
        priordered(root->right);
    }
}

void postordered(struct node *root)
{
    if (root != NULL)
    {
        postordered(root->left);
        postordered(root->right);
        printf("%d", root->data);
    }
}

void main()
{
    int choi;

start:

    printf("\n------ MENU ------\n");
    printf("\n 1.Create\n 2.Delet\n 3.Display\n 4.Exit\n");
    printf("Enter Choice : ");
    scanf("%d", &choi);

    switch (choi)
    {
    case 1:
        root = create();
        goto start;
        break;

    case 2:
        root = NULL;
        goto start;
        break;

    case 3:
        printf("\nInoredr : ");
        inordered(root);
        printf("\nPreorder : ");
        priordered(root);
        printf("\nPostorder : ");
        postordered(root);
        goto start;
        break;

    case 4:
        exit(0);
        break;

    default:
        printf("\n!! Invalid Choice !!\n");
        break;
    }
}