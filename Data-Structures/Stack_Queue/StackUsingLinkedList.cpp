#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

class stack 
{
   int size;
   node *temp,*top;
   public:
    stack()
    {
    	top=NULL;
    	temp=NULL;
    	size=0;
	}
    void push(int n);
	void pop();
	void show();
	void clear();
};

void stack::push(int val)
{   
	temp=new node;
	temp->data=val;
	temp->next=top;
	top=temp;
	size++;
}

void stack::pop()
{
	if(top!=NULL)
	{
	    node *T=top;
		top=top->next;
        cout<<T->data<<" value popped.";
        getch();
        delete T;
        size--;
    }
    else
    {
        cout<<"\nStack Empty!!";
        getch();
    }
}

void stack::show()
{   
    node *T= top;
    if(T==NULL)
    {cout<<"\nEmpty!!";
    getch();
    }
    else
    {
    cout<<"\nStack is:: \n";
    while(T!=NULL)
    {
	   cout<<"\t\t"<<T->data<<"\n";
       T=T->next;
    }
    getch();
    }
}

void stack::clear()
{
	top=NULL;
	size=0;
	cout<<"\nStack cleared.";
	getch();
}

int main()
{
    stack Obj;
    int ch,n;
    do{
    system("cls");
    cout<<"-----STACK AS LINKED LIST------";
    cout<<endl<<"1. Push.\n2. Pop.\n3. clear.\n4. Display.\n5. Exit.\nEnter choice::\t";
    cin>>ch;
    switch(ch)
    {
              case 1: cout<<"Enter the number to push into the stack:";
                      cin>>n;
                      Obj.push(n);
                      break;
                      
              case 2: Obj.pop();break;
              case 3: Obj.clear();break;
              case 4: Obj.show();break;
              case 5: exit(0);
    }
    }while(1);
    
getch();
return 0;    
}
