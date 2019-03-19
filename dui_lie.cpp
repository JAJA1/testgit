#include<iostream>
#include<stdlib.h>
typedef struct cunchu{
	int data;
	struct cunchu *next;
}dui;
void zhu(dui *k,dui *u);
void ru(dui *a,dui *w);
void tui(dui *b,dui *e);
void cha(dui *c,dui *r);
void main(void)
{
	dui *h,*s;
	h=s=(dui*)malloc(sizeof(dui));
	h->next=NULL;
	zhu(h,s);
	return ;
}
void zhu(dui *k,dui *u)
{
	int n;
	std::cout<<"jin 1 tui 2 cha 3"<<std::endl;
	std::cin>>n;
	switch(n){
	case 1:ru(k,u);break;
	case 2:tui(k,u);break;
	case 3:cha(k,u);break;
	default:std::cout<<"error"<<std::endl;
	}
	return ;
}
void ru(dui *a,dui *w)
{
	dui *p;
	p=(dui*)malloc(sizeof(dui));
	std::cout<<"data"<<std::endl;
	std::cin>>p->data;
	p->next=NULL;
	w->next=p;
	w=p;
	zhu(a,p);
	return ;
}
void tui(dui *b,dui *e)
{
	dui *p;
	p=b->next;
	b->next=b->next->next;
	free(p);
	zhu(b,e);
	return ;
}
void cha(dui *c,dui *r)
{
	dui *p;
	p=c;
	while(p->next){
		p=p->next;
		std::cout<<p->data<<std::endl;
	}
	zhu (c,r);
	return ;
}