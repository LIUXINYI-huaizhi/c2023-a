#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int count;
    int size;
} Stack;

Stack *create_stack(int size);

bool is_empty(Stack *);

void stack_push(Stack *s, int value);

bool is_full(Stack *s);

int stack_pop(Stack *s);

int main() {
    Stack *stack = create_stack(3);
    assert(is_empty(stack));
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);

    assert(is_full(stack));

    int x = stack_pop(stack);
    assert(x == 3);
    assert(stack_pop(stack) == 2);
    assert(stack_pop(stack) == 1);
    assert(is_empty(stack));
}

int stack_pop(Stack *s) {
    return s->data[--s->count];
}

bool is_full(Stack *s) {
    return s->count == s->size;
}

void stack_push(Stack *s, int value) {
    s->data[s->count++] = value;
}

Stack *create_stack(int size) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->count = 0;
    s->size = size;
    s->data = (int *) malloc(size * sizeof(int));
    return s;
}

bool is_empty(Stack *s) {
    return s->count == 0;
}
//
// Created by 27775 on 2023/10/17.
//
