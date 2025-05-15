#include <stdio.h>
#include <stdlib.h>
//BST with all type of traversal USERDEFINED
// Definition of a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node *newNode(int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
      newnode->left = newnode->right = NULL;
    newnode->data = data;
    return newnode;
}

// Function to insert a node in a BST
struct Node *insertNode(struct Node *root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to create a BST dynamically
struct Node *createBST() {
     int n;
    struct Node *root = NULL;
    int data;
    printf("how many node u want to enter: ");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        printf("Enter a value to insert into BST");
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    return root;
}

// Function for inorder traversal of the BST
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for postorder traversal of the BST
void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function for preorder traversal of the BST
void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node *root = NULL;
    int choice, value;

    printf("Binary Search Tree Menu:\n");
    printf("1. Create BST\n");
    printf("2. Insert a Node\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Preorder Traversal\n");
    printf("6. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            root = createBST();
            printf("BST created successfully.\n");
            break;

        case 2:
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            printf("Inserted %d into the BST.\n", value);
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;

        case 6:
            printf("Exiting.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
