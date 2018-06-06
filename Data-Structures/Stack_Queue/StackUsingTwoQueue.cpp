#include<iostream>
#include<conio.h>
#define MAX 50
using namespace std;

class queue
{
      int front, rear,e;
      int q[MAX];
      public:
             int size;
             queue();
             void input();
             void enque(int);
             int deque();
             int isempty();
             int isfull();
             void display();
};

queue::queue()
{
     front=rear=-1;
     e=size=0;
}

void queue::enque(int e)
{
    if(front==-1 && rear==-1)
     {
    	q[0]=e;
        front++;
		rear++;
     }
     else
     {
           if((rear+1)%size==(front)%size)
           {
		   cout<<"\nStack is full.";
		   getch();
           return;
           }
           else
           { 
               rear=(rear+1)%size;
               q[rear%size]=e;   
           }                  
     }
}

int queue::deque()
{
    if(front==-1&& rear==-1)
     {  
            cout<<"\nStack is Already Empty!!!";
            getch();
            return 0;
     }
     else if((front)%size==(rear)%size)
     {
     	int t=q[front%size];
        front=rear=-1;
        return t;
     }
     else 
     {
        int t=q[front%size];
        front=(front+1)%size;
        return t;
    }
}

int queue::isfull()
{
     if((rear+1)%size==(front)%size)
     return 1;
     else 
     return 0;
}

int queue::isempty()
{
     if((front==-1 && rear==-1) || (front>rear))
     return 1;
     else 
     return 0;
}

void queue::display()
{
    if(front==-1&&rear==-1)
    cout<<"\nStack is Empty!!!";
    else
    {
   	 cout<<"\nStack is :: \t\t";
     for(int i=front%size;i!=(rear)%size; i=(i+1)%size)
     {
          cout<<q[i]<<"\n\t\t\t";
     }
     cout<<q[rear];
 	 }
}

int main()
{
    queue obj1,obj2;
    int choice,e;
    cout<<"Enter the size of stack::";
    cin>>obj1.size;
    obj2.size=obj1.size;
    do{
    system("cls");
    if(obj1.isempty())
        obj2.display();
    else
        obj1.display();
    cout<<"\n";
    cout<<"\n*****STACK USING QUEUE******";
    cout<<"\n1.PUSH";
    cout<<"\n2.POP";
    cout<<"\n0.exit.";
    cout<<"\nEnter choice::";
    cin>>choice;
    if(choice==1)
    {
      if(obj1.isempty())
      {
        if(obj2.isfull()==0)
        {
        cout<<"\nEnter value::";
        cin>>e; 
        obj1.enque(e);
        while(!obj2.isempty())
        {e=obj2.deque();
         obj1.enque(e);
        }
        }
        else
        {cout<<"\nStack is full.";getch();}
      }
      else
      {
        if(obj1.isfull()==0)
        {
        cout<<"\nEnter value::";
        cin>>e;
        obj2.enque(e);
        while(!obj1.isempty())
        {e=obj1.deque();
         obj2.enque(e);
        }
        }
        else
        {cout<<"\nStack is full.";getch();}
      }        
    }
    else if(choice==2)
    {
         if(obj1.isempty())
         {
           e=obj2.deque();
           cout<<"\nElement popped = "<<e;getch();
         }
         else
         {
            e=obj1.deque();
            cout<<"\nElement popped = "<<e;getch();
         }
    }
    else if(choice==0)
    exit(0);
    }while(1);
    getch();
    return 0;
}
