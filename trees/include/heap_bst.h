#ifndef _HEAP_BST_H_
#define _HEAP_BST_H_

typedef struct heap_bst HeapBST;

HeapBST* heap_bst_create();
int heap_bst_search(HeapBST* hb, int info);
int heap_bst_insert(HeapBST** hb, int info);
int heap_bst_delete(HeapBST** hb, int info);
void free_heap_bst(HeapBST** hb);
void heap_bst_print(HeapBST* hb);

#endif