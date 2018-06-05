#include<iostream>
#include<conio.h>
using namespace std;
class array
{
      int arr[100];
      int n;
      public:
             array()
             {
                n=0;
             }
             void reverse();
             void input();
             void display();
};

void array::input()
{
     cout<<"\nEnter size of array:";
     cin>>n; 
     for(int i=0;i<n;i++)
     {
             cout<<"\nEnter "<<i+1<<" element : ";
             cin>>arr[i];
     }
}

void array::display()
{
	 for(int i=0;i<n;i++)
     {
             cout<<arr[i]<<"\t";
     }
}
    
void array:: reverse()
{
     int x,y,i;
     i=0;
     x=n-1;
     while(i<=x)
     {
             y=arr[i];
             arr[i++]=arr[x];
             arr[x--]=y;
     }
}     
int main()
{
    array obj;
    obj.input();
    cout<<"\nOriginal array is::"<<endl;
    obj.display();
    cout<<"\n\n";
	obj.reverse();
    cout<<"\nReversed Array is ::"<<endl;
	obj.display();
    getch();
    return 0;
}
