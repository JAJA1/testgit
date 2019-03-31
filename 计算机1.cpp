
#include <iostream>
#include<stdlib.h>
using namespace std;
int cal(int x,int y,char c);
int pr(char c);
void in(int *a,int *t);
void iner(char *s,int *t);
int isfu(int *t);
int em(int *t);
int pu(int *a,int *n,int *t);
int pu1(char *a,char *c,int *t);
int pp(int *a,int *t);
int pp1(char *a,int *t);
int com(char *s,char *s2,int *t2,int *s1,int *t1);
enum use{fu=-10,o,e,u,q};
int cal(int x, int y, char c)
{
	switch (c) {
	case '+':return x + y;
	case '-':return x - y;
	case '*':return x * y;
	case '/':return x / y;
	}
}
int pr(char c)
{
	switch (c) {
	case '+':
	case '-': {
		return 1;
	}
	case '*':
	case '/': {
		return 2;
	}
	default:return 0;
	}
	return 0;
}
void in(int *a, int *t) {
	int i;
	for (i = 0; i < 50; i++)
		a[i] = 0;
	*t = -1;
}
void iner(char *s, int *t)
{
	int i;
	for (i = 0; i < 50; i++)
		s[i] = 0;
	*t = -1;
}
int isfu(int *t)
{
	if (*t == 49) {
		return fu;
	}
	return o;
}
int em(int *t)
{
	if (*t == -1)
		return e;
	return o;
}
int pu(int *a, int *n, int *t)
{
	if (isfu(t) == fu)
	{
		return fu;
	}
	(*t)++;
	a[*t] = *n;
	return q;
}
int pu1(char *a, char *c, int *t)
{
	if (isfu(t) == fu)
		return fu;
	(*t)++;
	a[*t] = *c;
	return q;
}
int pp(int *a, int *t)
{
	int n;
	if (em(t) == e)
		return e;
	n = a[*t];
	(*t)--;
	return n;
}
int pp1(char *a, int *t)
{
	char c;
	if (em(t) == e)
		return e;
	c = a[*t];
	(*t)--;
	return c;
}
int com(char *s, char *s2, int*t2, int*s1, int *t1)
{
	int n, n1, al;
	char c;
	if (*s == '\0')
		return u;
	if (isfu(t2) == fu)
		return fu;
	else if (em(t2) == e||*s=='(')
		pu1(s2, s, t2);
	else if (*s == ')')
	{
		c = pp1(s2, t2);
		while (c != '(') {
			n = pp(s1, t1);
			n1 = pp(s1, t1);
			al = cal(n1, n, c);
			pu(s1, &al, t1);
			c = pp1(s2, t2);
		}
	}
	else
	{
		c = pp1(s2, t2);
		if (c == '(')
		{
			pu1(s2, &c, t2);
			pu1(s2, s, t2);
			return u;
		}
		n = pr(c);
		n1 = pr(*s);
		if (n1 > n) {
			pu1(s2, &c, t2);
			pu1(s2, s, t2);
		}
		else
		{
			n = pp(s1, t1);
			n1 = pp(s1, t1);
			al = cal(n1, n, c);
			pu(s1, &al, t1);
			com(s, s2, t2, s1, t1);
		}
	}
	return u;
}
int main()
{
	int n, n1, al;
	char c;
	char *d = (char*)malloc(sizeof(char) * 100);
	char *s = (char*)malloc(sizeof(char) * 100);
	char *p = d;
	int s1[50];
	int t1;
	char s2[50];
	int t2;
	in(s1, &t1);
	iner(s2, &t2);
	cin >> s;
	char *v = s;
	while (*s != '\0') {
		if (*s >= '0'&&*s <= '9') {
			while (*s >= '0'&&*s <= '9') {
				*p = *s;
				s++;
				p++;
			}
			*p = '\0';
			p = d;
			n = (int)d;
			pu(s1, &n, &t1);
		}
		com(s, s2, &t2, s1, &t1);
		if (*s == '\0')
			break;
		s++;
	}
	while (t2 != -1) {
		n = pp(s1, &t1);
		n1 = pp(s1, &t1);
		c = pp1(s2, &t2);
		al = cal(n1, n, c);
		pu(s1, &al, &t1);
	}
	cout << v << "=" << al << endl;
	return 0;
}