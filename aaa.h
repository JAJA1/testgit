#pragma once
#include <iostream>  
using namespace std;
const int max = 100;//ջ�����洢��  
template <typename emm>
class stack {
public:
	stack();//���캯�������ڳ�ʼ��  
	bool empty();//�ж�ջ�Ƿ�Ϊ��  
	bool full();//�ж�ջ�Ƿ�Ϊ��  
	bool get_top(emm &x);//ȡջ��Ԫ��  
	bool push(emm x);//Ԫ����ջ  
	bool pop();//ɾ��ջ��  
private:
	int count;//Ԫ�صļ�����  
	emm data[max];//˳��洢�ṹ  
};
template <typename emm>
stack<emm>::stack() {
	count = 0;
}
template <typename emm>
bool stack<emm>::empty() {
	if (count == 0)
		return true;
	return false;
}
template <typename emm>
bool stack<emm>::full() {
	if (count == max)
		return true;
	return false;
}
template <typename emm>
bool stack<emm>::get_top(emm &x) {
	if (!empty()) {
		x = data[count - 1];
		return true;
	}
	return false;
}
template <typename emm>
bool stack<emm>::push(emm x) {
	if (!full()) {
		data[count++] = x;
		return true;
	}
	return false;
}
template <typename emm>
bool stack<emm>::pop() {
	if (!empty()) {
		--count;
		return true;
	}
	return false;
}