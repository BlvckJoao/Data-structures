#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct stack Stack;

Stack* stack_create();
void stack_free(Stack** s);
int stack_is_full(Stack* s);
int stack_is_hollow(Stack* s);
int stack_size(Stack* s);
int stack_push(Stack* s, int info);
int stack_pop(Stack* s, int* rm_value);
int stack_top(Stack* s);

#endif
