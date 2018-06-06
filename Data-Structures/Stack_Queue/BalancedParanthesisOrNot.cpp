#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class stack
{
	char st[50];
	
	public:
	int t;
	stack()
	{
		t=-1;
	}
	void push(char c)
	{
		t++;
		st[t]=c;
	}
	char pop()
	{
     	if(t>-1)
	 	{
     		t--;
     		return st[t+1];
	 	}
    }
};

int main()
{
    stack s;
	int flag=0,i=0;
	int n1=0,n2=0,n3=0;
	char e[50];
    cout<<"\nEnter the Expression :: ";
    cin.getline(e,50);
    while(i<strlen(e))
	{
    if(e[i]=='(' || e[i]=='{' || e[i]=='[')   
   	{
	   s.push(e[i]);
	}
    else if(e[i]==')' || e[i]=='}' || e[i]==']')
    {
    if(e[i]==')')
    	{if(s.pop()!='(')
    		{flag=1;break;}
    	 else
    	 n1++;
		}
    else if(e[i]=='}')
    	{if(s.pop()!='{')
    		{flag=1;break;}
		 else
    	 n2++;
		}
    else if(e[i]==']')
    	{if(s.pop()!='[')
    		{flag=1;break;}
			else
    	 n3++;
		}
    }
    i++;
	}
    
	if(flag==1 || s.t!=-1)
   	{
   	cout<<"\nParanthesis are not balanced.\n";
	}
	else
	{
	cout<<"\nParantheis are Balanced.";
	cout<<"\n\nNo. of '()' Paranthesis pairs = "<<n1;
	cout<<"\n\nNo. of '{}' Paranthesis pairs = "<<n2;
	cout<<"\n\nNo. of '[]' Paranthesis pairs = "<<n3<<"\n";
	}
	system("pause");
	return 0;
}
