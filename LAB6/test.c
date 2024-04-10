#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* expression(char exp[]) {
    char variableNames[10];
    int variableValues[10];
    int variableCount = 0;

    for (size_t i = 0; i < strlen(exp); ++i) {
        if (isalpha(exp[i])) {
            char var = exp[i];
            int found = 0;

            for (int j = 0; j < variableCount; j++) {
                if (variableNames[j] == var) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("請輸入變量 %c 的值：", var);
                scanf("%d", &variableValues[variableCount]);
                variableNames[variableCount] = var;
                variableCount++;
            }
        }
    }

    for (size_t i = 0; i < strlen(exp); ++i) {
        if (isalpha(exp[i])) {
            for (int j = 0; j < variableCount; ++j) {
                if (exp[i] == variableNames[j]) {
                    exp[i] = variableValues[j] + '0';
                    break;
                }
            }
        }
    }

    // return exp;
}


int main() {
    char exp[100];
    printf("請輸入表達式：\n");
    scanf("%s", exp);

    char* result = expression(exp);
    printf("結果: %s\n", result);
    

    return 0;
}
