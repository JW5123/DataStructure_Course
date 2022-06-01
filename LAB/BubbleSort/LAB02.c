//BubbleSort
#include <stdio.h>
#define SIZE 5
void BubbleSort(int arr[]){
	for(int i = 1; i < SIZE; i++){
		for(int j = 0; j < (SIZE - i); j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main(){
	int arr[SIZE];
	int inp;
	for(int i = 0; i < SIZE; i++){
		scanf("%d", &inp);
		arr[i] = inp;
	}
	printf("排序前:");
	for(int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	BubbleSort(arr);
    printf("排序後:");
	for(int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}



/*
void BubbleSort(int arr[] , int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[i]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
*/

/*
void BubbleSort(int arr[]){
	for(int i = 1; i < SIZE; i++){
		for(int j = 0; j < (SIZE - i); j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
*/