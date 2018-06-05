#include<iostream>
#include<conio.h>

using namespace std;

class Divide
{
      int a,b,div,rem;
      bool sign;   //to store sign of no. true=negative, false=positive
  public:
      Divide();
      void input();
      void show();
      int divide(int);
      void storeSign();  //to store final sign negative/positive in bool sign.
};

Divide::Divide()
{
      a=0;
      b=1;
      div=0;
      sign=0;
}
    
void Divide::input()
{
      do{
           cout<<"Enter Dividend:";
           cin>>a;
           cout<<"Enter Divisor:";
           cin>>b;
           if(b==0)
           {
                    cout<<"Error: Can't Divide by 0";
                    getch();
           }
        }while(b==0);
}



int Divide::divide(int a)
{
                
      if(a==0)
      div=0;
      if((a-b)<b)
      rem=a-b;
      else 
      {
          //if((a-b)>b)
          divide(a-b);
          div++;
      }
}


void Divide::storeSign()
{
     if(a<0&&b<0)
     sign=0;
     else if(a<0||b<0)
     sign=1;
}

void Divide::show()
{
     divide(a);
     cout<<a<<"/"<<b<<" = "<<div;
     cout<<"\nRemainder="<<rem;
}

int main()
{
    Divide obj;
    obj.input();
    obj.show();
    getch();
    return 0;
}
