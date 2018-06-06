#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
       int data;
       node *next;
};
class ll
{
      public:
      		 int size;
			 node *head, *temp;
             ll()
             {
                 head=temp=NULL;
                 size=0;
             }
             void create(int);
             void insertatbeg(int);
             void insertatmid(int,int);
             void insertatend(int);
             void beforeval(int, int);
             void afterval(int, int);
             void delhead();
             void deltail();
             void delpos(int);
             void display();
             void search();
             void reverse();
};

void ll::create(int v)
{
       temp=new node;
       temp->data=v;
       temp->next=NULL;
       head=temp;
       size++;
}

void ll::insertatbeg(int v)
{
	if(head==NULL)
	create(v);
	else
	{
     temp=new node;
     temp->data=v;
     temp->next=head;
     head=temp;
     size++;
 	}
}

void ll::insertatmid(int v,int pos)
{
	if(pos==1)
	insertatbeg(v);
	else if(pos==size+1)
	insertatend(v);
	else if(pos<=0 || pos>size)
    {
     cout<<"\nInvalid Position!!!!";
     getch();
 	}
	else
	{
     node *T;
     T=head;
     int count=1;
     while(count<pos-1)
     {T=T->next;
     count++;
     }
     temp=new node;
     temp->next=T->next;
     temp->data=v;
     T->next=temp;
     size++;
 	}
}

void ll::insertatend(int v)
{
	if(head==NULL)
	create(v);
	else
	{
     temp=new node;
     temp->data=v;
     temp->next=NULL;
     node *T;
     T=head;
     while(T->next!=NULL)
     {
       T=T->next;
     }
     T->next=temp;
     size++;
 	}
}

void ll::beforeval(int val,int v)
{
     node *T=head;
     if(T->data==val)
     {
       temp= new node;
       temp->data=v;
       temp->next=head;
       head=temp;
     }
     else
     {
        	while((T->next)->data!=val)
         	{
         	T=T->next;
         	if(T->next==NULL)
         	{
         	cout<<"\nEntered value was not found in list!!!!";
         	getch();
         	return;
     		}
			}
         	temp= new node;
         	temp->data=v;
         	temp->next=T->next;
         	T->next=temp;
     }
     size++;
}

void ll::afterval(int val,int v)
{
     node *T=head;
     while(T->data!=val)
     {
		if(T->next==NULL)
        {
        cout<<"\nEnter value was not found in list!!!!";
        getch();
        return;
     	}
    	T=T->next;
	 }
     temp= new node;
     temp->data=v;
     temp->next=T->next;
     T->next=temp;
     size--;
}

void ll::delhead()
{
     node *T=head;
     head=T->next;
     size--;
     delete T;
}
void ll::deltail()
{
     node *T=head;
     if(T->next==NULL)
     {
       head=NULL;
     }
     else
     {
     while((T->next)->next!=NULL)
       { T=T->next;
       }
     T->next=(T->next)->next;
     }
     size--;
}

void ll::delpos(int pos)
{
     if(pos==1)
     delhead();
     else if(pos==size)
     deltail();
     else if(pos<=0 || pos>size)
     {
     cout<<"\nInvalid Position!!!!";
     getch();
 	 }
     else
     {
         node *T=head;
         int ct=1;
         node *p=T->next;
         while(ct<pos-1)
         {
           T=T->next;
           p=T->next;
           ct++;
          }
          if(p->next==NULL)
          T->next;
          else
          {
            T->next=p->next;
            delete p;
          }
     size--;
     }
}

void ll::display()
{
     node *T;
     T=head;
     if(T==NULL)
     {
     cout<<"The List is empty!!"<<endl;
     }
     else
     {
     cout<<"Current list is::\n";
     while(T!=NULL)
     {
     cout<<T->data<<" ";
     T=T->next;
     }
     cout<<"\n\nSize = "<<size<<endl;
     }
}

void ll::search()
{
	int e,ct=1;
	if(head==NULL)
	{
	cout<<"\nList Doesn't Existed!!!";
	getch();
	return;
	}
	
	cout<<"\nEnter the Element to search:: ";
	cin>>e;
	node *T=head;
	while(T->data!=e)
	{
	T=T->next;
	ct++;
	if(T==NULL)
	{
		cout<<"\nElement Not Found.";
		getch();
		return;
	}
	}
	
	cout<<"\nElement was found at position "<<ct<<".";
	getch();
}

void ll::reverse()
{
	if(head==NULL)
	{
		cout<<"\nList Doesn't Exist!!!!";
		getch();
		return;
	}
	else if(head->next==NULL)
	return;
	
	
	node *t=head;
	node *p=t->next;
	node *q=p->next;
	t->next=NULL;
    while(q!=NULL)
    {
        p->next=t;
        t=p;
        p=q;
        q=q->next;
    }

    p->next=t;
    head=p;
}

int main()
{
    ll obj;
    int choice,e,ans,pos;
    do{
    system("cls");
    obj.display();
    cout<<"\n**********MENU*****************";
    cout<<"\n1.Insertion.";
    cout<<"\n2.Deletion.";
    cout<<"\n3.Search an Element.";
    cout<<"\n4.Reverse the List.";
    cout<<"\n0.Exit.";
    cout<<"\n\nEnter choice::";
    cin>>choice;
    switch(choice)
    {
       case 1:
            cout<<"\n1. Insert at beginning.";
            cout<<"\n2. Insert at a position.";
            cout<<"\n3. Insert at end.";
            cout<<"\n4. Insert before a value.";
            cout<<"\n5. Insert after a value.";
            cout<<"\nEnter choice::";
            cin>>ans;
            if(ans==1)
            {
			cout<<"\nEnter the Element:: ";
            cin>>e;
			obj.insertatbeg(e);
			}
            else if(ans==2)
            {
			cout<<"\nEnter the postion:: ";
            cin>>pos;
            cout<<"\nEnter the Element:: ";
            cin>>e;
            obj.insertatmid(e,pos);
            }
            else if(ans==3)
            {
			cout<<"\nEnter the Element:: ";
            cin>>e;
			obj.insertatend(e);
			}
			else if(ans==4 || ans==5)
			{
				if(obj.head==NULL)
				{
				cout<<"\nList doesn't Exit!!";
				getch();
				}
				else
				{
				if(ans==4)
            	{
				cout<<"\nEnter that value::";
            	cin>>pos;
            	cout<<"\nEnter the new element::";
            	cin>>e;
            	obj.beforeval(pos,e);
            	}
            	else if(ans==5)
            	{
				cout<<"\nEnter that value::";
            	cin>>pos;
            	cout<<"\nEnter new element::";
            	cin>>e;
            	obj.afterval(pos,e);
            	}
            	}
            }
            	break;
       case 2:
            if(obj.head!=NULL)
            {
            cout<<"\n1. Delete from begining.";
            cout<<"\n2. Delete from last.";
            cout<<"\n3. Delete by position.";
            cout<<"\nChoice::";
            cin>>ans;
            if(ans==1)
            {obj.delhead();}
            else if(ans==2)
            {obj.deltail();}
            else if(ans==3)
            {
                 cout<<"\nEnter the position of node to be deleted::";
                 cin>>pos;
                 obj.delpos(pos);
            }
            }
            else
            {
            cout<<"\nError!!! List is Empty.";
            getch();
            }
			break;
	   case 3:obj.search();
	   		  break;
	   case 4:obj.reverse();
	   		  break;
	   		  
       case 0:exit(0);
       default: cout<<"Wrong choice!!!";
                break;
    }
    }while(1);
    getch();
    return 0;
}
