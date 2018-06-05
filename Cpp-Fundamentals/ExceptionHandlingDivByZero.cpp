#include<iostream>
#include<conio.h>
using namespace std;
void divide(int a,int b);
int main()
{
	int num;
	int num2;
	cout<<"Enter the number and number to divide with :";
	cin>>num>>num2;
	try
	{	
	divide(num,num2);
    }
	catch(int x)
	{
		cout<<"Division by zero.";
		exit(100);
	}
	catch(double y)
	{
		cout<<"Division by negative number.";
	}
	getch();
	return 0;
}

void divide(int a,int b)
{

		if(b==0)
		{
			throw b;
		}
		
        else if(b<0)
        {
        	throw 8.9;
        }
        cout<<"The quotient is"<<a/b;
}
