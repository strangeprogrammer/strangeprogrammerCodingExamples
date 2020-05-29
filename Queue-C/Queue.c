#include <stddef.h>
#include <stdlib.h>

#include "Queue.h"

//Code

SLN* allocSLN_d_n(void* datum,SLN* next){
	SLN* retval=(SLN*)(malloc(sizeof(SLN)));
	retval->next=next;
	retval->datum=datum;
	return retval;
}

SLN* allocSLN_d(void* datum){
	return allocSLN_d_n(datum,NULL);
}

SLN* allocSLN(){
	return allocSLN_d(NULL);
}

void freeSLN(SLN* tofree){
	DIENULLVOID(tofree);
	tofree->next=NULL;
	tofree->datum=NULL;
	free(tofree);
	return;
}

void appendSLN(SLN* after,SLN* toappend){
	DIENULLVOID(after);
	DIENULLVOID(toappend);
	toappend->next=after->next;
	after->next=toappend;
	return;
}

Queue* allocQueue(){
	Queue* retval=(Queue*)malloc(sizeof(Queue));
	retval->length=0;
	retval->head=allocSLN();
	retval->tail=allocSLN();
	appendSLN(retval->head,retval->tail);
	return retval;
}

bool freeQueue(Queue* q){
	DIENULLTYPE(q,false);
	if(0<(q->length)){
		return false;
	}
	freeSLN(q->head);
	freeSLN(q->tail);
	q->head=NULL;
	q->tail=NULL;
	free(q);
	return true;
}

void enqueue(Queue* q,void* toqueue){
	DIENULLVOID(q);//Allow queueing 'NULL'
	appendSLN(q->tail,allocSLN());
	q->tail->datum=toqueue;
	q->tail=q->tail->next;
	q->length++;
	return;
}

void* dequeue(Queue* q){
	DIENULL(q);
	if((q->length)<1){
		return NULL;
	}
	void* retval;
	SLN* toremove=q->head->next;
	retval=toremove->datum;
	q->head->next=toremove->next;
	freeSLN(toremove);
	q->length--;
	return retval;
}
