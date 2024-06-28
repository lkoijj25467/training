#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

void initQueue(Queue* q){
    q->head = 0;
    q->tail = 0;
    q->size = 0;
}

void enqueue(Queue* q, void* data){
    if(q->size == MAX_SIZE){
        return;
    }
    q->members[q->tail] = data;
    q->tail = (q->tail + 1) % MAX_SIZE;
    q->size++;
}

void* dequeue(Queue* q){
    if(q->size == 0)
        return NULL;
    
}