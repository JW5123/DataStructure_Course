#include <stdio.h>
#define SIZE 5

int search(int arr[], int target, int size){
    int i;
    for(i = 0; i < size; i++){
        if(*(arr + i) == target){
            return i + 1;
        }
    }
    return -1;
}
int main(){

    int arr[SIZE];
    int i, target, element, *ptr;
    ptr = arr;
    printf("=======  循序搜尋法  =======\n"); 
    printf("----  請連續輸入五個數值 ----\n"); 
    printf("\n");
    for(i = 0; i < SIZE; i++){
        printf("請輸入第%d個值 : ", i + 1);
        scanf("%d", ptr + i);
    }
    printf("\n");
    printf("請輸入搜尋的數值 : ");
    scanf("%d", &target);
    element = search(arr, target, SIZE);
    printf("========================\n");
    if(element != -1){
        printf("%d 是第 %d 個數字! \n", target, element);
    }
    else{
        printf("沒有這個數字 -> %d\n", target);
    }
    return 0;
}