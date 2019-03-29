/*计算器
括号匹配
中缀表达式转化后缀表达式*/
#include"stackClass.h"
#include<iostream>
#include<string>
#define maxsize_exp 50
using namespace std;
int main()
{
	char infix[maxsize_exp] ;//中缀表达式
	char suffix[maxsize_exp];//后缀表达式
	cout << "高大上计算器" << endl;
	gets_s(infix, maxsize_exp);
	Stack<double>cal;
		cal.infix2suffix(infix,suffix);
		double sum = cal.Calculation(suffix);
		//cout << suffix << endl;
		cout << "经高大上计算器计算结果是" << sum << endl;
		return 0;

}