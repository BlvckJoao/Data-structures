#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct Node {
    int info;
    struct Node* next;
}node;

node* createNode(int info) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) return NULL;

    new->info = info;
    new->next = NULL;
    return new;
}

int insertFront(node** phead, int info) {
    node* new = createNode(info);
    if(new == NULL) return 0;

    new->next = *phead;
    *phead = new;
    return 1;
}

int insertIn(node** phead, int info, int idx) {
    node* new = createNode(info);
    if(new == NULL) return 0;

    node* aux = *phead;
    for(size_t i = 0; i < idx - 1; i++){
        aux = aux->next;
    }
    aux->next = new;
    aux = aux->next;
    new->next = aux->next;

    return 0; 
}

int insertBack(node** phead, int info) {
    node* new = createNode(info);
    if (new == NULL) return 0;
    
    node* aux = *phead;
    while(aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = new;
    return 1;
}

node* searchInfo(node* head, int info) {
    node* aux = head;

    while(aux->info != info) {
        aux = aux->next;
    }
    return aux;
}

node* searchIndex(node* head, int idx) {
    node* aux = head;
    int count = 0;

    while(count != idx) {
        aux = aux->next;
        count++;
    }
    return aux;
}

int removeInfo(node** phead, int info) {
    node* aux = *phead;

    while(aux->info != info) {
        aux = aux->next;
    }

    
}