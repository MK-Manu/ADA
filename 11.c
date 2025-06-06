#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void generateRandomArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

int main() {
    FILE *fp = fopen("sorting_times.csv", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "n,Time taken (ms)\n");

    srand(time(NULL));

    int max_n = 10000;
    int min = 1;
    int max = 10000;
    clock_t start, end;
    double cpu_time_used;

    for (int n = 5000; n <= max_n; n += 500) {
        int arr[n];
        generateRandomArray(arr, n, min, max);
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        printf("Time taken to sort %d elements: %.2f ms\n", n, cpu_time_used);
        fprintf(fp, "%d,%.2f\n", n, cpu_time_used);
    }

    fclose(fp);
    printf("Data saved to sorting_times.csv\n");

    return 0;
}
