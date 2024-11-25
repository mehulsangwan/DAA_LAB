#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    double r1 = (double)item1->value / item1->weight;
    double r2 = (double)item2->value / item2->weight;
    return r2 - r1 > 0 ? 1 : -1;
}

void greedyKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    int totalValue = 0;

    printf("\nGreedy Approach:\n");
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Selected item: weight = %d, value = %d\n", items[i].weight, items[i].value);
        }
    }

    printf("Total value (Greedy): %d\n", totalValue);
}

void dynamicKnapsack(Item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = dp[i - 1][w] > (dp[i - 1][w - items[i - 1].weight] + items[i - 1].value)
                               ? dp[i - 1][w]
                               : dp[i - 1][w - items[i - 1].weight] + items[i - 1].value;
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nDynamic Programming Approach:\n");
    printf("Total value (Dynamic): %d\n", dp[n][capacity]);

    printf("Selected items:\n");
    int w = capacity;
    for (int i = n; i > 0 && dp[i][w] != 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item: weight = %d, value = %d\n", items[i - 1].weight, items[i - 1].value);
            w -= items[i - 1].weight;
        }
    }
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (weight value): ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    greedyKnapsack(items, n, capacity);
    dynamicKnapsack(items, n, capacity);

    return 0;
}
