#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int count=0;

int forking(){
	
	pid_t id =fork();
	if(id)
		count++;
	else
		count=0;
	return id;
}

int main(){
	
	//creating the processes tree
	(forking()&&(forking()&&(forking()||(forking()&&forking())&&forking())||(forking()||(forking()&&forking()))))||(forking()||(forking()&&forking()));

	//Total of offspring
	int child = 0;

	//Number of offspring that returned from one child
	int offspring = 0;

	//Waiting for all children
	for(int i = 0; i < count; ++i){

		wait(&offspring);
		child += offspring;
	}

	printf("The number of the offspring of %d is %d", getpid(), child);

	return child + 1;
}
