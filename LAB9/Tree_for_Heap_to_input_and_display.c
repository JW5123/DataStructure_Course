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

void InputRecord(Record element[], int* count){

    scanf("%d", &element[*count].priority);
    scanf(" %[^\n]", element[*count].who);
    scanf(" %[^\n]", element[*count].event);
    scanf(" %[^\n]", element[*count].date);
    scanf(" %[^\n]", element[*count].location);
    
    for(int i = 0; i < *count; i++){
        if(element[i].priority == element[*count].priority){
            printf("KEY EXIST:");
            for(int j = 0; j < *count; j++){
                printf(" %d", element[j].priority);
            }
            printf("\nNew Key:\n");
            scanf("%d", &element[*count].priority);
        }
    }

    (*count)++;
    printf("OK\n");

}

void DisplayRecord(Record element[], int count){
    for (int i = 0; i < count; i++) {
        printf("%d\n", element[i].priority);
        printf("%s, %s, %s, %s\n", element[i].who, element[i].event, element[i].date, element[i].location);
    }
}

void CreateHeap(){
    printf("ERROR\n");
}

void Quit(){
    printf("quit\n");
    exit(0);
}

int main(){

    Record element[MAX_RECORD];

    int count = 0;
    int option;

    while(1){
        scanf("%d", &option);
        switch(option){
            case 1:
                InputRecord(element, &count);
                break;
            case 2:
                DisplayRecord(element, count);
                break;
            case 3:
                CreateHeap();
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