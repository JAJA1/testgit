//只有一艘船，能乘2人，船的运行速度为2人中较慢一人的速度，过去后还需一个人把船划回来，问把n个人运到对岸，最少需要多久
#include<iostream>
using namespace std;
int main()
{
		int a[100], t, n, sum;
		cin >> t;
		while (t--)
		{
			cin >> n;
			sum = 0;
			for (int i = 0; i < n; i++)
				cin >> a[i];
			while (n > 3)
			{
				if (sum + a[1] + a[0] + a[n - 1] + a[1] < sum + a[n - 1] + a[0] + a[n - 2] + a[0])
					sum = sum + a[1] + a[0] + a[n - 1] + a[1];
				else
					sum = sum + a[n - 1] + a[0] + a[n - 2] + a[0];
				n -= 2;
			}
			if (n == 3) sum += a[0] + a[1] + a[2];
			else if (n == 2) sum += a[1];
			else sum += a[0];
			cout << sum;
		}
	return 0;
}