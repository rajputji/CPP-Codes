#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
	int data;
	node *next;
	node()
	{
		next=NULL;
	}	
};

class ll
{
	int size;
	node *head,*temp;
	public:
	ll();
	void create();
	void display();
	void concatenate(ll);
	void merge(ll,ll);
};

ll::ll()
{
	head=temp=NULL;
	size=0;
}

void ll::create()
{
	int val;	
	cout<<"\nEnter Element::";
	cin>>val;
	size++;
	temp=new node;
	temp->data=val;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		node *T=head;
		while(T->next!=NULL)
		{
			T=T->next;
		}
		T->next=temp;
	}
}

void ll::display()
{
	node *T=head;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->next;
     }
}

void ll::concatenate(ll obj2)
{
    node *T=head;
    cout<<"\nAfter concatenation, The list is::"<<endl;
	while(T->next!=NULL)
	{
		cout<<T->data<<" ";
		T=T->next;
	}
	
	T->next=obj2.head;
	
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->next;
	}
	getch();
}

void ll::merge(ll obj,ll obj2)
{
	node *p=obj.head;
	node *q=obj2.head;
	node* r=head;
	while((p!=NULL)&&(q!=NULL))
	{
	    node *temp=new node;
	    temp->next=NULL;
		if((p->data)<(q->data))
		{
			temp->data=p->data;
			p=p->next;
		}
        else if((q->data)<(p->data))
		{
			temp->data=q->data;
			q=q->next;
		
		}
		else if(p->data==q->data)
		{
			temp->data=p->data;
			p=p->next;
			q=q->next;
		}
	
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			r=head;
			while(r->next!=NULL)
			{r=r->next;}
		
        r->next=temp;
		}
	  }
  	
      while(p!=NULL)
	  {	
	        node *temp=new node;
            temp->next=NULL;
			temp->data=p->data;
			p=p->next;
			r=head;
			while(r->next!=NULL)
			r=r->next;
			r->next=temp;
	  }
	  
      while(q!=NULL)
	   {
           node *temp=new node;
           temp->next=NULL;
		   temp->data=q->data;
		   q=q->next;
		   r=head;
		   while(r->next!=NULL)
		   r=r->next;
		   r->next=temp;
		}
		
	cout<<"\nAfter Merging, The list is ::"<<endl;
	node *T=head;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->next;
     }
     getch();
}

int main()
{
	int choice,ans;
	ll obj,obj2,obj3;
    do
    
    {
    system("cls");
	cout<<"\n\t\t*****Menu*****";
	cout<<"\n\t\t1.Create list 1.";
	cout<<"\n\t\t2.Create list 2.";
	cout<<"\n\t\t3.display the lists.";
	cout<<"\n\t\t4.concatenate.";
	cout<<"\n\t\t5.merge.";
	cout<<"\n\t\t6.Exit.";
	cout<<"\n\n\t\tEnter choice::";
	cin>>choice;
	switch(choice)
	  {
		case 1: do{
               system("cls");
               cout<<"\n\t\t";
               obj.display();
			   cout<<"\n\t\t****Create List 1****";
			   cout<<"\n\t\t(Enter elements in sorted manner)"<<endl;
               cout<<"\n\t\t1.Add Element.";
		       cout<<"\n\t\t2.Return to main.";
		       cout<<"\n\n\t\tEnter choice::";
		       cin>>ans;
		       if(ans==1)
			   obj.create();
			   else if(ans==2)
			   break;
               }while(1);
			   break;
        case 2:do{
               system("cls");
               cout<<"\n\t\t";
               obj2.display();
			   cout<<"\n\t\t****Create list 2****";
			   cout<<"\n\t\t(Enter elements in sorted manner)"<<endl;
               cout<<"\n\t\t1.Add Element.";
		       cout<<"\n\t\t2.Return to main.";
		       cout<<"\n\n\t\tEnter choice::";
		       cin>>ans;
		       if(ans==1)
			   obj2.create();
			   else if(ans==2)
			   break;
               }while(1);
			   break;
		
		case 3:cout<<"\n\nList 1 is = ";
			   obj.display();
			   cout<<"\n\nList 2 is = ";
			   obj2.display();
			   getch();
		       break;
		
		case 4:obj.concatenate(obj2);
		       break;
		
		case 5:obj3.merge(obj,obj2);
		       break;
        case 6:exit(0);
               break;
        default:cout<<"\nWrong choice!!";
                getch();
                break;
      }
    }while(1);
	getch();
	return 0;
}
