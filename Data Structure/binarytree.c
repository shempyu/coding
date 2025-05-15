#include <stdio.h>
#include <stdlib.h>
//binary tree user defined
// Definition of a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node *newNode(int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}


// Function to create a binary tree dynamically
struct Node *createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node *node = newNode(data);

    printf("Enter left child of %d:\n", data);
    node->left = createTree();

    printf("Enter right child of %d:\n", data);
    node->right = createTree();

    return node;
}

// Driver code
int main() {
    printf("Create the binary tree:\n");
    struct Node *root = createTree();


    return 0;
}
