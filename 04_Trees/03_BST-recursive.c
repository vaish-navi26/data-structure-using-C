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

struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    else
    {
        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insertNode(root->right, data);
        }
        else
        {
            printf("\nData already exist!!");
        }
        return root;
    }
}

struct node *findMin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root != NULL)
    {
        if (data < root->data)
        {
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = deleteNode(root->right, data);
        }
        else if (data == root->data)
        {
            // there is no Right child
            if (root->right == NULL)
            {
                struct node *temp = root->left;
                free(root);
                printf("\n Node Deleted !!");
                return temp;
            }
            // there is no Left child
            else if (root->left == NULL)
            {
                struct node *temp = root->right;
                free(root);
                printf("\n Node Deleted !!");
                return temp;
            }
            // no child
            else if (root->left == NULL && root->right == NULL)
            {
                free(root);
                printf("\n Node Deleted !!");
            }
            // both child
            else
            {
                struct node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
    }
    else
    {
        printf("\nData does NOT exist !!");
    }
    return root;
}

void search(struct node *root, int data)
{
    if (root != NULL)
    {
        if (data == root->data)
        {
            printf("\nData Found !!");
        }
        else if (data < root->data)
        {
            search(root->left, data);
        }
        else if (data > root->data)
        {
            search(root->right, data);
        }
    }
    else
    {
        printf("\nData NOT Found !!");
    }
}

void inordered(struct node *root)
{
    if (root != NULL)
    {
        inordered(root->left);
        printf("%d ", root->data);
        inordered(root->right);
    }
}

void priordered(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
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
        printf("%d ", root->data);
    }
}

int getHeight(struct node *root)
{
    int left,right;

    if (root == NULL)
    {
        return -1;
    }

    left = getHeight(root->left);
    right = getHeight(root->right);

    return ((left > right)?left:right) + 1;
}

int count = 0;

void totalNode(struct node *root)
{
    if (root != NULL)
    {
        count++;
        totalNode(root->left);
        totalNode(root->right);
    }    
}

void main()
{
    int choi, data;
    struct node *root = NULL;

START:

    printf("\n------ MENU ------");
    printf("\n 1.Add\n 2.Delet\n 3.Search\n 4.Height\n 5.Total node\n 6.Display\n 7.Exit");
    printf("\nEnter choice : ");
    scanf("%d", &choi);

    switch (choi)
    {
    case 1:
        // Add
        printf("\nEnter data : ");
        scanf("%d", &data);
        root = insertNode(root, data);
        goto START;
        break;

    case 2:
        // Delete
        printf("\nEnter the data to be deleted : ");
        scanf("%d", &data);
        root = deleteNode(root, data);
        goto START;
        break;

    case 3:
        // Search
        printf("\nEnter the data to be search : ");
        scanf("%d", &data);
        search(root, data);
        goto START;
        break;

    case 4:
        // Height of the tree
        printf("Height = %d",getHeight(root));
        goto START;
        break;

    case 5:
        // Total no. of nodes
        totalNode(root);
        printf("Total No. of nodes = %d",count);
        goto START;
        break;

    case 6:
        // Display
        printf("\nInoredr : ");
        inordered(root);
        printf("\nPreorder : ");
        priordered(root);
        printf("\nPostorder : ");
        postordered(root);
        goto START;
        break;

    case 7:
        exit(0);
        break;

    default:
        printf("\n Invalid Input !!");
        goto START;
        break;
    }
}
