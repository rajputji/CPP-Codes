#include<iostream>
#include<conio.h>

using namespace std;

class ReverseNo
{
      long n,rev;
      public:
	      ReverseNo();
    	  void input();
      	  void reverse();
};

ReverseNo::ReverseNo()
{
  n=0;rev=0;
}

void ReverseNo::input()
{
     cout<<"\nEnter the number whose digits you want to reverse:";
     cin>>n;
}

void ReverseNo::reverse()
{
     long m=n,d;
     while(m>0)
     {
        d=m%10;
        m=m/10;
        rev=rev*10+d;
     }
     cout<<"\n\nThe reverse number of "<<n<<" is:"<<rev;
}

int main()
{
    ReverseNo obj;
    obj.input();
    obj.reverse();
    getch();
    return 0;
}
    
     
