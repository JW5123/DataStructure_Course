#include <stdio.h>
#include <stdlib.h>

int *stack;
int size = 0;
int current = 0;

void create_stack(int stackSize){
    stack = (int*)malloc(stackSize * sizeof(int));
    size = stackSize;
    printf("OK\n");
}

void push_element(int value){
    if(current == size){
        printf("Stack full\n");
        return;
    }
    stack[++current] = value;
    printf("OK\n");
}

void pop_element(){
    if(current == 0){
        printf("Stack empty\n");
        return;
    }
    printf("%c\n", stack[current--]);
}

void Quit(){
    printf("quit\n");
    exit(0);
}

int main(){

    int option, stackSize;
    char value;

    while(1){
        scanf("%d", &option);

        switch(option){
            case 1:
                scanf("%d", &stackSize);
                create_stack(stackSize);
                break;
            case 2:
                scanf(" %c", &value);   // 取整數後跳過空格並讀取字元
                push_element(value);
                break;
            case 3:
                pop_element();
                break;
            case 0:
                Quit();
                break;
            default:
                break;
        }
    }

    return 0;
}