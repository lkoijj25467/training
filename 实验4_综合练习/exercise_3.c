#include<stdio.h>
#include<stdlib.h>

#define SIZE 0xFF
typedef struct _queue {
	int tail;
	int head;
	int size;
	int data[SIZE];
}Queue;

typedef struct _stack {
	int data[0xFF];
	int size;
	int top;
}Stack;

void initStack(Stack* stack) {
	stack->top = -1;
	stack->size = 0;
}

void push(Stack* s, int n) {
	s->top++;
	s->data[s->top] = n;
	s->size++;
}

int pop(Stack* s) {
	int pop = s->data[s->top];
	s->top--;
	s->size--;
	return pop;
}

void initQueue(Queue* q) {
	q->tail = 0;
	q->head = 0;
	q->size = 0;
}

int isEmpty(Queue* q) {
	return (q->size == 0);
}

void enQueue(Queue* q, int n) {
	if (q->size < SIZE) {
		q->data[q->head] = n;
		q->head = (q->head + 1) % SIZE;
		q->size++;
	}
}

void delQueue(Queue* q, int n) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	initStack(s);
	while (q->data[q->tail] != n && q->tail != (q->head)) {
		push(s, q->data[q->tail]);
		q->tail = (q->tail + 1) % SIZE;
	}
	if (q->data[q->tail] == n) {
		q->size--;
		while (s->size > 0) {
			q->data[q->tail] = pop(s);
			q->tail = (q->tail - 1) % SIZE;
		}
		q->tail = (q->tail + 1) % SIZE;
	}
	else {
		while (s->size > 0) {
			q->tail = (q->tail - 1) % SIZE;
			q->data[q->tail] = pop(s);
		}
	}
	//q->size--;
	free(s);
}

int main() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	initQueue(q);
	for (int i = 0; i <= 128; i++)
		enQueue(q, i);
	delQueue(q, 9);
	delQueue(q, 127);
	delQueue(q, 128);
	delQueue(q, 256);
	for (int tail = q->tail; tail != q->head; tail = (tail + 1) % SIZE)
		printf("%d ", q->data[tail]);
	system("pause");
}
