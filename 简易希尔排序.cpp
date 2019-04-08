// ConsoleApplication43.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
void sort(int *a, int n)
{
	int i, j, k, t;
	k = n / 2;
	while (k > 0)
	{
		for (i = k; i < n; i++)
			t = a[i];
		j = i - k;
		while (j >= 0 && t < a[j])
		{
			a[j + k] = a[j];
			j = j - k;
		}
		a[j + k] = t;
	}
	k /= 2;

}
int main()
{
	int i;
	int a[] = { 2,3,5,1,4,6,9,7,55,8,0,100 };
	sort(a,12);
	for (i = 0; i < 12; i++)
		printf("%d", a[i]);
}
