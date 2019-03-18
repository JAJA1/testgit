
#include<iostream>
using namespace std;
typedef int Elemtype; 
 //小雨争打算先自定义一个类型，方便之后的操作 
typedef struct Stacknode
{
    Elemtype data;
    struct Stacknode *next;
}snode;  
               
class LinkStack
{

 public:
    LinkStack();
    int Push(Elemtype data);    //进栈
    int Pop();                  //出栈  
    int Clear();                //清空链栈
    bool isEmpty();             //判空
    int print() const;          //打印链栈内元素 
   ~LinkStack();               //析构,销毁
    static int Count;           //存放栈的大小
    snode *top;                 //栈顶指针

};                                     //至此，类的建造已经结束 
                                       /**初始化栈的长度*/
int LinkStack::Count = 0;

LinkStack::LinkStack()
{
    top = NULL;        //top = NULL表示链栈为空
}


LinkStack::~LinkStack()
{
    snode *p = NULL;
    while(top)           //析构自动，循环释放节点
    {
        p = top->next;
        delete top;
        top = p;
    }
}
/***********************
进栈操作
Push
data为进栈的数据
***********************/
int LinkStack::Push(Elemtype data)
{
    snode *snew = new snode;    //创建新节点
    snew->data = data;          //新节点赋值
    snew->next = top;           //新栈顶指向旧栈顶
    top  = snew;               //top指向新栈顶
    Count ++;
    return 1;
}
/***********************
出栈操作
Pop
***********************/
int LinkStack::Pop()  // 
{
    if(!top)
        return -1;
    if(isEmpty() == 1)
    {
        cout<<"栈为空"<<endl;
        return 1;
    }
    snode *p=top->next;       //预存下一节点的指针
                                    //data = top->data;          //将栈顶元素返回给主函数使用
    delete top;                 //释放栈顶空间
    top = p;                    //栈顶下移
    Count --;
    return 1;
}
// 判断链栈是否为空


bool LinkStack::isEmpty()
{  
    return (top == NULL);       //栈顶为空则返回1 ，不为空返回0
}
/***********************
清空链栈
Clear
形式同析构函数
***********************/
int LinkStack::Clear()
{
    snode *p;
    while(top)                  //循环释放节点
    {
        p = top;
       top = top->next;
       
    }
    return 1;
}
//打印链栈中元素，通过遍历链栈打印元素值


int LinkStack::print() const
{
    snode *p = top;
    while(p && Count)            //栈不为空 && 栈中存在数
    {
        cout<<p->data<<ends<<ends;   //遍历打印栈中数据
        p = p->next;
    }
    return 1;
}
int main()
{
    LinkStack qi;          //定义对象 ls
    int x;                  //输入的可选择数
    cout<<"******************************* "<<endl;
     cout<<"##############################"<<endl;
     cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ "<<endl;
     cout<<"￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥ "<<endl;
     cout<<"******************************* "<<endl;
    cout<<"开始你的表演朋友： "<<endl;
    cout<<"初始  "<<endl;
    cout<<"1: 压栈  "<<endl;
    cout<<"2：出栈  "<<endl;
    cout<<"3：判断栈是否为空  "<<endl;
    cout<<"4：清栈  "<<endl;
    cout<<"5：显示栈长  "<<endl;
    cout<<"6：给我打印  "<<endl;
    cout<<"销毁"<<endl;
    cout<<"******************************* "<<endl;
     cout<<"##############################"<<endl;
     cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ "<<endl;
     cout<<"￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥ "<<endl;
     cout<<"******************************* "<<endl;
     
    cout<<"表演吧，请输入："<<endl;
    
    while(cin>>x)
      {
        switch (x)
        {
            case 1:
                cout<<"输入压栈数：,<如果你想停止输入,请打入0，此0不计入栈长>"<<endl;
				
                cin>>x;
                while(x)
                {
                    qi.Push(x);
                    cin>>x;
                }
                cout<<endl<<"请继续下一步：";
                break;
            case 2:
                if(qi.isEmpty())
                    cout<<"链栈为空栈"<<endl;
                while(qi.top)
                {
                   qi.Pop();
                }
                cout<<endl<<"请输入下一步操作：";
                break;
            case 3:
                if(qi.isEmpty())
                    cout<<"链栈为空栈"<<endl;
                else
                    cout<<"链栈不为空"<<endl;
                cout<<endl<<"请输入下一步操作：";
                break;
            case 4:
                qi.Clear();
                cout<<endl<<"请输入下一步操作：";
                break;
            case 5:
               cout<<qi.Count<<endl;
                cout<<endl<<"请输入下一步操作：";
                break;
            case 6:
                if(qi.isEmpty())
                    cout<<"链栈为空栈"<<endl;
                else
                    qi.print();
                cout<<endl<<"请输入下一步操作：";
                break;
            default: break;
        }
    }
    return 0;
}

