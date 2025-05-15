#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

// Structure to represent a vertex
typedef struct Vertex {
    int id;
    int color;
    int discoveryTime;
    int finishTime;
    int parent;
    struct Vertex* next;
} Vertex;

// Structure to represent the graph
typedef struct Graph {
    int verticesCount;
    Vertex** adjList;
} Graph;

int time = 0;

// Function to create a new vertex
Vertex* createVertex(int id) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->id = id;
    newVertex->color = WHITE;
    newVertex->discoveryTime = 0;
    newVertex->finishTime = 0;
    newVertex->parent = -1;
    newVertex->next = NULL;
    return newVertex;
}

// Function to initialize the graph
Graph* createGraph(int verticesCount) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->verticesCount = verticesCount;
    graph->adjList = (Vertex**)malloc(verticesCount * sizeof(Vertex*));
    for (int i = 0; i < verticesCount; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Vertex* newVertex = createVertex(dest);
    newVertex->next = graph->adjList[src];
    graph->adjList[src] = newVertex;
}

// DFS-VISIT function
void dfsVisit(Graph* graph, Vertex* u) {
    time++;
    u->discoveryTime = time;
    u->color = GRAY;

    printf("Visited Vertex %d at time %d\n", u->id, time);

    Vertex* v = graph->adjList[u->id];
    while (v) {
        if (graph->adjList[v->id]->color == WHITE) {
            graph->adjList[v->id]->parent = u->id;
            dfsVisit(graph, graph->adjList[v->id]);
        }
        v = v->next;
    }

    u->color = BLACK;
    time++;
    u->finishTime = time;
    printf("Finished Vertex %d at time %d\n", u->id, time);
}

// DFS function
void dfs(Graph* graph) {
    for (int i = 0; i < graph->verticesCount; i++) {
        if (!graph->adjList[i]) {
            graph->adjList[i] = createVertex(i);
        }
        graph->adjList[i]->color = WHITE;
        graph->adjList[i]->parent = -1;
    }

    for (int i = 0; i < graph->verticesCount; i++) {
        if (graph->adjList[i]->color == WHITE) {
            dfsVisit(graph, graph->adjList[i]);
        }
    }
}

// Main function
int main() {
    int vertices, edges;
    
    // User-defined input for vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    Graph* graph = createGraph(vertices);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nStarting Depth First Search:\n");
    dfs(graph);

    // Free memory
    for (int i = 0; i < vertices; i++) {
        free(graph->adjList[i]);
    }
    free(graph->adjList);
    free(graph);

    return 0;
}
