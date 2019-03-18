#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void sound()
	{
		cout<<"animal speak!"<<endl;
		cout<<'\a';
	} 
		virtual void fly()
	{
		cout<<"anaimal can  fly!"<<endl;
	}
		
};有b 
class insect
{ public:
	virtual void crawl()
	{
		cout<<"animal crawl!"<<endl;
		
	} 
		virtual void live()
	{
		cout<<"anaimal can  live everywhere!"<<endl;
	}
      
};
class Cat:public Animal
{
public:
	virtual void sound()
	{
		cout<<"亚瑟王史话2 cat speak!兰斯洛塔逃离。"<<endl;
		cout<<'\a';
	}
};
class Leopard:public Animal
{
public:
	virtual void sound()
	{
		cout<<"leopard speak!王的剑士战死"<<endl;
		cout<<'\a';
	}
};

class lion:public Animal
{
public:
	virtual void sound()
	{
		cout<<"lion speak亚瑟王即将出战!"<<endl;
		cout<<'\a';
	}
};


class gragon:public Animal
{
public:
	virtual void sound()
	{
		cout<<"gragon speak!"<<endl;
		cout<<'\a';
	}
		virtual void fly()
	{
		cout<<"gragon can not only speak,but also can  fly!王拔出了石中剑"<<endl;
		cout<<'\a';
	}
};

class snake:public insect
{
public:	virtual void crawl()
	{
		cout<<"snake crawl!"<<endl;
		
	} 
		virtual void live()
	{
		cout<<"snake can  live in water!蛇即将汇集成怪物之王"<<endl;
	}

};

class monster:public Animal,public insect
{
public:
	virtual void sound()
	{
		cout<<"monster speak!"<<endl;
		cout<<'\a';
	} 
		virtual void fly()
	{
		cout<<"monster can  fly!"<<endl;
	}
		virtual void crawl()
	{
		cout<<"monster crawl!"<<endl;
		
	} 
		virtual void live()
	{
		cout<<"monster can  live everywhere!"<<endl;
	cout<<"however,King Arthur himself captures the monster and cuts off its head,亚瑟王亲自捉住怪物，并砍下它的头"<<endl;
}


	
};

int main()
{
	Animal *a;
	Cat c;
	a=&c;
	a->sound();
	Leopard l;
	a=&l;
	a->sound();
	lion p;
	a=&p;
		a->sound();
		gragon q;
		a=& q;
		a->sound();
		a->fly();
		snake m;
		insect *b;
		b=&m;
		 b->crawl();
		b->live();
		monster z;
		a=&z;
		a->sound();
		a->fly();
	b=&z;
	 b->crawl();
		b->live();
	return 0;

}
