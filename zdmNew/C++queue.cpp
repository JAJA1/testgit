#include "queue.h"
#include<iostream>
using namespace std;
int main()
{
	int t;
	queue *sta = new queue;
	cout << "��1��2��3д�������" << endl;
	sta->EnQueue(1);
	sta->EnQueue(2);
	sta->EnQueue(3);
	cout << "��������Ԫ��" << endl;
	t = sta->DeQueue();
	cout << "��������" << t << endl;
	cout << "��4д�������" << endl;
	sta->EnQueue(4);
	while (!sta->isEmpty())
	{
		t = sta-> DeQueue();
		cout << t << endl;
	}
	sta->print_queue();
	return 0;
}



