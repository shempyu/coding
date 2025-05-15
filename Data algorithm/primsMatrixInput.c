#include <stdio.h>
#include <limits.h>

#define MAX_V 100 
#define INF 100 // Representation of infinity

int extractMin(int dist[], int mstSet[], int V) {
    int min = INF, minIndex = -1;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Prim's Algorithm
void primMST(int V, int adjMatrix[MAX_V][MAX_V]) {
    int parent[V];                                                                                     // To store the resulting MST
    int dist[V];                                                                                     // Key values to pick minimum weight edge
    int mstSet[V];                                                                                   // To track vertices included in MST

    // Initialize keys and mstSet
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        mstSet[i] = 0;
        parent[i] = -1;                                                                                // No parent initially
    }

    dist[0] = 0; 
    for (int i = 0; i < V - 1; i++) {
        int u = extractMin(dist, mstSet, V);
        mstSet[u] = 1;  
        for (int j = 0; j < V; j++) {
            if (adjMatrix[u][j] != INF && !mstSet[j] &&  dist[j] >adjMatrix[u][j]) {
                dist[j] = adjMatrix[u][j];
                parent[j] = u;
            }
        }
    }

    // Calculate and print the MST
    int totalWeight = 0;
    printf("\nMinimum Spanning Tree (MST):\n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, adjMatrix[i][parent[i]]);
        totalWeight += adjMatrix[i][parent[i]];  // Accumulate the total MST weight
    }

    // Print the total weight of the MST
    printf("Total Weight of MST: %d\n", totalWeight);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int adjMatrix[MAX_V][MAX_V];

    printf("\nEnter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    primMST(V, adjMatrix);

    return 0;
}
