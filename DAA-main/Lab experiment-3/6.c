#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int weight;
    int value;
} Item;

typedef struct
{
    int level;
    int profit;
    int weight;
    float bound;
} Node;

int compare(const void *a, const void *b)
{
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    double r1 = (double)item1->value / item1->weight;
    double r2 = (double)item2->value / item2->weight;
    return r2 - r1 > 0 ? 1 : -1;
}

void backtrackingKnapsack(int i, int n, int W, int currentWeight, int currentProfit, int *maxProfit, Item items[])
{
    if (currentWeight <= W && currentProfit > *maxProfit)
        *maxProfit = currentProfit;
    if (i == n || currentWeight > W)
        return;
    backtrackingKnapsack(i + 1, n, W, currentWeight + items[i].weight, currentProfit + items[i].value, maxProfit, items);
    backtrackingKnapsack(i + 1, n, W, currentWeight, currentProfit, maxProfit, items);
}

float bound(Node u, int n, int W, Item items[])
{
    if (u.weight >= W)
        return 0;
    float profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;
    while (j < n && totalWeight + items[j].weight <= W)
    {
        totalWeight += items[j].weight;
        profitBound += items[j].value;
        j++;
    }
    if (j < n)
        profitBound += (W - totalWeight) * ((float)items[j].value / items[j].weight);
    return profitBound;
}

void branchAndBoundKnapsack(int n, int W, Item items[])
{
    Node u, v;
    int maxProfit = 0;
    Node queue[1000];
    int front = 0, rear = 0;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u, n, W, items);
    queue[rear++] = u;
    while (front != rear)
    {
        u = queue[front++];
        if (u.level == -1 || u.bound > maxProfit)
        {
            v.level = u.level + 1;
            v.weight = u.weight + items[v.level].weight;
            v.profit = u.profit + items[v.level].value;
            if (v.weight <= W && v.profit > maxProfit)
                maxProfit = v.profit;
            v.bound = bound(v, n, W, items);
            if (v.bound > maxProfit)
                queue[rear++] = v;
            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = bound(v, n, W, items);
            if (v.bound > maxProfit)
                queue[rear++] = v;
        }
    }
    printf("Total value (Branch & Bound): %d\n", maxProfit);
}

void dynamicKnapsack(int n, int W, Item items[])
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
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
    printf("Total value (Dynamic): %d\n", dp[n][W]);
}

int main()
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d (weight value): ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    qsort(items, n, sizeof(Item), compare);
    int maxProfit = 0;
    backtrackingKnapsack(0, n, W, 0, 0, &maxProfit, items);
    printf("Total value (Backtracking): %d\n", maxProfit);
    branchAndBoundKnapsack(n, W, items);
    dynamicKnapsack(n, W, items);
    return 0;
}
