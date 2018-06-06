#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 50
class stack
{
      int top,e,size;
      int stk[MAX];
      public:
             stack();
             void input();
             void push(int e);
             int pop();
             int isempty();
             int isfull();
             void display();
             void clear();
};

stack::stack()
{
              top=-1;
              e=0;
}
void stack::input()
{
     cout<<"\nEnter the size of stack::";
     cin>>size;
}

void stack::push(int e)
{
    if(isfull())
    {
    cout<<"STACK is FULL!! Cannot enter more elements!!";
    getch();
    return;
    }
    else
    {
        top++;
        stk[top]=e;
    }
}

int stack::pop()
{
    if(isempty())
    {cout<<"STACK is Empty!! NO element";
    getch();
    return 0;
    }
    else
    {
    int x=stk[top--];
    cout<<"\nElement popped is : "<<x;
    getch();
    return x;
	}
}

int stack::isfull()
{
     if(top==size-1)
     return 1;
     else 
     return 0;
}

int stack::isempty()
{
     if(top==-1)
     return 1;
     else 
     return 0;
}

void stack::display()
{
     if(isempty())
     cout<<"\nStack is Empty!!";
     else
     {
     cout<<"\nSTACK is::\n";
     for(int i=top;i>=0;i--)
     {
     cout<<"\t\t"<<stk[i]<<"\n";
     }
     }
     getch();
}

void stack::clear()
{
	top=-1;
}

int main()
{
    stack ob;
    int choice,e;
    ob.input();
    do{
    system("cls");
    cout<<"\n*****STACK MENU*****";
    cout<<"\n1.PUSH";
    cout<<"\n2.POP";
    cout<<"\n3.CLEAR.";
    cout<<"\n4.Display.";
    cout<<"\n5.Exit.";
    cout<<"\nEnter choice::";
    cin>>choice;
    if(choice==1)
     {
     cout<<"\nEnter the Value::";
     cin>>e;
     ob.push(e);
     }
    else if(choice==2)
    ob.pop();
    else if(choice==3)
    ob.clear();
    else if(choice==4)
    ob.display();
    else if(choice==5)
    exit(0);
    }while(1);
    getch();
    return 0;
}
