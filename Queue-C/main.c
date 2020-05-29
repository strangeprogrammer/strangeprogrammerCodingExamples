#include <stdio.h>

#include "Queue.h"

int main(){
	int	firstIn=4,
		secondIn=9,
		thirdIn=41;
	
	Queue* q=allocQueue();
	
	printf("First in:\t%d\n",firstIn);
	printf("Second in:\t%d\n",secondIn);
	printf("Third in:\t%d\n",thirdIn);
	
	printf("\n");
	
	enqueue(q,&firstIn);
	enqueue(q,&secondIn);
	enqueue(q,&thirdIn);
	
	printf("First out:\t%d\n",*((int*)dequeue(q)));
	printf("Second out:\t%d\n",*((int*)dequeue(q)));
	printf("Third out:\t%d\n",*((int*)dequeue(q)));
	
	printf("\n");
	
	printf("Freeing status:\t%d\n",freeQueue(q));
	
	return 0;
}
