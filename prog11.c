#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int a[MAX], b[MAX];  // Global arrays for sorting

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    // Merge both halves into b[]
    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left half if any
    if (i > mid) {
        while (j <= ub) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    // Copy back from b[] to a[]
    for (int p = lb; p <= ub; p++) {
        a[p] = b[p];
    }
}

void mergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

void generateRandomArray(int a[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (max - min + 1) + min;
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

    int min = 1;
    int max = 10000;
    clock_t start, end;
    double cpu_time_used;

    for (int n = 5000; n <= 10000; n += 500) {
        generateRandomArray(a, n, min, max);

        start = clock();
        mergeSort(a, 0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        printf("Time taken to sort %d elements: %.2f ms\n", n, cpu_time_used);
        fprintf(fp, "%d,%.2f\n", n, cpu_time_used);
    }

    fclose(fp);
    printf("Data saved to sorting_times.csv\n");

    return 0;
}
