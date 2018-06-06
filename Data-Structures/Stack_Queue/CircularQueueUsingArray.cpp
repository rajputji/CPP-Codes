#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 50
class queue
{
      int q[MAX],e,front,rear,size;
      public :
	  		queue();
	  		void input();
            void enqueue();
            void dequeue();
            void display();
};

queue::queue()
{
	e=size=0;
	front=rear=-1;
}

void queue::input()
{
	cout<<"\nEnter the size :: ";
	cin>>size;
}

void queue::enqueue()
{
     cout<<"\nEnter the element :: ";
     cin>>e;
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
		   cout<<"\nQueue is full ";
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

void queue::dequeue()
{
     if(front==-1&& rear==-1)
     {  
            cout<<"\nQueue is Already Empty!!!";
            getch();
            return ;
     }
     else if((front)%size==(rear)%size)
     {
     	cout<<"\nDeleting "<<q[front%size]<<"\n";getch();
        front=rear=-1;
        return ;
     }
     else 
     {
        cout<<"\nDeleting "<<q[front%size]<<"\n";getch();
        q[front%size]=0;
        front=(front+1)%size;
    }
}

void queue::display()
{    
     if(front==-1&&rear==-1)
     cout<<"\nQueue is Empty!!!";
     else
     {
     	cout<<"\nQueue is :: \n";
     for(int i=front%size;i!=(rear)%size; i=(i+1)%size)
     {
          cout<<q[i]<<" ";
     }
     cout<<q[rear];
 	 }
}

int main()
{
    queue obj;
    int ch,ans;
    obj.input();
    do
    {
    system("cls");
    obj.display();
    cout<<"\n\t\t*****Main Menu*****";
    cout<<"\n1. Enqueue ";
    cout<<"\n2. Dequeue ";
    cout<<"\n3.Exit.";
    cout<<"\n\nEnter your choice :";
    cin>>ch;
    switch(ch)
    {
    	case 1: obj.enqueue(); break;
    	case 2: obj.dequeue(); break;
    	case 3: exit(0); break;
    	default: cout<<"\nWrong choice!!!";getch();
    }   
    }while(1);
    return 0;

}
