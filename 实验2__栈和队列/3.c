#include<stdio.h>
#include<stdlib.h>

#define MAX 20
typedef struct queue {
	int data[MAX];
	int head;
	int tail;
	int isFull;
}Queue;

void pause(){
	int i;
	scanf("%d", &i);
}

void init(Queue* q) {
	q->head = 0;
	q->tail = 0;
	q->isFull = 0;
}

int isEmpty(Queue* q) {
	if (!q->isFull && q->head == q->tail) {
		return 1;
	}
	else {
		return 0;
	}
}

int pop(Queue* q) {
	if (!q->isFull && q->tail == q->head) {
		printf("Empty\n");
		return -1;
	}
	else {
		int res = q->data[q->head];
		q->data[q->head] = 0;
		q->head = (q->head + 1) % MAX;
		if (q->isFull) {
			q->isFull = 0;
		}
		return res;
	}
}

int insert(Queue* q, int n) {
	if (!q->isFull) {
		q->data[q->tail] = n;
		q->tail = (q->tail + 1) % MAX;
		if (q->tail == q->head) {
			q->isFull = 1;
		}
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	Queue q;
	init(&q);
	int i = 1;
	while (1) {
		if (q.isFull)
			break;
		insert(&q, i);
		i++;
		if (q.isFull)
			break;
		insert(&q, i);
		printf("%d*", pop(&q));
	}
	while (!isEmpty(&q)) {
		printf("%d#", pop(&q));
	}
	pause();
}