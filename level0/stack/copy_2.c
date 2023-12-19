//
// Created by 27775 on 2023/10/24.
//
#include "stack.h"

bool is_full(Stack *stack) {
    return stack->sp == stack->bp + stack->size - 1;
}

bool is_empty(Stack *stack) {
    return stack->sp == NULL;
}

double pop(Stack *stack) {
    assert(!is_empty(stack));//pop with an empty stack
    double res = *(stack->sp);
    if (stack->sp == stack->bp) {
        stack->sp = NULL;
        return res;

    }
    stack->sp--;
    return res;
}


void push(Stack *stack, double x) {
    if (stack->sp == NULL) {
        stack->sp = stack->bp;
        *stack->sp = x;
        return;
    }
    assert(!is_full(stack));//push in a full stack
    stack->sp++;
    *(stack->sp) = x;
}

Stack *create_stake(int size) {
    static Stack new_stack;
    new_stack.bp = malloc(sizeof(int) * size);
    new_stack.sp = NULL;
    new_stack.size = size;
    return &new_stack;
}
