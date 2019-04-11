#include<iostream>
#include<stdlib.h>
using namespace std;
void kuaipai(int a[],int low,int high);
int fenge(int a[], int low, int high);
void duipai(int b[],int n);
void jishu(int c[],int n);
void xier(int e[],int n);
void xuanze(int g[],int n);
int main()
{
	int a[10],b[10],d[101],e[10],g[10];
	int i;
	cout << "输入10个数：";
	for (i = 0; i < 10; i++)
		cin >> a[i];
	kuaipai(a, 0,9);
	for (i = 0; i < 10; i++)
		cout << a[i]<<" ";
	cout << endl << "快速排序" << endl;
	system("pause");
	cout << "输入第二个数组：";
	for (i = 0; i < 10; i++)
		cin >> b[i];
	duipai(b, 10);
	for (i = 0; i < 10; i++)
		cout << " " << b[i] <<" ";
	cout << endl << "堆排序" << endl;
	cout << "输入10个数：";
		jishu(d, 100);
	cout << endl << "计数排序" << endl;
	cout << "输入10个数：";
	for (i = 0; i < 10; i++)
		cin >> e[i];
	xier(e, 10);
	for (i = 0; i < 10; i++)
		cout << e[i] <<" ";
	cout << endl << "希尔排序" << endl;
	system("pause");
	cout << "输入10个数：：";
	for (i = 0; i < 10; i++)
		cin >> g[i];
	xuanze(g, 10);
	for (i = 0; i < 10; i++)
		cout << g[i]<<" ";
	cout << endl<< "选择排序"<<endl;
	system("pause");
	return 0;
}

void kuaipai(int a[],int low,int high)
{
	int middle;
	if (low<high)
	{
		middle = fenge(a,low,high);
		kuaipai(a,low, middle - 1);
		kuaipai(a, middle + 1, high);
	}
}
int fenge(int a[], int low, int high)
{
	int temp1,temp;
	temp1 = a[low];
	while (low < high)
	{
		while (low < high&&a[high] >=temp1)
			high--;
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
		while (low < high&&a[low] <=temp1)
			low++;
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}
	return low;
}

void duipai(int b[], int n)
{
	int i, j, k, temp, l, x;
	for (i = 10; i > 0; i--)
	{
		if (i % 2 == 0)
			k = (i - 1) / 2;
		else
			k = i / 2;
		for (j = k; j >= 0; j--)
		{
			l = j;
			while (l <= k)
			{
				if ((2 * l + 2) > i)
				{
					if (b[l] >= b[(2 * l) + 1])
						break;
					else
					{
						temp = b[l];
						b[l] = b[(2 * l) + 1];
						b[(2 * l) + 1] = temp;
						l = (2 * l) + 1;
					}
				}
				else
				{
					if (b[l] >= b[(2 * l) + 1] && b[l] >= b[(2 * l) + 2])
						break;
					if (b[(2 * l) + 1] > b[(2 * l) + 2])
					{
						temp = b[l];
						b[l] = b[(2 * l) + 1];
						b[(2 * l) + 1] = temp;
						l = (2 * l) + 1;
					}
					else
					{
						temp = b[l];
						b[l] = b[(2 * l) + 2];
						b[(2 * l) + 2] = temp;
						l = (2 * l) + 2;
					}
				}

			}
		}
		x = b[0];
		b[0] = b[i];
		b[i] = x;
	}
}

void jishu(int d[], int n)
 {
	int i,j;
	for (i = 0; i <= 100; i++)
		d[i] = 0;
	for (i = 1; i <= 10; i++)
	{
		cin >> j;
		d[j]++;
	}
	for (i = 0; i <= 100; i++)
		for (j = 1; j <= d[i]; j++)
			cout << i<<" ";
	return ;
}

void xier(int e[], int n)
{
		int i, j, k, gap, temp;
		for (gap =10 / 2; gap > 0; gap = gap / 2)
		{
			for (i = 0; i < gap; i++)
			{
				for (j = i + gap; j < 10; j = j + gap)
				{
					if (e[j] < e[j - gap])
					{
						temp = e[j];	
						k = j - gap;
						while (k >= 0 && e[k] > temp)
						{
							e[k + gap] = e[k];
							k = k - gap;
						}
						e[k + gap] = temp;
					}
				}
			}
		}
}

void xuanze(int g[], int n)
{
	int i,j,temp,min;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i; j < n; j++)
		{
			if (g[j] < g[min])
				min = j;
		}
		temp = g[min];
		g[min] = g[i];
		g[i] = temp;
	}
	return;
}
