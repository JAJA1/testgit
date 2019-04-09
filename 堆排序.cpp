// ConsoleApplication45.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
using namespace std;

typedef struct
{
	int length;
	int r[66];
}SqList;

void HeapAdjust(SqList *L, int s, int len)
{
	int temp;
	temp = L->r[s];
	for (int i = 2 * s; i <= len; i *= 2) //沿关键字较大的孩子结点向下筛选
	{
		if (i < len&&L->r[i] < L->r[i + 1])
			i++;                          //i为关键字中较大的记录的下标
		if (temp > L->r[i])
			break;
		L->r[s] = L->r[i];
		s = i;
	}
	L->r[s] = temp;
}

void swap(SqList *L, int m, int i)  //交换函数

{
	int temp;
	temp = L->r[m];
	L->r[m] = L->r[i];
	L->r[i] = temp;
}

void HeapSort(SqList *L)
{
	int i;
	int len = L->length;
	for (i = len / 2; i > 0; i--)
		HeapAdjust(L, i, len);   //把r构成一个大顶堆
	for (i = len; i > 0; i--)
	{
		swap(L, 1, i);       
		HeapAdjust(L, 1, i - 1);        //重新调整为大顶堆
	}
}


int main()
{
	int i;
	SqList L;
	SqList *p = &L;
	cin >> L.length;
	for ( i = 1; i <= L.length; i++)
		cin >> L.r[i];
	HeapSort(p);
	for ( i= 1; i <= L.length; i++)
		cout << L.r[i] << endl<<endl;
}
