#include <stdio.h>
#include <stdlib.h>
#include "include/queue/queue.h"

void queue_combine(Queue* q1, Queue* q2, Queue* rst){
        float temp;
                
        while(!queue_is_empty(q1) && !queue_is_empty(q2)){
                queue_insert(rst, queue_remove(q1));
                queue_insert(rst, queue_remove(q2));
        }

        while(!queue_is_empty(q1)){
                queue_insert(rst, queue_remove(q1));
        }

        while(!queue_is_empty(q2)){
                queue_insert(rst, queue_remove(q2));
        }
        return;
}