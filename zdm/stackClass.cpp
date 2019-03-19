#include "stackClass.h"
#include<iostream>
using namespace std;
int main()
{
	int t;
	Stack *sta=new Stack();
	cout << "将1，2，3压入栈内" << endl;
	sta->push(1);
	sta->push(2);
	sta->push(3);
	cout << "弹出栈顶元素" << endl;
	t = sta->pop();
	cout << "弹出的是" << t << endl;
	cout << "将4压入栈内" << endl;
	sta->push(4);
	while (!sta->isEmpty())
	{
		t = sta->pop();
		cout << t << endl;
	}
	return 0;
}