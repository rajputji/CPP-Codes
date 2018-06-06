#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class cdll
{
    node *tail;
    int size;
	public:
    	cdll()
    	{
        size=0;
        tail=NULL;
    	}
    void create(int);
    void insertatbeg(int);
    void insertatend(int);
    void insertbypos(int,int);
    void deletehead();
    void deletetail();
    void deletepos(int);
    void display();
    void reverse();
    void search(int);
};

void cdll::create(int val)
{
	node *temp=new node;
	temp->data=val;
	tail=temp;
	tail->next=tail;
	tail->prev=tail;
	size=1;
}
void cdll::insertatbeg(int val)
{
    node* temp=new node;
    temp->data=val;
    if(tail==NULL)
    {
        tail=temp;
        tail->next=tail;
        tail->prev=tail;
    }
    else
    {
        temp->next=tail->next;
        temp->prev=tail;
        tail->next=temp;
    }
    size++;
}

void cdll::insertatend(int val)
{
    node *temp=new node;
    temp->data=val;
    if(tail==NULL)
    {
        tail=temp;
        tail->next=tail;
        tail->prev=tail;
    }
    else
    {
    temp->next=tail->next;
    temp->prev=tail;
    tail->next=temp;
    temp->next->prev=temp;
    tail=temp;
	}
    size++;
}

void cdll::insertbypos(int val,int pos)
{
	if(pos==0)
	{
		cout<<"\nError!!!";getch();
		return;
	}
	else if(pos==1)
	insertatbeg(val);
	else if(pos==size+1)
	insertatend(val);
	else if(pos>size)
	{
	cout<<"\nPosition Exceeded the size!!!";getch();
	}
	else
    {
     node *t=tail;
     int ct=1;
     while(ct<=pos-1)
     {
	 t=t->next;
     ct++;
     }
     node *temp=new node;
     temp->data=val;
     temp->next=t->next;
     t->next->prev=temp;
     t->next=temp;
     temp->prev=t;
     size++;
 	 }
}
void cdll::deletehead()
{
    if(tail==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
        return;
    }
    node *t=tail->next;
    tail->next=tail->next->next;
    tail->next->prev=tail;
    delete t;
}

void cdll::deletetail()
{

    if(tail==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
        return;
    }
    if(tail->next==tail)
    {
    	tail=NULL;
    	size--;
    	return;
    }

    node *t=tail->next->next;
    while(t->next->next!=tail)
        t=t->next;
    node *p=t->next;
    t->next=t->next->next;
    delete p;
    size--;
}

void cdll::deletepos(int pos)
{
    if(tail==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
        return;
    }
    else if(pos<=0 || pos>size+1)
    {
        cout<<"\nInvalid Position!!!";
        return;
    }
    node *t;
    int ct;
    if(pos>=size/2)
    {
        ct=size;
        t=tail;
        while(ct!=pos)
        {
            t=t->next;
            cout<<ct<<" ";
            ct--;
        }
    }
    else
    {
        ct=1;
        t=tail->next;
        while(ct!=pos)
        {
            t=t->next;
            cout<<ct<<"-";
            ct++;
        }
    }


    node *p=t;
    t=p->prev;
    t->next=p->next;
    p->next->prev=t;
    delete p;
    size--;
    getch();
}

void cdll::reverse()
{
    if(tail==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
        return;
    }
    node *head=tail->next;
	node *t=tail->next;
	node *p;
    do
    {
        p=t->next;
        t->next=t->prev;
        t->prev=p;
        t=t->next;
    }while(t!=head);

    tail=head;
}

void cdll::search(int val)
{
    if(tail==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
		return;
    }
    
    if(tail->data==val)
    {
        cout<<"\nElement was found at position "<<size<<".";getch();
        return;
    }
    
    int ct=1;
    node *t=tail->next;
    do
    {
        if(t->data==val)
            break;
            
        t=t->next;
        ct++;
    }while(t!=tail);

    if(t!=tail)
    {
        cout<<"\nElement was found at position "<<ct<<".";getch();
    }
    else
    {
        cout<<"\nElement was not found.";getch();
    }
}

void cdll::display()
{
    if(tail==NULL)
    {
        cout<<"\n\t\tThe list is Empty!!!";
        return;
    }
    cout<<"\n\t\tThe List is :: ";
    node *t=tail->next;
    do
    {
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=tail->next);
    
	cout<<"\n\n\t\tThe Size = "<<size;
}

int main()
{
    cdll obj;
    int ch,val,pos;
    do
    {
        system("cls");
        obj.display();
        cout<<"\n";
        cout<<"\n\t\t*****CIRCULAR-DOUBLY-LINKED-LIST******"<<endl;
        cout<<"\n\t\t1. Create";
		cout<<"\n\t\t2. Insert at Beginning";
		cout<<"\n\t\t3. Insert at End";
		cout<<"\n\t\t4. Insert by position";
		cout<<"\n\t\t5. Delete From Beginning";
		cout<<"\n\t\t6. Delete From End";
		cout<<"\n\t\t7. Delete by position";
		cout<<"\n\t\t8. Reverse the Linked List";
		cout<<"\n\t\t9. Search an Element";
		cout<<"\n\t\t0. Exit";
		cout<<"\n\n\t\tEnter your choice::";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nEnter the Element::";
                    cin>>val;
                    obj.create(val);
                    break;
            case 2: cout<<"\nEnter the Element::";
                    cin>>val;
                    obj.insertatbeg(val);
                    break;
            case 3: cout<<"\nEnter The Element::";
                    cin>>val;
                    obj.insertatend(val);
                    break;
            case 4: cout<<"\nEnter the Element::";
            		cin>>val;
            		cout<<"\nEnter Position::";
            		cin>>pos;
            		obj.insertbypos(val,pos);
            		break;
            case 5: obj.deletehead();
                    break;
            case 6: obj.deletetail();
                    break;
            case 7: cout<<"\nEnter Position to be deleted ::";
                    cin>>val;
                    obj.deletepos(val);
                    break;
			case 8: obj.reverse();
					break;
			case 9: cout<<"\nEnter the Element to Search::";
					cin>>val;
					obj.search(val);
					break;
            case 0: exit(0);
            		break;
        }
    }while(1);

return 0;
}
