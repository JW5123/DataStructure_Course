#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 50

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

int main(){

    char infix[MAX] = {'\0'};
    char postfix[MAX] = {'\0'};

    while(1){
        scanf("%s", infix);
        
        if(infix[0] == '0'){
            printf("quit\n");
            break;
        }
        if(!isInputValid(infix)){
            printf("ERROR\n");
        } else {
            inToPostfix(infix, postfix);
            printf("Postfix expression:");
            for(int i = 0; postfix[i] != '\0'; i++){
                printf("%c", postfix[i]);
            }
            printf("\n");
        }
        for (int i = 0; i < MAX; i++) {
            postfix[i] = '\0';
        }
    }

    return 0;
}