#include <stdio.h>
#include "../lista.h"

int comprimento(node* l) {
      int count = 0;

    while (l != NULL) {
        count++;
        l = l->next;
    }

    return count;
}


int maiores_que_n(node* l, int n) {
      int count = 0;

    while (l != NULL) {
        if(l->info > n) { count++; }
        l = l->next;
    }

    return count;
}

node* last(node* l) {
    if(l == NULL) return NULL;
    node* aux = l;

    while(aux->next != NULL){
        aux = aux->next;
    }
    return aux;
}

node* concatena(node* l1, node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    node* aux = l1;

    while (aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = l2;
    return l1;
}