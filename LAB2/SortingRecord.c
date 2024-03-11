#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORD 10

typedef struct {
    char name[50];
    char event[50];
    char date[11];
    char location[50];
} Record;


int menu() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void EnterRecord(Record AppBook[], int* count) {
    printf("Input\n");
    if (*count < MAX_RECORD) {
        scanf("%s", AppBook[*count].name);
        scanf("%s", AppBook[*count].event);
        scanf("%s", AppBook[*count].date);
        scanf("%s", AppBook[*count].location);
        (*count)++;
        printf("OK\n");
    } else {
        printf("Maximum records reached!\n");
    }
}

void DisplayRecords(Record AppBook[], int count) {
    printf("Display\n");
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            printf("%s %s %s %s\n", AppBook[i].name, AppBook[i].event, AppBook[i].date, AppBook[i].location);
        }
    } else {
        printf("No Data\n");
    }
}

void SortingRecord(Record AppBook[], int count) {
    printf("Sorting\n");
    if (count > 1) {
        for (int i = 0; i < count - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < count; j++) {
                int year1, month1, day1;
                sscanf(AppBook[j].date, "%d/%d/%d", &year1, &month1, &day1);

                int year2, month2, day2;
                sscanf(AppBook[minIndex].date, "%d/%d/%d", &year2, &month2, &day2);

                if (year1 < year2 || (year1 == year2 && (month1 < month2 || (month1 == month2 && day1 < day2)))) {
                    minIndex = j;
                }
            }
            Record temp = AppBook[i];
            AppBook[i] = AppBook[minIndex];
            AppBook[minIndex] = temp;
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%s %s %s %s\n", AppBook[i].name, AppBook[i].event, AppBook[i].date, AppBook[i].location);
    }
}

void Delete(Record AppBook[], int* count) {
    printf("Delete\n");
}

void Search(Record AppBook[], int count) {
    printf("Search\n");
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
                DisplayRecords(AppBook, count);
                break;
            case 3: 
                SortingRecord(AppBook, count);
                break;
            case 4: 
                Delete(AppBook, &count);
                break;
            case 5: 
                Search(AppBook, count);
                break;
            case 6: 
                Quit();
                break;
            default: 
                printf("ERROR\n");
        }
    }
    return 0;
}
