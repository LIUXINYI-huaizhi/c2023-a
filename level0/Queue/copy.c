#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue{
    int* arr;
    int* head;
    int* tail;
    unsigned size;
} Queue;

bool is_empty(Queue* q){
    return q->head==q->tail;
}

bool is_full(Queue* q){
    return (q->arr+(q->tail-q->arr+1)%q->size)==q->head;
}

Queue* create_queue(unsigned size){
    Queue* q = (Queue *)malloc(sizeof(Queue));
    q->arr = q->head = q->tail = (int*) malloc((size+1)*sizeof(int));
    q->size = size+1;
    return q;
}

bool queue_append(Queue* q, int val){
    if(is_full(q))return false;
    *(q->tail++) = val;
    q->tail = q->arr+(q->tail-q->arr)%q->size;
    return true;
}

int queue_pop(Queue* q){
    if(is_empty(q))return -1;
    int val = *(q->head++);
    q->head = q->arr+(q->head-q->arr)%q->size;
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