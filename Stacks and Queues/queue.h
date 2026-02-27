#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct queue{
	int elements[QUEUE_SIZE];
	int start;
	int end;
}Queue;

Queue* queue_create();
int queue_is_empty(Queue* q);
int queue_is_full(Queue* q);
int queue_insert(Queue* q, int info);
int queue_remove(Queue* q, int* rm_value);
void queue_free(Queue* q);
void queue_print(Queue* q);
