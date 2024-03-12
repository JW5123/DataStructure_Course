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
    if (count > 0) {
        for (int i = 1; i <= count; i++) {
            printf("%d %s %s %s %s\n",  AppBook[i].series, AppBook[i].name, AppBook[i].event, AppBook[i].date, AppBook[i].location);
        }
    }
}

void SortData(Record AppBook[], int *count) {
    for (int i = 0; i < *count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < *count; j++) {
            if (AppBook[j].series < AppBook[minIndex].series) {
                minIndex = j;
            }
        }
        Record temp = AppBook[i];
        AppBook[i] = AppBook[minIndex];
        AppBook[minIndex] = temp;
    }
}

void EnterRecord(Record AppBook[], int* count, int* num) {
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
            (*count)++;
            (*num)++;
            AppBook[*count] = newData;
            AppBook[*count].series = *num;
            printf("%d %s %s %s %s\n", *num, newData.name, newData.event, newData.date, newData.location);
        }
    } else {
        printf("Full\n");
    }
}

void SortingRecord(Record AppBook[], int count) {
    if (count == 0) {
        printf("No Data\n");
        return;
    }

    printf("Sorting\n");
    char option;
    scanf("%c", &option);

    switch (option) {
        case 'A':
            SortData(AppBook, &count);
            break;
        case 'B':
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
            break;
        default:
            return;
    }

    DisplayRecord(AppBook, count);
}

void DeleteRecord(Record AppBook[], int *count) {

    SortData(AppBook, count);

    if (*count > 0) {

        printf("Delete:");
        for (int i = 1; i <= *count; i++) {
            printf(" %d", AppBook[i].series);
        }
        printf("\n");

        int deleteNum;
        while(scanf("%d", &deleteNum)){

            int foundIndex = 0;
            for (int i = 1; i <= *count; i++) {
                if (AppBook[i].series == deleteNum) {
                    for (int j = i; j <= *count; j++) {
                        AppBook[j] = AppBook[j + 1];
                    }
                    foundIndex = 1;
                    break;
                }
            }

            if (foundIndex != 0) {
                --*count;
                printf("Series:");
                for (int i = 1; i <= *count; i++) {
                    printf(" %d", AppBook[i].series);
                }
                printf("\n");
                break;

            } else {
                printf("No Data\n");
            }
        }
    } else {
        printf("No Data\n");
    }
}

void Search(Record AppBook[], int count) {
    printf("Searching\n");
}

void Quit() {
    printf("Quit\n");
    exit(0);
}

int main() {

    Record AppBook[MAX_RECORD];
    int count = 0, num = 0;
    int choice;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1: 
                EnterRecord(AppBook, &count, &num);
                break;
            case 2:
                DeleteRecord(AppBook, &count);
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
