#include<iostream>
#include<conio.h>
using namespace std;
class rec
{
      int a,b,p;
      public:
             rec();
             void input();
             int pro(int a,int b);
             void output();
};

rec::rec()
{}

void rec::input()
{
     cout<<"Enter a::";
     cin>>a;
     cout<<"Enter b::";
     cin>>b;
}

void rec::output()
{
     p=pro(a,b);
     cout<<"\nThe product of "<<a<<" and  "<<b<<" is = "<<p;
}

int rec::pro(int a,int b)
{
    if(b==0)
    return 0;
    	else
    return a+pro(a,b-1);
}
int main()
{
    rec o;
    o.input();
    o.output();
    getch();
    return 0;
}
