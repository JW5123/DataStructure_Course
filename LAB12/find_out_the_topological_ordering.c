#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int job;
    int next;
} Node;

typedef struct {
    int numJobs;
    Node adjList[MAX_SIZE];
    int head[MAX_SIZE];
    int visited[MAX_SIZE];
    int nodeIndex;
} Graph;

Graph createGraph(int numJobs) {
    Graph graph;
    graph.numJobs = numJobs;
    graph.nodeIndex = 0;

    for (int i = 0; i < numJobs; i++) {
        graph.head[i] = -1;
        graph.visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graphPtr, int start, int end) {
    Graph graph = *graphPtr;
    graph.adjList[graph.nodeIndex].job = end;
    graph.adjList[graph.nodeIndex].next = graph.head[start];
    graph.head[start] = graph.nodeIndex;
    graph.nodeIndex++;
    *graphPtr = graph;
}

bool isCyclicUtil(Graph* graph, int job) {
    if (graph->visited[job] == 0) {
        graph->visited[job] = 1;

        for (int i = graph->head[job]; i != -1; i = graph->adjList[i].next) {
            int adjJob = graph->adjList[i].job;
            
            if (!graph->visited[adjJob]) {
                if (isCyclicUtil(graph, adjJob)) {
                    return true;
                }
            } 
            else {
                return true;
            }
        }
    }
    graph->visited[job] = 0;
    return false;
}

void topologicalSortUtil(Graph* graph, int job, int* stack, int* stackIndex) {
    graph->visited[job] = 1;

    for (int i = graph->head[job]; i != -1; i = graph->adjList[i].next) {
        int adjJob = graph->adjList[i].job;
        if (!graph->visited[adjJob]) {
            topologicalSortUtil(graph, adjJob, stack, stackIndex);
        }
    }
    stack[(*stackIndex)++] = job;
}

void topologicalSort(Graph* graph, int* stack, int* stackIndex) {

    for (int i = 0; i < graph->numJobs; i++) {
        if (!graph->visited[i]) {
            topologicalSortUtil(graph, i, stack, stackIndex);
        }
    }
}


void parseInput(char* line, int prereq[][2], int* numPrereq, int* isAlpha) {
    *numPrereq = 0;
    *isAlpha = 0;

    char* token = strtok(line, ",");
    while (token != NULL) {
        char u, v;
        sscanf(token, " %c %c", &u, &v);
        if (isalpha(u) || isalpha(v)) {
            *isAlpha = 1;
        }
        if (*isAlpha) {
            prereq[*numPrereq][0] = u - 'a';
            prereq[*numPrereq][1] = v - 'a';
        } else {
            prereq[*numPrereq][0] = u - '0';
            prereq[*numPrereq][1] = v - '0';
        }
        (*numPrereq)++;
        token = strtok(NULL, ",");
    }
}

bool processInput(int numJobs, char* line, int prereq[][2], int* result, int* isAlpha) {
    int numPrereq;

    parseInput(line, prereq, &numPrereq, isAlpha);

    if (numPrereq > numJobs) {
        return false;
    }

    Graph graph = createGraph(numJobs);

    for (int i = 0; i < numPrereq; i++) {
        addEdge(&graph, prereq[i][1], prereq[i][0]);
    }

    for (int i = 0; i < graph.numJobs; i++) {
        if (isCyclicUtil(&graph, i)) {
            return false;
        }
    }

    int stack[MAX_SIZE];
    int stackIndex = 0;
    for (int i = 0; i < numJobs; i++) {
        graph.visited[i] = 0;
    }

    topologicalSort(&graph, stack, &stackIndex);

    for (int i = 0; i < numJobs; i++) {
        result[i] = stack[numJobs - i - 1];
    }

    return true;
}

int main() {
    int numJobs;
    while (1) {
        scanf("%d", &numJobs);
        if (numJobs == 0) {
            printf("quit\n");
            break;
        }

        char line[MAX_SIZE];
        scanf(" %[^\n]", line);

        int prereq[MAX_SIZE][2];
        int result[MAX_SIZE];
        int isAlpha = 0;

        if (!processInput(numJobs, line, prereq, result, &isAlpha)) {
            printf("false\n");
            continue;
        }

        for (int i = 0; i < numJobs - 1; i++) {
            if (isAlpha) {
                printf("%c ", result[i] + 'a');
            } else {
                printf("%d ", result[i]);
            }
        }
        if (isAlpha) {
            printf("%c", result[numJobs - 1] + 'a');
        } else {
            printf("%d", result[numJobs - 1]);
        }
        printf("\n");
    }

    return 0;
}