#include "pch.h"
#include <iostream>
#include<stdlib.h>
#define M 50
using namespace std;
void pai(int x[], int i);
void dui(int s[], int t, int n);
int main()
{
	int a[M] = { 0 };
	int n, i = 0;
	do {
		cin >> n;
		a[i++] = n;
		pai(a, i);
	} while (i <= M);
	return 0;
}
void dui(int s[], int t, int n)
{
	int w, k;
	w = 2 * t + 1;
	k = s[t];
	while (w <= n) {
		if ((w < n) && (s[w] > s[w + 1]))
			w++;
		if (s[t] > s[w]) {
			s[t] = s[w];
			t = w;
			w = 2 * w + 1;
		}
		else
			break;
	}
	s[t] = k;
}
void pai(int x[], int j)
{
	int i, k;
	for (i = j / 2 - 1; i >= 0; i--)
		dui(x, i , j - 1);
	for (i = j - 1; i > 0; i--) {
		k = x[0];
		x[0] = x[i];
		x[i] = k;
		dui(x, 0 , i-1);
	}
	for (i = 0; i < j; i++)
		cout << x[i] << " ";
	cout << endl;
}