#include <stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE];
int current = 0;
int *ptr = stack;
void push(){
    if(current == MAXSIZE){
        printf(" .... 堆疊已滿 ! \n\n");
    }
    else{
        printf("   請輸入第 %d 筆整數 : ", current + 1);
        scanf("%d", ptr + current);
        //*(ptr + current) = inp;
        current++;
    }
    printf("\n\n");
}
void pop(){
    if(current == 0){
        printf(" .... 堆疊已經空了 !\n\n");
    }
    else{
        current--;
        printf("  ... Pop from stack : %d\n\n", *(ptr + current));
        //*(ptr + current) = 0;
    }
}
void printout(){
    printf("目前堆疊內陣列 : ");
    for(int i = current - 1 ; i >= 0; i--){
        printf("  %d", *(ptr + i));
    }
    printf("\n                Top<--Stack-->Bottom\n\n");
}
signed main(){
    int flag = 1;
    int choose;
    while(flag){
        printf(" === Stack Operation === \n");
        printf("   1. Push Operation \n");
        printf("   2. Pop Operation \n");
        printf("   3. Printout Stack \n");
        printf("   0. Quit \n");
        printf(" ======================= \n");
        printf("   請選擇 [0-3] : ");
        scanf("%d", &choose);
        printf("\n\n");
        switch (choose)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            printout();
            break;
        case 0:
            flag = 0;
            break;
        default:
            printf(" === Error input (0-3) !!\n\n");
            break;
        }
    }
}