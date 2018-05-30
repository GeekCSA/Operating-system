#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Args{
    int* arr;
    int* countOfSwap;
    int id;
    int size;
    pthread_barrier_t* barrier;
    sem_t* sem;
}Args;
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void* run (void* args){
    Args* myargs=(Args*)args;
    int id=myargs->id;
    do{
            pthread_barrier_wait(myargs->barrier);
            *(myargs->countOfSwap)=0;

            pthread_barrier_wait(myargs->barrier);
            //aizogi
            if(id!=myargs->size-1 && myargs->arr[id]>myargs->arr[id+1]){   
                sem_wait(myargs->sem);        
                *(myargs->countOfSwap)+=1;
                swap(&myargs->arr[id],&myargs->arr[id+1]);
                sem_post(myargs->sem); 

            }
            pthread_barrier_wait(myargs->barrier);
            //zogi
            if(myargs->arr[id]<myargs->arr[id-1]){
                sem_wait(myargs->sem);        
                *(myargs->countOfSwap)+=1;
                swap(&(myargs->arr[id-1]),&(myargs->arr[id]));
                sem_post(myargs->sem); 
            }
            pthread_barrier_wait(myargs->barrier);
    }
    while(*(myargs->countOfSwap)!=0);
}
void sort(int* arr , int size){
    sem_t sem;
    sem_init(&sem,0,1);

    pthread_barrier_t barrier;
    pthread_barrier_init(&barrier,0,(size/2));

    pthread_t* threads=malloc(sizeof(pthread_t)*(size/2));
    Args* args = malloc(sizeof(Args)*(size/2));
    int* temp =malloc(sizeof(int));
    *temp=0;
    int threadindex=0;
    for(int i=1,threadindex=0;i<size;i+=2,++threadindex)
    {
        args[threadindex].sem=&sem;
        args[threadindex].arr=arr;
        args[threadindex].id=i;
        args[threadindex].barrier=&barrier;
        args[threadindex].countOfSwap=temp;
        args[threadindex].size=size;
        pthread_create(&threads[threadindex],0,run,&args[threadindex]);
    }
    for(int i=0; i<(size/2);++i)
    {
        pthread_join(threads[i],0);
    }
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
}