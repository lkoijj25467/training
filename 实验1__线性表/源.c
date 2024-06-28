#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ListNode {
	char* name;
	char* street;
	char* city;
	char* country;
	int tel;
	struct ListNode* next;
	struct ListNode* pre;
	int isEnd;
}Node;

void init(Node* node) {
	node->name = (char*)malloc(sizeof(char) * 0xFFFF);
	node->street = (char*)malloc(sizeof(char) * 0xFFFF);
	node->city = (char*)malloc(sizeof(char) * 0xFFFF);
	node->country = (char*)malloc(sizeof(char) * 0xFFFF);
	node->tel = 0;
	node->next = NULL;
	node->pre = NULL;
	node->isEnd = 0;
}

Node* search(char* name, Node* list) {
	Node* ptr = list;
	while (ptr->isEnd != 1) {
		if (strcmp(name, ptr->name) == 0) {
			return ptr;
		}
		else {
			ptr = ptr->next;
		}
	}
	return NULL;
}

void append(Node* target, Node* list) {
	Node* end = list;
	while (end->isEnd != 1) {
		end = end->next;
	}
	if (end->pre != NULL) {
		end->pre->next = target;
		target->pre = end->pre;
		target->next = end;
		end->pre = target;
		return;
	}
	else {
		list->city = target->city;
		list->country = target->country;
		list->name = target->name;
		list->street = target->street;
		list->tel = target->tel;
		list->isEnd = 0;
		Node* newEnd = (Node*)malloc(sizeof(Node));
		init(newEnd);
		newEnd->isEnd = 1;
		newEnd->pre = list;
		list->next = newEnd;
		list->pre = NULL;
	}
}

void del(Node* target, Node* list) {
	if (list->isEnd == 1) {
		printf("Erro\n");
		return;
	}
	if (target->pre != NULL) {
		target->pre->next = target->next;
		target->next->pre = target->pre;
		free(target);
		return;
	}
	else {
		list = list->next;
		free(list->pre);
		list->pre = NULL;
		return;
	}
}

Node* createList(Node* head) {
	Node* list = head;
	head->next = (Node*)malloc(sizeof(Node));
	init(head->next);
	head->next->isEnd = 1;
	head->next->pre = head;
	return list;
}

void show(Node* node) {
	if (node == NULL) {
		printf("Erro\n");
		return;
	}
	printf("name: %s\n", (node->name));
	printf("street: %s\n", (node->street));
	printf("city: %s\n", (node->city));
	printf("country: %s\n", (node->country));
	printf("tel : %d\n", node->tel);
}

void menu() {
	printf("1:search\n2:input\n3:del\n4:output\n5:append\n6:quit\n");
	return;
}

void input(Node* list) {
	FILE* f = fopen("input.txt", "a+");
	if (feof(f)) {
		return;
	}
	while (!feof(f)) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		init(newNode);
		fscanf(f, "%s", newNode->name);
		fscanf(f, "%s", newNode->street);
		fscanf(f, "%s", newNode->city);
		fscanf(f, "%s", newNode->country);
		fscanf(f, "%d", &(newNode->tel));
		append(newNode, list);
	}
	if (f != NULL)
		fclose(f);
	return list;
}

void output(Node* list) {
	FILE* f = fopen("input.txt", "w");
	Node* ptr = list;
	while (ptr->isEnd != 1) {
		fprintf(f, "%s ", ptr->name);
		fprintf(f, "%s ", ptr->street);
		fprintf(f, "%s ", ptr->city);
		fprintf(f, "%s ", ptr->country);
		fprintf(f, "%d", ptr->tel);
		fprintf(f, "\n");
		ptr = ptr->next;
	}
	fclose(f);
	return;
}

int main() {
	Node* mainList = (Node*)malloc(sizeof(Node));
	init(mainList);
	mainList->isEnd = 1;
	strcpy(mainList->name, "end");
	int choice = 0;
	while (1) {
		menu();
		scanf("%d", &choice);
		if (choice == 1) {
			if (mainList != NULL) {
				char* name = (char*)malloc(sizeof(char)*0xFFFFF);
				scanf("%s", name);
				Node* n = search(name, mainList);
				show(n);
			}
			else {
				printf("Please input information fist.\n");
			}
		}
		else if (choice == 2) {
			input(mainList);
		}
		else if (choice == 3) {
			char* name = (char*)malloc(sizeof(char) * 0xFFFFF);			
			scanf("%s", name);
			if (search(name, mainList) != NULL) {
				del(search(name, mainList), mainList);
			}
			else {
				printf("Nobody found.\n");
			}
		}
		else if (choice == 4) {
			if (mainList != NULL) {
				output(mainList);
			}
			else {
				printf("Please input information first.\n");
			}
		}
		else if (choice == 5) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			init(newNode);
			scanf("%s", newNode->name);
			scanf("%s", newNode->street);
			scanf("%s", newNode->city);
			scanf("%s", newNode->country);
			scanf("%d", &(newNode->tel));
			append(newNode, mainList);
		}
		else if(choice == 6) {
			return 0;
		}
		else {
			continue;
		}
	}

}