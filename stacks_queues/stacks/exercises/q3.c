#include <stdio.h>
#include <stdlib.h>
#include "include/stack/stack.h"

#define MAX_SIZE 100

typedef struct stack{
        char values[100];
        int top;
}Stack;

char* invert_string(char* str){
        Stack* s = create_stack();
        char inverted[MAX_SIZE];
        for(int i = 0; str[i] != '\0'; i++){
                stack_push(s, str[i]);
        }
        for(int i = 0; inverted[i] != '\0'; i++){
                inverted = stack_pop(s);
        }
        return inverted;
}

int is_palindrome(char* str) {
        char* inverted = invert_string(srt);

        for(int i = 0; i != '\0'; i++){
                if(str[i] != inverted[i]){
                        return 0;
                }
        }
        return 1;
}

int is_expr_valid(char* expr){
        Stack* s = create_stack();
        for(int i = 0; i != '\0'; i++){
                if(expr[i] == '('){
                        stack_push(s, expr[i])
                }
                if(expr[i] == ')'){
                        if(stack_top(s) == '('){
                                stack_pop();
                        }
                }
        }
        return stack_is_empty(s);
}