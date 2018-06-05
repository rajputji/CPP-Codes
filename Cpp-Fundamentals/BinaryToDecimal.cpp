//PROGRAM TO CONVERT A BINARY NUMBER ENTERED BY USER TO DECIMAL
#include<iostream>
#include<conio.h>
#include<math.h>
#include<process.h>

using namespace std;

int main()
{
    int bin,decimal=0,r,i=0;
    
    cout<<"Enter binary number:";
    cin>>bin;
    
    int tmp=bin;
    while(tmp>0)
    {              
         r=tmp%10;
         if(r==1 || r==0)
         { 
		 	tmp/=10;
            decimal+=pow(2,i)*r;
            i++;
         }
         else
         {
         	 cout<<"entered an invalid binary number";
             getch();
             exit(0);
         }
    }
    cout<<"Decimal equivalent of "<<bin<<" is:"<<decimal;
    getch();
    return 0;
}
