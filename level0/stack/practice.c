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
    Stack *stack_1 = create_stack(5);
    char arr[9]={'4','1','2','+','+','3','*','2','-'};
    for(int i=0;i<=8;i++){
        if((int)arr[i]<=57&&(int)arr[i]>=48) stack_push(stack_1, (int)arr[i]-'0');
        else{
            int temp=stack_pop(stack_1);
            int ans;
            if(arr[i]=='+'){ans=temp+stack_pop(stack_1);
           }
           if(arr[i]=='-'){ans=stack_pop(stack_1)-temp;
                }
            if(arr[i]=='*'){ans=stack_pop(stack_1)*temp;
                }
            if(arr[i]=='/'){ans=stack_pop(stack_1)/temp;
                }
            stack_push(stack_1, ans);
        }
    }
    printf("%d",stack_pop(stack_1));
    return is_empty(stack_1);
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
