//
// Created by 27775 on 2023/10/24.
//

#ifndef C2023_CHALLENGE_STACK_H
#define C2023_CHALLENGE_STACK_H

#endif //C2023_CHALLENGE_STACK_H
//
// Created by Cyril on 2023/10/24.
//

#ifndef PRACTICE_C_STACK_H
#define PRACTICE_C_STACK_H

#include <stdbool.h>
#include <intrin.h>
#include <assert.h>

typedef struct {
    double *bp;
    double *sp;
    unsigned size;
} Stack;

bool is_full(Stack *stack);

bool is_empty(Stack *stack);

double pop(Stack *stack);

void push(Stack *stack, double x);

Stack *create_stake(int size);



#endif //PRACTICE_C_STACK_H
