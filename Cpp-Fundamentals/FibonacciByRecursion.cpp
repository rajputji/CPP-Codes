#include<iostream>
#include<conio.h>
using namespace std;
int fibo(int a);
int main()
{
	 int n,l,s=0;
     cout<<"Enter number of terms :";
     cin>>n;
     cout<<"Required series is::";
     for(int l=0;l<n; l++)
     {
	  	cout<<fibo(l)<<",";
     	s+=fibo(l);
     }
     return 0;
}

int fibo(int a)
{
    if(a==0)
    	return 0;
    else if(a==1)
    	return 1;
    else
    	return (fibo(a-1)+fibo(a-2));
}
