#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
       int exp,coef;
       node *next;
};

class poly
{
     public:
	 	node *head,*temp,*t;
        poly();
        void insert(int,int); 
        void add(node*, node*);
    	void display();
};

poly::poly()
{
       head=temp=t=NULL;
}

void poly::insert(int exp,int coef)
{
     temp=new node;
     temp->exp=exp;
     temp->coef=coef;
     temp->next=NULL;
     if(head==NULL)
     {
            head=temp;
            return;
     }
     else
     {
         t=head;
         while(t->next!=NULL)
         t=t->next;
         t->next=temp;
     }
}

void poly::add(node *head1, node *head2)
{
     node *p=head1;
     node *q=head2;
     node *r;
     while((p!=NULL) && (q!=NULL))
     {
        	temp=new node;
        	if(p->exp==q->exp)
             {
                  temp->exp=p->exp;
                  temp->coef=(p->coef)+(q->coef);
                  temp->next=NULL;
                  p=p->next;
                  q=q->next;
             }
             else if((p->exp)>(q->exp))
             { 
                  temp->exp=p->exp;
                  temp->coef=p->coef;
                  temp->next=NULL;
                  p=p->next;
             }
             else if((p->exp)<(q->exp))
             {
                  temp->exp=q->exp;
                  temp->coef=q->coef;
                  temp->next=NULL;
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
                     r=r->next;
                    r->next=temp;
             }
     }
     
     while(p!=NULL)
     {      temp=new node;
            temp->exp=p->exp;
            temp->coef=p->coef;
            temp->next=NULL;
            p=p->next;
            if(head==NULL)
             {
                    head=temp;
             }
             else
             {
                    r=head;
                    while(r->next!=NULL)
                     r=r->next;
                    r->next=temp;
             }
     }
     
     while(q!=NULL)
     {
            temp=new node;
            temp->exp=q->exp;
            temp->coef=q->coef;
            temp->next=NULL;
            q=q->next;
            if(head==NULL)
             {
                    head=temp;
             }
             else
             {
                    r=head;
                    while(r->next!=NULL)
                     r=r->next;
                    r->next=temp;
             }
     }
}

void poly::display()
{
     t=head;
     if(t==NULL)
     {
         cout<<"Polynomial is Not Enterd!!!";
     }
     else
     {
         while(t!=NULL)
         {
            cout<<t->coef<<" X^"<<t->exp;
            if(t->next!=NULL)
            	cout<<" + ";
            t=t->next;
         }
     }
}

int main()
{
      poly obj1,obj2,obj3;
      int exp,coef,ch,ans;
      do
	  {
	  	system("cls");
	  	cout<<"\n\t\t*****POLYNOMIAL ADDITION*****";
	  	cout<<"\n\t\t1.Enter first Polynomial.";
	  	cout<<"\n\t\t2.Enter second Polynomial.";
	  	cout<<"\n\t\t3.Add the polynomials.";
	  	cout<<"\n\t\t0.Exit";
	  	cout<<"\n\n\t\tEnter choice::";
	  	cin>>ch;
	  	switch(ch)
	  	{
	  		case 1: do
			  		{
			  		system("cls");
	  				cout<<"\n\t\t******First polynomial*****\n\n\t\t";
      				obj1.display();
      				cout<<"\n\n1.Add more.";
      				cout<<"\n2.return to main.";
      				cout<<"\nEnter here::";
      				cin>>ans;
      				if(ans==1)
      				{
            		cout<<"\n\n\nEnter the coefficient value ::";
        			cin>>coef;
            		cout<<"\nEnter the exponent value ::";
            		cin>>exp;
            		obj1.insert(exp,coef);
            		}
            		else if(ans==2)
            		break;
            		}while(1);
      				break;
      		case 2: do
     				{
     				system("cls");
      				cout<<"\n\n\t\t*****Second polynomial******\n\n\t\t";
     				obj2.display();
            		cout<<"\n\n1.Add more.";
      				cout<<"\n2.return to main.";
      				cout<<"\nEnter here::";
      				cin>>ans;
      				if(ans==1)
      				{
            		cout<<"\n\n\nEnter the coefficient value ::";
        			cin>>coef;
            		cout<<"\nEnter the exponent value ::";
            		cin>>exp;
            		obj2.insert(exp,coef);
            		}
            		else if(ans==2)
            		break;
            		}while(1);
      				break;
      		case 3:	obj3.add(obj1.head,obj2.head);
      				if(obj3.head==NULL)
      				{cout<<"\nEnter the polynomials first!!";getch();}
					else
					{
					cout<<"\n\t\tFirst polynomial is =\t";obj1.display();
      				cout<<"\n\t\tSecond polynomial is =\t";obj2.display();
      				cout<<"\n\n\t\tNew Polynomial after addition =\t";
					obj3.display();
					getch();
					}
					break;
			case 0: exit(0);
	  	}
  	  }while(1);
	return 0;
}              
