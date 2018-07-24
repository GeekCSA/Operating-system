#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>

void sort(int* arr, int k){

	

}

int main(){

    int arr[]={2,3,1,5,6,4,44,43,34,12};
	printf("The original Array is: \n");
	for(int i = 0; i < 10; ++i){
		printf("%d ",arr[i]);
	}

	sort(arr,10);

	printf("\nThe new Array is: \n");
	for(int i = 0; i < 10; ++i){
		printf("%d ",arr[i]);
	}
	return 0;
}
