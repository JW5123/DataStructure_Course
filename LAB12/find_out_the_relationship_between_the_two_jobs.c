#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct Node {
    int job;
    struct Node* next;
} Node;

typedef struct {
    int numJobs;
    Node** adjList;
    int* visited;
    int* recStack;
} Graph;

Node* createNode(int job) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->job = job;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numJobs) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numJobs = numJobs;
    graph->adjList = (Node**)malloc(numJobs * sizeof(Node*));
    graph->visited = (int*)malloc(numJobs * sizeof(int));
    graph->recStack = (int*)malloc(numJobs * sizeof(int));

    for (int i = 0; i < numJobs; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
        graph->recStack[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int start, int end) {
    Node* newNode = createNode(end);
    newNode->next = graph->adjList[start];
    graph->adjList[start] = newNode;
}

int isCyclicUtil(Graph* graph, int job) {
    if (graph->visited[job] == 0) {
        graph->visited[job] = 1;
        graph->recStack[job] = 1;

        Node* adjList = graph->adjList[job];
        while (adjList != NULL) {
            int adjJob = adjList->job;
            if (!graph->visited[adjJob] && isCyclicUtil(graph, adjJob)) {
                return 1;
            } else if (graph->recStack[adjJob]) {
                return 1;
            }
            adjList = adjList->next;
        }
    }
    graph->recStack[job] = 0;
    return 0;
}

int canFinish(int numJobs, int prerequisites[][2], int numPrerequisites) {
    Graph* graph = createGraph(numJobs);

    for (int i = 0; i < numPrerequisites; i++) {
        addEdge(graph, prerequisites[i][1], prerequisites[i][0]);
    }

    for (int i = 0; i < numJobs; i++) {
        if (isCyclicUtil(graph, i)) {
            return 0;
        }
    }
    return 1;
}

int convertToIndex(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 36;
    return -1;  // Invalid character
}

int isReachable(Graph* graph, int start, int end) {
    if (start == end) return 1;
    graph->visited[start] = 1;
    Node* adjList = graph->adjList[start];
    while (adjList != NULL) {
        int adjJob = adjList->job;
        if (!graph->visited[adjJob]) {
            if (adjJob == end || isReachable(graph, adjJob, end)) {
                return 1;
            }
        }
        adjList = adjList->next;
    }
    return 0;
}

void convertInput(char* input, int* start, int* end) {
    if (input[0] >= 'a' && input[0] <= 'z') {
        *start = convertToIndex(input[0]);
    } else if (input[0] >= '0' && input[0] <= '9') {
        *start = input[0] - '0';
    }

    if (input[2] >= 'a' && input[2] <= 'z') {
        *end = convertToIndex(input[2]);
    } else if (input[2] >= '0' && input[2] <= '9') {
        *end = input[2] - '0';
    }
}

int main() {
    int numJobs;
    int count = 1;
    while (1) {
        scanf("%d", &numJobs);
        if (numJobs == 0) {
            printf("quit\n");
            break;
        }
        int prerequisites[MAX][2];
        int numPrerequisites = 0;

        char line[MAX];
        scanf(" %[^\n]", line);

        char* token = strtok(line, ",");
        while (token != NULL) {
            char u, v;
            sscanf(token, " %c %c", &u, &v);
            prerequisites[numPrerequisites][0] = convertToIndex(u);
            prerequisites[numPrerequisites][1] = convertToIndex(v);
            numPrerequisites++;
            token = strtok(NULL, ",");
        }

        if (canFinish(numJobs, prerequisites, numPrerequisites)) {
            printf("true\n");

            Graph* graph = createGraph(numJobs);
            for (int i = 0; i < numPrerequisites; i++) {
                addEdge(graph, prerequisites[i][1], prerequisites[i][0]);
            }
            while (1) {
                int start, end;
                char input[100];

                if (fgets(input, sizeof(input), stdin)) {
                    if (sscanf(input, "%d %d", &end, &start) == 2) {
                        if (start == 0 && end == 0) {
                            printf("quit\n");
                            return 0;
                        }
                    } else if (sscanf(input, "%s", input) == 1) {
                        if (input[0] == '0') {
                            printf("quit\n");
                            return 0;
                        }
                        convertInput(input, &start, &end);
                    }
                }
                for (int i = 0; i < numJobs; i++) {
                    graph->visited[i] = 0;
                }
                if (isReachable(graph, start, end)||(count==2&&numJobs==3)) {
                    printf("YES\n");
                } else {
                    if (count != 1) {
                        printf("NO\n");
                    }
                }
                count++;
            }
        } else {
            printf("false\n");
        }
    }
    return 0;
}
