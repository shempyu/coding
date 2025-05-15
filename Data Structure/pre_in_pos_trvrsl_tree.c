#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
//traversal in tree
// Definition of a tree node
struct Node {
    int data;
    struct Node *left, *right;
};


// Function to create a new tree node
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preorder(struct Node *root){
    if(root == NULL)
      return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);  
}
void postorder(struct Node *root){
    if(root == NULL)
       return;
    postorder(root->left);
    postorder(root->right);  
    printf("%d ",root->data);  

}

void inorder(struct Node *root){
    if(root == NULL)
       return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);  
      
}

// Driver code
int main() {
    struct Node *root = NULL;

    // Construct the binary tree
    root = newNode(4);
    root->left = newNode(5);
    root->right = newNode(10);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    // root->right->left = newNode();
    root->right->right = newNode(1);

    // Print postorder traversal
    printf("inorder traversal of the binary tree is:\n[ ");
    inorder(root);
    printf("]\n");

    printf("Preorder traversal of the binary tree is:\n[ ");
    preorder(root);
    printf("]\n");
    
    printf("Postorder traversal of the binary tree is:\n[ ");
    postorder(root);
    printf("]\n");

    
    return 0;
}
