#include<iostream>
#include<conio.h>

using namespace std;

class Swapping
{
      int n1,n2;
      public:
      void input();
      void swapp();
      void show();
};

void Swapping::input()
{
     cout<<"Enter A:";
     cin>>n1;
     cout<<"Enter B:";
     cin>>n2;
}

void Swapping::swapp()
{
     int *n=new int;
	 int *pn1=&n1,*pn2=&n2;
  
     *n=*pn1;
     *pn1=*pn2;
     *pn2=*n;
     delete n;
}

void Swapping::show()
{
     cout<<"\n\nAfter swapping:-"<<endl;
     cout<<"A="<<n1<<endl;
     cout<<"B="<<n2;
     getch();
}

int main()
{
    Swapping obj;
    obj.input();
    obj.swapp();
    obj.show();   
    return 0;
}

    
