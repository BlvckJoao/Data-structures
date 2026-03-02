#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node{
        int info;
        struct node* next;
}Node;

typedef struct stack {
        Node* top;
}Stack;

Node* create_node(int info){
        Node* n = (Node*)malloc(sizeof(Node));
        if(n == NULL) return NULL;
        n->info = info;
        n->next = NULL;
        return n;
}

Stack* stack_create(){
        Stack* s = (Stack*)malloc(sizeof(Stack));
        if(s == NULL) return NULL;
        s->top = NULL;
        return s;
}

void stack_free(Stack** ps){
        if(ps == NULL || *ps == NULL) return;
        
        Node* current = (*ps)->top;
        while(current != NULL){
                Node* temp = current;
                current = current->next;
                free(temp);
        }
        free(*ps);
        *ps = NULL;
}

void stack_push(Stack* s, int info){
        if(s == NULL) return;
        Node* n = create_node(info);
        if(n == NULL) return;
        n->next = s->top;
        s->top = n;
}

int stack_pop(Stack* s){
        if(s == NULL || s->top == NULL) return -1;
        Node* temp = s->top;
        int info = temp->info;
        s->top = s->top->next;
        free(temp);
        return info;
}

int stack_top(Stack* s){
        if(s == NULL || s->top == NULL) return -1;
        return s->top->info;
}

int stack_empty(Stack* s){
        if(s == NULL) return 1;
        return s->top == NULL;
}