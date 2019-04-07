#include<iostream>
#include<stdlib.h>
using namespace std;
typedef char ElemType;
typedef  struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void CreateBiTree(BiTree *T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#')
		*T = NULL; 
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);   
	}
}
//��ʾ�Ա������Ľ�����ݽ��еĴ������,�˴������ǽ������ǰ��������
void operation1(ElemType ch)
{
	cout << ch << " ";
}
//�ݹ鷽ʽǰ�����������
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	operation1(T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//�ݹ鷽ʽ�������������

void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	operation1(T->data);
	InOrderTraverse(T->rchild);
}

//�ݹ鷽ʽ�������������

void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	operation1(T->data);
}


int main()
{
	BiTree T = NULL;
	cout << "����ǰ������ķ�ʽ������չ��������"; 
	CreateBiTree(&T);
	cout << "�ݹ�ǰ��������Ϊ��" << endl;
	PreOrderTraverse(T);
	cout << endl;
	cout << "�ݹ�����������Ϊ��" << endl;
	InOrderTraverse(T);
	cout << endl;
	cout << "�ݹ����������Ϊ��" << endl;
	PostOrderTraverse(T);
	cout << endl;
	return 0;
}