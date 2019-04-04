#include "pch.h"
#include <iostream>
#include<stdlib.h>
#define MAX 50
using namespace std;
typedef struct eee {
	char x;
	struct eee *lchild;
	struct eee *rchild;
	int tr;
}jie;
typedef struct www {
	jie *data[MAX];
	int  top;
}zhan;
zhan *creats();
int emptys(zhan *t);
int fulls(zhan *t);
void pushs(zhan *t, jie *x);
void pops(zhan *t);
jie* gtops(zhan *t);
jie* creatk();
void xian(jie *t);
void zhong(jie *t);
void hou(jie *t);
zhan *creats()
{
	zhan *s;
	s = (zhan*)malloc(sizeof(zhan));
	s->top = 0;
	return s;
}
int emptys(zhan *t)
{
	return t->top == 0;
}
int fulls(zhan *t)
{
	return t->top == MAX;
}
void pushs(zhan *t, jie *x)
{
	if (fulls(t))
		cout << "over flow" << endl;
	else
		t->data[t->top++] = x;
	return;
}
void pops(zhan *t)
{
	if (emptys(t))
		cout << "under flow" << endl;
	else
		t->top--;
	return;
}
jie* gtops(zhan *t)
{
	return t->data[t->top - 1];
}
int main()
{
	jie *s;
	int n;
	s = creatk();
	cout << "1，先序   2，中序   3，后序	";
	cin >> n;
	cout << endl;
	switch (n) {
	case 1:xian(s);
	case 2:zhong(s);
	case 3:	hou(s);
	}
	return 0;
}
jie* creatk()
{
	char c;
	jie *k;
	cin >> c;
	if (c == '#')
		k = nullptr;
	else {
		k = (jie*)malloc(sizeof(jie));
		k->x = c;
		k->lchild = creatk();
		k->rchild = creatk();
	}
	return k;
}
void xian(jie *t)
{
	zhan *p;
	p = creats();
	if (t == nullptr)
		return;
	do {
		while (t) {
			cout << t->x;
			if (t->rchild)
				pushs(p, t->rchild);
			t = t->lchild;
		}
		if (!emptys(p)) {
			t = gtops(p);
			pops(p);
		}
	} while (!emptys(p)||p);
	return;
}
void zhong(jie *t)
{
	zhan *p;
	p = creats();
	if (t == nullptr)
		return;
	do {
		while (t) {
			pushs(p, t);
			t = t->lchild;
		}
		if (!emptys(p)) {
			t = gtops(p);
			pops(p);
			cout << t->x;
			t = t->rchild;
		}
	} while (!emptys(p) || p);
	return;
}
void hou(jie *t)
{
	zhan *p;
	p = creats();
	if (t == nullptr)
		return;
	do {
		while (t) {
			t->tr = 0;
			pushs(p, t);
			t = t->lchild;
		}
		while (!emptys(p)) {
			t = gtops(p);
			if (t->tr == 1) {
				cout << t->x;
				pops(p);
			}
			else
				break;
		}
		if (!emptys(p)) {
			t = gtops(p);
			pops(p);
			t->tr = 1;
			pushs(p, t);
			t = t->rchild;
		}
	} while (!emptys(p));
	return;
}