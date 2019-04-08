// ConsoleApplication41.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
using namespace std;                                     
#define N 10
int num[N];
int quick_sort(int L, int R)
{
	int left = L, right = R;

	int base = num[L];
	int temp;
	if (L > R)                                     //通过左右哨兵的移动同时将数列分割成两部分，再次通过递归将左右两个部分进行排序
													 //个人总结的快速排序核心注意点

		return 0;

	while (right != left)
	{
		while (num[right] >= base && right > left)    //寻找右边小于base的值 
		{
			right--;

		}
		while (num[left] <= base && right > left)    //寻找左边大于base 
		{
			left++;
		  }
		                                             //如果没有相遇，这左右值交换
		if (right > left)
		{
			temp = num[left];
			num[left] = num[right];
			num[right] = temp;
		}
	}

	 
	if (right = left)
		num[L] = num[right];
	num[left] = base;
	quick_sort(L, left - 1);
	quick_sort(right + 1, R);     
}
int main()
{
	int i = 0, n = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)       
		scanf("%d", &num[i]);
	quick_sort(1, n);
	for (i = 1; i <= n; i++)
		printf("%d\t", num[i]);
	return 0;
}

