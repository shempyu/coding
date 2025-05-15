#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in the graph
typedef struct Edge {
    int u;       // Start vertex of the edge
    int v;       // End vertex of the edge
    int weight;  // Weight of the edge
} Edge;

// Function to create an adjacency matrix from edges
void createAdjMatrix(int V, int E, Edge edges[], int** adjMatrix) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;  // Initialize weights
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;  // For undirected graph
    }
}

// Function to find the vertex with the minimum key value
int extractMin(int key[], int mstSet[], int V) {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Prim's Algorithm
void primMST(int V, int** adjMatrix) {
    int parent[V];  // To store the resulting MST
    int key[V];     // Key values to pick minimum weight edge
    int mstSet[V];  // To track vertices included in MST

    // Initialize keys and mstSet
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
        parent[i] = -1;  // No parent initially
    }

    // Start with the first vertex
    key[0] = 0;  // Include the first vertex in MST

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = extractMin(key, mstSet, V);
        mstSet[u] = 1;  // Add u to MST set

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] != INT_MAX && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    // Print the MST
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, adjMatrix[i][parent[i]]);
    }
}

int main() {
    int V, E;

    // User-defined input
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    Edge edges[E];
    printf("Enter the edges (start_vertex end_vertex weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Create adjacency matrix
    int** adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = (int*)malloc(V * sizeof(int));
    }
    createAdjMatrix(V, E, edges, adjMatrix);

    // Call Prim's Algorithm
    printf("\nMinimum Spanning Tree (MST):\n");
    primMST(V, adjMatrix);

    // Free allocated memory
    for (int i = 0; i < V; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
