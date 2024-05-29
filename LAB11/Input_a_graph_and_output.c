#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define min(a, b) (a < b ? a : b)

typedef struct {
    int deg;
    int adj[MAX];
} Node;

Node graph[MAX];
char ART[MAX], val[MAX];
int id;
int nodes = 0;

void addEdge(int x, int y) {
    graph[x].adj[graph[x].deg++] = y;
    graph[y].adj[graph[y].deg++] = x;
}

void clearEdge() {
    memset(graph, 0, sizeof(graph));
    nodes = 0;
}

int DFS(int x, int root) {
    int y, m, res, child = 0;

    res = val[x] = ++id;
    for (int i = 0; i < graph[x].deg; i++) {
        y = graph[x].adj[i];
        if (!val[y]) {
            if (root && ++child > 1)
                ART[x] = 1;
            m = DFS(y, 0);
            res = min(res, m);
            if (m >= val[x] && !root) {
                ART[x] = 1;
            }
        } else {
            res = min(val[y], res);
        }
    }
    return res;
}

void articulate() {
    memset(ART, 0, sizeof(ART));
    memset(val, 0, sizeof(val));
    for (int i = 0; i < nodes; i++) {
        if (!val[i])
            DFS(i, 1);
    }
}

int main() {

    int i, x, y, found;
    char input[10];

    while(1){
        while (scanf("%s", input) != EOF) {
            if (strcmp(input, "e") == 0){
                printf("quit\n");
                return 0;
            }
            else {
                x = atoi(input);
                scanf("%d", &y);
                if (x == -1 && y == -1)
                    break;
                addEdge(x, y);
                if (x >= nodes)
                    nodes = x + 1;
                if (y >= nodes)
                    nodes = y + 1;
            }
        }

        articulate();

        printf("OK\n");
        for (found = i = 0; i < nodes; i++) {
            if (ART[i]) {
                if(found)
                    printf(" ");
                printf("%d", i);
                found = 1;
            }
        }
        if (!found) {
            printf("NO\n");
        } else {
            printf("\n");
        }
        clearEdge();
    }

    return 0;
}
