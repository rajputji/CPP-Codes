#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;

class queue
{
	int x;
	stack<int> s1,s2;
	public:
		void enque(int);
		int deque();
		void display();
		void transfer();
}q;

void queue::enque(int x)
{
	if(s1.empty())
	{
		while(!s2.empty())
			s1.push(s2.top()),s2.pop();
		s1.push(x);
	}
	else
		s1.push(x);
}

int queue::deque()
{
	if(s2.empty())
	{
		cout<<"\n Queue empty!!!";
		return -1;
	}
	int ele=s2.top();
	s2.pop();
	return ele;
}

void queue::transfer()
{
	while(!s1.empty())
	s2.push(s1.top()),s1.pop();
}

int main()
{
	int data,c;
	char ch='y';
	int x;
	while(1)
	{
		cout<<"\n 1. Enque \n 2. Deque \n 0. Exit ";
		cout<<"\n Choice: "; cin>>c;
		switch(c)
		{
			case 1:
				cout<<"\n Enter elements (-1 to stop) :: \n";
				while(data!=-1)
				{
					cin>>data;
					if(data!=-1)
					q.enque(data);
				}
				data=0;
				q.transfer();
				break;
			case 2:
				x=q.deque();
				if(x!=-1)
					cout<<"\n Element deleted is: "<<x;				
				break;
			case 0:
				return 0;
			default:
				cout<<"\n Invalid choice!!! ";
		}
		
	}
	return 0;
}
