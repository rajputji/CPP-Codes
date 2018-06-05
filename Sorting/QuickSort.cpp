#include<iostream>
#include<conio.h>
using namespace std;

int partition(int a[],int l,int r)
{
	int i=l+1;
	int j=r;
	while(i<=j)
	{
		while(a[i]<=a[l])
		i++;
		while(a[j]>a[l])
		j--;
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	return j;
}
void Qsort(int a[],int l,int r)
{
	if(l<r)
	{
	int p=partition(a,l,r);
	//cout<<"\nPivot="<<a[p]<<endl;
	Qsort(a,l,p-1);
	Qsort(a,p+1,r);
	}
}

int main()
{
    int arr[20];
    int s;
    cout<<"Enter size of the array:";
    cin>>s;
    cout<<"Enter the elements into the array:-\n";
    for(int i=0;i<s;i++)
        cin>>arr[i];
    cout<<"Original Array:-"<<endl;
    for(int i=0;i<s;i++)
        cout<<arr[i]<<" ";
    Qsort(arr,0,s-1);
    cout<<"\nArray after quick sort:-\n";
    for(int i=0;i<s;i++)
        cout<<arr[i]<<" ";
        getch();
        return 0;
}
