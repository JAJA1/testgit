#include "pch.h"
#include <iostream>
#define M 50
using namespace std;
void kuai(int x[], int t,int w);
int main()
{
	int a[M] = { 0 };
	int n, i = 0, j;
	do {
		cin >> n;
		a[i++] = n;
		kuai(a, 0, i-1);
		for (j = 0; j < i; j++)
			cout << a[j] << " ";
		cout << endl;
	} while (i <= M);
	return 0;
}
void kuai(int x[], int t, int w)
{
	int i, j, k;
	i = t;
	j = w;
	k = x[i];
	if (t >= w)
		return;
	do {
		while ((x[j] >= k) && (j > i))
			j--;
		if (i < j) {
			x[i] = x[j];
			i++;
		}
		while ((x[i] <= k) && (j > i))
			i++;
		if (i < j) {
			x[j] = x[i];
			j--;
		}
		x[i] = k;
		kuai(x, t, i - 1);
		kuai(x, i + 1, w);
	} while (j > i);
	return;
}
