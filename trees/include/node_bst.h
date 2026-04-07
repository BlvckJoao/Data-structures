#ifndef NODE_BST_H
#define NODE_BST_H

typedef struct Node {
        int info;
        struct Node* left_child;
        struct Node* right_child;
} Node;

typedef struct BST {
        Node* root;
} BST;

BST* bst_create();
int bst_insert(BST* t, int info);
Node* bst_node_search(Node* n, int info);
Node* bst_search(BST* t, int info);
int bst_node_remove(Node** n, int info);
int bst_remove(BST* t, int info);
void bst_destroy(BST* t);