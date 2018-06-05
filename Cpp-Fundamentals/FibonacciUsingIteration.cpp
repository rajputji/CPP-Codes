#include<iostream>
#include<conio.h>

using namespace std;

class Fibonacci
{
      int n,a,b,c;
      public:
      void input();
      void showSeries();
};

void Fibonacci::input()
{
     cout<<"Enter number of terms :";
     cin>>n;
}

void Fibonacci::showSeries()
{
     a=0;b=1;
     system("cls");
     cout<<"FIBONACCI SERIES UPTO "<<n<<" TERMS"<<endl<<endl;
     cout<<a<<", "<<b;
     
     
     
     for(int i=0;i<n-2;i++)
     {
             c=a+b;
             cout<<", "<<c;
             a=b;
             b=c;
     }
     getch();
}

int main()
{
    Fibonacci obj;
    obj.input();
    obj.showSeries();
}

             

