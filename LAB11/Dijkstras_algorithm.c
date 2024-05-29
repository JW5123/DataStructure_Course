#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_CITIES 100

int graph[MAX_CITIES][MAX_CITIES];
int minCost[MAX_CITIES][MAX_CITIES];

void initializeGraph(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
            minCost[i][j] = INT_MAX;
        }
    }
}

void Dijkstra(int from, int to, int stops, int n) {
    minCost[from][0] = 0;

    for (int i = 1; i <= stops + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (graph[j][k] != INT_MAX && minCost[j][i - 1] != INT_MAX) {
                    if (minCost[k][i] > minCost[j][i - 1] + graph[j][k]) {
                        minCost[k][i] = minCost[j][i - 1] + graph[j][k];
                    }
                }
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i <= stops + 1; ++i) {
        if (minCost[to][i] < result) {
            result = minCost[to][i];
        }
    }

    if (result == INT_MAX) {
        printf("NO\n");
    } else {
        printf("%d\n", result);
    }
}

int vertexes, edges;

void buildGraph(){
    scanf("%d %d", &vertexes, &edges);
    initializeGraph(vertexes);
    for (int i = 0; i < edges; ++i) {
        int j, k, cost;
        scanf("%d %d %d", &j, &k, &cost);
        graph[j - 1][k - 1] = cost;
    }
    printf("OK\n");
}

void findCheapestPrice(){
    int from, to, stops;
    scanf("%d %d %d", &from, &to, &stops);
    for (int i = 0; i < vertexes; ++i) {
        for (int j = 0; j <= stops + 1; ++j) {
            minCost[i][j] = INT_MAX;
        }
    }
    Dijkstra(from - 1, to - 1, stops, vertexes);
}

void quit(){
    printf("quit\n");
    exit(0);
}

int main() {
    
    int option;
    while (1) {
        scanf("%d", &option);
        switch(option){
            case 1:
                buildGraph();
                break;
            case 2:
                findCheapestPrice();
                break;
            case 0:
                quit();
                break;
            default:
                break;
        }
    }
    return 0;
}
