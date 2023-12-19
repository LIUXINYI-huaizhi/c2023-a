#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue{
    int* data;
    int* head;
    int* tail;
    unsigned size;
} Queue;

void forward(Queue *q, int *d);

bool is_empty(Queue* q){
    return q->head==q->tail;
}

bool is_full(Queue* q){
//    return (q->data + (q->tail - q->data + 1) % (q->size + 1)) == q->head;
    return q->head-q->tail==1 || q->tail-q->head==q->size;
}

Queue* create_queue(unsigned size){
    Queue* q = (Queue *)malloc(sizeof(Queue));
    q->data = q->head = q->tail = (int*) malloc((size + 1) * sizeof(int));
    q->size = size;
    return q;
}

int* forward(Queue *q, int *d) {
    q->data + (d+1 - q->data) % (q->size + 1);
}

bool queue_append(Queue* q, int val){
    if(is_full(q))return false;
    *(q->tail) = val;
    q->tail = forward(q, q->tail);
    return true;
}

int queue_pop(Queue* q){
    if(is_empty(q))return -1;
    int val = *(q->head);
    q->head = q->data + (q->head - q->data) % (q->size + 1);
    return val;
}


int main(){
    Queue* queue=create_queue(3);//实现上最后一个元素是“哨兵”,避免head==tail无法判断空满
    assert(is_empty(queue));
    queue_append(queue, 1);
    queue_append(queue, 2);
    queue_append(queue, 3);

    assert(is_full(queue));

    int x=queue_pop(queue);
    assert(queue_pop(queue)==2);
    assert(queue_pop(queue)==3);
    assert(is_empty(queue));
}