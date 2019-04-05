
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
		(*T)->data = ch;               //���ɽ��
		createbitree(&(*T)->lchild);//����������
		createbitree(&(*T)->rchild);//����������    
	}
}


//�ݹ鷽ʽǰ�����������
void preordertraverse(bitree T, int shudecengji)
{
	if (T == NULL)
		return;


	cout << T->data << " ";
	cout << T->data << "��" << shudecengji << "��" << endl;

	preordertraverse(T->lchild, shudecengji + 1);
	preordertraverse(T->rchild, shudecengji + 1);
}

//�ݹ鷽ʽ�������������

void inordertraverse(bitree T, int shudecengji)
{
	if (T == NULL)
		return;
	inordertraverse(T->lchild, shudecengji + 1);

	cout << T->data << " ";
	cout << T->data << "��" << shudecengji << "��" << endl;

	inordertraverse(T->lchild, shudecengji + 1);
	(T->rchild, shudecengji + 1);
}

//�ݹ鷽ʽ�������������

void postordertraverse(bitree T, int shudecengji)
{
	if (T == NULL)
		return;
	postordertraverse(T->lchild, shudecengji + 1);
	postordertraverse(T->rchild, shudecengji + 1);

	cout << T->data << " ";
	cout << T->data << "��" << shudecengji << "��" << endl;
}

int main()
{
	int shudecengji = 1;                                   //����
	bitree T = NULL;
	cout << "ǰ�������������";           //����AB#D##C##
	createbitree(&T);

	cout << "ǰ��" << endl;
	preordertraverse(T, shudecengji);
	cout << endl;

	cout << "����" << endl;
	inordertraverse(T, shudecengji);
	cout << endl;

	cout << "����" << endl;
	postordertraverse(T, shudecengji);
	cout << endl;

	return 0;
}
