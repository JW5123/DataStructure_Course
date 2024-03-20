#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT 10

typedef struct {
    int coef[20];
    int exp[20];
} POLY;


void eread() {
    
}

void printEquation(){
    printf("Not yet\n");
}

void printALL(){
    printf("Not yet\n");
}

void eadd(){
    printf("Not yet\n");
}

void Quit(){
    printf("quit\n");
    exit(0);
}

int main(){
    
    POLY Euquation[MAX_COUNT];

    int option;

    while(1){
        scanf("%d", &option);
        switch(option) {
            case 1:
                readData();
                break;
            case 2:

                break;
            case 3:
                printALL();
                break;
            case 4:
                break;
            case 0:
                Quit();
                break;
            default:
                printf("ERROR\n");
                break;
        }
    }
}

/*



*/