/*������
����ƥ��
��׺���ʽת����׺���ʽ*/
#include"stackClass.h"
#include<iostream>
#include<string>
#define maxsize_exp 50
using namespace std;
int main()
{
	char infix[maxsize_exp] ;//��׺���ʽ
	char suffix[maxsize_exp];//��׺���ʽ
	cout << "�ߴ��ϼ�����" << endl;
	gets_s(infix, maxsize_exp);
	Stack<double>cal;
		cal.infix2suffix(infix,suffix);
		double sum = cal.Calculation(suffix);
		//cout << suffix << endl;
		cout << "���ߴ��ϼ�������������" << sum << endl;
		return 0;

}