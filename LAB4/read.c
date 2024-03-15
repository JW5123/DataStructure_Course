#include <stdio.h>
#include <stdlib.h>
#define MAX_Count 10

typedef struct {
    char series;
    int coef[20]; //係數
    int exp[20];
} POLY;


void readData() {
    char str;
    char s[1];
    scanf("%s", &str);
    sscanf(s, "%c=", &str);
    printf("%s", s);
}

void printEquation(){

}

void add(){

}

void printALL(){

}

void Quit(){
    printf("quit\n");
    exit(0);
}

int main(){
    
    POLY Euq[MAX_Count];

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
                break;
            case 4:
                break;
            case 0:
                Quit();
                break;
            default:
                break;
        }
    }
}

/*



*/