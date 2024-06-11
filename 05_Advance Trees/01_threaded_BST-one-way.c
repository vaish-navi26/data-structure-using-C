#include <stdio.h>
#include <stdlib.h>

// Node structure for threaded binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int isThreaded; // Indicates whether the right pointer is a thread
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

// Function to find the leftmost node in a subtree
struct Node *leftMost(struct Node *node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to perform an in-order traversal of the threaded binary tree
void inorder(struct Node *root) {
    struct Node *current = leftMost(root);

    while (current != NULL) {
        printf("%d ", current->data);

        // If the right pointer is a thread, move to the in-order successor
        if (current->isThreaded) {
            current = current->right;
        } else {
            // Otherwise, move to the leftmost child in the right subtree
            current = leftMost(current->right);
        }
    }
}


// Function to insert a new node into the threaded binary tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node and make it the root
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recursively insert into the left or right subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        // If the right subtree is empty, insert and thread
        if (root->right == NULL) {
            struct Node* newNode = createNode(data);
            newNode->right = root->right;
            newNode->isThreaded = 1;
            root->right = newNode;
        } else {
            // Otherwise, recursively insert into the right subtree
            root->right = insert(root->right, data);
        }
    }

    return root;
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
        root = insert(root, data);
        goto START;
        break;

    case 2:
        // Display
        printf("\nInoredr : ");
        inorder(root);
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

