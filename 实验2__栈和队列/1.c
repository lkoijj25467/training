#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack_ {
	char* elements;
	int top;
}Stack;

void pause(){
	int i;
	scanf("%d", &i);
}
void init(Stack *s) {
	s->elements = (char*)malloc(sizeof(char) * 0xFFFFFFF);
	s->top = -1;
}

void insert(Stack* s, char e) {
	s->top++;
	s->elements[s->top] = e;
	return;
}

void pop(Stack* s) {
	if (s->top != -1) {
		//free((char*) & (s->elements[s->top]));
		s->top--;
	}
	else {
		return;
	}
	return;
}

int main() {
	Stack s;
	init(&s);
	char* input = (char*)malloc(sizeof(char) * 0xFFFFF);
	scanf("%s", input);
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '(') {
			insert(&s, input[i]);
		}
		else if (input[i] == ')') {
			if (s.elements[s.top] == '(') {
				pop(&s);
			}
		}
	}
	if (s.top == -1) {
		printf("matched");
	}
	else {
		printf("unmatched");
	}
	
	pause();
}	
