#include <stdio.h>
#include <stdlib.h>
#include "include/tree.h"

typedef struct node {
        int info;
        struct node* left_child;
        struct node* right_child;
}Node;

typedef struct node_BST{
        struct node_BST* root
}BST;

BST* bst_create(){
        BST* bst = (BST*)malloc(sizeof(BST));
        if(!bst) return NULL;
        bst->root  = NULL;

        return bst;
}

Node* create_node(int info){
        Node* n = (Node*)malloc(sizeof(Node));
        if(!n) return NULL;
        n->info = info;

        return n;
}

int bst_insert(BST* t, int info){
        if(!t) return -1;
        return bst_node_insert(t->root, info);
}

int bst_node_insert(Node* n, int info){
        if(!n) return -1;
        if(bst_node_search(n, info) != NULL) return 0; //dado já existe na arvore

        if(n->info > info){
                if(n->left_child == NULL){
                        Node* new = create_node(info);
                        n->left_child = new;
                        return 1;
                }
                return bst_node_insert(n->left_child, info);
        }

        if(n->info < info){
                if(n->right_child == NULL){
                        Node* new = create_node(info);
                        n->right_child = new;
                        return 1;
                }
                return bst_node_insert(n->right_child, info);
        }
}

Node* bst_search(BST* t, int info){
        if(!t) return NULL;
        return bst_node_search(t->root, info);
}

Node* bst_node_insert(Node* n, int info){
        if(!n) return NULL;
        if(n->info == info) return n;
        if(n->info > info) return bst_node_insert(n->left_child, info);
        if(n->info < info) return bst_node_insert(n->right_child, info);
}