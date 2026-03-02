#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node{
        int info;
        struct node* next;
        struct node* prev;
}Node;

typedef struct queue {
        Node* front;
        Node* rear;
}Queue;

Node* create_node(int info){
        Node* n = (Node*)malloc(sizeof(Node));
        if(n == NULL) return NULL;
        n->info = info;
        n->next = NULL;
        n->prev = NULL;
        return n;
}

Queue* queue_create(){
        Queue* q = (Queue*)malloc(sizeof(Queue));
        if(q == NULL) return NULL;
        q->front = NULL;
        q->rear = NULL;
        return q;
}

void queue_free(Queue** pq){
        if(pq == NULL || *pq == NULL) return;
        
        Node* aux = (*pq)->front;
        while(aux != NULL){
                Node* temp = aux;
                aux = aux->next;
                free(temp);
        }
        free(*pq);
        *pq = NULL;
}

int queue_is_empty(Queue* q){
        if(q == NULL) return -1;
        return (q->front == NULL);
}

int queue_size(Queue* q){
        if(q == NULL) return -1;
        int count = 0;
        Node* aux = q->front;
        while(aux != NULL){
                count++;
                aux = aux->next;
        }
        return count;
}

int queue_insert(Queue* q, int info){
        if(q == NULL) return -1;
        Node* new = create_node(info);
        if(new == NULL) return -1;
        if(q->rear == NULL){
                q->front = new;
                q->rear = new;
        } else {
                q->rear->next = new;
                new->prev = q->rear;
                q->rear = new;
        }
        return 0;
}

int queue_remove(Queue* q,  int* rm_value){
        if(q == NULL || q->front == NULL) return -1;
        Node* temp = q->front;
        *rm_value = temp->info;

        q->front = q->front->next;
        if(q->front != NULL) {
                q->front->prev = NULL;
        }else{
                q->rear = NULL;
        }
        free(temp);
        return 0;
}

void queue_print(Queue* q){
        if(q == NULL) return;
        Node* aux = q->front;
        while(aux != NULL){
                printf("%d ", aux->info);
                aux = aux->next;
        }
        printf("\n");
}