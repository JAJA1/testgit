#include<iostream>
using namespace std;
 struct  node
{ int data;
 struct node *next;
 } ;
 
 struct jQueue//zuoqianquhehouquzhizhen
{   
    struct node *rear;
    struct node *front;      
    
    int n; //fubiao      
};


void create(struct  jQueue *Q)  //jianliduilie
{
    
    struct node *head = new node;
    head->next = NULL;  
    Q->front = head;
    Q->rear = head;
    Q->n = 0;
}; 

void queuePop(struct jQueue *Q)  //chulie
{
    struct node *temp;
    if(Q->front->next != NULL)
    {
        temp = Q->front->next; 
        Q->front->next = Q->front->next->next;
        cout<<temp->data<<endl;
               delete(temp);
        if(Q->front->next == NULL)  //zhenduiteshuqingkuang
            Q->rear = Q->front;
        Q->n--;
    }
};
void queueInsert(struct jQueue *Q, int num) //rulie
{
    struct node *p = new node;
    p->data = num;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    Q->n++;
};

void print(struct jQueue *Q)
{
    cout<<"´òÓ¡"<<endl;
    struct node *temp = Q->front;
   
         while(temp != Q->rear)
        {
            cout<<temp->next->data<<endl;
            temp = temp->next;
            
        }
    
    cout<<"½áÊø"<<endl;
    cout<<endl;
    
}




int main()
{   jQueue Q;
create(&Q);
   	queueInsert(&Q, 6);
    queueInsert(&Q, 4); 
    queueInsert(&Q, 6);
    queueInsert(&Q, 3);
    queueInsert(&Q, 9);
    print(&Q);  queuePop(&Q);                
    print(&Q);  queuePop(&Q);
    print(&Q);  queuePop(&Q);
    print(&Q);   queuePop(&Q);
    print(&Q);   queuePop(&Q);
    return 0;
}


