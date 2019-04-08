// ConsoleApplication44.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
void sort(int *a, int n)
{
	int i, j, k;
	int x;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
			for (j = i; j < n - 2; j++)
				if (a[j] < a[k])
					k = j;
		if(i!=k)
		{
			x = a[i];
			a[i] = a[k];
			a[k] = x;
		}
	}
}
int main()
{
	int i;
	int a[] = { 2,3,5,1,4,6,9,7,55,8,100 };
	sort(a, 12);
	for (i = 0; i < 12; i++)
		cout << a[i] << endl;
}
