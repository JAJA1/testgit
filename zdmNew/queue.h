#pragma once
#include<iostream>
#define max 100
using namespace std;
typedef struct queueDATE
{
	int Date;
	queueDATE *next;
}date, *date1;
class queue
{
public:
	queue();
	~queue();
	void EnQueue(int x);//入队
	int DeQueue();//出队
	bool isEmpty();//判断队列是否为空
	int sizeof_queue();//判断队列长度
	void print_queue();//打印队列
private:
	date1 front;
	date1 rear;
};
queue::queue()
{
	front = rear = new date;
	if (front == NULL)
	{
		cout << "error" << endl;
	}
	front->next = NULL;
}
queue::~queue()
{
	while (front)
	{
		rear = front->next;
		delete front;
		front = rear;
	}
}
void queue::EnQueue(int x)
{
	date *p = new date;
	p->next = NULL;
	p->Date = x;
	rear->next = p;
	rear = p;
}
int queue::DeQueue()
{
	date *p;
	int n;
	p = front->next;
	n = p->Date;
	front->next = front->next->next;
	if (rear == p)
	{	
		rear = front;
	}
	delete p;
	return n;
}
bool queue::isEmpty()
{
	if (rear == front)
		return true;
}
int queue::sizeof_queue()
{
	return (front - rear) / 4;
}
void queue::print_queue()
{
	date *p;
	p = front->next;
	if (p == NULL)
	{
		cout << "空" << endl;
	}
	while (p != NULL)
	{
		cout << p->Date<<endl;
		p = p->next;
	}
	return;
}
