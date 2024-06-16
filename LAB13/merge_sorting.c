#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_MERGED_SIZE 500

void mergeArrays(int arr1[], int arr2[], int len1, int len2, int merge_arr[]) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j])
            merge_arr[k++] = arr1[i++];
        else
            merge_arr[k++] = arr2[j++];
    }
    while (i < len1)
        merge_arr[k++] = arr1[i++];
    while (j < len2)
        merge_arr[k++] = arr2[j++];
}

void printSegments(char *seg_arr[], int num_seg) {
    for (int i = 0; i < num_seg; i++) {
        printf("%s", seg_arr[i]);
        if (i < num_seg - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

char* merge_format(char *segment1, char *segment2) {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int len1 = 0, len2 = 0;

    char *token = strtok(segment1, " ");
    while (token != NULL) {
        arr1[len1++] = atoi(token);
        token = strtok(NULL, " ");
    }

    if (segment2 != NULL) {
        token = strtok(segment2, " ");
        while (token != NULL) {
            arr2[len2++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    int merge_arr[MAX_MERGED_SIZE];
    mergeArrays(arr1, arr2, len1, len2, merge_arr);

    char *mergedStr = (char *)malloc(MAX_MERGED_SIZE * sizeof(char));
    char buffer[10];
    mergedStr[0] = '\0';
    for (int j = 0; j < len1 + len2; j++) {
        sprintf(buffer, "%d ", merge_arr[j]);
        strcat(mergedStr, buffer);
    }
    mergedStr[strlen(mergedStr) - 1] = '\0';

    return mergedStr;
}

int main() {
    char input[MAX_SIZE];

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            printf("quit\n");
            break;
        }

        char *list[MAX_SIZE];
        int num_seg = 0;

        char *token = strtok(input, ",");
        while (token != NULL) {
            list[num_seg++] = token;
            token = strtok(NULL, ",");
        }

        while (num_seg > 1) {
            int count = 0;

            for (int i = 0; i < num_seg; i += 2) {
                if (i + 1 < num_seg) {
                    list[count++] = merge_format(list[i], list[i + 1]);
                } else {
                    list[count++] = merge_format(list[i], NULL);
                }
            }

            num_seg = count;
            printSegments(list, num_seg);
        }

        if (num_seg == 1) {
            printf("DONE\n");
        }
    }

    return 0;
}