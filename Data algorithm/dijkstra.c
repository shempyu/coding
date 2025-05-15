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

// find the vertex with the minimum distance
int extractMin(int dist[], int visited[], int V)
{
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's Algorithm implementation
void dijkstra(int V, int E, Edge edges[], int source)
{
    int dist[V];    // Distance array
    int visited[V]; // Visited array

    // Initialize distances and visited set
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX; // Set all distances to infinity
        visited[i] = 0; // Mark all vertices as unvisited
    }
    dist[source] = 0; // Distance to source is 0

   

    // Priority queue simulation
    for (int i = 0; i < V - 1; i++)
    {
        int u = extractMin(dist, visited, V); // Extract vertex with minimum distance
        if (u == -1)
            break;      // Break if no vertex is reachable
        visited[u] = 1; // Mark the vertex as visited

        // Relaxation step
        for (int j = 0; j < E; j++)
        {
            if (edges[j].u == u)
            { // For edges starting from 'u'
                int v = edges[j].v;
                int weight = edges[j].weight;
                if (!visited[v] && dist[u] != INT_MAX && dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Print the distances from the source
    printf("Vertex\tDistance from Source (%d)\n", source);
    for (int i = 0; i < V; i++)
    {
        printf("%d\t", i);
        if (dist[i] == INT_MAX)
            printf("Infinity\n");
        else
            printf("%d\n", dist[i]);
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

    // Call Dijkstra's Algorithm
    dijkstra(V, E, edges, source);

    return 0;
}
