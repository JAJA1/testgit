/*����Ǯ����100Ԫ��50Ԫ��20Ԫ��10Ԫ��5Ԫ��1Ԫ*/
#include<iostream>
using namespace std;
int main()
{
	int  x, sum[6] = { 0 };
	cin >> x;
	sum[0] += x / 100;
	x %= 100;
	sum[1] += x / 50;
	x %= 50;
	sum[2] += x / 20;
	x %= 20;
	sum[3] += x / 10;
	x %= 10;
	sum[4] += x / 5;
	x %= 5;
	sum[5] += x;
	for (int i = 0; i < 6; i++)
		cout << sum[i] <<" ";
	return 0;
}