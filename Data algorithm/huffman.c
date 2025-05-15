#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char charr;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

// Define a comparison function for the min-heap
int compareNodes(const void* a, const void* b) {
    return ((Node*)a)->freq - ((Node*)b)->freq;
}

// Function to create a new node
Node* createNode(char charr, int freq) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->charr = charr;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build the Huffman tree
Node* buildHuffmanTree(char chars[], int freqs[], int n) {
    // Create an array of nodes
    Node* arr = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        arr[i] = *createNode(chars[i], freqs[i]);
    }

    // Build the initial min-heap using qsort
    qsort(arr, n, sizeof(Node), compareNodes);

    while (n > 1) {
        // Extract the two nodes with the smallest frequencies
        Node* left = (Node*)malloc(sizeof(Node));
        Node* right = (Node*)malloc(sizeof(Node));
        *left = arr[0];
        *right = arr[1];

        // Create a new internal node with combined frequency
        Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Replace the first two nodes with the new node
        arr[0] = *newNode;
        memmove(&arr[1], &arr[2], (n - 2) * sizeof(Node)); // Shift remaining nodes
        n--;
        // Rebuild the min-heap
        qsort(arr, n, sizeof(Node), compareNodes);
    }

    // Return the root of the Huffman tree
    Node* root = (Node*)malloc(sizeof(Node));
    *root = arr[0];
    return root;
}

// Function to print the Huffman codes
void printHuffmanCodes(Node root[], char code[], int top) {
     
    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
         printf("%c: %s\n", root->charr, code);
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    char chars[n];
    int freqs[n];

    printf("Enter the characters :\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &chars[i]);
    }

     printf("Enter the frequencis :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freqs[i]);
    }

    // Build Huffman tree
    Node* root = buildHuffmanTree(chars, freqs, n);

    char code[100];
    printf("\nHuffman Codes:\n");
    printHuffmanCodes(root, code, 0);

    return 0;
}
