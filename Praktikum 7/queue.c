#include "queue.h"
#include <stdio.h>
void CreateQueue(Queue *q){
	IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
boolean isEmpty(Queue q){
	return (IDX_HEAD(q)==IDX_UNDEF) && (IDX_TAIL(q)==IDX_UNDEF);
}

boolean isFull(Queue q){
	return (IDX_HEAD(q)==0) && (IDX_TAIL(q)==CAPACITY-1);
}

int length(Queue q){
	if(isEmpty(q)) return 0;
	return IDX_TAIL(q)-IDX_HEAD(q)+1;
}

void enqueue(Queue *q, ElType val){
	if (isEmpty(*q)){
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
        HEAD(*q)=val;
    } 
	else if (IDX_TAIL(*q)==(CAPACITY-1)){
        int i;
        for (i=IDX_HEAD(*q);i<=IDX_TAIL(*q);i++)(*q).buffer[i-IDX_HEAD(*q)]=(*q).buffer[i];
        IDX_TAIL(*q) -= IDX_HEAD(*q)-1;
        IDX_HEAD(*q) = 0;
        TAIL(*q)=val;
    }
    else{
    	IDX_TAIL(*q)++;
    	TAIL(*q)=val;
	}
}

void dequeue(Queue *q, ElType *val){
	*val = HEAD(*q);
    if (IDX_HEAD(*q)==IDX_TAIL(*q)){
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    } 
	else IDX_HEAD(*q)++;
}

void displayQueue(Queue q){
	printf("[");
	int i;
	if(!isEmpty(q)){
		for(i=IDX_HEAD(q); i<=IDX_TAIL(q);i++){
			printf("%d", q.buffer[i]);
			if(i!=IDX_TAIL(q)) printf(",");
		}
	}
    printf("]");
}

