#include<iostream>
#include<conio.h>

using namespace std;
struct node
{
    int data;
    node* next;
};

class cll
{
    node *head,*tail;
    int size;
    public:
    cll()
    {
        head=tail=NULL;
        size=0;
    }
    
    void create(int);
    void insertatbeg(int);
    void insertatend(int);
    void insertbypos(int,int);
    void deletetail();
    void deletehead();
    void deletepos(int);
    void display();
    void reverse();
    void search(int);
};

void cll::create(int val)
{
    node *temp=new node;
    temp->data=val;
    head=tail=temp;
    tail->next=head;
    size++;
}

void cll::insertatbeg(int val)
{
    if(size==0)
    {
        cout<<"\nSorry!!! List is Empty!!!";getch();
        return;
    }
    else
    {
       node *temp=new node;
       temp->data=val;
       temp->next=head;
       head=temp;
       tail->next=head;
       size++;
    }
}

void cll::insertatend(int val)
{
    if(size==0)
    {
        cout<<"\nSorry!!! List is Empty!!!";getch();
        return;
    }
    else
    {
        node *temp=new node;
        temp->data=val;
        tail->next=temp;
        tail=temp;
        tail->next=head;
        size++;
    }
}

void cll::insertbypos(int val,int pos)
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
     node *t=head;
     int ct=1;
     while(ct<pos-1)
     {
	 t=t->next;
     ct++;
     }
     node *temp=new node;
     temp->next=t->next;
     temp->data=val;
     t->next=temp;
     size++;
 	 }
}


void cll::deletehead()
{
    if(size==0)
    {
        cout<<"\nSorry!!! List is Empty!!!";getch();
        return;
    }
    else if(head==tail)
    {
        head=tail=NULL;
        size--;
        return;
    }
    node *temp=head;
    head=head->next;
    tail->next=head;
    delete temp;
    size--;
}

void cll::deletetail()
{
     if(size==0)
    {
        cout<<"\nSorry!!! List is Empty!!!";getch();
        return;
    }
     else if(head==tail)
    {
        head=tail=NULL;
        size--;
        return;
    }
    node* t=head;
    while(t->next->next!=head)
    {t=t->next;}
    
    t->next=head;
    
	node *p=tail;
    tail=t;
    delete p;
    size--;
}

void cll::deletepos(int pos)
{
    if(size==0)
    {
        cout<<"\nSorry!!! List is Empty!!!";getch();
        return;
    }
    else if(pos>size || pos<=0)
    {
        cout<<"\nInvalid position!!!!";getch();
        return;
    }
    else if(pos==1)
    {
        deletehead();
        return;
    }
    else if(pos==size)
    {
        deletetail();
        return;
    }

    int ct=1;
    node *t=head;
    while(ct!=pos-1)
    {
        t=t->next;
        ct++;
    }
    node *p=t->next;
    t->next=p->next;
    delete p;
    size--;
}

void cll::display()
{
    if(size==0)
    {
        cout<<"\n\t\tList is Empty!!!!!";
        return;
    }
    cout<<"\n\t\tThe List is :: ";
    node *t=head;
    do
    {
        cout<<t->data<<" ";
        t=t->next;

    }while(t!=head);
    
    cout<<"\n\n\t\tThe Size = "<<size;
}

void cll::reverse()
{
    if(size==0)
    {
        cout<<"\nSorry!!! List is Empty!!!";getch();
        return;
    }

    node *t=head;
	node *p=t->next;
	node *q=p->next;
    
	t->next=tail;
    while(q!=head)
    {
        p->next=t;
        t=p;
        p=q;
        q=q->next;
    }

    p->next=t;
    t=head;
    head=tail;
    tail=t;
}

void cll::search(int val)
{
	if(size==0)
    {
        cout<<"\nSorry!!! List is Empty!!!";getch();
        return;
    }
    
    node *t=head;
    int ct=1;
    do
    {
        if(t->data==val)
        {
            cout<<"\nElement was found at position "<<ct<<".";getch();
            break;
        }
        ct++;
        t=t->next;
    }while(t!=head);
    
	if(t==head && ct!=1)
    {
        cout<<"\nElement was not found!!!!";getch();
    }
}

int main()
{
    cll obj;
    int ch,val,pos;
    do
    {
        system("cls");
        obj.display();
        cout<<"\n";
        cout<<"\n\t\t*****CIRCULAR-LINKED-LIST******"<<endl;
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
