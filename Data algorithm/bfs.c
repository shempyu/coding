#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for the queue
struct Queue {
    int items[MAX];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Enqueue function
void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

// Dequeue function
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1; // Reset the queue
    } else {
        q->front++;
    }
    return item;
}

// BFS function
void bfs(int n, int graph[n][n], int start) {
    int color[n], distance[n], parent[n];
    struct Queue q;

    initializeQueue(&q);

    // Initialize all vertices
    for (int i = 0; i < n; i++) {
        color[i] = 0; // WHITE
        distance[i] = -1; // Infinity (not reachable initially)
        parent[i] = -1; // NIL
    }

    // Initialize start vertex
    color[start] = 1; // GRAY
    distance[start] = 0;
    enqueue(&q, start);

    printf("BFS traversal: ");

    // BFS loop
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1 && color[v] == 0) { // Explore adjacent vertices
                color[v] = 1; // GRAY
                distance[v] = distance[u] + 1;
                parent[v] = u;
                enqueue(&q, v);
            }
        }

        color[u] = 2; // BLACK (fully explored)
    }

    printf("\n\nVertex Distance and Parent:\n");
    printf("Vertex\tDistance\tParent\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i, distance[i], parent[i]);
    }
}

int main() {
    int n, start;

    // Take input for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    // Take input for the adjacency matrix
    printf("\nEnter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Take input for the starting vertex
    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    // Call BFS function
    bfs(n, graph, start);

    return 0;
}
