#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
typedef struct Edge {
    int u;      // Start vertex of the edge
    int v;      // End vertex of the edge
    int weight; // Weight of the edge
} Edge;

// Structure to represent a subset for union-find
typedef struct Subset {   // subset -> citygriup
    int parent;
    int rank;
} Subset;



// Function to find the set of an element i (uses path compression)
int findPrent(Subset subsets[], int v) {   // v- vertex -.city
    if (subsets[v].parent != v) {
        subsets[v].parent = findPrent(subsets, subsets[v].parent);
    }
    return subsets[v].parent;
}

// Function to perform the union of two sets x and y (uses union by rank)
void unionSets(Subset subsets[], int x, int y) {  //x ,y ->
    int parentX = findPrent(subsets, x);
    int parentY = findPrent(subsets, y);

    if (subsets[parentX].rank < subsets[parentY].rank) {
        subsets[parentX].parent = parentY;
    } else if (subsets[parentX].rank > subsets[parentY].rank) {
        subsets[parentY].parent = parentX;
    } else {
        subsets[parentY].parent = parentX;
        subsets[parentX].rank++;
    }
}

// Comparator function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal's algorithm implementation
void kruskal(int V, int E, Edge edges[]) {
    Edge mst[V - 1]; // To store the resultant MST
    int idx = 0;          // mstIndex
    int i = 0;          // Index for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of weight
    qsort(edges, E, sizeof(Edge), compareEdges);

    // Allocate memory for creating subsets
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    // Initialize disjoint sets
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Step 2: Pick the smallest edge and check if it forms a cycle
    while (idx < V - 1 && i < E) {
        Edge nextEdge = edges[i++];

        int x = findPrent(subsets, nextEdge.u); //(citygroup,nextroad.cityA)
        int y = findPrent(subsets, nextEdge.v); //(citygroup,nextroad.cityB)

        // If including this edge does not form a cycle
        if (x != y) {
            mst[idx++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the result
    printf("Edges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (i = 0; i < idx; i++) {
        printf("%d -- %d == %d\n", mst[i].u, mst[i].v, mst[i].weight);
        totalWeight += mst[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);

    // Free memory
    free(subsets);
}

int main() {
    int V, E;

    // User-defined input for the graph
    printf("Enter vert and edges  ");
    scanf("%d %d", &V,&E);

    Edge edges[E];
    printf("Enter the edges (start_vertex end_vertex weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Call Kruskal's algorithm
    kruskal(V, E, edges);

    return 0;
}










