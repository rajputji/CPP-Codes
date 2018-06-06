#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

class queue
{
    node *front,*rear,*temp;
    int size;
    public:
           queue()
           {
           front=rear=NULL;
           size=0;
           }
    void enqueue(int);
    void dequeue();
    void display();
};

void queue::enqueue(int val)
{
    temp = new node;
    temp->data=val;
    if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    size++;
}

void queue::dequeue()
{
    if(front==NULL || size==0)
    {cout<<"\nQueue is Already Empty.";
    getch();
    }else
    {
        node *temp=front;
        front=front->next;
        delete temp;
        size--;
    }
}

void queue::display()
{
        node *T= front;
        int i=1;
        if(T==NULL || size==0)
        cout<<"\nQueue is empty !!!";
        else
        {
        cout<<"\nQueue is :: "<<endl;
		while(i<=size)
             {
		     cout<<T->data<<" ";
		     T=T->next;
		     i++;
             }
        }
}
int main()
{
        queue obj;
        int ch,d;
        do
		{
        system("cls");
        obj.display();
        cout<<"\n";
        cout<<"\n******Queue-As Linked List*****";
        cout<<"\n 1. Enqueue.";
		cout<<"\n 2. Dequeue.";
		cout<<"\n 3. Exit.";
		cout<<"\nEnter choice::";
        cin>>ch;
         switch(ch)
         {
            case 1: cout<<"Enter element::";
                    cin>>d;
                    obj.enqueue(d);
                    break;
            case 2: obj.dequeue();
                    break;
            case 3: exit(0);
            	    break;
         }
         }while(1);
getch();
return 0;
}
