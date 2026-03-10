#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define MAX_SIZE 100

typedef struct tree{
	int values[MAX_SIZE];
}Heap_BST;

Heap_BST* heap_bst_create(){
	Heap_BST* hb = (Heap_BST*)malloc(sizeof(Heap_BST));
	if(hb == NULL) return NULL;

	return hb;
}

int heap_bst_search(Heap_BST* hb, int info){
	int iterator = 0;

	while(iterator <= MAX_SIZE){
		if(hb->values[iterator] > info){
			iterator = iterator * 2 + 1;
		}else if(hb->values[iterator] < info){
			iterator = iterator * 2 + 2;
		}else{
			return hb->values[iterator]
		}
	}
	return -1;
}
