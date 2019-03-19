#pragma once
#include<iostream>
#define maxsize 50
using namespace std;
class Stack
{
public:
	Stack();
	~Stack();
	void push(int x);
	int pop();
	int size();
	int isEmpty();
private:
	int *a;
	int count;
};
Stack::Stack()
{
	a = new int[maxsize];
	if (!a)
	{
		cout << "error" << endl;
	}
	count = 0;
}
Stack::~Stack()
{
	if (a)
	{
		delete[] a;
		a = NULL;
	}
}
void Stack::push(int x)
{
	a[++count] = x;
}
int Stack::pop()
{
	int t;
	t = a[count--];
	return t;
}
int Stack::size()
{
	return count;
}
int Stack::isEmpty()
{
	return size() == 0;
}