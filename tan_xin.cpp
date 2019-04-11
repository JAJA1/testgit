#include "pch.h"
#include <iostream>
#define N 5
using namespace std;
int mon[N] = { 1,2,5,10,20 };
int chao[N] = { 4,4,2,2,1 };
int shu(int m);
int shu(int m)
{
	int r=0, i, h;
	for (i = N - 1; i >= 0; i--) {
		if (m / mon[i] < chao[i])
			h = m / mon[i];
		else
			h = chao[i];
		m -= h * mon[i];
		r += h;
	}
	return r;
}
int main()
{
	int n, k;
	cout << "需付钱数 ";
	cin >> n;
	k = shu(n);
	cout <<"至少"<< k <<"张钞票"<< endl;
}
