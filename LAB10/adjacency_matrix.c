#include <stdio.h>
#define MAX_NODES 100

int main() {
    int adjMatrix[MAX_NODES][MAX_NODES] = {0};
    int x, y, maxNode = 0;

    while (scanf("%d %d", &x, &y) != EOF) {
        if (x == -1 && y == -1)
            break;
        if (x > maxNode) 
            maxNode = x;
        if (y > maxNode) 
            maxNode = y;
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    printf("input:\nmatrix:\n");
    for (int i = 0; i <= maxNode; i++) {
        for (int j = 0; j <= maxNode; j++) {
            printf("%d", adjMatrix[i][j]);
            if(i != maxNode || j != maxNode)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
