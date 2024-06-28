#ifndef QUEUE_H
#define QUEUE_H
#define MAX_SIZE 0xFFF

typedef struct{
    void* members[MAX_SIZE];
    int head;
    int tail;
    int size;
}Queue;

void initQueue(Queue* q);

void enqueue(Queue* q, void* data);

typedef struct{
    void* members[MAX_SIZE];
    int head;
    int tail;
    int size;
}Stack;




typedef struct{
    void* data;
    Node* next;
}Node;

#endif // QUEUE_H