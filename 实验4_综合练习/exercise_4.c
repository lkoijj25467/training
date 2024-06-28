#include<stdio.h>
#include<stdlib.h>
typedef struct _BinNode {
	int data;
	struct _BinNode* lchild;
	struct _BinNode* rchild;
}BinNode;

BinNode* init() {
	return (BinNode*)malloc(sizeof(BinNode));
}
int isBinSearchTree(BinNode* root) {
	if (root->lchild != NULL && root->rchild != NULL) {
		if (root->data <= root->rchild->data && root->data >= root->lchild->data) {
			return isBinSearchTree(root->lchild) * isBinSearchTree(root->rchild);
		}
		else
			return 0;
	}
	else if (root->rchild != NULL) {
		if (root->data <= root->rchild->data) {
			return isBinSearchTree(root->rchild);
		}
		else
			return 0;
	}
	else if (root->lchild != NULL) {
		if (root->data >= root->lchild->data) {
			return isBinSearchTree(root->lchild);
		}
		else
			return 0;
	}
	else if (root->lchild == NULL && root->rchild == NULL)
		return 1;
}
 
int main() {
	BinNode* root = init();
	root->data = 8;
	root->lchild = init(); root->lchild->lchild = NULL; root->lchild->rchild = NULL;
	root->lchild->data = 6;
	root->rchild = init(); root->rchild->lchild = NULL; root->rchild->rchild = NULL;
	root->rchild->data = 9;
	BinNode* newRoot = init(); newRoot->rchild = NULL;
	newRoot->data = 1;
	newRoot->lchild = root;
	printf("%d\n", isBinSearchTree(newRoot));
	system("pause");
}
