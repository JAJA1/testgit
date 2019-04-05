
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef  struct zaoshu
{
	char data;
	struct zaoshu *lchild, *rchild;
} zaoshu, *bitree;
void createbitree(bitree *T);
void preordertraverse(bitree T, int shudecengji);
void inordertraverse(bitree T, int shudecengji);
void postordertraverse(bitree T, int shudecengji);

void createbitree(bitree *T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (bitree)malloc(sizeof(zaoshu));
		(*T)->data = ch;               //生成结点
		createbitree(&(*T)->lchild);//构造左子树
		createbitree(&(*T)->rchild);//构造右子树    
	}
}


//递归方式前序遍历二叉树
void preordertraverse(bitree T, int shudecengji)
{
	if (T == NULL)
		return;


	cout << T->data << " ";
	cout << T->data << "第" << shudecengji << "层" << endl;

	preordertraverse(T->lchild, shudecengji + 1);
	preordertraverse(T->rchild, shudecengji + 1);
}

//递归方式中序遍历二叉树

void inordertraverse(bitree T, int shudecengji)
{
	if (T == NULL)
		return;
	inordertraverse(T->lchild, shudecengji + 1);

	cout << T->data << " ";
	cout << T->data << "第" << shudecengji << "层" << endl;

	inordertraverse(T->lchild, shudecengji + 1);
	(T->rchild, shudecengji + 1);
}

//递归方式后序遍历二叉树

void postordertraverse(bitree T, int shudecengji)
{
	if (T == NULL)
		return;
	postordertraverse(T->lchild, shudecengji + 1);
	postordertraverse(T->rchild, shudecengji + 1);

	cout << T->data << " ";
	cout << T->data << "第" << shudecengji << "层" << endl;
}

int main()
{
	int shudecengji = 1;                                   //层数
	bitree T = NULL;
	cout << "前序输入二叉树：";           //输入AB#D##C##
	createbitree(&T);

	cout << "前序：" << endl;
	preordertraverse(T, shudecengji);
	cout << endl;

	cout << "中序：" << endl;
	inordertraverse(T, shudecengji);
	cout << endl;

	cout << "后序：" << endl;
	postordertraverse(T, shudecengji);
	cout << endl;

	return 0;
}
