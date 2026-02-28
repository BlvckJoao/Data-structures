#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct stack {
        int* values;
        int top;
        int max;
}Stack;

Stack* stack_create(){
        Stack* s = (Stack*)malloc(sizeof(Stack));
        if(!s) return NULL;

        s->max = STACK_SIZE;
        s->values = (int*)malloc(sizeof(int) * STACK_SIZE);
        s->top = -1;
        
        return s;
}

void stack_free(Stack** ps){
    if(ps == NULL || *ps == NULL) return;

    free((*ps)->values);
    free(*ps);
    *ps = NULL;
}

int stack_is_full(Stack* s){
	if(s == NULL) return -1;

	if(s->top == s->max - 1) return 1;
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
		s->max *= 2;

                int* temp = realloc(s->values, s->max * sizeof(int));
                if(temp == NULL) return -1;
                s->values = temp;
	}

	s->top++;
	s->values[s->top] = info;

	return 1;
}

int stack_pop(Stack *s, int* pop_value) {
        if(s == NULL) return -1;
	if(stack_is_empty(s)) return 0;

	if(pop_value != NULL){
		*(pop_value) = s->values[s->top];
	}
	s->values[s->top] = 0;
	s->top--;

        if(s->top + 1 <= s->max / 4 && s->max > STACK_SIZE){
                s->max /= 2;

                int* temp = realloc(s->values, s->max * sizeof(int));
                if(temp == NULL) return -1;
                s->values = temp;
        }

	return 1;
}

int stack_top(Stack* s){
	if(s == NULL) return -1;
	return s->values[s->top];
}