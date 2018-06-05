#include<iostream>
#include<conio.h>
 
using namespace std;

int main()
{
  int array[100], n,temp;

  cout<<"Enter Size of Array\t";
  cin>>n;
 
  cout<<"Enter Elements\n", n; 
  for (int i=0;i<n;i++)
  {
  	cout<<"Element A["<<i<<"] ::";
    cin>>array[i];
  }
  for(int x=0; x<n; x++)
	{
		int s = x;
		for(int y=x; y<n; y++)
		{
			if(array[s]>array[y])
			{
				s = y;
			}
		}
		int temp=array[x];
        array[x]=array[s];
        array[s]=temp;
	}
	
	cout<<"Selection Sort in ascending order:\n";
  	for (int i=0;i<n;i++ )
    cout<<array[i]<<"\t";
  
  getch();
  return 0;
}
