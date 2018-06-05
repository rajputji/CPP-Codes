#include<iostream>
#include<conio.h>
using namespace std;
void allot(int s)
{
	if(s==1)
	{
			int *p=new int [10000000];
			throw "memory could not be allocated for int";
	}
	else if(s==2)
	{
			char *p=new char [1000000];
			throw "memory could not be allocated for char";
	}
	else if(s==3)
	{
			float *p=new float [1000000];
			throw "memory could not be allocated for float";
	}
}
int main()
{
	int ch;
	cout<<"\n\n\t ALLOCATE MEMORY FOR";
	cout<<"\n\n\t 1. int \n\n\t 2. char \n\n\t 3. float:\n\t";
	cin>>ch;
	try
	{
		allot(ch);
	}
	catch(const char * str)
	{
		cout<<"\n\n\t";
		cout<<str;
	}
	return 0;	
}
