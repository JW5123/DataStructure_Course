#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char poly[100];
    char identifier[10];

    fgets(poly, sizeof(poly), stdin);
    sscanf(poly, "%[^=]", identifier);

    int coef[20] = {0}, expo[20] = {0};
    int coef_count = 0, expo_count = 0;

    char *token = strtok(poly, "+-=");
    while (token != NULL) {
        int coef_val = 1;
        int expo_val = 0;
        char *ptr = token;

        if (isdigit(*ptr)) {
            coef_val = atoi(ptr);
            while (isdigit(*ptr)) ptr++;
        } else if (*ptr == '-') {
            coef_val = -1;
            ptr++;
        }

        if (*ptr == 'x') {
            ptr++;
            if (*ptr == '^') {
                ptr++;
                expo_val = atoi(ptr);
            } else {
                expo_val = 1;
            }
        }

        coef[coef_count] = coef_val;
        expo[expo_count] = expo_val;
        coef_count++;
        expo_count++;

        token = strtok(NULL, "+-=");
    }

    printf("%s\n", identifier);
    for (int i = 1; i < coef_count; i++) {
        printf("%d %d\n", coef[i], expo[i]);
    }

    return 0;
}
