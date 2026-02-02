#include <stdio.h>
#include <string.h>
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

node* retira_n(node* l, int n) {
    node* result = NULL;

    while (l != NULL) {
        if(l->info > n) {
            insertBack(&result, l->info);
        }
        l = l->next;
    }

    return result;
}

node* separa(node* l, int n) {
    if (l == NULL) return NULL;

    node* aux = l;

    while (aux != NULL && aux->info != n) {
        aux = aux->next;
    }

    if (aux == NULL) return NULL;

    node* separada = aux->next;
    aux->next = NULL;

    return separada;
}

node* merge(node* l1, node* l2) {
    node* result = NULL;

    while (l1 != NULL && l2 != NULL) {
        insertBack(&result, l1->info);
        insertBack(&result, l2->info);
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL) {
        insertBack(&result, l1->info);
        l1 = l1->next;
    }

    while (l2 != NULL) {
        insertBack(&result, l2->info);
        l2 = l2->next;
    }

    return result;
}

node* invert(node* l) {
    node* inverted = NULL;

    while(l != NULL) {
        insertFront(&inverted, l->info);
    }
    return inverted;
}

int is_equal(node* l1, node* l2) {
    while (l1 != NULL && l2 != NULL) {
        if (strcmp(l1->info, l2->info) != 0)
            return 0;

        l1 = l1->next;
        l2 = l2->next;
    }

    return l1 == NULL && l2 == NULL;
}

node* copia(node* l) {
    node* result = NULL;
    node* tail = NULL;

    while (l != NULL) {
        node* novo = malloc(sizeof(node));
        if (!novo) return NULL;

        novo->info = malloc(strlen(l->info) + 1);
        if (!novo->info) return NULL;

        strcpy(novo->info, l->info);
        novo->next = NULL;

        if (result == NULL) {
            result = novo;
            tail = novo;
        } else {
            tail->next = novo;
            tail = novo;
        }

        l = l->next;
    }

    return result;
}

int remove_lista_circular(node** head, int info) {
    if (*head == NULL) return 0;

    node* aux = *head;

    do {
        if (aux->info == info) {

            // Caso: único nó da lista
            if (aux->next == aux) {
                free(aux);
                *head = NULL;
                return 1;
            }

            // Ajusta os ponteiros
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;

            // Se for o head, move o head
            if (aux == *head)
                *head = aux->next;

            free(aux);
            return 1;
        }

        aux = aux->next;
    } while (aux != *head);

    // info não encontrado
    return 0;
}

int insert_before_head(node** head, int info) {
    node* novo = malloc(sizeof(node));
    if (novo == NULL) return 0;

    novo->info = info;

    // Caso lista vazia
    if (*head == NULL) {
        novo->next = novo;
        novo->prev = novo;
        *head = novo;
        return 1;
    }

    node* last = (*head)->prev;

    // Liga o novo nó
    novo->next = *head;
    novo->prev = last;

    // Ajusta os vizinhos
    last->next = novo;
    (*head)->prev = novo;

    return 1;
}