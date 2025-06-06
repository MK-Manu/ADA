#include <stdio.h>
#include <stdbool.h>

#define V 6
#define INF 99999

int minDistance(int dist[], bool sptSet[]) {
    int min = INF, min_index;

    for (int i = 0; i < V; i++) {
        if (!sptSet[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void printSolution(int dist[], int src) {
    printf("Vertex   Distance from Source %d\n", src);
    for (int i = 0; i < V; i++){
        printf("%d        %d", i, dist[i]);
        printf("\n"); }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int j = 0; j < V; j++) {
            if (!sptSet[j] && graph[u][j] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist, src);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int src = 0;

    printf("Shortest paths from vertex %d:\n", src);
    dijkstra(graph, src);

    return 0;
}
