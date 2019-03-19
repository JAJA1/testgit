#include<iostream>
using namespace std;
class ji
{
public:
	virtual void xu()
	{
		cout<<" #"<<endl;
	} 

};
class a1:public ji
{
public:
	virtual void xu()
	{
		cout<<" 1"<<endl;
	}
};
class a2:public ji 
{
public:
	virtual void xu()
	{
		cout<<" 2"<<endl;
	}
};
void main()
{
	ji *p;
	a1 b;
	p=&b;
	p->xu();
	a2 c;
	p=&c;
	p->xu();
	return ;
}
