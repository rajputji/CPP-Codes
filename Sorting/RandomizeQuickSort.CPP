#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstdlib>
using namespace std;

int ar[100];
int sft=0, cmp=0;
int partition(int ar[],int p,int r)
{
	int mid=(p+r)/2;
	int swp=ar[mid]; ar[mid]=ar[r]; ar[r]=swp;
	int x=ar[r];
	int i=p-1;
	for(int j=p;j<=r-1;j++)
	{
		cmp++;
		if(ar[j]<=x)
		{
		i=i+1;
		int swap=ar[i];
		ar[i]=ar[j];
		ar[j]=swap;
		}	
	}
	int swap1=ar[i+1];
	ar[i+1]=ar[r];
	ar[r]=swap1;
	return (i+1);
}

void quicksort(int ar[],int p,int r)
{
	if(p<r)
	{
	int q;
	q=partition(ar,p,r);
	quicksort(ar,p,q-1);
	quicksort(ar,q+1,r);
	}
}

int main()
{
int size;
//cout<<"\nEnter the size of the array::";
//cin>>size;
size=rand()%10+5;
for(int i=0;i<size;i++)
 ar[i]=rand()%100;
 
 cout<<"\nArray is ";
 for(int z=0;z<size;z++)
	cout<<"  "<<ar[z];
cout<<"\n";
quicksort(ar,0,size-1);
cout<<"\nSorted Array is ::";
for(int z=0;z<size;z++)
cout<<"  "<<ar[z];

cout<<"\n\nTotal comparisons = "<<cmp;
getch();
return 0;
}
