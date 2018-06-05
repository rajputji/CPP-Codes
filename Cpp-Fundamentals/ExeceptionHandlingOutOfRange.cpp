#include<iostream>
#include<conio.h>
#include<exception>
using namespace std;

int main()
{
	string s("My name is Abhishek Rajput");
	int n;
	try
	{
		cout<<"String length is "<<s.length();
		cout<<"\nEnter the pos to display charater ";
		cin>>n;
		cout<<s.at(n);
	}
	catch(exception& e)
	{
		cout<<"Error is "<<e.what();
	}
	return 0;
	getch();
}
