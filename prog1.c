#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n = 6, ne = 1;
int min, mincost = 0, adj[25][25], parent[25];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int temp[6][6] = {
        {0, 4, 4, 0, 0, 0},
        {4, 0, 2, 0, 0, 0},
        {4, 2, 0, 3, 4, 2},
        {0, 0, 3, 0, 3, 0},
        {0, 0, 4, 3, 0, 3},
        {0, 0, 2, 0, 3, 0}
    };

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            adj[i][j] = temp[i - 1][j - 1];
            if (adj[i][j] == 0)
                adj[i][j] = 999;
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (adj[i][j] < min) {
                    min = adj[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        adj[a][b] = adj[b][a] = 999;
    }

    printf("Minimum cost = %d\n", mincost);
    return 0;
}
