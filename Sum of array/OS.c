#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

typedef struct Args{
	int* arr;
	sem_t* sem;
	int k;
	int id;
	int sum;
}Args;
void* run(void* args)
{
	Args* myargs=(Args*) args;
	int k = myargs->k;
	int myid = myargs -> id;

	for(int i=1;i<=k;i*=2)
	{
		sem_wait(&myargs->sem[myid]);
		if(myid - i > 0)
			myargs->arr[myid] += myargs->arr[myid - i];
		if(myid == 0)
			sem_post(&myargs->sem[k-1]);
		else
			sem_post(&myargs->sem[myid-1]);
	}
}
void sumbyindex(int* arr,int k)
{
	sem_t* sem=malloc(sizeof(sem_t)*k);
	pthread_t* threads=malloc(sizeof(pthread_t)*k);
	Args* args=malloc(sizeof(Args)*k);
	for(int i=0;i<k;++i)
	{
		sem_init(&sem[i],0,i==k-1?1:0);
	}
	for(int i=0;i<k;i++)
	{
		args[i].arr=arr;
		args[i].sem=sem;
		args[i].sum=arr[i];
		args[i].k=k;
		args[i].id=i;
		pthread_create(&threads[i],0,run,&args[i]);
	}
	for(int i=0;i<k;++i)
	{
		pthread_join(threads[i],0);
	}
}


int main(){
	int a[]={1,2,3,4,5,6,7,8};
	printf("The original Array is: \n");
	for(int i = 0; i < 8; ++i){
		printf("%d ",a[i]);
	}

	sumbyindex(a,8);

	printf("\nThe new Array is: \n");
	for(int i = 0; i < 8; ++i){
		printf("%d ",a[i]);
	}
	return 0;
}
