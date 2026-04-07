#include <stdio.h>
#include <stdlib.h>
#include "include/heap_bst.h"

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

int heap_bst_insert(Heap_BST** hb, int info){
	int i = 0;

	while(i <= MAX_SIZE){
		if((*hb)->values[i] == 0){
			(*hb)->values[i] = info;
			return 1;
		}else if((*hb)->values[i] > info){
			i = i * 2 + 1;
		}else if((*hb)->values[i] < info){
			i = i * 2 + 2;
		}
	}
	return 0;
}

int heap_bst_delete(Heap_BST** hb, int info){
	int i = 0;

	while(i <= MAX_SIZE){
		if((*hb)->values[i] > info){
			i = i * 2 + 1;
		}else if((*hb)->values[i] < info){
			i = i * 2 + 2;
		}else{
			(*hb)->values[i] = 0;
			return 1;
		}
	}
	return 0;
}

void free_heap_bst(Heap_BST** hb){
	free(*hb);
	*hb = NULL;
}

void heap_bst_print(Heap_BST* hb){
	for(int i = 0; i < MAX_SIZE; i++){
		if(hb->values[i] != 0){
			printf("%d ", hb->values[i]);
		}
	}
	printf("\n");
}