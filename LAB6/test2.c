#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // 包含 ctype.h 头文件以使用 isalpha 函数

char* expression(char exp[]) {
    char variableNames[10]; // 存储变量名
    int variableValues[10]; // 存储变量值
    int variableCount = 0;

    // 输出原始表达式
    printf("原始表达式: %s\n", exp);

    // 提示用户输入变量值并保存
    for (int i = 0; i < strlen(exp); ++i) {
        if (isalpha(exp[i])) { // 检查是否为字母
            char var = exp[i];
            int found = 0;

            // 检查变量名是否已经存在，如果存在则直接跳过
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

    // 替换表达式中的变量为具体值
    for (int i = 0; i < strlen(exp); ++i) {
        if (isalpha(exp[i])) {
            for (int j = 0; j < variableCount; ++j) {
                if (exp[i] == variableNames[j]) {
                    exp[i] = variableValues[j] + '0'; // 将变量替换为具体值
                    break;
                }
            }
        }
    }

    // 输出替换后的表达式
    printf("替换后的表达式: %s\n", exp);

    return exp;
}


int main() {
    char exp[100];
    printf("請輸入表達式：\n");
    scanf("%s", exp);

    char* result = expression(exp); // 调用 expression 函数
    printf("結果: %s\n", result);
    

    return 0;
}
