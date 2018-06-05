#include<iostream>
#include<conio.h>
using namespace std;
int cm=0;
void merge(int a[],int p,int q,int r)
{
    int b[10];
    int k=p;
    int i,j;
	for(i=p,j=q+1;i<=q&&j<=r;)
	{
	 cm++;
	 if(a[i]<a[j])
	 {
	  b[k++]=a[i++];
	 }
	 else if (a[i]>a[j])
	 {
	  b[k++]=a[j++];
	 }
	 else
	 {
	  b[k++]=a[j++];
	  b[k++]=a[i++];

	 }
	 }
	while(i<=q)
	{
		b[k++]=a[i++];
	}
	while(j<=r)
	{
		b[k++]=a[j++];
	}
for(i=p;i<k;i++)
{
	a[i]=b[i];
}
}//merge

void merge_sort(int a[],int p,int r)
{
	int q;
	if (p<r)
	{
	 q=(p+r)/2;
	 merge_sort(a,p,q);
	 merge_sort(a,q+1,r);
	 merge(a,p,q,r);
	}
}//merge_sort

int main()
{
int a[10],n;
cout<<"\n\n\t\t\t...Merge sort......";
cout<<"\n\n\tEnter the size of Array :: ";
cin>>n;
cout<<"\n\n\tEnter the elements ::\n";
for(int i=0;i<n;i++)
{
cout<<"\t\t\t\t";
cin>>a[i];
}
merge_sort(a,0,n-1);
cout<<"\n\n\tSorted array is :: \t";
for(int i=0;i<n;i++)
{
cout<<a[i]<<" " ;
}
cout<<"\n\tTotal number of comparisons are = \t"<<cm;
getch();
return 0;
}//main
