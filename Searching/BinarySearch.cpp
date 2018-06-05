#include<iostream>
#include<conio.h>

using namespace std;

class BinarySearch
{
      int A[20],size,mid,beg,last,detected_position,n;
      public:
      void input();
      void B_Search();
      void print_array();
      void show();
};

void BinarySearch::input()
{

     cout<<"Enter the size of the array (<20):";
     cin>>size;
     cout<<"\n\nNow enter elements in the array...";
     cout<<"\nNOTE: Elements should be in INCREASING ORDER of their values.";
     getch();
     system("cls");
               
     for(int i=0;i<size;i++)
     {
             cout<<"\t\t\tElement No:"<<i+1;
             cout<<"\n\t\t\tIndex No:"<<i;
             cout<<"\nArray Status:-"<<endl;
             for(int j=0;j<i;j++)
             {
                     cout<<A[j]<<"  ";
             }
             cout<<endl<<"Enter element here:";
             cin>>A[i];
             system("cls");
     }
}        

void BinarySearch::print_array()
{
      cout<<"ARRAY STATUS:-";
      cout<<endl;
      for(int i=0;i<size;i++)
      {
              cout<<A[i]<<" ";
      }
}

void BinarySearch::B_Search()
{
     print_array();
     cout<<endl;
     cout<<"Enter number to be searched:";
     cin>>n;
     
     beg=0;last=size-1;
     detected_position=0;
     
     while(beg<=last)
     {
             mid=(beg+last)/2;
             if(A[mid]==n)
             {
                 
                 detected_position=mid+1;
                 break;
             }
             else if(A[mid]<n)
             {
                  beg=mid+1;
                  
             }
             else if(A[mid]>n)
             {last=mid-1; }
     }
}

void BinarySearch::show()
{
     system("cls");
     print_array();
     cout<<endl;
     if(detected_position>0)
     {
         cout<<endl<<n<<" found at position "<<detected_position;
     
     }
     else
     cout<<endl<<n<<" is not present in the array.";
     getch();
}    
     
int main()
{
    BinarySearch obj;
    obj.input();
    obj.B_Search();
    obj.show();
    return 0;
}

