#include <iostream>
#include <algorithm>   //菜市场购物活动时间安排，贪心算法实现，并不一定是最优解。控制在同一时间段里小贩有尽可能多的贩卖机会。用于处理时间错开。     
                       //齐雨争。未设置针对时间的防爆措施，所以无时间范围限制。
using namespace std;
int N;
struct mai
{
	int start;
	int end;
} shop[66];
                          // 小贩贩卖机会数

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
	cout << "菜市场贩卖活动数量:";
	cin >> N;
	cout << "输入每一个活动的开始和结束时间:";
	for (int i = 0; i < N; i++)
	{
		cin >> shop[i].start;
		cin >> shop[i].end;
	}


	sort(shop, shop + N, cmp);

	int fanmaishuliang = greedy();
	cout << "可以同时进行贩卖的小贩是 " << fanmaishuliang;
	return 0;
}
