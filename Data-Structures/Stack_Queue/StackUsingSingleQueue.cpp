#include<iostream>
#include<conio.h>
#define MAX 50
using namespace std;

class queue
{
	int front,rear,q[MAX],size;
	public:
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
	size=0;
}

void queue::input()
{
	cout<<"\nEnter the size of stack::";
	cin>>size;
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
        rear=(rear+1)%size;
        q[rear%size]=e;                 
     }
}

int queue::deque()
{
	 if(front==-1&& rear==-1)
     {  
            cout<<"\nStack is Already Empty!!!\n";
            getch();
            return -1;
     }
     else if((front)%size==(rear)%size)
     {
     	int a=q[front%size];
        front=rear=-1;
        return a;
     }
     else 
     {
        int a=q[front%size];
        front=(front+1)%size;
        return a;
    }
}

int queue::isempty()
{
	if(front==-1 && rear==-1)
	return 1;
	else
	return 0;
}

int queue::isfull()
{
	if((front%size)==((rear+1)%size))
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
     	cout<<"\nStack is :: \n";
     for(int i=front%size;i!=(rear)%size; i=(i+1)%size)
     {
          cout<<q[i]<<"\t\t\n";
     }
     cout<<q[rear]<<"\n";
 	 }
}

int main()
{
	queue obj;
	int choice,val,ct=0,el=0;
	char ch;
	obj.input();
	do
	{
	system("cls");
	obj.display();
	cout<<"\n";	
	cout<<"\n*****STACK USING SINGLE QUEUE*****";
	cout<<"\n1.PUSH.";
	cout<<"\n2.POP.";
	cout<<"\n0.Exit.";
	cout<<"\nEnter choice::";
	cin>>choice;
	if(choice==1)
     {
	    if(obj.isfull())
        {
		cout<<"\n Sorry!!!! STACK is full.\n";
        system("pause"); 
	    }
	   else
       {
		cout<<"\nEnter the element::";
		cin>>val;
		obj.enque(val);
		el++;
		ct=el;
		while(ct!=1)
		{
		 int a=obj.deque();
		 obj.enque(a);
		 ct--;
        }
       }
	}
	else if(choice==2)
	{
		int a=obj.deque();
		el--;
		if(a!=-1)
		cout<<"\nElement popped is = "<<a;getch();
	}
	else if(choice==0)
	exit(0);
	}while(1);
	getch();
	return 0;
}
