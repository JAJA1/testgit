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
//表示对遍历到的结点数据进行的处理操作,此处操作是将树结点前序遍历输出
void operation1(ElemType ch)
{
	cout << ch << " ";
}
//递归方式前序遍历二叉树
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	operation1(T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//递归方式中序遍历二叉树

void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	operation1(T->data);
	InOrderTraverse(T->rchild);
}

//递归方式后序遍历二叉树

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
	cout << "请以前序遍历的方式输入扩展二叉树："; 
	CreateBiTree(&T);
	cout << "递归前序遍历输出为：" << endl;
	PreOrderTraverse(T);
	cout << endl;
	cout << "递归中序遍历输出为：" << endl;
	InOrderTraverse(T);
	cout << endl;
	cout << "递归后序遍历输出为：" << endl;
	PostOrderTraverse(T);
	cout << endl;
	return 0;
}