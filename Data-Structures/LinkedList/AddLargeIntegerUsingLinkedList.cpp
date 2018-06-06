#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct node
{
       int data;
       node *next;
};

int ci=0;

class num
{
       public:
              node *top;
              num()
              {
              top=NULL;
              }
              int pop();
              void add(int);
              void pushres(int,int);
              void display();
};

int num::pop()
{
              int x=top->data;
              top=top->next;
              return x;
}

void num::add(int d)
{
              node *temp=new node;
              temp->data=d;
              if(top==NULL)
              {
              top=temp;
              top->next=NULL;
              }
              else
              {
              temp->next=top;
              top=temp;
              }
}

void num::pushres(int a,int b)
{
              node *temp=new node;
              if(a+b+ci>9)
              {
                        temp->data=(a+b+ci)%10;
                        ci=1;
              }
              else
              {
                  		temp->data=a+b+ci;
                  		ci=0;
              }
              if(top==NULL)
              {
              	top=temp;
              	top->next=NULL;
              	return;
        	  }
           	  temp->next=top;
              top=temp;
}
             
void num::display()
{
              node *d=top;
              while(d!=NULL)
              {
              cout<<d->data;
              d=d->next;
              }
}
    
int main()
{ 
    num no1,no2,res; 
    char c[50];
    int i=0;
    cout<<"\nEnter the first number::\t"; 
    cin.getline(c,'.'); 
    while(i<strlen(c))
    {
    	no1.add(int(c[i])-48);   
    	i++;
    }
    
    i=0;
    cout<<"\nEnter the second number::\t";      
    cin.getline(c,'.');
    while(i<strlen(c))
    {
    	no2.add(int(c[i])-48);
    	i++;
    }
    cout<<"\nSum = \t\t\t\t";
    while(no1.top && no2.top)
      res.pushres(no1.pop(),no2.pop());
    if(no1.top) 
    	while(no1.top)
    		res.pushres(no1.pop(),0);
    else if(no2.top)
    	while(no2.top) 
    		res.pushres(no2.pop(),0);
    if(ci==1)
    	res.pushres(0,0);
    res.display();
    getch();
    return 0;
}
