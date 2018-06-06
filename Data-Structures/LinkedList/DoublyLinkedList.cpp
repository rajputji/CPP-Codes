#include<iostream>
#include<conio.h>
using  namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};

class dll
{
	int size;
	node *temp,*head,*tail;
	public:
		dll();
		void display();
		void insertatend(int);
		void insertatpos(int,int);
		void insertatbeg(int);
		void insertafterval(int,int);
		void insertbeforeval(int,int);
		void search(int);
		void deletehead();
        void deletetail();
        void deletepos(int);
        void reverse();
};

dll::dll()
{
	size=0;
	temp=head=tail=NULL;
}

void dll::insertatend(int val)
{
	temp=new node;
	temp->next=NULL;
	temp->data=val;
	if(head==NULL)
	{
	temp->prev=NULL;
	head=temp;
	}
	else
	{
	tail->next=temp;
	temp->prev=tail;
	}
	tail=temp;
	size++;
}

void dll::insertatpos(int pos,int val)
{
	if(pos==1)
	insertatbeg(val);
	else if(pos==size+1)
	insertatend(val);
	else if(pos>size)
	{
		cout<<"\nERROR!!! Position Exceeded the size!!!!";
		getch();
	}
	else
	{
	temp=new node;
	int ct=1;
	if(pos<=(size/2))
	{
		node *T=head;
		while(ct<pos-1)
		{
			T=T->next;
			ct++;
		}
		temp->data=val;
		temp->next=T->next;
		T->next->prev=temp;
		temp->prev=T;
		T->next=temp;
		size++;
	}
	else if(pos>(size/2))
	{
		pos=size-pos+2;
		node *T=tail;
		while(ct<pos-1)
		{
			T=T->prev;
			ct++;
		}
		temp->data=val;
		temp->prev=T->prev;
		T->prev->next=temp;
		temp->next=T;
		T->prev=temp;
		size++;
	}
	}
}
void dll::insertatbeg(int val)
{
	if(head==NULL)
	insertatend(val);
	else
	{
	temp=new node;
	temp->data=val;
	temp->prev=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	size++;
	}
}

void dll::insertbeforeval(int pos, int val)
{
	if(head==tail || head->data==pos)
	insertatbeg(val);
	else
	{
	temp=new node;
	temp->data=val;
	node *T=head;
	while((T->next)->data!=pos)
	T=T->next;
	temp->next=T->next;
	temp->prev=T;
	T->next->prev=temp;
	T->next=temp;
	size++;
	}
}

void dll::insertafterval(int pos, int val)
{
	if(head==tail)
	insertatend(val);
	else
	{
	temp=new node;
	temp->data=val;
	node *T=head;
	while(T->data!=pos)
	T=T->next;
	temp->next=T->next;
	temp->prev=T;
	T->next->prev=temp;
	T->next=temp;
	size++;
	}
}

void dll::deletehead()
{
    if(head==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
        return;
    }
    else if(head==tail)
    {
    head=tail=NULL;
    size--;
    return;
    }
    node *t=head;
    head=head->next;
    head->prev=NULL;
    size--;
    delete t;
}

void dll::deletetail()
{

    if(head==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
        return;
    }
    if(head==tail)
    {
    	head=tail=NULL;
    	size--;
    	return;
    }
    
    tail=tail->prev;
    tail->next=NULL;
    size--;
}

void dll::deletepos(int pos)
{
    if(head==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
        return;
    }
    else if(pos<=0 || pos>size+1)
    {
        cout<<"\nInvalid Position!!!";
        getch();
        return;
    }
    else if(pos==1)
    deletehead();
    else if(pos==size)
    deletetail();
    else
    {
    node *t;
    int ct;
    if(pos>=size/2)
    {
        ct=size;
        t=tail;
        while(ct!=pos)
        {
            t=t->prev;
            ct--;
        }
    }
    else
    {
        ct=1;
        t=head;
        while(ct!=pos)
        {
            t=t->next;
            ct++;
        }
    }


    node *p=t;
    t=p->prev;
    t->next=p->next;
    p->next->prev=t;
    delete p;
    size--;
    
    }
}


void dll::reverse()
{
    if(head==NULL)
    {
        cout<<"\nError!!! The list is Empty!!!";getch();
        return;
    }
    else if(head==tail)
    return;
    
        node *p,*t,*q;
        p=tail;tail=head;head=p;
        p=head;t=p->prev;q=t->prev;
        while(q!=NULL)
        {
        p->next=t;
        t->prev=p;
        if(p==head)
        p->prev=NULL;
        p=t;t=q;q=q->prev;
        }
        p->next=t;
        t->prev=p;
        t->next=NULL;
}

void dll::search(int val)
{
	node *T=head;
	int ct=0;
	while(T!=NULL)
    {
    ct++;
    if(T->data==val)
    {
    cout<<"\nElement found at postion = "<<ct;
    getch();
    return;
    }
    T=T->next;
    }
    if(T==NULL)
    {
    cout<<"\nElement not found!!";
    getch();
    }
}

void dll::display()
{
	node *T=head;
	if(T==NULL)
	{
		cout<<"\nList is Empty!!!";
	}
	else
	{
		cout<<"\nList is::"<<endl;
		while(T!=NULL)
		{
			cout<<T->data<<" ";
			T=T->next;
		}
		cout<<"\n\nList size is = "<<size<<endl;
	}
}

int main()
{
	dll obj;
	int choice,ans,val,pos;
	do
	{
		system("cls");
		obj.display();
		cout<<"\n";
		cout<<"\n*****DOUBLE LINKED LIST****";
		cout<<"\n1.insertion.";
		cout<<"\n2.Deletion.";
		cout<<"\n3.Search.";
		cout<<"\n4.Reverse the list.";
		cout<<"\n0.exit.";
		cout<<"\nEnter choice::";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\n1.Insert at begining."
						<<"\n2.Insert at position."
						<<"\n3.Insert at last."
						<<"\n4.Insert before a value."
						<<"\n5.Insert after a value."
						<<"\nEnter choice::";
					cin>>ans;
					switch(ans)
					{
						case 1: cout<<"\nEnter the element::";
								cin>>val;
								obj.insertatbeg(val);
								break;
						case 2: cout<<"\nEnter the postion::";
								cin>>pos;
								cout<<"\nEnter the element::";
								cin>>val;
								obj.insertatpos(pos,val);
								break;
						case 3:	cout<<"\nEnter the element::";
								cin>>val;
								obj.insertatend(val);
								break;
						case 4:	cout<<"\nEnter that value::";
								cin>>pos;
								cout<<"\nEnter the new element::";
								cin>>val;
								obj.insertbeforeval(pos,val);
								break;
						case 5: cout<<"\nEnter that value::";
								cin>>pos;
								cout<<"\nEnter the new element::";
								cin>>val;
								obj.insertafterval(pos,val);
								break;
					}
					break;
			case 2:cout<<"\n1.Delete from begining."
						<<"\n2.Delete by position."
						<<"\n3.Delete from last."
						<<"\nEnter choice::";
					cin>>ans;
					switch(ans)
					{
						case 1:obj.deletehead();
								break;
						case 2: cout<<"\nEnter the postion::";
								cin>>pos;
								obj.deletepos(pos);
								break;
						case 3: obj.deletetail();
								break;
					} 
					break;
			case 3: cout<<"\nEnter the element to search::";
			        cin>>val;
			        obj.search(val);
				    break;
            case 4: obj.reverse();
                    break;
			case 0: exit(0);
					break;
		}
	}while(1);
	getch();
	return 0;
}
