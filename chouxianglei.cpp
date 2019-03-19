#include<iostream> //武子涵 
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
		cout<<"saber:呆毛最能吃"<<endl;
	}
};
class lancer:public servent 
{
public:
	virtual void job()
	{
		cout<<"lancer:大狗幸运e"<<endl;
	}
};

class archer:public servent 
{
public:
	virtual void job()
	{
		cout<<"archer:红a啥都会"<<endl;
	}
};
class assassin:public servent 
{
public:
	virtual void job()
	{
		cout<<"assassin:看门大爷"<<endl;
	}
};
class caster:public servent 
{
public:
	virtual void job()
	{
		cout<<"caster:c组自古出真爱"<<endl;
	}
};
class berserker:public servent 
{
public:
	virtual void job()
	{
		cout<<"berserker:b叔强无敌"<<endl;
	}
};
int main()
{
	cout<<"servent之间的特点:"<<endl; 
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
