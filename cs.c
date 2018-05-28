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
        pthread_wait(&myargs->sem[myid]);
        if(myid - i > 0)
            myargs->arr[myid] += myargs->arr[myid - i];
        if(myid == 0)
            pthread_post(&myargs->sem[k-1]);
        else
            pthread_post(&myargs->sem[myid-1]);
    }
}
void sumbyindex(int* arr,int k)
{
    sem_t* sem=malloc(sizeof(sem_t)*k);
    ptrhead_t* threads=malloc(sizeof(ptrhead_t)*k);
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
        ptrhead_create(&threads[i],0,run,&args[i]);
    }
    for(int i=0;i<k;++i)
    {
        ptrhead_join(&threads[i],0);
    }
}


int main(){
int a[]={1,2,3,4,5,6,7,8};
return 0;
}
