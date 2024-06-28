#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 0xFFFF
typedef struct Stack_ {
	char operators[MAX];
	int nums[MAX];
	int top;
}Stack;

void pause(){
	int i;
	scanf("%d", &i);
}

void init(Stack* s) {
	s->top = -1;
	return;
}

void insert_num(Stack* s, int num) {
	s->top++;
	s->nums[s->top] = num;
	return;
}

void insert_operator(Stack* s, char operator) {
	s->top++;
	s->operators[s->top] = operator;
	return;
}


int pop_num(Stack* s) {
	if (s->top != -1) {
		s->top--;
		return (int)(s->nums[s->top + 1]);
	}
	else {
		return -1;
	}
}

char pop_operator(Stack* s) {
	if (s->top != -1) {
		s->top--;
		return (char)(s->operators[s->top + 1]);
	}
	else {
		return -1;
	}
}

int peek_num(Stack* s) {
	if (s->top != -1) {
		return s->nums[s->top];
	}
	return -1;
}

char peek_operator(Stack* s) {
	if (s->top != -1) {
		return s->operators[s->top];
	}
	return -1;
}

int a2i(char c) {
	return c - '0';
}

int main() {
	char* input = (char*)malloc(sizeof(char) * 0xFFFFF);
	scanf("%s", input);
	Stack stack_nums;
	Stack stack_operators;
	init(&stack_nums);
	init(&stack_operators);
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] <= '9' && input[i] >= '0') {
			insert_num(&stack_nums, a2i(input[i]));
		}
		else {
			if (input[i] == '+' || input[i] == '-') {
				if (stack_operators.top != -1) {
					if (stack_operators.operators[stack_operators.top] == '*') {
						int A = pop_num(&stack_nums);
						int B = pop_num(&stack_nums);
						insert_num(&stack_nums, A * B);
						pop_operator(&stack_operators);
						insert_operator(&stack_operators, input[i]);
					}
					else if (stack_operators.operators[stack_operators.top] == '/') {
						int A = pop_num(&stack_nums);
						int B = pop_num(&stack_nums);
						insert_num(&stack_nums, A / B);
						pop_operator(&stack_operators);
						insert_operator(&stack_operators, input[i]);
					}
					else {
						insert_operator(&stack_operators, input[i]);
					}
				}
				else {
					insert_operator(&stack_operators, input[i]);
				}
			}
			else {
				insert_operator(&stack_operators, input[i]);
			}
		}
	}
	while (stack_nums.top != 0){
		if (peek_operator(&stack_operators) == '+') {
			int A = pop_num(&stack_nums);
			int B = pop_num(&stack_nums);
			insert_num(&stack_nums, A + B);
			pop_operator(&stack_operators);
		}
		if (peek_operator(&stack_operators) == '-') {
			int A = pop_num(&stack_nums);
			int B = pop_num(&stack_nums);
			insert_num(&stack_nums, A - B);
			pop_operator(&stack_operators);

		}
		if (peek_operator(&stack_operators) == '*') {
			int A = pop_num(&stack_nums);
			int B = pop_num(&stack_nums);
			insert_num(&stack_nums, A * B);
			pop_operator(&stack_operators);

		}if (peek_operator(&stack_operators) == '/') {
			int A = pop_num(&stack_nums);
			int B = pop_num(&stack_nums);
			insert_num(&stack_nums, A / B);
			pop_operator(&stack_operators);

		}
	}
	printf("%d", pop_num(&stack_nums));
	pause();
}
