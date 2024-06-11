#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
void create();
int height(struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);


void main()
{
    int choi, x;
START:
    printf("\n------- Menu --------");
    printf("\n1. Insert \n2. Delet \n3.Display \n4.Height \n5.Exit");
    printf("\nEnter the choiche : ");
    scanf("%d", &choi);

    switch (choi)
    {
    case 1:
        create();
        goto START;
        break;

    case 2:
        printf("Enter the Data to be deleted : ");
        scanf("%d", &x);
        root = delete (root, x);
        goto START;
        break;

    case 3:
        printf("\nInOrder : ");
        inorder(root);
        printf("\nPreOrder : ");
        preorder(root);
        printf("\nPostOredr : ");
        postorder(root);
        goto START;
        break;

    case 4:
        height(root);
        goto START;
        break;

    case 5:
        exit(0);
        break;

    default:
        printf("\nInvalid Choiche !!!\n");
        goto START;
        break;
    }
}

void create()
{
    int data;
    struct node *n, *temp;

    printf("Enter the data : ");
    scanf("%d", &data);

    n = (struct node *)malloc(sizeof(struct node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;
   
    if (root == NULL)
    {
        root = n;
        printf("\nn->data : %d", n->data);
        printf("\nroot->data : %d", root->data);
    }
    else
    {
        temp = root;
        while (1)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = n;
                    printf("\nn->data : %d", n->data);
                    printf("\ntemp->data : %d", temp->left->data);
                    break;
                }
                temp = temp->left;
            }
            else if (data > temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = n;
                    printf("\nn->data : %d", n->data);
                    printf("\ntemp->data : %d", temp->right->data);
                    break;
                }
                temp = temp->right;
            }
            else
            {
                free(n); // data already exist
                break;
            }
        }
    }
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);

    if (left_height > right_height)
    {
        return 1 + left_height;
    }
    else
    {
        return 1 + right_height;
    }
}




void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}