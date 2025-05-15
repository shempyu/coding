#include <stdio.h>
#include <limits.h>
#define MAX_V 100 

typedef struct Edge {
    int u;      
    int v;       
    int weight;  
} Edge;

void createAdjMatrix(int V, int E, Edge edges[], int adjMatrix[MAX_V][MAX_V]) {
    // Initialize the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;  // Diagonal = 0, others = infinity
        }
    }

    // Fill the matrix with edge weights
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
void primMST(int V, int adjMatrix[MAX_V][MAX_V]) {
    int parent[V];                                                                         // To store the resulting MST
    int key[V];                                                                            // Key values to pick minimum weight edge
    int mstSet[V];                                                                          // To track vertices included in MST

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

        // Update key and parent for EACH adjacent vertices V OF U
        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] != INT_MAX && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    // Calculate and print the MST
    int totalWeight = 0;
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, adjMatrix[i][parent[i]]);
        totalWeight += adjMatrix[i][parent[i]];  // Accumulate the total MST weight
    }

    // Print the total weight of the MST
    printf("Total Weight of MST: %d\n", totalWeight);
}

int main() {
    int V, E;

    // User-defined input
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V,&E);

    Edge edges[E];
    printf("Enter the edges (start_vertex end_vertex weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    //  adjacency matrix for representing weight between edges
    int adjMatrix[MAX_V][MAX_V];

    // Create adjacency matrix
    createAdjMatrix(V, E, edges, adjMatrix);

    // Call Prim's Algorithm
    printf("\nMinimum Spanning Tree (MST):\n");
    primMST(V, adjMatrix);
     

    return 0;
}
