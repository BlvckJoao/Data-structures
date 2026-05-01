#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct stack{
        int elements[MAX_SIZE];
        int top;
}Stack;

Stack* create_stack() {
        Stack* s = (Stack*)malloc(sizeof(Stack));
        if(s == NULL) return NULL;
        
        s->top = -1;

        return s;
}

int is_empty(Stack* s){
        if(s == NULL) return -1;
        return s->top == -1 ? 1 : 0;
}

int is_full(Stack* s){
        if(s == NULL) return -1;
        return s->top == MAX_SIZE - 1 ? 1 : 0;
}

int push(Stack* s, int info) {
        if(s == NULL) return -1;

        if(is_full(s)) return 0;

        s->top++;
        s->elements[s->top] = info;

        return 1;
}

int pop(Stack* s, int* pop) {
        if(s == NULL) return -1;
        if(is_empty(s)) return 0;

        if(pop != NULL){
		*(pop) = s->elements[s->top];
	}
        s->elements[s->top] = 0; //opcional
        s->top--;

        return 1;
}

int stack_top(Stack* s) {
        if(s == NULL || is_empty(s)) return -1;
        return s->elements[s->top];
}

void print_stack(Stack* s){
        if(s == NULL) return;
        for(int i = s->top; i >= 0; i--){
                printf("%d\n", s->elements[i]);
        }
        printf("\n");
        return;
}

int main(){
        
        Stack* s = create_stack();
        
        printf("%s", is_empty(s) ? "Está vazia\n" : "Não está vazia\n");
        printf("%s", is_full(s) ? "Está cheia\n" : "Não está cheia\n");
        
        for(int i = 0; i < 5; i++){
            push(s, i * 5);
            print_stack(s);
        }
        
        printf("%s", is_empty(s) ? "Está vazia\n" : "Não está vazia\n");
        printf("%s", is_full(s) ? "Está cheia\n" : "Não está cheia\n");
        
        for(int i = 0; i < 5; i++){
            pop(s, NULL);
            print_stack(s);
        }

        printf("%s", is_empty(s) ? "Está vazia\n" : "Não está vazia\n");
        printf("%s", is_full(s) ? "Está cheia\n" : "Não está cheia\n");
        
        free(s);
        
        return 0;
}