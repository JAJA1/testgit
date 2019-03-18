
#include<iostream>
using namespace std;
typedef int Elemtype; 
 //С�����������Զ���һ�����ͣ�����֮��Ĳ��� 
typedef struct Stacknode
{
    Elemtype data;
    struct Stacknode *next;
}snode;  
               
class LinkStack
{

 public:
    LinkStack();
    int Push(Elemtype data);    //��ջ
    int Pop();                  //��ջ  
    int Clear();                //�����ջ
    bool isEmpty();             //�п�
    int print() const;          //��ӡ��ջ��Ԫ�� 
   ~LinkStack();               //����,����
    static int Count;           //���ջ�Ĵ�С
    snode *top;                 //ջ��ָ��

};                                     //���ˣ���Ľ����Ѿ����� 
                                       /**��ʼ��ջ�ĳ���*/
int LinkStack::Count = 0;

LinkStack::LinkStack()
{
    top = NULL;        //top = NULL��ʾ��ջΪ��
}


LinkStack::~LinkStack()
{
    snode *p = NULL;
    while(top)           //�����Զ���ѭ���ͷŽڵ�
    {
        p = top->next;
        delete top;
        top = p;
    }
}
/***********************
��ջ����
Push
dataΪ��ջ������
***********************/
int LinkStack::Push(Elemtype data)
{
    snode *snew = new snode;    //�����½ڵ�
    snew->data = data;          //�½ڵ㸳ֵ
    snew->next = top;           //��ջ��ָ���ջ��
    top  = snew;               //topָ����ջ��
    Count ++;
    return 1;
}
/***********************
��ջ����
Pop
***********************/
int LinkStack::Pop()  // 
{
    if(!top)
        return -1;
    if(isEmpty() == 1)
    {
        cout<<"ջΪ��"<<endl;
        return 1;
    }
    snode *p=top->next;       //Ԥ����һ�ڵ��ָ��
                                    //data = top->data;          //��ջ��Ԫ�ط��ظ�������ʹ��
    delete top;                 //�ͷ�ջ���ռ�
    top = p;                    //ջ������
    Count --;
    return 1;
}
// �ж���ջ�Ƿ�Ϊ��


bool LinkStack::isEmpty()
{  
    return (top == NULL);       //ջ��Ϊ���򷵻�1 ����Ϊ�շ���0
}
/***********************
�����ջ
Clear
��ʽͬ��������
***********************/
int LinkStack::Clear()
{
    snode *p;
    while(top)                  //ѭ���ͷŽڵ�
    {
        p = top;
       top = top->next;
       
    }
    return 1;
}
//��ӡ��ջ��Ԫ�أ�ͨ��������ջ��ӡԪ��ֵ


int LinkStack::print() const
{
    snode *p = top;
    while(p && Count)            //ջ��Ϊ�� && ջ�д�����
    {
        cout<<p->data<<ends<<ends;   //������ӡջ������
        p = p->next;
    }
    return 1;
}
int main()
{
    LinkStack qi;          //������� ls
    int x;                  //����Ŀ�ѡ����
    cout<<"******************************* "<<endl;
     cout<<"##############################"<<endl;
     cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ "<<endl;
     cout<<"������������������������������ "<<endl;
     cout<<"******************************* "<<endl;
    cout<<"��ʼ��ı������ѣ� "<<endl;
    cout<<"��ʼ  "<<endl;
    cout<<"1: ѹջ  "<<endl;
    cout<<"2����ջ  "<<endl;
    cout<<"3���ж�ջ�Ƿ�Ϊ��  "<<endl;
    cout<<"4����ջ  "<<endl;
    cout<<"5����ʾջ��  "<<endl;
    cout<<"6�����Ҵ�ӡ  "<<endl;
    cout<<"����"<<endl;
    cout<<"******************************* "<<endl;
     cout<<"##############################"<<endl;
     cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ "<<endl;
     cout<<"������������������������������ "<<endl;
     cout<<"******************************* "<<endl;
     
    cout<<"���ݰɣ������룺"<<endl;
    
    while(cin>>x)
      {
        switch (x)
        {
            case 1:
                cout<<"����ѹջ����,<�������ֹͣ����,�����0����0������ջ��>"<<endl;
				
                cin>>x;
                while(x)
                {
                    qi.Push(x);
                    cin>>x;
                }
                cout<<endl<<"�������һ����";
                break;
            case 2:
                if(qi.isEmpty())
                    cout<<"��ջΪ��ջ"<<endl;
                while(qi.top)
                {
                   qi.Pop();
                }
                cout<<endl<<"��������һ��������";
                break;
            case 3:
                if(qi.isEmpty())
                    cout<<"��ջΪ��ջ"<<endl;
                else
                    cout<<"��ջ��Ϊ��"<<endl;
                cout<<endl<<"��������һ��������";
                break;
            case 4:
                qi.Clear();
                cout<<endl<<"��������һ��������";
                break;
            case 5:
               cout<<qi.Count<<endl;
                cout<<endl<<"��������һ��������";
                break;
            case 6:
                if(qi.isEmpty())
                    cout<<"��ջΪ��ջ"<<endl;
                else
                    qi.print();
                cout<<endl<<"��������һ��������";
                break;
            default: break;
        }
    }
    return 0;
}

