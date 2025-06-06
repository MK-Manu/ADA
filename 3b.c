#include <stdio.h>

#define V 4

void printTransitiveClosure(int closure[][V]) {
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", closure[i][j]);
        }
        printf("\n");
    }
}

void transitiveClosure(int graph[][V]) {
    int closure[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            closure[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    printTransitiveClosure(closure);
}

int main() {
    int graph[V][V] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    transitiveClosure(graph);

    return 0;
}
