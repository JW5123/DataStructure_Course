#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_RECORD 100

typedef struct {
    int priority;
    char who[20];
    char event[20];
    char date[20];
    char location[20];
} Record;

void swap(Record *a, Record *b){
    Record temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Record element[], int size, int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if(left < size && element[left].priority > element[largest].priority){
        largest = left;
    }

    if(right < size && element[right].priority > element[largest].priority){
        largest = right;
    }

    if(largest != index){
        swap(&element[index], &element[largest]);
        heapify(element, size, largest);
    }
}

void buildMaxHeap(Record element[], int size){
    for(int i = size / 2 - 1; i >= 0; i--){
        heapify(element, size, i);
    }
}

void InputRecord(Record element[], int* count){


    if(*count < MAX_RECORD){

        Record newData;

        scanf("%d", &newData.priority);
        scanf(" %[^\n]s", newData.who);
        scanf(" %[^\n]s", newData.event);
        scanf(" %[^\n]s", newData.date);
        scanf(" %[^\n]s", newData.location);

        for(int i = 0; i < *count; i++){
            if(element[i].priority == newData.priority){
                printf("KEY EXIST:");
                for(int j = 0; j < *count; j++){
                    printf(" %d", element[j].priority);
                }
                printf("\n");

                printf("New Key:\n");
                scanf("%d", &newData.priority);
            }
        }

        element[*count] = newData;
        (*count)++;
        printf("OK\n");
    } else {
        printf("Record are full\n");
    }

}

void DisplayRecord(Record element[], int count, int* heapBuilt){

    if(*heapBuilt == 1){
        printf("No Data\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", element[i].priority);
        printf("%s, %s, %s, %s\n", element[i].who, element[i].event, element[i].date, element[i].location);
    }
}

void CreateHeap(Record element[], int count, int* heapBuilt){

    if(*heapBuilt == 0){
        buildMaxHeap(element, count);
        *heapBuilt = 1;
    } else {
        printf("No Data\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        printf("%d ", element[i].priority);
    }
    if (count > 0) {
        printf("%d\n", element[count - 1].priority);
    }

    for(int i = count - 1; i >= 0; i--){
        printf("%d\n%s, %s, %s, %s\n", element[0].priority, element[0].who, element[0].event, element[0].date, element[0].location);
        swap(&element[0], &element[i]);
        heapify(element, i, 0);
    }
}

void Quit(){
    printf("quit\n");
    exit(0);
}

int main(){

    Record element[MAX_RECORD];

    int count = 0;
    int option;
    int heapBuilt = 0;

    while(1){
        scanf("%d", &option);
        switch(option){
            case 1:
                InputRecord(element, &count);
                break;
            case 2:
                DisplayRecord(element, count, &heapBuilt);
                break;
            case 3:
                CreateHeap(element, count, &heapBuilt);
                break;
            case 0:
                Quit();
                break;
            default:
                printf("ERROR\n");
                break;
        }
    }

    return 0;
}