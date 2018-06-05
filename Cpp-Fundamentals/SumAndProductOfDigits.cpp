#include<iostream>
#include<conio.h>
using namespace std;

class Digits
{
      int n,sum,product;
      public:
      Digits();
      void input();
      void sum_pro_of_digits();
      
};

Digits::Digits()
{
   n=0;sum=0;product=1;
}

void Digits::input()
{
     cout<<"\nEnter the value of n:";
     cin>>n;
}

void Digits::sum_pro_of_digits()
{
     int m=n,d;
          
     while(m>=1)
     {
        d=m%10;
        m=m/10;
        sum+=d;
        product*=d;
     }
     cout<<"\n\nSum of the digits of "<<n<<" is : "<<sum;
     cout<<"\nProduct of the digits of "<<n<<" is: "<<product;
     getch();
}

int main()
{
    Digits obj;
    obj.input();
    obj.sum_pro_of_digits();
    getch();
    return 0;
}    
