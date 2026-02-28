#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct queue Queue;

Queue* queue_create();
int queue_is_empty(Queue* q);
int queue_is_full(Queue* q);
int queue_size(Queue* q);
int queue_insert(Queue* q, int info);
int queue_remove(Queue* q, int* rm_value);
void queue_free(Queue** q);
void queue_print(Queue* q);

#endif