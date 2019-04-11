#include "pch.h"
#include <iostream>
using namespace std;
#define M 50
void ji(int x[], int j);
int main()
{
	int a[M] = { 0 };
	int n, i = 0, j;
	do {
		cin >> n;
		a[i++] = n;
		ji(a, i);
		for (j = 0; j < i; j++)
			cout << a[j] << " ";
		cout << endl;
	} while (i <= M);
	return 0;
}
void ji(int x[], int j)
{
	int max, i, el = 0, m = 1;
	int da[M] = { 0 };
	max = x[0];
	for (i = 1; i < j; i++) {
		if (max < x[i])
			max = x[i];
	}
	for (i = 10; max >= 1; ) {
		el++;
		max /= i;
	}
	while (el) {
		int b[10] = { 0 };
		for (i = 0; i < j; i++)
			b[x[i] / m % 10]++;
		for (i = 1; i < 10; i++)
			b[i] += b[i - 1];
		for (i = j - 1; i >= 0; i--)
			da[--b[x[i] / m % 10]] = x[i];
		for (i = 0; i < j; i++)
			x[i] = da[i];
		m *= 10;
		el--;
	}
}
