#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct _nodeList {
	int size;
	int hash[0xFFFF];
	int data[0xFFFF];
}NodeList;

void init(NodeList* list) {
	list->size = 0;
	for (int i = 0; i < 0xFFFF; i++)
		list->hash[i] = 0;
}
void insert(NodeList* list, int n) {
	if (list->hash[n] != 0) {
		return;
	}
	list->hash[n] = n;
	if (list->size == 0) {
		list->size++;
		list->data[0] = n;
		return;
	}
	else {
		for (int i = 0; i < list->size; i++) {
			if (n < list->data[i]) {
				for (int j = list->size; j > i; j--) {
					list->data[j] = list->data[j - 1];
				}
				list->data[i] = n;
				list->size++;
				return;
			}
		}
		list->data[list->size] = n;
		list->size++;
		return;
	}
}

int main() {
	NodeList* list1 = (NodeList*)malloc(sizeof(NodeList));
	NodeList* list2 = (NodeList*)malloc(sizeof(NodeList));
	NodeList* list3 = (NodeList*)malloc(sizeof(NodeList));
	init(list1); init(list2); init(list3);
	srand(time(NULL));
	int n;
	for (int i = 0; i < 0xFF; i++) {
		n = rand() % 1000 + 1;
		insert(list1, n);
	}
	printf("list1: ");
	for (int i = 0; i < list1->size; i++) {
		printf("%d ", list1->data[i]);
	}
	printf("\n");
	for (int i = 0; i < 0xFF; i++) {
		n = rand() % 1000 + 1;
		insert(list2, n);
	}
	printf("list2: ");
	for (int i = 0; i < list2->size; i++) {
		printf("%d ", list2->data[i]);
	}
	printf("\n");

	for (int i = 0; i < list1->size; i++) {
		if (list2->hash[list1->data[i]] != 0)
			insert(list3, list1->data[i]);
	}
	printf("list3: ");
	for (int i = 0; i < list3->size; i++) {
		printf("%d ", list3->data[i]);
	}
	system("pause");
}