#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // 包含 ctype.h 头文件以使用 isalpha 函数
#include <stdbool.h>
#include <math.h> // 包含 math.h 头文件以使用 pow 函数

#define MAX_VARS 10

bool isInputValid(char* infix){
    int count = 0;
    for(int i = 0; infix[i] != '\0'; i++){
        if(infix[i] == '('){
            count++;
        } else if(infix[i] == ')'){
            count--;
            if(count < 0)
                return false;
        }
    }
    return count == 0;
}

int priority(char opt){
    switch(opt){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void inToPostfix(char* infix, char* postfix){
    char stack[MAX_VARS] = {'\0'};
    int i, j, top = 0;
    for(i = 0, j = 0; infix[i] != '\0'; i++){
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else {
            switch(infix[i]){
                case '(':
                    stack[++top] = infix[i];
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(priority(stack[top]) >= priority(infix[i])){
                        postfix[j++] = stack[top--];
                    }
                    stack[++top] = infix[i];
                    break;
                case ')':
                    while(stack[top] != '('){
                        postfix[j++] = stack[top--];
                    }
                    top--;
                    break;
                default:
                    postfix[j++] = infix[i];
            }
        }
    }
    while(top >= 0){
        postfix[j++] = stack[top--];
    }
}

float evaluateExpression(char exp[]) {
    float stack[MAX_VARS];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            stack[++top] = exp[i] - '0'; // 将字符转换为数字入栈
        } else {
            float operand2 = stack[top--];
            float operand1 = stack[top--];
            switch (exp[i]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                case '^':
                    stack[++top] = pow(operand1, operand2);
                    break;
            }
        }
    }
    return stack[top]; // 返回栈顶元素，即为表达式的值
}

char* expression(char exp[]) {
    char variableNames[MAX_VARS]; // 存储变量名
    int variableValues[MAX_VARS]; // 存储变量值
    int variableCount = 0;

    // 提示用户输入变量值并保存
    for (int i = 0; exp[i] != '\0'; ++i) {
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
    for (int i = 0; exp[i] != '\0'; ++i) {
        if (isalpha(exp[i])) {
            for (int j = 0; j < variableCount; ++j) {
                if (exp[i] == variableNames[j]) {
                    exp[i] = variableValues[j] + '0'; // 将变量替换为具体值
                    break;
                }
            }
        }
    }

    // 计算替换后的表达式的值
    float result = evaluateExpression(exp);

    // 将结果格式化为小数点后一位
    sprintf(exp, "%.1f", result);

    return exp;
}

int main() {
    char exp[MAX_VARS];
    printf("請輸入表達式：\n");
    scanf("%s", exp);

    char result[MAX_VARS];
    expression(exp); // 调用 expression 函数
    printf("結果: %s\n", exp);

    return 0;
}
