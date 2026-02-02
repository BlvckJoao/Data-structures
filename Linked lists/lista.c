#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct Node {
    int info;
    struct Node* next;
} node;

node* createNode(int info) {
    node* novo = malloc(sizeof(node));
    if (novo == NULL) return NULL;

    novo->info = info;
    novo->next = NULL;
    return novo;
}

int insertFront(node** phead, int info) {
    node* novo = createNode(info);
    if (!novo) return 0;

    novo->next = *phead;
    *phead = novo;
    return 1;
}

int insertBack(node** phead, int info) {
    node* novo = createNode(info);
    if (!novo) return 0;

    if (*phead == NULL) {
        *phead = novo;
        return 1;
    }

    node* aux = *phead;
    while (aux->next != NULL)
        aux = aux->next;

    aux->next = novo;
    return 1;
}

int insertIn(node** phead, int info, int idx) {
    if (idx < 0) return 0;

    if (idx == 0)
        return insertFront(phead, info);

    node* aux = *phead;
    int count = 0;

    while (aux != NULL && count < idx - 1) {
        aux = aux->next;
        count++;
    }

    if (aux == NULL) return 0;

    node* novo = createNode(info);
    if (!novo) return 0;

    novo->next = aux->next;
    aux->next = novo;
    return 1;
}


node* searchInfo(node* head, int info) {
    while (head != NULL) {
        if (head->info == info)
            return head;
        head = head->next;
    }
    return NULL;
}

node* searchIndex(node* head, int idx) {
    int count = 0;

    while (head != NULL) {
        if (count == idx)
            return head;
        head = head->next;
        count++;
    }
    return NULL;
}

int removeInfo(node** phead, int info) {
    if (*phead == NULL) return 0;

    if ((*phead)->info == info) {
        node* temp = *phead;
        *phead = temp->next;
        free(temp);
        return 1;
    }

    node* aux = *phead;
    while (aux->next != NULL && aux->next->info != info)
        aux = aux->next;

    if (aux->next == NULL) return 0;

    node* temp = aux->next;
    aux->next = temp->next;
    free(temp);
    return 1;
}

int removeIndex(node** phead, int idx) {
    if (*phead == NULL || idx < 0) return 0;

    if (idx == 0) {
        node* temp = *phead;
        *phead = temp->next;
        free(temp);
        return 1;
    }

    node* aux = *phead;
    int count = 0;

    while (aux->next != NULL && count < idx - 1) {
        aux = aux->next;
        count++;
    }

    if (aux->next == NULL) return 0;

    node* temp = aux->next;
    aux->next = temp->next;
    free(temp);
    return 1;
}
