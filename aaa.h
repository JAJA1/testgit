#pragma once
#include <iostream>  
using namespace std;
const int max = 100;//栈的最大存储量  
template <typename emm>
class stack {
public:
	stack();//构造函数，用于初始化  
	bool empty();//判断栈是否为空  
	bool full();//判断栈是否为满  
	bool get_top(emm &x);//取栈顶元素  
	bool push(emm x);//元素入栈  
	bool pop();//删除栈顶  
private:
	int count;//元素的计数器  
	emm data[max];//顺序存储结构  
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