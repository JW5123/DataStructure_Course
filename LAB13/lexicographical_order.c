#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    int result = strcmp(wordA->word, wordB->word);
    if (result == 0)
        return wordB->count - wordA->count;
    return result;
}

void processInput(char *input) {
    char buffer[MAX_LENGTH];
    char *words[MAX_WORDS];
    int wordCount = 0;
    int n;

    char *token = strrchr(input, ',');
    if (token == NULL) {
        n = -1;
    } else {
        n = atoi(token + 1);
        *token = '\0';
    }

    char *ptr = input;
    while (sscanf(ptr, "%s", buffer) == 1) {
        words[wordCount++] = strdup(buffer);
        ptr += strlen(buffer) + 1;
    }

    WordCount wordCounts[MAX_WORDS] = {0};
    int uniqueCount = 0;

    for (int i = 0; i < wordCount; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(words[i], wordCounts[j].word) == 0) {
                wordCounts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordCounts[uniqueCount].word, words[i]);
            wordCounts[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    qsort(wordCounts, uniqueCount, sizeof(WordCount), compare);

    int printedCount = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (wordCounts[i].count > 1) {
            if (printedCount > 0)
                printf(" ");
            printf("%s", wordCounts[i].word);
            printedCount++;
            if (n == printedCount)
                break;
        }
    }
    printf("\n");

    for (int i = 0; i < wordCount; i++)
        free(words[i]);
}

int main() {
    char input[1000];
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) {
            printf("quit\n");
            break;
        }
        processInput(input);
    }
    return 0;
}