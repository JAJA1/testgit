#include <iostream>
#include <algorithm>   //���г�����ʱ�䰲�ţ�̰���㷨ʵ�֣�����һ�������Ž⡣������ͬһʱ�����С���о����ܶ�ķ������ᡣ���ڴ���ʱ�����     
                       //��������δ�������ʱ��ķ�����ʩ��������ʱ�䷶Χ���ơ�
using namespace std;
int N;
struct mai
{
	int start;
	int end;
} shop[66];
                          // С������������

int greedy()
{
	int num = 0;
	for (int i = 0, j = i + 1; i < N; ++j)
	{
		if (shop[j].start > shop[i].end)
		{
			i = j;
			num++;
		}
	}
	return num;
}


bool cmp(mai a, mai b)
{
	return a.end < b.end;
}

int main()
{
	cout << "���г����������:";
	cin >> N;
	cout << "����ÿһ����Ŀ�ʼ�ͽ���ʱ��:";
	for (int i = 0; i < N; i++)
	{
		cin >> shop[i].start;
		cin >> shop[i].end;
	}


	sort(shop, shop + N, cmp);

	int fanmaishuliang = greedy();
	cout << "����ͬʱ���з�����С���� " << fanmaishuliang;
	return 0;
}
