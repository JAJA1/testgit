#include "stackClass.h"
#include<iostream>
using namespace std;
int main()
{
	int t;
	Stack *sta=new Stack();
	cout << "��1��2��3ѹ��ջ��" << endl;
	sta->push(1);
	sta->push(2);
	sta->push(3);
	cout << "����ջ��Ԫ��" << endl;
	t = sta->pop();
	cout << "��������" << t << endl;
	cout << "��4ѹ��ջ��" << endl;
	sta->push(4);
	while (!sta->isEmpty())
	{
		t = sta->pop();
		cout << t << endl;
	}
	return 0;
}