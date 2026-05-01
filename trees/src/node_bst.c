#include <stdio.h>
#include <stdlib.h>
#include "include/node_bst.h"

BST* bst_create() {
        BST* bst = (BST*)malloc(sizeof(BST));
        if (!bst) return NULL;
        bst->root = NULL;
        return bst;
}

Node* create_node(int info) {
        Node* n = (Node*)malloc(sizeof(Node));
        if (!n) return NULL;
        n->info = info;
        n->left_child = NULL;       
        n->right_child = NULL;
        return n;
}

int bst_node_insert(Node** n, int info) {
        if (!n) return -1;
        if (*n == NULL) {
                *n = create_node(info);
                return (*n) ? 1 : -1;
        }

        if (bst_node_search(*n, info) != NULL) return 0;

        if ((*n)->info > info) {
                return bst_node_insert(&(*n)->left_child, info);
        }

        if ((*n)->info < info) {
                return bst_node_insert(&(*n)->right_child, info);
        }

        return 0;
}

int bst_insert(BST* t, int info) {
        if (!t) return -1;
        return bst_node_insert(&(t->root), info);
}

Node* bst_node_search(Node* n, int info) {
        if (!n) return NULL;
        if (n->info == info) return n;
        if (n->info > info) return bst_node_search(n->left_child, info);
        return bst_node_search(n->right_child, info);
}

Node* bst_search(BST* t, int info) {
        if (!t) return NULL;
        return bst_node_search(t->root, info);
}

static Node* min_node(Node* n) {
        while (n->left_child != NULL)
                n = n->left_child;
        return n;
}


int bst_node_remove(Node** n, int info) {
        if(!n || !*n) return -1;

        if((*n)->info > info) {
                return bst_node_remove(&(*n)->left_child, info);
        }

        if((*n)->info < info) {
                return bst_node_remove(&(*n)->right_child, info);
        }

        Node* to_remove = *n;
        if (to_remove->left_child == NULL) {
                *n = to_remove->right_child;
        } else if (to_remove->right_child == NULL) {
                *n = to_remove->left_child;
        } else {
                Node* min_right = min_node(to_remove->right_child);
                to_remove->info = min_right->info;
                bst_node_remove(&to_remove->right_child, min_right->info);
                return 1;
        }
}

int bst_remove(BST* t, int info) {
        if (!t) return -1;
        return bst_node_remove(&(t->root), info);
}

void bst_destroy(BST* t) {
        if (!t) return;
        bst_node_destroy(t->root);
        free(t);
}

void bst_node_destroy(Node* n) {
        if (!n) return;
        //freeing in post-order to avoid dangling pointers
        bst_node_destroy(n->left_child);
        bst_node_destroy(n->right_child);
        free(n);
}

//PARTE AVL

int bst_check_balanced(Node* n, int* height) {
        if (!n) { *height = -1; return 1; }

        int left_h, right_h;
        if (!bst_check_balanced(n->left_child,  &left_h))  return 0;
        if (!bst_check_balanced(n->right_child, &right_h)) return 0;

        *height = 1 + (left_h > right_h ? left_h : right_h);
        return abs(left_h - right_h) <= 1;
}

int bst_is_balanced(Node* n) {
        int h;
        return bst_check_balanced(n, &h);
}

int bst_left_rotation(Node** n) {
        if (!n || !*n || !(*n)->right_child) return 0;

        Node* new_root = (*n)->right_child;
        (*n)->right_child = new_root->left_child;
        new_root->left_child = *n;
        *n = new_root;

        return 1;
}

int bst_right_rotation(Node** n) {
        if (!n || !*n || !(*n)->left_child) return 0;

        Node* new_root = (*n)->left_child;
        (*n)->left_child = new_root->right_child;
        new_root->right_child = *n;
        *n = new_root;

        return 1;
}

int bst_left_double_rotation(Node** n) {
        if (!n || !*n || !(*n)->left_child) return 0;
        if (!(*n)->left_child->right_child) return 0;

        if (!bst_right_rotation(&(*n)->left_child)) return 0;
        return bst_right_rotation(n);
}

int bst_right_double_rotation(Node** n) {
        if (!n || !*n || !(*n)->right_child) return 0;
        if (!(*n)->right_child->left_child) return 0;

        if (!bst_left_rotation(&(*n)->right_child)) return 0;
        return bst_left_rotation(n);
}

//funções de exercicio

int bst_pares(BST* t) {
        if (!t) return -1;
        return bst_node_pares(t->root);
}

int bst_node_pares(Node* n){
        if(!n) return 0;
        int count = 0;
        if(n->info % 2 == 0) count++;
        //pecorre a arvore em pre-ordem para contar os nós pares
        count += bst_node_pares(n->left_child);
        count += bst_node_pares(n->right_child);
        return count;
}

int bst_folhas(BST* t) {
        if (!t) return -1;
        return bst_node_folhas(t->root);
}

int bst_node_folhas(Node* t){
        if(!t) return 0;

        int count = 0;

        count += bst_node_folhas(t->left_child);
        count += bst_node_folhas(t->right_child);
        if(t->left_child == NULL && t->right_child == NULL) count++;

        return count;
}

int bst_umfilho(BST* t) {
        if (!t) return -1;
        return bst_node_umfilho(t->root);
}

int bst_node_umfilho(Node* t){
        if(!t) return 0;

        int count = 0;

        count += bst_node_umfilho(t->left_child);
        count += bst_node_umfilho(t->right_child);
        if(t->left_child == NULL && t->right_child != NULL ||
           t->left_child != NULL && t->right_child == NULL ) count++;

        return count;
}

int bst_igual(BST* a, BST* b){
        if(!a || !b) return -1;
        return bst_node_igual(a->root, b->root);
}

int bst_node_igual(Node* a, Node* b){
        if(a == NULL && b == NULL) return 1;
        if(a == NULL || b == NULL) return 0;
        
        return (a->info == b->info) && 
               bst_node_igual(a->left_child, b->left_child) && 
               bst_node_igual(a->right_child, b->right_child);
}

BST* bst_copia(BST* t) {
        if (!t) return NULL;
        BST* copy = bst_create();
        bst_node_copia(t->root, &copy->root);
        return copy;
}

static void bst_node_copia(Node* src, Node** dest) {
        *dest = create_node(src->info);
        bst_node_copia(src->left_child, &(*dest)->left_child);
        bst_node_copia(src->right_child, &(*dest)->right_child);
}       