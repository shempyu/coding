#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in the graph
typedef struct Edge
{
    int u;      // Start vertex of the edge
    int v;      // End vertex of the edge
    int weight; // Weight of the edge
} Edge;



// Bellman-Ford Algorithm implementation
void bellmanFord(int V, int E, Edge edges[], int source)
{
    int dist[V];
    // Function to initialize distances
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX; // Set all distances to infinity
    }
    dist[source] = 0; // Distance to source is 0
    // Relaxation step
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
        {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    // Print the distances from the source
    printf("Vertex\tDistance from Source (%d)\n", source);
    for (int i = 0; i < V; i++)
    {
        printf("%d\t", i);
        if (dist[i] == INT_MAX)
        {
            printf("Infinity\n");
        }
        else
        {
            printf("%d\n", dist[i]);
        }
    }
}

int main()
{
    int V, E, source;

    // User-defined input for the graph
    printf("Enter the number of vertices ,edges,sorce : ");
    scanf("%d  %d %d", &V,&E,&source);

    Edge edges[E];
    printf("Enter the edges (start_vertex end_vertex weight):\n");
    for (int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Call the Bellman-Ford algorithm
    bellmanFord(V, E, edges, source);

    return 0;
}
