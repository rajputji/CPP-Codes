#include<iostream>
#include<conio.h>
#include<cmath>

using namespace std;

void print(int a[],int n)
{
	cout<<"\nSorted Array is :: ";
	for(int i=0;i<n;i++)
	cout<<a[i]<<"  ";
	cout<<"\n";
}
void countsort(int arr[], int size, int digit)
{
    int *b=new int[size];
    int c[10] = {0};
    for (int i=0;i<size;i++)
	c[(arr[i] / digit) % 10]++;
    for (int i=1;i<10;i++)
	c[i]+=c[i-1];
    for (int i=size-1; i>=0;i--)
    {
	b[c[(arr[i] /digit) % 10] - 1] = arr[i];
	c[(arr[i] / digit) % 10]--;
    }
    for (int i=0;i<size;i++)
	arr[i] = b[i];

}


int findmax(int a[],int n)
{
	int maxpos=0;
	for(int i=1;i<n;i++)
	if(a[i]>a[maxpos])
	maxpos=i;
	return a[maxpos];
}

void radixsort(int arr[], int n)
{
    int m = findmax(arr, n);
    for (int i = 1;(m/i) > 0; i*= 10)
	countsort(arr,n,i);
}

int main()
{
	system("cls");
	int size;
    cout<<"\nEnter Size of array :: ";
	cin>>size;
	int *arr=new int[size];
	cout<<"\nEnter elements of array ::\n";
	for(int i=0;i<size;i++)
	cin>>*(arr+i);
	radixsort(arr,size);
	print(arr,size);
	getch();
	return 0;
}

