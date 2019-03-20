#include "queue.h"
#include<iostream>
using namespace std;
int main()
{
	int t;
	queue *sta = new queue;
	cout << "将1，2，3写入队列内" << endl;
	sta->EnQueue(1);
	sta->EnQueue(2);
	sta->EnQueue(3);
	cout << "弹出队列元素" << endl;
	t = sta->DeQueue();
	cout << "弹出的是" << t << endl;
	cout << "将4写入队列内" << endl;
	sta->EnQueue(4);
	while (!sta->isEmpty())
	{
		t = sta-> DeQueue();
		cout << t << endl;
	}
	sta->print_queue();
	return 0;
}



