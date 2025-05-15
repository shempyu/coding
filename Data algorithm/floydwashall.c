#include <stdio.h>
#include<limits.h>
#define INF 99 // Representation of infinity

// Floyd-Warshall Algorithm
void floydWarshall(int v, int graph[v][v]) {
    int dist[v][v];

    // Initialize the distance matrix with the input graph
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Perform relaxation for each intermediate vertex k
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&  dist[i][j] >dist[i][k] + dist[k][j] ) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final distance matrix
    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v;

    // Take input for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    int graph[v][v];

    // Take input for the adjacency matrix
    printf("\nEnter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Call Floyd-Warshall Algorithm
    floydWarshall(v, graph);

    return 0;
}
