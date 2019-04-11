#include "pch.h"
#include <iostream>
using namespace std;
#define M 50
void erfan(int x[], int j);
int main()
{
	int a[M] = { 0 };
	int n, i = 0;
	do {
		cin >> n;
		a[i++] = n;
		erfan(a, i);
	} while (i <= M);
	return 0;
}
void erfan(int x[], int j)
{
	int i,h,k,t,w,m;
		k = x[j-1];
		t = 0;
		w = j - 2;
	while (t <= w){
		m = (t + w) / 2;
		if (k < x[m])
			w = m - 1;
		else
			t = m + 1;
	}
	for (h = j-1; h >= t; h--)
		x[h] = x[h-1];
	x[t] = k;
	for (i = 0; i < j; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
	return;
}
