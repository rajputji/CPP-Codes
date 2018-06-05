#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

class Binary
{
      long dec,bin;
      int prefix_zeros;
      public:
      Binary()
      {
              dec=0;bin=0;prefix_zeros=0;
      }
      void input();
      void show();
      void convert();
};

void Binary::convert()
{
     long temp=dec;
     int r,zeros=0;
     long tbin=0;
     bool flag=true;
     
     while(temp>0)
     {
                 r=temp%2;
                 temp/=2;
                 tbin=tbin*10+r;
                 if(r==0&&flag==true)
                  {
                       zeros++;
                  }
                  else  flag=false;
     }
     
     while(tbin>0)
     {
                  r=tbin%10;
                  tbin/=10;
                  if(r==0&&flag==true)
                  {
                       prefix_zeros++;
                  }
                  else  flag=false;
                  bin=bin*10+r;
     }
     
     for(int i=0;i<zeros;i++)
     {
             bin*=10;
     }
     
}


void Binary::show()
{
     cout<<"Binary equivalent of "<<dec<<" is = ";
     
     for(int i=0;i<prefix_zeros;i++)
     cout<<0;
     
     cout<<bin;
}

void Binary::input()
{
     cout<<"Enter Decimal no:";
     cin>>dec;
}

int main()
{
    Binary obj;
    obj.input();
    obj.convert();
    obj.show();
    getch();
    return 0;
}
