#include <stdio.h>
#include <stdlib.h>
#include "include/stack/stack.h"

#define SIZE 100

float top(Stack* s) {
        float top_value = stack_pop(p)
        stack_push(p, top_value);
        return top_value;
}

void transfer(Stack* s1, Stack* s2) {
        float temp[SIZE];
        int i = 0;
        while(s2->top != -1){
                temp[i] = stack_pop(s2);
                i++;
        }
        for(size_t j = 0; j < i + 1; j++){
                stack_push(s1, temp[i-j]);
        }
}

Stack* stack_copy(Stack* s){
    Stack* copy = stack_create();
    Stack* aux = stack_create();
    float temp;

    while(!stack_is_empty(s)){
        stack_push(aux, stack_pop(s));
    }

    while(!stack_is_empty(aux)){
        temp = stack_pop(aux);
        stack_push(s, temp);
        stack_push(copy, temp);
    }

    return copy;
}