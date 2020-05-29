#ifndef QUEUE_H
#define QUEUE_H

//Macros

#define DIENULLTYPE(x,y) if((x)==NULL) return y
#define DIENULL(x) DIENULLTYPE(x,NULL)
#define DIENULLVOID(x) DIENULLTYPE(x,)

//Types

typedef enum bool { //Only in C
	true=1,
	false=0
} bool;

typedef struct SLN {
	struct SLN	*next;
	void		*datum;
} SLN;

typedef struct Queue {
	SLN		*head;
	SLN		*tail;
	unsigned long	length;
} Queue;

//Prototypes

SLN* allocSLN_d_n(void* datum,SLN* next);
SLN* allocSLN_d(void* datum);
SLN* allocSLN();
void freeSLN(SLN* tofree);
void appendSLN(SLN* after,SLN* toappend);

Queue* allocQueue();
bool freeQueue(Queue* q);
void enqueue(Queue* q,void* toqueue);
void* dequeue(Queue* q);

#endif /* QUEUE_H */
