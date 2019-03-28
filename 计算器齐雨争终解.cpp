

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath> 
using namespace std;
template <class T>
class Stack
{
public:
	Stack(int zuidachang = 100);
	T Top() const { return stack[top]; };
	bool IsEmpty() const { return top == -1; }
	bool IsFull() const { return top == toptop; }
	void push(T& x) {
		if (IsFull())
		{
			cout << "full;" << endl;

		}
		else
			top = top + 1;
		stack[top] = x;

	};
	void del(T& x)
	{
		if (IsEmpty())
		{
			cout << "empty" << endl;

		}
		else
			x = stack[top];
		top = top - 1;

	};
	void makeempty() { top = -1; }                        //清栈         
	void print()
	{
		for (int i; i <= top; i++) {
			cout << stack[i] << endl;
		}
		cout << endl;
	}
private:

	int top;                                //栈底 
	int toptop;                               //  栈顶
	T *stack;
};


template<class T>
Stack<T>::Stack(int zuidachang) {
	toptop = zuidachang - 1;
	stack = new T[zuidachang];
	top = -1;
}

bool isNum(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}


//计算器
class cal {
public:
	cal(string s);
	int out(char);                        //外优先级
	int in(char);                          //内优先级 
	bool youxianjipanduan(char, char);             //判断优先级 前一个为栈外符号，后一个为栈内符号 若前大于后返回1，否则返回0 
	int youxianjipanduan(char);                   //判断运算符  若是')'返回 0，否则返回 1 
	void dealNum(); 	                           //处理数据	 
	int calculate();                                //计算 
	void setString(string const s)
	{
		this->s = '#' + s + '#';

	}
private:
	Stack<char> *symble;         //符号栈 
	Stack<int> *numberzhan;          //数据栈 
	string s;
};
cal::cal(string s) {

	numberzhan = new Stack<int>(1000);
	symble = new Stack<char>(1000);
}

int cal::out(char symble)
{
	switch (symble) {
	case '#':
		return 0;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 4;
	case '/':
		return 4;
	case '%':
		return 4;
	case '^':
		return 6;
	case '(':
		return 8;
	case ')':
		return 1;
	default:
		throw 1;
	}
}
int cal::in(char symble) {
	switch (symble) {
	case '#':
		return 0;
	case '(':
		return 1;
	case '+':
		return 3;
	case '-':
		return 3;
	case '*':
		return 5;
	case '/':
		return 5;
	case '%':
		return 5;
	case '^':
		return 7;
	case ')':
		return 9;
	default:
		throw 1;
	}
}

bool cal::youxianjipanduan(char outp, char inp) {
	if (out(outp) > in(inp))
		return true;
	else
		return false;
}
int cal::youxianjipanduan(char symble) {

	if (symble == ')')
		return 0;
	else if (symble == '#')
		return -1;

	else
		return 1;
}
void cal::dealNum() {                        //将数据栈中的前两个弹出进行计算，结果放回数据栈，符号栈弹出顶部元素 

	char _temp = 0;
	int dtemp1 = 0;
	int dtemp2 = 0;
	symble->del(_temp);
	numberzhan->del(dtemp1);
	numberzhan->del(dtemp2);
	switch (_temp) {
	case '+':
		dtemp2 += dtemp1;
		break;
	case '-':
		dtemp2 = dtemp2 - dtemp1;
		break;
	case '*':
		dtemp2 = dtemp2 * dtemp1;
		break;
	case '/':
		if (dtemp1 == 0)
			throw 0;                     //pao
		else
			dtemp2 = dtemp2 / dtemp1;
		break;
	case '^':
		dtemp2 = pow(dtemp2, dtemp1);
		break;
	case '%':
		dtemp2 = dtemp2 % dtemp1;
		break;
	default:
		throw 1;                         //pao
	}
	numberzhan->push(dtemp2);
}
int cal::calculate() {
	for (int i = 0; i < s.size(); i++) {   //遍历字符串 
		if (isNum(s[i]))
		{
			int temp = (int)(s[i]) - 48;     //char强制类型转换为int ascii 码数值，减 48 转换为对应整数值 
			int _temp = 0;
			if (i > 0 && isNum(s[i - 1])) {
				numberzhan->del(_temp);
				temp = _temp * 10 + temp;
			}
			numberzhan->push(temp);
		}
		else {
			char temp = s[i];
			if (symble->IsEmpty()) {
				symble->push(temp);
			}
			else {
				if (youxianjipanduan(temp, symble->Top())) {
					symble->push(temp);
				}
				else   if (youxianjipanduan(temp) == 1) {                           //栈外优先级小于栈内优先级
					while (!youxianjipanduan(temp, symble->Top()))
					{
						dealNum();
					}
					symble->push(temp);

				}
				else if (youxianjipanduan(temp) == -1) {
					while (symble->Top() != '#') {
						dealNum();
					}
					int result = numberzhan->Top();
					symble->makeempty();
					numberzhan->makeempty();
					return result;
				}
				else if (youxianjipanduan(temp) == 0) {
					while (symble->Top() != '(') {
						dealNum();
					}
					symble->del(temp);
				}
			}
		}
	}
}

int main() {
	try {                      //bao
		string s = "0";
		cal c(s);
		while (1)
		{
			s = "";
			cout << "**********开始计算***********" << endl;
			cout << "&&&&一个数字一个运算符&&&&" << endl;
			cout << "         请善待本计算器         " << endl;
			getline(cin, s);
			c.setString(s);
			int result = 0;
			result = c.calculate();
			cout << c.calculate() << endl;
			cout << "you are good!" << endl;
			system("pause");
			cout << "进行下一轮计算" << endl;

		}
	}

	catch (int paochu) {                                   //zhua
		if (paochu == 0)
			cout << "除数为0，舍";
		else if (paochu == 1)
			cout << "符号无法识别！" << endl;             //使用try throw   catch 进行错误情况处理 
	}
	return 0;
}
