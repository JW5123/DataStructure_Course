#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define PREREQ_MAX 500


bool DFS(int i, int graph[][PREREQ_MAX], int curPrereq[], int *visited) {
    if (visited[i] > 0)
        return true;

    if (visited[i] == 0) {
        visited[i] = 1;
        for (int i = 0; i < curPrereq[i]; i++) {
            if (DFS(graph[i][i], graph, curPrereq, visited)) {
                return true;
            }
        }
        visited[i] = -1;
    }
    return false;
}

bool canFinish(int numJobs, int graph[][PREREQ_MAX], int curPrereq[]) {
    int visited[500] = {0};
    for (int i = 0; i < numJobs; i++) {
        if (DFS(i, graph, curPrereq, visited)) {
            return false;
        }
    }
    return true;
}

int charToIndex(char c) {
    return c - 'a';
}

int main() {

    while (1) {
        int numJobs;
        char input[1000];

        scanf("%d", &numJobs);
        getchar();
        
        if (numJobs == 0) {
            printf("quit\n");
            break;
        }

        int graph[500][PREREQ_MAX] = {0};
        int curPrereq[500] = {0};

        fgets(input, sizeof(input), stdin);

        bool str = isalpha(input[0]);

        char jobChar, prereqChar;
        int job, prereq;

        char *token = strtok(input, ",");
        while (token != NULL) {
            if (str) {
                sscanf(token, " %c %c", &jobChar, &prereqChar);
                int job = charToIndex(jobChar);
                int prereq = charToIndex(prereqChar);
                graph[job][curPrereq[job]++] = prereq;
            } else {
                sscanf(token, " %d %d", &job, &prereq);
                graph[job][curPrereq[job]++] = prereq;
            }
            token = strtok(NULL, ",");
        }

        if (canFinish(numJobs, graph, curPrereq)) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }

    return 0;
}
