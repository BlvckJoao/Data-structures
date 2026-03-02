#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct queue {
	int elements[QUEUE_SIZE];
	int start;
	int end;
}Queue;

Queue* create_queue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->start = 0;
	q->end = 0;

	return q;
}

int queue_is_empty(Queue* q){
	if(!q) return -1;

	if(q->start == q->end) return 1;
	return 0;
}

int queue_is_full(Queue* q){
	if(!q) return -1;

	if((q->end + 1) % QUEUE_SIZE == q->start) return 1;
	return 0;
}

int queue_size(Queue* q){
    if(!q) return -1;

    if(q->end >= q->start)
        return q->end - q->start;

    return QUEUE_SIZE - q->start + q->end;
}

int queue_insert(Queue* q, int info){
	if(!q) return -1;

	if(queue_is_full(q)) return 0;

	q->elements[q->end] = info;
	q->end = (q->end + 1) % QUEUE_SIZE;

	return 1;
}

int queue_remove(Queue* q, int* rm_value){
	if(!q) return -1;
	if(queue_is_empty(q)) return 0;

	if(rm_value){
        	*rm_value = q->elements[q->start];
	}
	q->start = (q->start + 1) % QUEUE_SIZE;

    	return 1;
}

void queue_free(Queue** pq){
	if(!pq) return;
	free(*pq);
	pq = NULL;
	
	return;
}

void queue_print(Queue* q){
	printf("[ ");
	for(size_t i = q->start; i != q->end; i = (i+1) % QUEUE_SIZE) {
		printf("%d ",  q->elements[i]);
	}
	printf(" ]\n");
}

int main(){

	Queue* q = create_queue();

	queue_insert(q, 3);
	queue_insert(q, 5);
	queue_insert(q, -1);

	queue_print(q);

	queue_remove(q, NULL);

	queue_print(q);

	queue_insert(q, 10);

	queue_print(q);

	queue_insert(q, 5);

	queue_print(q);

	queue_remove(q, NULL);
	queue_print(q);
	queue_remove(q, NULL);
	queue_print(q);
	queue_remove(q, NULL);
	queue_print(q);
	

	return 0;
}