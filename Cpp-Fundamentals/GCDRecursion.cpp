#include<iostream>
#include<conio.h>
using namespace std;
class rec
{
      int a,b,g;
      public:
             rec(){}
             void input();
             void swap(int &a,int &b);
             void output();
             int calc(int x,int y);
};
void rec::input()
{
     cout<<"\nEnter first number::";
     cin>>a;
     cout<<"\nEnter second number::";
     cin>>b;
     if(a<b)
     swap(a,b);
}

void rec::swap(int &a,int &b)
{
     int temp=a;
     a=b;
     b=temp;
}

void rec::output()
{
     g=calc(a,b);
     cout<<"\nRequired GCD is = "<<g;
}

int rec::calc(int x,int y)
{
    int r;
    if(y==0)
    return 0;
    else
    {
        r=x%y;
        if(r==0)
        return y;
        else
        return calc(y,r);
    }
}

int main()
{
    rec o;
    o.input();
    o.output();
    getch();
    return 0;
}
