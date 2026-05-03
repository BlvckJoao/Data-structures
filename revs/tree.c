#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
        int info;
        struct node* left;
        struct node* right;
}Node;

typedef struct tree{
        struct node* root;
}Tree;


Node* create_node(int info){
        Node* new = (Node*)malloc(sizeof(Node));
        if(new == NULL) return NULL;
        
        new->info = info;
        new->left = NULL;
        new->right = NULL;
        
        return new;
}


Tree* create_tree(){
        Tree* t = (Tree*)malloc(sizeof(Tree));
        if(t == NULL) return NULL;
        
        return t;
}

Node* node_search(Node* root, int info) {
        if(root == NULL) return NULL;
        if(info > root->info) return node_search(root->right, info);
        if(info < root->info) return node_search(root->left, info);
        return root;
}

Node* tree_search(Tree* t, int info){
        return node_search(t->root, info);
}

int node_insert(Node** root, int info) {
        if (root == NULL) return -1;
        if (*root == NULL) {
                *root = create_node(info);
                return (*root) ? 1 : -1;
        }
        
        if(node_search(*root, info) != NULL) return 0;
        
        if(info > (*root)->info) return node_insert(&(*root)->right, info);
        if(info < (*root)->info) return node_insert(&(*root)->left, info);
        
        return 0;
}

int tree_insert(Tree* t, int info){
    return node_insert(&t->root, info);
}


static Node* min_right(Node* n){
        if(n->left == NULL) return n;
        return min_right(n->left);
}

int node_remove(Node** root, int info){
        if(root == NULL || *root == NULL) return 0;
        
        if(info < (*root)->info) return node_remove(&(*root)->left, info);
        if(info > (*root)->info) return node_remove(&(*root)->right, info);
        
        Node* to_remove = *root;
        
        if(to_remove->left == NULL && to_remove->right == NULL){
                free(to_remove);
                *root = NULL;
        }
        else if(to_remove->left == NULL){
                *root = to_remove->right;
                free(to_remove);
        }
        else if(to_remove->right == NULL){
                *root = to_remove->left;
                free(to_remove);
        }
        else {
                Node* temp = min_right((*root)->right);
                (*root)->info = temp->info;
                node_remove(&(*root)->right, temp->info);
        }
        
        return 1;
}

int tree_remove(Tree* t, int info){
        return node_remove(&t->root, info);
}

//

int height(Node* n) {
        if(n == NULL) return -1;
        
        int left_h = height(n->left);
        int right_h = height(n->right);
        
        return (left_h > right_h ? left_h : right_h) + 1;
}

Node** check_unbalance(Node** n, int* height) {
    if (!n) {
        *height = -1;
        return NULL;
    }

    int lh, rh;

    Node** left = check_unbalance(&(*n)->left, &lh);
    if (left) return left;

    Node** right = check_unbalance(&(*n)->right, &rh);
    if (right) return right;

    *height = (lh > rh ? lh : rh) + 1;

    if (abs(lh - rh) > 1)
        return n;

    return NULL;
}

int right_rotation(Node** n) {
        if(n == NULL || *n == NULL || (*n)->left == NULL) return -1;
        
        Node* new_root = (*n)->left;
        (*n)->left = new_root->right;
        new_root->right = *n;
        *n = new_root;
        
        return 1;
}

int left_rotation(Node** n) {
        if(n == NULL || *n == NULL || (*n)->right == NULL) return -1;
        
        Node* new_root = (*n)->right;
        (*n)->right = new_root->left;
        new_root->left = *n;
        *n = new_root;
        
        return 1;
}

int double_left_rotation(Node** n) {
    if (!n || !*n || !(*n)->left || !(*n)->left->right) return 0;
        
    if (left_rotation(&(*n)->left) == -1) return 0;
    return right_rotation(n);
}

int double_right_rotation(Node** n) {
    if (!n || !*n || !(*n)->right || !(*n)->right->left) return 0;
        
    if (right_rotation(&(*n)->right) == -1) return 0;
    return left_rotation(n);
}

//

void print_tree_node(Node* n, int mode){
        if(n == NULL) {
            return;
        }
        
        switch(mode) {
            
            case 0: //preorder
                    printf("%d, ", n->info);
                    print_tree_node(n->left, mode);
                    print_tree_node(n->right, mode);
                    
                    break;
                    
            
            case 1: //inorder
                    print_tree_node(n->left, mode);
                    printf("%d ,", n->info);
                    print_tree_node(n->right, mode);
                    
                    break;
            
            case 2: //postorder
                    print_tree_node(n->left, mode);
                    print_tree_node(n->right, mode);
                    printf("%d ,", n->info);
                    
                    break;
                    
            default:
                    print_tree_node(n, 0);
                    break;
        }
}

void print_tree_visual(Node* root, int level) {
    if (root == NULL) return;

    // Primeiro imprime a direita
    print_tree_visual(root->right, level + 1);

    // Espaçamento
    for (int i = 0; i < level * 5; i++) {
        printf(" ");
    }

    // Imprime o nó
    printf("%d\n", root->info);

    // Depois imprime a esquerda
    print_tree_visual(root->left, level + 1);
}

void print_tree(Tree* t, int mode){
        print_tree_node(t->root, mode);
}

void free_node(Node** n){
        if(n == NULL || *n == NULL) return;
    
        free_node(&(*n)->left);
        free_node(&(*n)->right);
        
        free(*n);
        n == NULL;
        
        return;
}

void free_tree(Tree* t){
        free_node(&t->root);
}

int main() {
    
    Tree* t = create_tree(10);
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ;
    
    for(int i = 0; i < 10; i++) {
        tree_insert(t, arr[i]);
    }
    
    print_tree_visual(t->root, 1);
    
    int h;
    Node** balance = check_unbalance(&(t->root), &h);

    while (balance != NULL) {
        Node* n = *balance;
    
        int lh = height(n->left);
        int rh = height(n->right);
    
        int balance_factor = lh - rh;
    
        if (balance_factor > 1) {
            int child_balance = height(n->left->left) - height(n->left->right);
    
            if (child_balance >= 0) {
                // LL
                right_rotation(balance);
            } else {
                // LR
                double_left_rotation(balance);
            }
    
        } else if (balance_factor < -1) {
            int child_balance = height(n->right->left) - height(n->right->right);
    
            if (child_balance <= 0) {
                // RR
                left_rotation(balance);
            } else {
                // RL
                double_right_rotation(balance);
            }
    }
    
    print_tree_visual(t->root, 1);
    
    free_tree(t);
    
    return 0;
        }
}