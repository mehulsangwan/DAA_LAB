#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define INF INT_MAX
#define V 5
#define E 8

typedef struct {
    int src, dest, weight;
} Edge;

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < V; i++)
            if (!visited[i] && dist[i] < min) min = dist[i], u = i;
        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
}

void bellmanFord(Edge edges[E], int src) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
        for (int j = 0; j < E; j++)
            if (dist[edges[j].src] != INF &&
                dist[edges[j].src] + edges[j].weight < dist[edges[j].dest])
                dist[edges[j].dest] =
                    dist[edges[j].src] + edges[j].weight;
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 2},
        {0, 0, 7, 0, 9},
        {0, 0, 2, 9, 0}};
    Edge edges[E] = {{0, 1, 4}, {1, 2, 8}, {2, 3, 7},
                     {2, 4, 2}, {3, 4, 9}, {1, 0, 4},
                     {2, 1, 8}, {3, 2, 7}};

    clock_t start, end;

    start = clock();
    dijkstra(graph, 0);
    end = clock();
    printf("Dijkstra Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    bellmanFord(edges, 0);
    end = clock();
    printf("Bellman-Ford Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
