#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct queue {
        int elements[MAX_SIZE];
        int start;
        int end;
}Queue;

Queue* create_queue() {
        Queue* q = (Queue*)malloc(sizeof(Queue));
        if(q == NULL) return NULL;

        q->start = 0;
        q->end = 0;

        return 0;
}

int is_empty(Queue* q){
	if(q == NULL) return -1;

	if(q->start == q->end) return 1;
	return 0;
}

int is_full(Queue* q){
	if(q == NULL) return -1;

	if((q->end + 1) % MAX_SIZE == q->start) return 1;
	return 0;
}

int enqueue(Queue* q, int info){
        if(q == NULL) return -1;

        if(is_full(q)) return 0;

        q->end = (q->end + 1) % MAX_SIZE;
        q->elements[q->end] = info;

        return 1;
}

int dequeue(Queue* q, int info){
        if(q == NULL) return -1;

        if(is_empty(q)) return 0;

        q->start = (q->start + 1) % MAX_SIZE;

        return 1;
}