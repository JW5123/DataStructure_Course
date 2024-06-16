#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

void countFrequent(int arr[], int n, int k) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int buckets[max + 1];
    for (int i = 0; i <= max; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    int freqArr[max + 1][2];
    for (int i = 0; i <= max; i++) {
        freqArr[i][0] = i;
        freqArr[i][1] = buckets[i];
    }

    qsort(freqArr, max + 1, sizeof(freqArr[0]), cmpfunc);

    int result[k];
    int count = 0;
    for (int i = 0; i <= max && count < k; i++) {
        if (freqArr[i][1] > 0) {
            result[count++] = freqArr[i][0];
        }
    }

    qsort(result, count, sizeof(int), cmpfunc);

    for (int i = 0; i < count; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {

    char input[100];

    while (1) {
        fgets(input, 100, stdin);

        if (input[0] == '0') {
            printf("quit\n");
            break;
        }
        char *token = strtok(input, ",");
        char *numbers = token;
        token = strtok(NULL, ",");
        int k = atoi(token);

        int arr[100];
        int n = 0;

        token = strtok(numbers, " ");
        while (token != NULL) {
            arr[n++] = atoi(token);
            token = strtok(NULL, " ");
        }

        countFrequent(arr, n, k);
    }

    return 0;
}
