#include<iostream>
using namespace std;
typedef struct emm
{
	int data;
	struct emm *next1;
	struct emm *next2;
}EMM,*e;
void zhengxu(e &T)
{
	if (T)
	{
		cout << T->data <<" ";
		zhengxu(T->next1);
		zhengxu(T->next2);
	}
}
void zhongxu(e &T)
{
	if (T)
	{
		zhongxu(T->next1);
		cout << T->data << " ";
		zhongxu(T->next2);

	}
}
void houxu(e &T)
{
	if (T)
	{
		houxu(T->next1);
		houxu(T->next2);
		cout << T->data << " ";
	}
}
void create(e &T)
{
	int c;
	cin >> c;
	if (c == 0)
	{
		T = NULL;
	}
	else
	{
		T = new EMM;
		T->data = c;
		create(T->next1);
		create(T->next2);
	}
}
int main(void)
{
	e T;
	create(T);
	cout << "�������" << endl;
	cout << "����Ϊ��" ;
	zhengxu(T);
	cout << endl << "����Ϊ��";
	zhongxu(T);
	cout << endl << "����Ϊ��";
	houxu(T);
	return 0;
}

