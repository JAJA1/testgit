#include <iostream>  
#include<string>
#include "aaa.h"  
using namespace std;
bool shuzi(char x);
int fuhao(char x);
int suan(string s);
int main()
{
	string expression;
	cout << "����һ����'#'��ͷ�ͽ�β�ı��ʽ��" << endl;
	cin >> expression;
	suan(expression);
	cin.get(),cin.get();
	
}
//���� 
bool shuzi(char x)
{
	if (x >= '0' && x <= '9')
		return true;
	return false;
}
//�ж���������ȼ�
int fuhao(char x)
{
	if (x == '+' || x == '-')
		return 0;
	else if (x == '*' || x == '/')
		return 1;
	else if (x == '(' || x == ')'||x == '['||x == ']')
		return -1;
	else if (x == '#')
		return -2;
}
//�� 
int suan(string s) 
{
	stack<int> number;
	stack<char> operate;
	char top;
	int a,b;
	for (int i = 0; i < s.size(); ++i) 
	{
		if (shuzi(s[i])) 
		{
			int Temp = 0;
			string temp;
			temp += s[i];
			while (shuzi(s[++i]))
				temp += s[i];
			for (int j = 0; j < temp.size(); ++j) 
			{
				Temp = Temp * 10 + temp[j] - 48;
			}
			number.push(Temp);
		}//ת������  
		if (!shuzi(s[i])) 
		{
			if (operate.empty()) 
			{
				operate.push(s[i]);
			}//��ջ'#'  
			else {
				operate.get_top(top);
				if (fuhao(s[i]) > fuhao(top) || s[i] == '(')  
				{
					operate.push(s[i]);
				}//��ջ�����ȼ��������  
				else {
					while (fuhao(s[i]) <= fuhao(top)) 
					{
						if (top == '#'&&s[i] == '#') 
						{
							int answer;
							operate.pop();
							number.get_top(answer);
							cout << "\n���ǣ�" << answer << endl;
							number.pop();
							return 0;
						} 
						else if (top == '('&&s[i] == ')')
						{
							++i;
						}//��������������ʱ�����������ţ�ɾ��������  
						else if (top == '['&&s[i] == ']') 
						{
							++i;
						}//����������������ʱ�������������ţ�ɾ����������  
						else 
						{
							number.get_top(a);
							number.pop();
							number.get_top(b);
							number.pop();
						}
						if (top == '+') 
						{
							b += a;
							number.push(b);
						}
						else if (top == '-')
						{
							b -= a;
							number.push(b);
						}
						else if (top == '*')
						{
							b *= a;
							number.push(b);
						}
						else if (top == '/')
						{
							b /= a;
							number.push(b);
						}
						operate.pop();
						operate.get_top(top);   
					}
					operate.push(s[i]);
				}
			}
		}
	}  
} //