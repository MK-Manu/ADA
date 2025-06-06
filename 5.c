#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int arr[MAX_VERTICES];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int data) {
    s->arr[++s->top] = data;
}

int pop(Stack *s) {
    if (!isEmpty(s))
        return s->arr[s->top--];
    else {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
}

typedef struct {
    int vertices;
    int **adjMatrix;
} Graph;

Graph* createGraph(int vertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; ++i)
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
}

void DFS(Graph *graph, int vertex, bool *visited, Stack *s) {
    visited[vertex] = true;
    for (int i = 0; i < graph->vertices; ++i) {
        if (graph->adjMatrix[vertex][i] && !visited[i])
            DFS(graph, i, visited, s);
    }
    push(s, vertex);
}

void topologicalSort(Graph *graph) {
    Stack s;
    initialize(&s);
    bool visited[MAX_VERTICES] = {false};
    for (int i = 0; i < graph->vertices; ++i) {
        if (!visited[i])
            DFS(graph, i, visited, &s);
    }
    printf("Topological ordering of vertices: ");
    while (!isEmpty(&s))
        printf("%d ", pop(&s));
    printf("\n");
}

int main() {
    int vertices = 6;
    Graph *graph = createGraph(vertices);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    topologicalSort(graph);
    return 0;
}
