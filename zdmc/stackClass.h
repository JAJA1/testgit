#pragma once
//#include<string>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#define maxsize_stack 50
#define maxsize_exp 50
#define othersize 10
template<class elemType>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(elemType e);
	bool Pop(elemType &e);//记录出栈元素
	void clearStack();
	int StackLen();//当前长度
	double Calculation(char suffix[]);//后缀表达式的计算
	void infix2suffix(char infix[], char suffix[]);//中缀表达式变为后缀表达
private:
	elemType *base;//栈底
	elemType *top;//指向栈顶
	int stackSize;//当前栈的最大容量
};
template<class elemType>
Stack<elemType>::Stack()
{
	base = new elemType[maxsize_stack];
	if (base == NULL)
		exit(0);
	top = base;
	stackSize = maxsize_stack;
}//初始化栈
template<class elemType>
Stack<elemType>::~Stack()
{
	delete[]base;
}//释放栈
template<class elemType>
void Stack<elemType>::Push(elemType e)
{
	if (top - base == stackSize)
	{
		base = (elemType *)realloc(base,(maxsize_stack + othersize) * sizeof(elemType));
			if (base == NULL)
				exit(0);
		top = base+ othersize;
		stackSize = othersize +maxsize_stack;
	}
	*(top++) = e;
	return;
}//将e入栈
template<class elemType>
bool Stack<elemType>::Pop(elemType &e)
{
	if(top==base)
		return false;
	else
	{
		e = *(--top);
		return true;
	}
}
template<class elemType>
void Stack<elemType>::clearStack()
{
	top = base;
	return;
}
template<class elemType>
int Stack<elemType>::StackLen()
{
	return top - base;
}
template<class elemType>
void Stack<elemType>::infix2suffix(char infix[], char suffix[])//中缀表达式变为后缀表达
{
	Stack<char>s;
	int i=0, j=0;
	char e;
	while (infix[j] != '\0')
	{
		while (infix[j] >= '0'&&infix[j] <= '9')
		{
			suffix[i++] = infix[j];
			j++;
			if (infix[j] < '0' || infix[j] > '9')
			{
				suffix[i++] = ' ';
			}
		}
		switch (infix[j])
		{
		case ')':
			s.Pop(e);
			while (e != '(')
			{
				suffix[i++] = e;
				suffix[i++] = ' ';
				s.Pop(e);
			}
			break;
		case '.':
			i -= 1;
			suffix[i++] = infix[j];
			break;
		case '+':
		case '-':
			if (s.StackLen() == 0)
				s.Push(infix[j]);
			else
			{
				do
				{
					s.Pop(e);
					if (e == '(')
					{
						s.Push(e);
					}
					else
					{		
						suffix[i++] = e;
						suffix[i++] = ' ';
					}
				} while (s.StackLen() && e != '(');
				s.Push(infix[j]);
			}
			break;
		case '*':
		case '/':
		case '(':
			s.Push(infix[j]);
			break;
		//case '[':
		//case ']':
		case '\0':
			break;
		default:
			printf("格式错误\n");
			exit(0);
		}
		if (infix[j] == '\0')
			break;
		j++;
	}
	while (s.StackLen())
	{
		s.Pop(e);
		suffix[i++] = e;
		suffix[i++] = ' ';
	}
	suffix[i] = '\0';
	return ;
}
template<class elemType>
double Stack<elemType>::Calculation(char suffix[])//后缀表达式的计算
{
	int i = 0, j;
	char c;
	char str[maxsize_exp];
	double a = 0, b = 0;
	for (j = 0; suffix[j] != '\0'; j++)
	{
		while ((suffix[j] >= 48) && (suffix[j] <= 57) || suffix[j] == '.')
		{
			str[i] = suffix[j];
			i++;
			str[i] = '\0';
			if (i >= 10)
			{
				printf("出错，输入的数据过长!\n");
				exit(0);
			}
			j++;
			if ((suffix[j] == ' '))
			{
				a = atof(str);
				Push(a);
				i = 0;
			}
		}
		switch (suffix[j])
		{
		case '+':
			Pop(a);
			Pop(b);
			Push(b + a);
			break;
		case '-':
			Pop(a);
			if (!Pop(b))
			{
				Push(-a);
				break;
			}
			Push(b - a);
			break;
		case '*':
			Pop(a);
			Pop(b);
			Push(b*a);
			break;
		case '/':
			Pop(a);
			if (a == 0)
			{
				printf("除数不能为零 ！\n");
				exit(0);
			}
			Pop(b);
			Push(b *1.0/ a);
			break;
		default:
			break;
		}
	}
	Pop(a);
	return a;
}
