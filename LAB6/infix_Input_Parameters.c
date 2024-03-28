#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

void expression(char exp[]){
    char value[10]; 
    int number[10];
    int count = 0;

    for (int i = 0; i < strlen(exp); ++i) {
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
    printf("%s\n", exp);
    for (int i = 0; i < count; ++i) {
        printf("%c=%d\n", value[i], number[i]);
    }
}

int main() {
    char exp[100];

    while(scanf("%s", exp) != EOF){
        if(exp[0] == '0'){
            printf("quit\n");
            break;
        }
        expression(exp);
    }

    return 0;
}
