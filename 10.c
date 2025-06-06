#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

int main() {
    FILE *fp;
    fp = fopen("sorting_times.csv", "w");
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
        quickSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        printf("Time taken to sort %d elements: %.2f ms\n", n, cpu_time_used);
        fprintf(fp, "%d,%.2f\n", n, cpu_time_used);
    }

    fclose(fp);
    printf("Data saved to sorting_times.csv\n");

    return 0;
}
