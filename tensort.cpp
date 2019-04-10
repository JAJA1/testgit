#include<iostream>
#include<string.h>
#define maxsize 10
using namespace std;
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b = t;
}
int Max(int *a, int k) 
{  
	int max = a[0];
	for (int i = 0; i < k; i++)
	{
		if (max < a[i]) 
		{
			max = a[i];
		}
	}
	return max;
}
void Bubble_Sort(int *a,int k)
{
	int t = 0;
	for (int i = 0; i < k - 1; i++)
	{
		t = 0;
		for (int j = 0; j < k - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t += 1;
				swap(a[j], a[j + 1]);
			}
		}
		if (t == 0)
			break;
	}
	cout << "ð��������Ϊ��";
	for (int i = 0; i < k; i++)
		cout << a[i] << " ";
	cout << endl;
	return;
}
void Select_Sort(int *a, int k)
{
	for (int i = 0; i < k; i++)
	{
		int mindata = i;
		for (int j = i; j < k; j++)
		{
			if (a[j] < a[mindata])
				mindata = j;
		}
		swap(a[i], a[mindata]);
	}
	cout << "ѡ��������Ϊ��";
	for (int i = 0; i < k; i++)
		cout << a[i] << " ";
	cout << endl;
	return;
}
void Insert_Sort(int *a, int k)
{
	for (int i = 1; i < k; i++)
	{
		int t = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > t)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
	cout << "����������Ϊ��";
	for (int i = 0; i < k; i++)
		cout << a[i] << " ";
	cout << endl;
	return;
}
void Shell_Sort(int *a, int k)
{
	int gap = k;
	while (gap = gap / 3 + 1)
	{
		for (int i = gap; i < k; i++)
		{
			int key = a[i];
			int j = i - gap;
			for (; j + 1 > 0 && a[j] > key; j -= gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = key;
		}
	}
	cout << "ϣ��������Ϊ��";
	for (int i = 0; i < k; i++)
		cout << a[i] << " ";
	cout << endl;
	return;
}
void Merge_Sort(int *a, int k);
void Quick_Sort(int *a, int left,int right)
{
	if (left >= right)
		return ;
	int i=left, j=right, t=a[i];
	while (i < j)
	{
		while (i < j&&a[j] >= t)
		{
			j--;
		}//�ѱ�tС�ķŵ�һ��
		a[i] = a[j];
		while (i < j&&a[i] <= t)
		{
			i++;
		}//�ѱ�t��ķ���һ��
		a[j] = a[i];
	}
	a[i] = t;
	Quick_Sort(a, left, i - 1);
	Quick_Sort(a, i + 1, right);
}
void heap(int a[], int node, int k)
{
	int n = a[node];
	for (int i = 2 * node + 1; i < k; i = 2 * i + 1)
	{
		if (i + 1 < k&&a[i + 1] > a[i])
			i++;
		if (a[i] > a[node])
		{
			a[node] = a[i];
			node = i;
		}
	}
	a[node] = n;
}
void Heap_Sort(int *a, int k)
{
	for (int node = k / 2 - 1; node >= 0; --node)
	{
		heap(a, node, k);
	}

	for (int i = k - 1; i > 0; --i)
	{
		swap(a[0], a[i]);
		heap(a, 0, i);
	}
}
void Count_Sort(int *a, int k, int max)
{
	int *bucket;
	bucket = new int(max);
	memset(bucket, 0, (max + 1) * sizeof(k));
	for (int i = 0; i < k; i++)
	{
		++bucket[a[i]];
	}
	cout << "����������Ϊ";
	for (int i = 0; i <= max; i++)
		for (int j = 0; j < bucket[i]; j++)
			cout << i << " ";
	free(bucket);
	bucket = NULL;
}
void Radix_Sort(int *a, int k,int max)
{
	int m[maxsize];
	for (int i = 0; i < k; i++)
	{
		m[i] = a[i];
	}
	int bucket[10][maxsize];
	for (int j = 0; max!= 0; j++) //ѭ�����λ����
	{
		int t = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < k; j++)
				bucket[i][j] = 0;//��ʼ������

		int c[10] = { 0 }; //��¼Ͱ��¼��Ԫ�ظ���
		for (int i = 0; i < k; i++) //��λ
		{
			bucket[a[i] % 10][c[a[i] % 10]] = m[i];
			c[a[i] % 10]++;
			a[i] /= 10;
		}

		for (int i = 0; i < 10; i++)
		{
			for (int p = 0; p < k; p++)
			{
				if (bucket[i][p] != 0)//���Ͱ������
				{
					m[t] = bucket[i][p];
					t++;//��¼
				}
			}
		}//��Ͱ��ȡ��Ԫ�ؽ�Ԫ�ػָ�������
		for (int i = 0; i < t; i++)
		{
			a[i] = m[i] / 10;
			for (int p = 0; p < j; p++)
				a[i] /= 10;
		}
		max/= 10;
	}
	cout << "����������Ϊ��";
	for (int i = 0; i < k; i++)
		cout << m[i] << " ";
}
void Bucket_Sort(int *a, int k, int max)//�о�Ͱ��Ϊһʱ�����һ��
{
	int *bucket;
	bucket = new int(max);
	memset(bucket, 0, (max + 1) * sizeof(k));
	for (int i = 0; i < k; i++)
	{
		++bucket[a[i]];
	}
	cout << "Ͱ������Ϊ";
	for (int i = 0; i <= max; i++)
		for (int j = 0; j < bucket[i]; j++)
			cout << i << " ";
	free(bucket);
	bucket = NULL;
}
int main()
{
	int a[maxsize] = { 4,6,3,1,8,55,13,5,14,15 };
	cout << "ԭ����Ϊ";
	int k = sizeof(a) / sizeof(int);
	for (int i = 0; i < k; i++)
		cout << a[i]<<" ";
	cout << endl;
	//Bubble_Sort(a,k);
	//Select_Sort(a,k);
	//Insert_Sort(a,k);
	//Shell_Sort(a,k);
	//Merge_Sort(a,k);δд��
	/*Quick_Sort(a,0,maxsize-1);
	cout << "����������Ϊ��";
	for (int i = 0; i < k; i++)
		cout << a[i] << " ";
	cout << endl;*/
	/*Heap_Sort(a,k);
	cout << "��������Ϊ��";
	for (int i = 0; i < k; i++)
		cout << a[i] << " ";
	cout << endl; */
	/*int max=Max(a, k);
	Count_Sort(a,k,max);*/
	/*int max = Max(a, k);
	Radix_Sort(a,k,max);*/
	int max = Max(a, k);
	Bucket_Sort(a,k,max);
	return 0;
}