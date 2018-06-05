#include<iostream>
#include<conio.h>

using namespace std;

void insertOne(int arr[],int i,int n)
{
    bool located=false;
    int temp=arr[i],j;

    for(j=i-1;j>=0&&!(located);)
    {
        if(arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        else
            located=true;
    }
    arr[j+1]=temp;
    return;
}

void selectionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
        insertOne(arr,i,n);
    return;
}

int main()
{
    int n,arr[20];
    cout<<"Enter size of the array:";
    cin>>n;
    cout<<"Now enter elements into the array:-"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<"\nArray after sorting:-";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
}

