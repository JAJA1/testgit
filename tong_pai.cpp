#include "pch.h"
#include <iostream>
#define M 10
#define N 5
using namespace std;
void tong(int x[], int j);
int main()
{
	int a[M] = { 5,20,4,24,8,74,45,65,12,44 };
	int j;
	for (auto c : a)
		cout << c << " ";
	cout << endl;
	tong(a, M);
	for (j = 0; j < M; j++)
		cout << a[j] << " ";
	cout << endl;
	return 0;
}
void tong(int x[], int j)
{
	int i, k, max, min, u = 0, v = 0, h, d;
	int m[N][10] = { 0 };
	max = min = x[0];
	for (i = 0; i < j; i++) {
		if (max < x[i])
			max = x[i];
		else if (min > x[i])
			min = x[i];
	}
	k = (max - min) / N;
	while (u != N) {
		for (i = 0; i < j; i++) {
			if ((min + u * k <= x[i]) && (x[i] < min + (u + 1)*k)) {
				m[u][v] = x[i];
				v++;
				h = v;
			}
		}
		u++;
		v = 0;
	}
	m[u - 1][h] = max;
	u = 0;
	while (u != N) {
		k = v = 0;
		while (m[u][v] != 0) {
			k++;
			v++;
		}
		for (v = 0; v < k-1&&k != 1; v++) {
			for (d = v; d < k; d++) {
				if (m[u][v] > m[u][d]) {
					h = m[u][v];
					m[u][v] = m[u][d];
					m[u][d] = h;
				}
			}
		}
		u++;
	}v = 0;
	for (u = 0; u < N; u++) {
		while (m[u][v] != 0) {
			cout << m[u][v] << " ";
			v++;
		}
		v = 0;
	}cout << endl;
	u = 0;
	v = 0;
	while (u != N) {
		for (i = 0; i < M && m[u][v]!=0; i++) {
				x[i] = m[u][v];
				v++;
		}
		u++;
		v = 0;
	}
	return;
}