#include<stdio.h>
#include<stdlib.h>
typedef struct _stack {
	int data[0xFF];
	int size;
	int top;
}Stack;

typedef struct _queue {
	int data[0xFF];
	int head;
	int tail;
	int size;
	int isEmpty;
}Queue;

void initStack(Stack* stack) {
	stack->top = -1;
}

void push(Stack* s, int n) {
	s->top++;
	s->data[s->top] = n;
	s->size++;
}

int pop(Stack* s) {
	int pop = s->data[s->top];
	s->top--;
	return pop;
}

void initQueue(Queue* q) {
	q->head = 0;
	q->tail = 0;
	q->size = 0;
	q->isEmpty = 1;
}

void insertQueue(Queue* q, int n) {
	if (!q->isEmpty && q->head == q->tail)
		return;
	else {
		if (q->isEmpty == 1)
			q->isEmpty = 0;
		q->data[q->head] = n;
		q->head = (q->head + 1) % 0xFF;
		q->size++;
	}
}

int popQueue(Queue* q) {
	if (q->isEmpty)
		return -1;
	else {
		int pop;
		pop = q->data[q->tail];
		q->tail = (q->tail + 1) % 0xFF;
		q->size--;
		if (q->size == 0)
			q->isEmpty = 1;
		return pop;
	}
}

int main() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	initQueue(q);
	Stack* s = (Stack*)malloc(sizeof(Stack));
	initStack(s);
	for (int i = 0; i < 99; i++) {
		insertQueue(q, i);
	}
	while (!q->isEmpty) {
		push(s, popQueue(q));
	}
	while (s->top != -1) {
		insertQueue(q, pop(s));
	}
	for (int i = q->tail; i != q->head; i = (i + 1) % 0xFF) {
		printf("%d ", q->data[i]);
	}
	system("pause");
}