#include<iostream>
#include<conio.h>
#include<new>

using namespace std;

void allot(int s)
{
	  cout<<"Demonstrating memory allocation failure ";
      try
      {
      	double *a=new double[10000000000];
      	cout<<"\n Memory allocated successfully";
      }
      
      catch(exception & err)
      {
      	cout<<"\n program out of memory\n";
      	cout<<err.what();
      }	
}
int main()
{
	  int p=0;
	  allot(p);
      getch();
      return 0;
}

