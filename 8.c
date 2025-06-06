#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void findSubset(int set[], int n, int sum, int subset[], int subSize, int totalSum, int index) {
    if (totalSum == sum) {
        printf("Subset found: { ");
        for (int i = 0; i < subSize; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }

    if (index >= n || totalSum > sum)
        return;

    subset[subSize] = set[index];
    findSubset(set, n, sum, subset, subSize + 1, totalSum + set[index], index + 1);

    findSubset(set, n, sum, subset, subSize, totalSum, index + 1);
}

int main() {
    int set[] = {12, 4, 5, 6, 7, 2, 3, 8, 9};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 15;
    int subset[MAX_SIZE];
    int subSize = 0;

    printf("Finding subset(s) with sum %d:\n", sum);
    findSubset(set, n, sum, subset, subSize, 0, 0);

    return 0;
}
