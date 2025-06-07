#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define N 8

int x[N];         
int board[N][N];  

bool isSafe(int k, int i) {
    for (int j = 0; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

bool NQueens(int k) {
    for (int i = 0; i < N; i++) {
        if (isSafe(k, i)) {
            x[k] = i;
            if (k == N - 1) {
                for (int row = 0; row < N; row++) {
                    for (int col = 0; col < N; col++) {
                        board[row][col] = 0;
                    }
                }
                for (int row = 0; row < N; row++) {
                    board[row][x[row]] = 1;
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
    if (NQueens(0)) {
        printf("Solution found for %d queens is:\n", N);
        printBoard();
    } else {
        printf("No solution exists for %d-Queens\n", N);
    }
    return 0;
}
