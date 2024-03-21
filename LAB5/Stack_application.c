#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LEN 100

bool isValid(char *s) {
    char stack[MAX_LEN];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) 
                return false;

            char top_char = stack[top--];
            if ((c == ')' && top_char != '(') || (c == ']' && top_char != '[') || (c == '}' && top_char != '{')) {
                return false;
            }
        }
    }
    return top == -1;
    // if(top == -1)
    //     return true;
    // return false;
}

int main() {
    char input[MAX_LEN];
    while (fgets(input, MAX_LEN, stdin)) {
        if(input[0] == '0'){
            printf("quit\n");
            break;
        }
        printf("%s", isValid(input) ? "True\n" : "False\n");
        // if(isValid(input))
        //     printf("True\n");
        // else
        //     printf("False\n");
    }
    return 0;
}

