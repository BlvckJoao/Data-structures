#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

node* createNode(int info);

int insertFront(node** phead, int info);
int insertIn(node** phead, int info, int idx);
int insertBack(node** phead, int info);

node* searchInfo(node* head, int info);
node* searchIndex(node* head, int idx);

int removeInfo(node** phead, int info);
int removeIndex(node** phead, int idx);

int sortList(node* head);
void freeList(node** phead);
void printList(node* head);

#endif