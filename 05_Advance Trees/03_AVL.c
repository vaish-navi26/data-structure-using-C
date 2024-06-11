#include <stdio.h>
#include <stdlib.h>

// Node structure for AVL tree
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of a node
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new node with a given key
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to right rotate a subtree rooted with y
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate a subtree rooted with x
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a key into the AVL tree
struct Node *insertNode(struct Node *node, int key)
{
    // Perform standard BST insert
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else // Duplicate keys are not allowed
        return node;

    // Update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

void inordered(struct Node *root)
{
    if (root != NULL)
    {
        inordered(root->left);
        printf("%d ", root->key);
        inordered(root->right);
    }
}

void priordered(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        priordered(root->left);
        priordered(root->right);
    }
}

void postordered(struct Node *root)
{
    if (root != NULL)
    {
        postordered(root->left);
        postordered(root->right);
        printf("%d ", root->key);
    }
}

void main()
{
    int choi, data;
    struct Node *root = NULL;

START:

    printf("\n------ MENU ------");
    printf("\n 1.Add\n 2.Display\n 3.Exit");
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
        // Display
        printf("\nInoredr : ");
        inordered(root);
        printf("\nPreorder : ");
        priordered(root);
        printf("\nPostorder : ");
        postordered(root);
        goto START;
        break;

    case 3:
        exit(0);
        break;

    default:
        printf("\n Invalid Input !!");
        goto START;
        break;
    }
}
