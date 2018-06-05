#include<bits/stdc++.h>
using namespace std;
int steps=0;

stack<int> s[4];

void MoveRing(int src,int dest)
{
	int from,to,ringNo;
	if(s[src].empty())
	{
		from=dest; to=src; ringNo=s[dest].top();
		s[src].push(s[dest].top());
		s[dest].pop();
	}
	else if(s[dest].empty())
	{
		from=src; to=dest; ringNo=s[src].top();
		s[dest].push(s[src].top());
		s[src].pop();
	}
	else if(s[src].top()>s[dest].top())
	{
		from=dest; to=src; ringNo=s[dest].top();
		s[src].push(s[dest].top());
		s[dest].pop();
	}
	else
	{
		from=src; to=dest; ringNo=s[src].top();
		s[dest].push(s[src].top());
		s[src].pop();
	}
	cout<<"move ring "<<ringNo<<" from "<<char(from+'A'-1)<<" to "<<char(to+'A'-1)<<"\n";
}

void calculate(int n)
{
	int ringNo,f=0;
	int src=1,dest=3,aux=2;
	for(int i=n;i>=1;i--)
		s[src].push(i);
    //cout<<char(3+'A'-1)<<endl;
	for(int i=1;i<=steps;i++)
	{
		if(i%3==1)
			MoveRing(src,dest);
		if(i%3==2)
			MoveRing(src,aux);
		if(i%3==0)
			MoveRing(aux,dest);
	}
}

int main()
{
    int n;
    cout<<"\n Enter the number of rings :"<<endl;
    cin>>n;
    steps=pow(2,n)-1;
    calculate(n);
    cout<<"\n\nTotal Number of steps needed = "<<steps<<endl;
    return 0;
}
