#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
    double density;
};

int discreteKnapsack(struct Item items[], int n, int capacity) {
    for (int i = 0; i < n; i++) {
        items[i].density = (double)items[i].value / items[i].weight;
    }
    for (int i = 1; i < n; i++) {
        struct Item temp = items[i];
        int j = i - 1;
        while (j >= 0 && items[j].density < temp.density) {
            items[j + 1] = items[j];
            j--;
        }
        items[j + 1] = temp;
    }
    int totalValue = 0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
    }
    return totalValue;
}

double continuousKnapsack(struct Item items[], int n, int capacity) {
    for (int i = 0; i < n; i++) {
        items[i].density = (double)items[i].value / items[i].weight;
    }
    for (int i = 1; i < n; i++) {
        struct Item temp = items[i];
        int j = i - 1;
        while (j >= 0 && items[j].density < temp.density) {
            items[j + 1] = items[j];
            j--;
        }
        items[j + 1] = temp;
    }
    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += (capacity * items[i].density);
            capacity = 0;
        }
    }
    return totalValue;
}

int main() {
    struct Item discreteItems[] = {{10, 60}, {20, 100}, {30, 120}};
    int n1 = sizeof(discreteItems) / sizeof(discreteItems[0]);
    int discreteCapacity = 50;

    struct Item continuousItems[] = {{10, 60}, {20, 100}, {30, 120}};
    int n2 = sizeof(continuousItems) / sizeof(continuousItems[0]);
    int continuousCapacity = 50;

    printf("Discrete Knapsack Problem:\n");
    int discreteResult = discreteKnapsack(discreteItems, n1, discreteCapacity);
    printf("Maximum value obtained: %d\n\n", discreteResult);

    printf("Continuous Knapsack Problem:\n");
    double continuousResult = continuousKnapsack(continuousItems, n2, continuousCapacity);
    printf("Maximum value obtained: %.2f\n", continuousResult);

    return 0;
}
