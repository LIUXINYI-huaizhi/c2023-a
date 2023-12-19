#include<assert.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct stack{

};






































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