#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct stack{
	int values[STACK_SIZE];
	int top;
}Stack;

Stack* stack_create(){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if(s == NULL){
		printf("Erro ao alocar pilha");	
		return NULL;
	}
	return s;
}

void stack_free(Stack** ps){
	if(ps == NULL) return;
	free(*ps);
	ps == NULL;
	return;
}

int stack_is_full(Stack* s){
	if(s == NULL) return -1;

	if(s->top == STACK_SIZE - 1) return 1;
	return 0;
}

int stack_is_empty(Stack* s){
	if(s == NULL) return -1;

	if(s->top == -1) return 1;
	return 0;
}

int stack_size(Stack* s){
	if(s == NULL) return -1;
	return s->top + 1;
}

int stack_push(Stack* s, int info){
	if(s == NULL) return -1;

	if(stack_is_full(s)){
		return 0;
	}
	s->top++;
	s->values[s->top] = info;

	return 1;
}

int stack_pop(Stack* s, int* pop_value){
	if(s == NULL) return -1;
	if(stack_is_empty(s)) return 0;
	if(pop_value != NULL){
		*(pop_value) = s->values[s->top];
	}
	s->values[s->top] = 0;
	s->top--;
	return 1;
}

int stack_top(Stack* s){
	if(s == NULL) return -1;
	return s->values[s->top];
}
