#include<iostream> //���Ӻ� 
using namespace std;
class servent
{
public:
	virtual void job()
	{
		cout<<"servent"<<endl;
	} 

};
class saber:public servent
{
public:
	virtual void job()
	{
		cout<<"saber:��ë���ܳ�"<<endl;
	}
};
class lancer:public servent 
{
public:
	virtual void job()
	{
		cout<<"lancer:������e"<<endl;
	}
};

class archer:public servent 
{
public:
	virtual void job()
	{
		cout<<"archer:��aɶ����"<<endl;
	}
};
class assassin:public servent 
{
public:
	virtual void job()
	{
		cout<<"assassin:���Ŵ�ү"<<endl;
	}
};
class caster:public servent 
{
public:
	virtual void job()
	{
		cout<<"caster:c���Թų��氮"<<endl;
	}
};
class berserker:public servent 
{
public:
	virtual void job()
	{
		cout<<"berserker:b��ǿ�޵�"<<endl;
	}
};
int main()
{
	cout<<"servent֮����ص�:"<<endl; 
	servent *a;
	saber c;
	a=&c;
	a->job();
	lancer l;
	a=&l;
	a->job();
	archer p;
	a=&p;
	a->job();
	assassin q;
	a=&q;
	a->job();
	caster s;
	a=&s;
	a->job();
	berserker b;
	a=&b;
	a->job(); 
	return 0;
}
