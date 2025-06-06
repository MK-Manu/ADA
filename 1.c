#include <stdio.h>

#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;
edge_list spanlist;
int Graph[MAX][MAX], n;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();
void printGraph();

void kruskalAlgo() {
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i++) {
    for (j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }
  }

  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) {
      spanlist.data[spanlist.n++] = elist.data[i];
      applyUnion(belongs, cno1, cno2);
    }
  }
}

int find(int belongs[], int vertexno) {
  return belongs[vertexno];
}

void applyUnion(int belongs[], int c1, int c2) {
  for (int i = 0; i < n; i++) {
    if (belongs[i] == c2)
      belongs[i] = c1;
  }
}

void sort() {
  edge temp;
  for (int i = 1; i < elist.n; i++) {
    for (int j = 0; j < elist.n - 1; j++) {
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
    }
  }
}

// Print the final MST
void print() {
  int cost = 0;
  printf("\nMinimum Spanning Tree Edges:\n");
  for (int i = 0; i < spanlist.n; i++) {
    printf("%d - %d : %d\n", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost += spanlist.data[i].w;
  }
  printf("Total cost of MST: %d\n", cost);
}

void printGraph() {
  printf("Input Graph (Adjacency Matrix):\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%3d ", Graph[i][j]);
    }
    printf("\n");
  }
}

int main() {
  n = 6;

  // Valid 6x6 graph matrix (no index out-of-bound!)
  int tempGraph[6][6] = {
    {0, 4, 4, 0, 0, 0},
    {4, 0, 2, 0, 0, 0},
    {4, 2, 0, 3, 4, 2},
    {0, 0, 3, 0, 3, 0},
    {0, 0, 4, 3, 0, 3},
    {0, 0, 2, 0, 3, 0}
  };


  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      Graph[i][j] = tempGraph[i][j];

  printGraph();      // Show input matrix
  kruskalAlgo();     // Run Kruskal's algorithm
  print();           // Show result

  return 0;
}
