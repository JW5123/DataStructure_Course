#include <stdio.h>
#include <stdlib.h>

int *queue;
int size = 0;
int front = 0, tail = 0;

void create_queue(int queueSize){
    queue = (int*)malloc(queueSize * sizeof(int));
    size = queueSize;
    printf("OK\n");
}

void enqueue(int value){
    if(tail == size){
        printf("Queue full\n");
        return;
    }
    queue[tail++] = value;
    printf("OK\n");
}

void dequeue(){
    if(front == tail){
        printf("Queue empty\n");
        return;
    }
    // 此部分是geeksforgeeks的寫法(需釐清)
    int deletValue = queue[front];
    for (int i = 0; i < tail - 1; i++) {
        queue[i] = queue[i + 1];
    }
    tail--;
    printf("%c\n", deletValue);
}

void Quit(){
    printf("quit\n");
    exit(0);
}

int main(){

    int option, queueSize;
    char value;

    while(1){
        scanf("%d", &option);

        switch(option){
            case 1:
                scanf("%d", &queueSize);
                create_queue(queueSize);
                break;
            case 2:
                scanf(" %c", &value);
                enqueue(value);
                break;
            case 3:
                dequeue();
                break;
            case 0:
                Quit();
                break;
            default:
                break;
        }
    }

    return 0;
}