#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define INITIAL_MAX 10

typedef struct queue {
	int* values;
	int start;
	int end;
        int max;
}Queue;

Queue* create_queue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
        if(q == NULL) return NULL;

        q->max = INITIAL_MAX;
        q->values = (int*)malloc(q->max * sizeof(int));

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

	if((q->end + 1) % q->max == q->start) return 1;
	return 0;
}

int queue_size(Queue* q){
    if(!q) return -1;

    if(q->end >= q->start)
        return q->end - q->start;

    return q->max - q->start + q->end;
}

int queue_insert(Queue* q, int info){
	if(!q) return -1;

	if(queue_is_full(q)) {
                q->max *= 2;

                int* temp = realloc(q->values, q->max * sizeof(int));
                if(temp == NULL) return -1;
                q->values = temp;
        }

	q->values[q->end] = info;
	q->end = (q->end + 1) % q->max;

	return 1;
}

int queue_remove(Queue* q, int* rm_value){
	if(!q) return -1;
	if(queue_is_empty(q)) return 0;

	if(rm_value){
        	*rm_value = q->values[q->start];
	}
	q->start = (q->start + 1) % q->max;

        int size = queue_size(q);

        //Sim precisa disso tudo pra funcionar :,)

        if(size <= q->max / 4 && q->max > INITIAL_MAX){

                int new_max = q->max / 2;

                int* new_values = malloc(new_max * sizeof(int));
                if(!new_values) return -1;

                for(int i = 0; i < size; i++){
                        new_values[i] = q->values[(q->start + i) % q->max];
                }

                free(q->values);
                q->values = new_values;

                q->max = new_max;
                q->start = 0;
                q->end = size;
        }

    	return 1;
}

void queue_free(Queue** pq){
	if(!pq) return;
        free((*pq)->values);
	free(*pq);
	pq = NULL;
	
	return;
}

void queue_print(Queue* q){
	printf("[ ");
	for(size_t i = q->start; i != q->end; i = (i+1) % QUEUE_SIZE) {
		printf("%d ",  q->values[i]);
	}
	printf(" ]\n");
}