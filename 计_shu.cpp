#include "pch.h"
#include<iostream>
using namespace std;
int maxw(int x[], int s);
int* ji(int x[], int s);
int maxw(int x[], int s)
{
	int max = 0;
	int h = s;
	for (int i = 1; i != h; i++)
	{
		if (x[max] < x[i])
			max = i;
	}
	return x[max];
}
int* ji(int x[], int s)
{
	int i, j;
	int k = maxw(x, s) + 1;
	int *c = (int*)malloc(sizeof(int)*k);
	int h = s;
	int *b = (int*)malloc(sizeof(int)*h);
	for (j = 0; j != k; j++)
		c[j] = 0;
	for (i = 0; i != h; i++)
		c[x[i]] = c[x[i]] + 1;
	for (i = 1; i != k; i++)
		c[i] = c[i] + c[i - 1];
	for (i = h - 1; i >= 0; i--)
	{
		b[c[x[i]] - 1] = x[i];
		c[x[i]] = c[x[i]] - 1;
	}
	return b;
}
int main()
{
	int a[10] = { 4,5,2,1,6,3,8,9,7,10 };
	int *p = ji(a, 10);
	for (int i = 0; i != 10; ++i)
		cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i != 10; ++i)
		cout << p[i] << " ";
	return 0;
}