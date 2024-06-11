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
    struct node *temp = NULL;
    if (root == NULL)
    {
        root = createNode(data);
        return root;
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
                    temp->left = createNode(data);
                    break;
                }
                temp = temp->left;
            }
            else if (data > temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = createNode(data);
                    break;
                }
                temp = temp->right;
            }
            else
            {
                printf("\nData already present !!");
                break;
            }
        }
    }
    return root;
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
    struct node *current = root;
    struct node *parent = NULL;

    // find the node to be deleted
    while (current != NULL && data != current->data)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
    }
    // printf("\ncurrent = %d", current->data);
    // printf("\nparent = %d", parent->data);

    // data not present
    if (current == NULL)
    {
        printf("\nData NOT present !!");
        return root;
    }

    // case 1:- only left child
    // case 2:- only right child
    // case 3:- no child
    if (current->right == NULL)
    {
        if (parent == NULL)
        {
            root = current->left;
        }
        else
        {
            if (current == parent->left)
            {
                parent->left = current->left;
            }
            else if (current == parent->right)
            {
                parent->right = current->left;
            }
        }
        free(current);
    }
    else if (current->left == NULL)
    {
        if (parent == NULL)
        {
            root = current->right;
        }
        else
        {
            if (current == parent->left)
            {
                parent->left = current->right;
            }
            else if (current == parent->right)
            {
                parent->right = current->right;
            }
        }
        free(current);
    }
    else
    {
        struct node *temp = findMin(current->right);
        current->data = temp->data;
        current->right = deleteNode(current->right, temp->data);
    }
    return root;
}

int search(struct node *root, int data)
{
    while (root != NULL)
    {
        if (data == root->data)
        {
            return 1;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else if (data > root->data)
        {
            root = root->right;
        }
    }
    return 0;
}

struct node *stack[100];
int top = -1;

void push(struct node *x)
{
    ++top;
    stack[top] = x;
}

struct node *pop()
{
    struct node *x;
    x = stack[top];
    --top;
    return x;
}

struct node *new_stack[100];
int new_top = -1;

void new_push(struct node *x)
{
    ++new_top;
    new_stack[new_top] = x;
}

struct node *new_pop()
{
    struct node *x;
    x = new_stack[new_top];
    --new_top;
    return x;
}

void inorder(struct node *root)
{
    struct node *stack = NULL;

start:

    while (root != NULL)
    {
        push(root);
        root = root->left;
    }

    while (top != -1 && root == NULL)
    {
        stack = pop();
        printf("%d ", stack->data);
        root = stack->right;
        goto start;
    }
}

void preorder(struct node *root)
{
    struct node *stack = NULL;

start:

    while (root != NULL)
    {
        push(root);
        printf("%d ", root->data);
        root = root->left;
    }

    while (top != -1 && root == NULL)
    {
        stack = pop();
        root = stack->right;
        goto start;
    }
}

void postorder(struct node *root)
{
    struct node *stack = NULL;

    push(root);
    while (top != -1)
    {
        stack = pop();
        new_push(stack);

        if (stack->left != NULL)
        {
            push(stack->left);
        }

        if (stack->right != NULL)
        {
            push(stack->right);
        }
    }

    // postorder printing
    while (new_top != -1)
    {
        stack = new_pop();
        printf("%d ", stack->data);
    }
}

struct node *queue[100];
int f = -1;
int r = -1;

void Qpush(struct node *x)
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

struct node *Qpop()
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

int getHeight(struct node *root)
{
    int height = -1, size = 0;
    struct node *temp = NULL;

    Qpush(root);

    if ((f != -1 && r != -1) && size == 0)
    {
        size = (r - f) + 1;
    }

    while (f != -1 && r != -1)
    {
        if (size == 0)
        {
            size = (r - f) + 1;
        }

        temp = Qpop();
        --size;

        if (size == 0)
        {
            ++height;
        }

        if (temp->left != NULL)
        {
            Qpush(temp->left);
        }

        if (temp->right != NULL)
        {
            Qpush(temp->right);
        }
    }
    return height;
}

int count = 0;

void totalNode(struct node *root)
{
    struct node *stack = NULL;

start:

    while (root != NULL)
    {
        push(root);
        root = root->left;
    }

    while (top != -1 && root == NULL)
    {
        stack = pop();
        count++;
        root = stack->right;
        goto start;
    }
}

void main()
{
    struct node *root = NULL;
    int choi, data, result;

START:

    printf("\n------ MENU ------");
    printf("\n 1.Add\n 2.Delet\n 3.Search\n 4.Height\n 5.Total node\n 6.Display\n 7.Exit");
    printf("\nEnter choice : ");
    scanf("%d", &choi);

    switch (choi)
    {
    case 1:
        printf("\nEnter data : ");
        scanf("%d", &data);
        root = insertNode(root, data);
        goto START;
        break;

    case 2:
        printf("\nEnter the data to be deleted : ");
        scanf("%d", &data);
        root = deleteNode(root, data);
        goto START;
        break;

    case 3:
        printf("\nEnter the data to be search : ");
        scanf("%d", &data);
        result = search(root, data);

        if (result == 1)
        {
            printf("\nData Found !!");
        }
        else
        {
            printf("\nData NOT Found !!");
        }
        goto START;
        break;

    case 4:
        // Height of the tree
        printf("Height = %d", getHeight(root));
        goto START;
        break;

    case 5:
        // Total no. of nodes
        totalNode(root);
        printf("Total No. of nodes = %d", count);
        goto START;
        break;

    case 6:
        // Display
        printf("\nInoredr : ");
        inorder(root);
        printf("\nPreorder : ");
        preorder(root);
        printf("\nPostorder : ");
        postorder(root);
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
