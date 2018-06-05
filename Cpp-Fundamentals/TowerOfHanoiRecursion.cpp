#include<bits/stdc++.h>
using namespace std;
int steps=0;

void calculate(int n,char from,char to,char aux)
{
	steps++;
    if(n==1)
     	cout<<"move ring 1 from "<<from<<" to "<<to<<"\n";
    else
    {
        calculate(n-1,from,aux,to);
        cout<<"move ring "<<n<<" from "<<from<<" to "<<to<<"\n";
        calculate(n-1,aux,to,from);
    }
}
int main()
{
    int n;
    cout<<"\n Enter the number of plates :"<<endl;
    cin>>n;
    calculate(n,'A','C','B');
    cout<<"\n\nTotal Number of steps needed = "<<steps<<endl;
    return 0;
}
