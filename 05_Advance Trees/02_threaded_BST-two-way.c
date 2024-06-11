#include <stdio.h>
#include <stdlib.h>
// Structure for threaded binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int lthread; // Thread flags
    int rthread; // Thread flags
};

struct Node *root = NULL;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->lthread = 1;
    newNode->rthread = 1; // Set threads to 1(true)initially return newNode;
}

// Function to insert a node in the threaded binary tree
void insertNode(int data)
{
    struct Node *curr = root, *parent = NULL;

    if (root == NULL)
    {
        root = createNode(data);
        return;
    }

    while (1)
    {
        parent = curr;
        if (data < curr->data)
        {
            if (curr->lthread == 0)
                curr = curr->left;
            else
            {
                struct Node *newNode = createNode(data);
                newNode->left = curr->left;
                newNode->right = curr;
                curr->left = newNode;
                curr->lthread = 0;
                return;
            }
        }
        else
        {
            if (curr->rthread == 0)
                curr = curr->right;
            else
            {
                struct Node *newNode = createNode(data);
                newNode->right = curr->right;
                newNode->left = curr;
                curr->right = newNode;
                curr->rthread = 0;
                return;
            }
        }
    }
}

// Function to perform an Inorder traversal of the threaded binary tree
void inorderTraversal(struct Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    
    if (curr->lthread == 0)
    {
        inorderTraversal(curr->left);
    }
    printf("%d ",curr->data);
    if (curr->rthread == 0)
    {
        inorderTraversal(curr->right);
    }
}

// Function to perform a Preorder traversal of the threaded binary tree
void preorderTraversal(struct Node *curr)
{
    if (curr == NULL)
        return;
    printf("%d ", curr->data);
    if (curr->lthread == 0)
        preorderTraversal(curr->left);
    if (curr->rthread == 0)
        preorderTraversal(curr->right);
}

// Function to perform a Postorder traversal of the threaded binary tree
void postorderTraversal(struct Node *curr)
{
    if (curr == NULL)
        return;
    if (curr->lthread == 0)
        postorderTraversal(curr->left);
    if (curr->rthread == 0)
        postorderTraversal(curr->right);
    printf("%d ", curr->data);
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertNode(data);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}