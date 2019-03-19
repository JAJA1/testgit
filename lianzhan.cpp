#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct hhh
{
	int i;
    struct hhh *top;	
}HHH; 
	int main(void)
{
	hhh *p,*head;
	hhh *p1;
	int j;
	int n;
	int x;
	int b=0; 
	cin>>n;
	p1=(HHH*)malloc(sizeof(HHH));
	
	head=p1->top=NULL;//顶针为0； 
	
    for(x=1;x<=n;x++)
    {
    
    	p=(HHH*)malloc(sizeof(HHH));
    	p->i=x;
    	p->top=p1->top;
    	p1->top=p;
        b++;
	}//入栈 
	head=p1=p1->top;
	
   	cout<<"栈顶元素:"<<p1->i<<endl; 
   	
   	cout<<"栈长度为:"<<b<<endl; 
   	
   	cout<<"栈元素为："<<endl;
   	
   	while(p1!=NULL)
	{
    	printf("%3d",p1->i);
		p1=p1->top;
    };
	return 0;
}

