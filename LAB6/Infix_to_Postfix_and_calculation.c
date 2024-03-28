#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#define MAX 50

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
    char stack[MAX] = {'\0'};
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

char* expression(char exp[]) {
    char value[10];
    int number[10];
    int count = 0;

    for (size_t i = 0; i < strlen(exp); ++i) {
        if (isalpha(exp[i])) {
            char var = exp[i];
            int found = 0;

            for (int j = 0; j < count; j++) {
                if (value[j] == var) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                scanf("%d", &number[count]);
                value[count] = var;
                count++;
            }
        }
    }

    for (size_t i = 0; i < strlen(exp); ++i) {
        if (isalpha(exp[i])) {
            for (int j = 0; j < count; ++j) {
                if (exp[i] == value[j]) {
                    exp[i] = number[j] + '0';
                    break;
                }
            }
        }
    }

    return exp;
}

double calculate(char op, double a, double b) { 
    switch(op) { 
        case '+': 
            return a + b; 
        case '-': 
            return a - b; 
        case '*': 
            return a * b; 
        case '/': 
            return a / b; 
        case '^': 
            return pow(a, b);
    } 
    return 0;
}

double eval(char* infix) {
    char postfix[MAX]= {'\0'};
    char temp[2] = {'\0'};
    double stack[MAX] = {0.0};
    
    inToPostfix(infix, postfix);

    int top, i;
    for(top = 0, i = 0; postfix[i] != '\0'; i++) {
        switch(postfix[i]) { 
            case '+': 
            case '-': 
            case '*': 
            case '/': 
            case '^':
                stack[top - 1] = calculate(postfix[i], stack[top - 1], stack[top]); 
                top--;
                break;
            default:
                temp[0] = postfix[i];
                stack[++top] = atof(temp);
        }
    }
    
    return stack[top];
}


int main(){

    char infix[MAX] = {'\0'};
    char postfix[MAX] = {'\0'};

    while(scanf("%s", infix) != EOF){
        if(infix[0] == '0'){
            printf("quit\n");
            break;
        } else {
            inToPostfix(infix, postfix);
            char* result = expression(infix);
            printf("Postfix expression:");
            for(int i = 0; postfix[i] != '\0'; i++){
                printf("%c", postfix[i]);
            }
            printf("\n");
            printf("eval:");
            printf("%.1f\n", eval(result));
        }
    }

    return 0;
}