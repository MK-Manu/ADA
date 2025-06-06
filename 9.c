#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
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

    for (int n = 1000; n <= max_n; n += 1000) {
        int arr[n];
        generateRandomArray(arr, n, min, max);
        start = clock();
        selectionSort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        printf("Time taken to sort %d elements: %.2f ms\n", n, cpu_time_used);
        fprintf(fp, "%d,%.2f\n", n, cpu_time_used);
    }

    fclose(fp);
    printf("Data saved to sorting_times.csv\n");

    return 0;
}
