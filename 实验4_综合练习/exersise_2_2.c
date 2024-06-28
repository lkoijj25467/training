#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
	struct _node* pre;
}Node;

typedef struct _list {
	Node* head;
	Node* root;
	int isEmpty;
	int size;
}List;

void initList(List* list) {
	list->size = 0;
	list->isEmpty = 1;
	list->head = NULL;
	list->root = (Node*)malloc(sizeof(Node));
	list->root->data = NULL;
	list->root->next = NULL;
	list->root->pre = NULL;
}
void insert(List* list, int n) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->pre = NULL;
	newNode->data = n;
	if (list->isEmpty) {
		list->root->next = newNode;
		newNode->pre = list->root;
		list->head = newNode;
		list->size++;
		list->isEmpty = 0;
	}
	else {
		list->head->next = newNode;
		newNode->pre = list->head;
		list->head = newNode;
		list->size++;
	}
}

void reverse(List* list) {
	Node* i = list->root->next;
	Node* j = list->head;
	int temp;
	while (1) {
		temp = i->data;
		i->data = j->data;
		j->data = temp;
		i = i->next;
		j = j->pre;
		if (i == j)
			return;
		if (i->pre == j || j->next == i)
			return;
	}
}

int main() {
	List* list = (List*)malloc(sizeof(List));
	initList(list);
	for (int i = 0; i < 10; i++)
		insert(list, i);
	reverse(list);
	for (Node* ptr = list->root->next; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->data);
	system("pause");
}
