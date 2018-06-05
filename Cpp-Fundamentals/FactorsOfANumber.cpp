#include<iostream>
#include<conio.h>

using namespace std;

void factors(int);

int main()
{         
     int num;
     char ch='y';
     while(ch=='y')
     {
          cout<<"\nEnter the number whose factors are to be displayed:"<<endl;
          cin>>num;   
          cout<<"\nThe Factors of "<<num<<" are : "<<endl; 
          factors(num);
          cout<<num;
          
          cout<<"\nDo you want to continue(y/n)?"<<endl;
          cin>>ch;
          if(ch!='y')
          exit(0);
     }     
     getch();
     return 0;
}

void factors(int x)
{   
        for(int i=1;i<=x/2;i=i+1)
    {
        if(x%i==0)        
        cout<<i<<"  ";
    }        
}
