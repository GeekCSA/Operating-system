#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void* create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  int protection = PROT_READ | PROT_WRITE;

  // The buffer will be shared (meaning other processes can access it), but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it:
  int visibility = MAP_ANONYMOUS | MAP_SHARED;

  // The remaining parameters to `mmap()` are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  return mmap(NULL, size, protection, visibility, 0, 0);
}



typedef struct Args{
	int* newSumArr;
	int* originalSumArr;

	int k;
	int id;
	int sum;
    pthread_barrier_t* barrier;
}Args;

void run(void* args)
{
	Args* myargs=(Args*) args;
	int k = myargs->k;
	int myid = myargs -> id;
	printf("___ %d ___",myid);
	for(int p=1;p<=k;p*=2)
	{

		pthread_barrier_wait(myargs->barrier);
		printf("___ %d ___",myid);
		fflush(stdout);
		if(myid - p >= 0)
			myargs->newSumArr[myid] += myargs->originalSumArr[myid - p];

		
		
		pthread_barrier_wait(myargs->barrier);
		//for(int j = 0; j < k; ++j){
		myargs->originalSumArr[myid] = myargs->newSumArr[myid];
		//}
	}
}

void sumbyindex(int* arr,int k)
{

	int* oldArr = create_shared_memory(sizeof(int)*k);
	int* newArr = create_shared_memory(sizeof(int)*k);

    pthread_barrier_t* barrier = create_shared_memory(sizeof(pthread_barrier_t));
	for(int i = 0; i < k; ++i){
		oldArr[i] = arr[i];
		newArr[i] = 0;
	}

    //pthread_barrier_t barrier;
    pthread_barrier_init(barrier,0,k);

	int* arrChilds = malloc(sizeof(int) * k);

	for(int i=0;i<k;i++)
	{
		int id = fork();
		arrChilds[i] = id;
		if(id == -1)
			exit(1);
		if(id == 0){
			Args* args=malloc(sizeof(Args)*k);
			args[i].newSumArr = newArr;;
			args[i].originalSumArr = oldArr;
			args[i].sum=arr[i];
			args[i].k=k;
			args[i].id=i;
			args[i].barrier = barrier;

			run(args);

			pthread_barrier_wait(args[i].barrier);
			arr[i] = oldArr[i];
			exit(0);
		}

	}

	for(int i = 0; i < k; ++i){
		wait(0);
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
