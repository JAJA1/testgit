#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct hhh
{
	int i;
	struct hhh *top;
	struct hhh *low;
}HHH;
int main(void)
{
	HHH	*r,*s,*p;
	int x,n,a=0;
	cin>>n;
	r=(HHH*)malloc(sizeof(HHH));
	p=r;
	p->low=NULL;
	r->top=NULL;
	for(x=1;x<=n;x++)
	{
		s=(HHH*)malloc(sizeof(HHH));
		s->i=x;
		s->top=r->top;
		r->top=s;
		r=s;
		a++;
	}
	p=p->top;
	cout<<"³¤¶ÈÎª"<<a<<endl;
   while(p!=NULL)
   {	
    	cout<<p->i;
		p=p->top;
   }
	return 0;
 } 
