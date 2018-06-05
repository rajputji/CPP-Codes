#include<iostream>
#include<conio.h>

using namespace std;

int A[20],B[20],size,k;
void count_sort(int A[],int B[], int k)
{
	int c[1000];
	for (int i=0;i<=k;i++)
		c[i]=0;
	for(int j=1;j<=size;j++)
		c[A[j]]=c[A[j]]+1;
	for(int i=1; i<=k;i++)
		c[i]=c[i]+c[i-1];
	for(int j=size;j>=1;j--)
	{	B[c[A[j]]]=A[j];
		c[A[j]]=c[A[j]]-1;
	}
}

int main()
{
	cout<<"\nEnter the Range";
	cin>>k;
	cout<<"Enter size of array::";
	cin>>size;
	cout<<"Enter "<<size<<" Elements(Under the range [1-"<<k<<"])::\n";
	for(int i=1;i<=size;i++)
	cin>>A[i];
	count_sort(A,B,k);
	cout<<"\nAfter sorting Array :: ";
	for(int i=1;i<=size;i++)
		cout<<B[i]<<" ";
	getch();
	return 0;
}
