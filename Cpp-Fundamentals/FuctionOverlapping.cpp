#include<iostream>
#include<conio.h>
using namespace std;
class cs
{
      public:
         cs(){}
         void input1();
         void input2();
         void input3();
         int calc(int a,int b);
         int calc(int a);
         float calc(float a);
};

void cs::input1()
{
    int a,b;
    cout<<"\nEnter length::";
    cin>>a;
    cout<<"\nEnter Breadth::";
    cin>>b;
    int A=calc(a,b);
    cout<<"\nArea is :: "<<A<<endl;
}

void cs::input2()
{
     int side;
     cout<<"\nEnter side of square::";
     cin>>side;
     int A=calc(side);
     cout<<"\nArea is :: "<<A<<endl;
}

void cs::input3()
{
     float r;
     cout<<"\nEnter radius::";
     cin>>r;
     float A=calc(r);
     cout<<"\nArea is :: "<<A<<endl;
}

int cs::calc(int a,int b)
{return a*b;}

int cs::calc(int a)
{return a*a;}

float cs::calc(float a)
{return (3.14*a*a);}

int main()
{
    int choice;
    cs o;
    char ch='y';
    while(ch=='y')
    {
    cout<<"\n**********MAIN MENU**********";
    cout<<"\n1.Calculate area of rectangle.";
    cout<<"\n2.Calculate area of square.";
    cout<<"\n3.Calculate area of circle.";
    cout<<"\n0.Exit.";
    cout<<"\nEnter your choice::";
    cin>>choice;
    
    switch(choice)
    {
                  case 1:o.input1();break;
                  case 2:o.input2();break;
                  case 3:o.input3();break;
                  case 0:exit(0);break;
                  default : cout<<"\nEnter a valid choice!";
    }
    cout<<"\nWant to cont????";
    cin>>ch;
    if(ch=='n')
    exit(0);
    }
    getch();
    return 0;
}
