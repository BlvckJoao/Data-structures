#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
}Node;

Node* create_node(int info){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n) return NULL;
    
    n->info = info;
    n->next = NULL;
    
    return n;
}

int insert_node_in_end(Node** n, int info){
    if(!n || !(*n)) return -1;
    
    Node* new = create_node(info);
    Node* aux = *n;
    
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = new;
    return 1;
}

int remove_node_info(Node** n, int info){
    if(!n || !(*n)) return -1;
    
    Node* aux = *n;
    while(aux->next->info != info){
        aux = aux->next;
    }
    if(aux == NULL) return 0;
    
    Node* to_remove = aux->next;
    aux->next = aux->next->next;
    
    free(to_remove);
    
    return 1;
}

Node* search_node_info(Node* n, int info){
    if(!n) return NULL;
    while(n != NULL && n->info != info){
        n = n->next;
    }
    if(n == NULL) return NULL;
    return n;
}

void free_list(Node** n){
    if(!n || !(*n)) return;
    
    while(*n != NULL){
        Node* to_remove = *n;
        *n = (*n)->next;
        free(to_remove);
    }
    return;
}

void print_list(Node* n){
    if(!n) return;
    
    while(n != NULL){
        printf("%d -> ", n->info);
        n = n->next;
    }
    printf(" NULL \n");
    return;
}

int main(){
    
    Node* n = create_node(5);
    insert_node_in_end(&n, 10);
    insert_node_in_end(&n, 3);
    print_list(n);
    
    int a = remove_node_info(&n, 3);
    print_list(n);
    
    for(int i = 0; i < 10; i++){
        insert_node_in_end(&n, i);
    }
    print_list(n);
    
    Node* searched = search_node_info(n, 11);
    printf("%d\n", searched->info);
    
    free_list(&n);
}