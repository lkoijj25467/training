#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

typedef struct BinNode_ {
	char word;
	int weigh;
	char* code;
	struct BinNode_* lchild;
	struct BinNode_* rchild;
}BinNode;

void pause(){
	char c;
	c = getchar();
	return;
}
BinNode* queue[0xFF];
int size = 0;
void init(BinNode* node) {
	node->lchild = NULL;
	node->rchild = NULL;
	node->code = (char*)malloc(sizeof(char) * 0xFF);
	strcpy(node->code, "");
}
void del(int idx) {
	for (int i = idx + 1; i <= size - 1; i++) {
		queue[i - 1] = queue[i];
	}
	size--;
}
void insert(BinNode* binNode) {
	if (size == 0) {
		queue[size] = binNode;
		size++;
		return;
	}
	for (int i = 0; i <= size - 1; i++) {
		if (binNode->weigh < queue[i]->weigh) {
			for (int j = size; j >= i + 1; j--) {
				queue[j] = queue[j - 1];
			}
			queue[i] = binNode;
			size++;
			return;
		}
	}
	queue[size] = binNode;
	size++;
}
//��queue������Ϊl��r��������ȡ�����ϲ���һ���µ���
BinNode* createTree(int l, int r) {
	int sum = queue[l]->weigh + queue[r]->weigh;
	BinNode* root = (BinNode*)malloc(sizeof(BinNode));
	init(root);
	root->lchild = queue[l];
	root->rchild = queue[r];
	root->weigh = sum;
	root->word = '#';
	insert(root);
	del(0);
	del(0);
	return root;
}
void preorder(BinNode* root) {
	if (root->word != '#') {
		printf("%c : %s\n", root->word, root->code);
		return;
	}
	if (root->lchild != NULL) {
		strcat(root->lchild->code, root->code);
		strcat(root->lchild->code, "0");
		preorder(root->lchild);
	}
	if (root->rchild != NULL) {
		strcat(root->rchild->code, root->code);
		strcat(root->rchild->code, "1");
		preorder(root->rchild);
	}
}

int main() {
	//create the tree
	char word[100];
	int freq[100];
	int N = 0; 
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %c", &word[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf(" %d", &freq[i]);
	}
	for (int i = 0; i < N; i++) {
		BinNode* node = (BinNode*)malloc(sizeof(BinNode));
		init(node);
		node->weigh = freq[i];
		node->word = word[i];
		insert(node);
	}
	while (size > 1) {
		createTree(0, 1);
	}
	BinNode* haffmanRoot = queue[0];
	preorder(haffmanRoot);
	system("pause");
}

