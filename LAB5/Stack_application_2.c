#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LEN 100

bool is_pair(char cur, char tmp) {
    if (cur == ')' && tmp == '(')
        return true;
    else if (cur == '}' && tmp == '{')
        return true;
    else if (cur == ']' && tmp == '[')
        return true;
    return false;
}

bool isValid(char *s) {
    char stack[MAX_LEN];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top >= 0) {
                char tmp = stack[top--];
                if (!is_pair(s[i], tmp))
                    return false;
            } else {
                return false; // top == -1
            }
        }
    }

    return top == -1;
}

int main() {
    char input[MAX_LEN];
    while (fgets(input, MAX_LEN, stdin)) {
        if(input[0] == '0'){
            printf("quit\n");
            break;
        }
        printf("%s", isValid(input) ? "True\n" : "False\n");
    }
    return 0;

    return 0;
}
