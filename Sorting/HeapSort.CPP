#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cm=0;

int left(int i)
{return i*2;}

int right(int i)
{return (i*2)+1;}

int parent(int i)
{return i/2;}

void swap(int &a,int &b)
{   int temp=a;
    a=b;
    b=temp;
}

int shift=0;
void max_heapify(int A[],int i,int size)
{
     if(i<1)
	return;
     int r=right(i);
     int l=left(i);
     int largest=i;
     cm++;
     if(r<=size && A[r-1]>A[largest-1])
	 largest=r;
	 cm++;
     if(l<=size && A[l-1]>A[largest-1])
	 largest=l;
     if(i!=largest)
     {
	swap(A[i-1],A[largest-1]);
	shift++;
	max_heapify(A,largest,size);
     }
}

void build_maxheap(int A[],int size)
{
    for(int i=size/2;i>=0;i--)
	max_heapify(A,i,size);
}

void heap_sort(int A[],int n)
{   int size=n;
    build_maxheap(A,size);
    for(int i=1;i<=n;i++)
    {
	cout<<"\n\nPASS = "<<i<<" =>\t";
	for(int j=0;j<n;j++)
		cout<<A[j]<<" ";
	shift++;
	swap(A[0],A[n-i]);
	size--;
	max_heapify(A,1,size);
    }
}

int main()
{      // clrscr();
	int A[20],n;
    cout<<"\nEnter size::";
	cin>>n;
	cout<<"\nEnter Elements::\n";
	for(int i=0;i<n;i++)
	{
	cout<<"Enter A["<<i<<"] ::";
	cin>>A[i];
	}
//	randomize();
//	n=random(10)+5;
	cout<<"\nSize = "<<n<<endl;
//	for(int i=0;i<n;i++)
//	A[i]=random(50);
	cout<<"\nEntered Array => ";
	for (int i=0;i<n;i++)
	cout<<A[i]<<" ";
	heap_sort(A,n);
	cout<<"\n\nSorted Array  => ";
	for(int i=0;i<n;i++)
	cout<<A[i]<<" ";
	cout<<"\n\nTotal number of comparisons = "<<cm;
	getch();
	return 0;
}
