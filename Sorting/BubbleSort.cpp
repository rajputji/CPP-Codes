#include <stdio.h>
#include<iostream>
 
using namespace std;

int main()
{
  int array[100], n,temp;
   
  cout<<"Enter Size of Array\n";
  cin>>n;
  cout<<"Enter Elements\n", n;
  for (int i=0;i<n;i++)
   {
   	cout<<"Element A["<<i<<"] ::";
	cin>>array[i];
	}
  
  for (int i=0;i<n-1;i++)
  {
    for (int j=0;j<n-i-1;j++)
    {
      if (array[j] > array[j+1])
      {
        temp= array[j];
        array[j]=array[j+1];
        array[j+1]=temp;
      }
    }
  }
 
  cout<<"Bubbled Sort in ascending order:\n";
  for (int i=0;i<n;i++ )
  cout<<array[i]<<"\t";
  return 0;
}
