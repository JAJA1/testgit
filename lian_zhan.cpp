#include<iostream>
#include<stdlib.h>
typedef struct cunchu{
	int data;
	struct cunchu *next;
}zhan;
void zhu(zhan *a);
zhan* ru (zhan *b);
zhan* tui (zhan *c);
void cha (zhan *d);
void main(void)
{
	zhan *h=(zhan*)malloc(sizeof(zhan));
	h->next=NULL;
	zhu(h);
	return ;
}
void zhu(zhan *a)
{
	int n;
	std::cout<<"jin 1 tui 2 cha 3"<<std::endl;
	std::cin>>n;
	switch(n){
	case 1:ru(a);break;
	case 2:tui(a);break;
	case 3:cha(a);break;
	default:std::cout<<"error"<<std::endl;
	}
	return ;
}
zhan* ru (zhan *b)
{
	zhan *p,*q;
	q=b;
	p=(zhan*)malloc(sizeof(zhan));
	std::cout<<"data "<<std::endl;
	std::cin>>p->data;
	p->next=q->next;
	q->next=p;
	zhu(b);
	return b;
}
zhan* tui(zhan *c)
{
	zhan *p;
	if(c->next)
	{
		p=c->next;
		c->next=c->next->next;
		free(p);
	}
	else{
		std::cout<<"yi"<<std::endl;}
	zhu(c);
	return c;
}
void cha(zhan *d)
{
	zhan *p=d;
	while(d->next){	
		std::cout<<d->next->data<<std::endl;
		d=d->next;
	}
	zhu(p);
	return ;
}