#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
     int n,f;
     cout<<"Enter the number whose factorial you want to find::";
     cin>>n;
     int recur(int a);
     f=recur(n);
     cout<<"Required answer is "<<n<<"! = "<<f<<endl;
     getch();
     return 0;
}
int recur(int a)
{
    if(a==1||a==0)
    	return 1;
    else
	    return (a*recur(a-1));
}
