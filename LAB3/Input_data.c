#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_RECORD 10

typedef struct {
    int series;
    char name[20];
    char event[20];
    char date[15];
    char location[20];
} Record;

int menu() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void DisplayRecord(Record AppBook[], int count) {
    printf("Not yet\n");
}

void EnterRecord(Record AppBook[], int* count) {
    if (*count < MAX_RECORD) {
        printf("Input\n");
        Record newData;

        scanf("%s", newData.name);
        scanf("%s", newData.event);
        scanf("%s", newData.date);
        scanf("%s", newData.location);

        bool isDuplicate = false;
        for (int i = 0; i < *count; i++) {
            if (strcmp(AppBook[i].name, newData.name) == 0 &&
                strcmp(AppBook[i].event, newData.event) == 0 &&
                strcmp(AppBook[i].date, newData.date) == 0 &&
                strcmp(AppBook[i].location, newData.location) == 0) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate) {
            printf("Existed\n");
        } else {
            newData.series = *count + 1;
            AppBook[*count] = newData;
            (*count)++;
            printf("%d %s %s %s %s\n", newData.series, newData.name, newData.event, newData.date, newData.location);
        }
    } else {
        printf("Full\n");
    }
}

void SortingRecord(Record AppBook[], int count) {
    printf("Not yet\n");
}

void DeleteRecord(Record AppBook[], int *count) {
    printf("Not yet\n");
}

void Search(Record AppBook[], int count) {
    printf("Not yet\n");
}

void Quit() {
    printf("Quit\n");
    exit(0);
}

int main() {

    Record AppBook[MAX_RECORD];
    int count = 0;
    int choice;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1: 
                EnterRecord(AppBook, &count);
                break;
            case 2: 
                DisplayRecord(AppBook, count);
                break;
            case 3: 
                SortingRecord(AppBook, count);
                break;
            case 4:
                Search(AppBook, count);
                break;
            case 9: 
                Quit();
                break;
            default: 
                printf("ERROR\n");
        }
    }
    return 0;
}