#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define N 8
int x[N + 1];
int board[N][N];

bool isSafe(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

bool NQueens(int k) {
    for (int i = 1; i <= N; i++) {
        if (isSafe(k, i)) {
            x[k] = i;
            if (k == N) {
                for (int row = 0; row < N; row++) {
                    for (int col = 0; col < N; col++) {
                        board[row][col] = 0;
                    }
                }
                for (int row = 1; row <= N; row++) {
                    board[row - 1][x[row] - 1] = 1;
                }
                return true;
            } else {
                if (NQueens(k + 1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (NQueens(1)) {
        printf("Solution found for 8 queens is :\n");
        printBoard();
    } else {
        printf("No solution exists for %d-Queens\n", N);
    }
    return 0;
}
