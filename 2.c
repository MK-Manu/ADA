#include <stdio.h>
#include <stdbool.h>

#define INF 9999999
#define V 5 

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};

int main() {
  int no_edge = 0;  
  int selected[V];  
  int total_cost = 0;
  selected[0] = true;

  int x, y;

  
  for (int i = 0; i < V; i++) {
    selected[i] = false;
  }

  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }

    printf("%d - %d : %d\n", x, y, G[x][y]);
    total_cost += G[x][y];
    selected[y] = true;
    no_edge++;
  }

  printf("Total cost of Minimum Spanning Tree: %d\n", total_cost);

  return 0;
}
