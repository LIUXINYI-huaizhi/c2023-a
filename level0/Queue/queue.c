#include<stdio.h>
void queue_append(int array[],int append){
    for (int i=0;i=sizeof(array)/sizeof(array[0]);i++){
        if(array[i]==0){
            int tail=i;
            array[tail+1]=append;
        }
    }
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

