#include<iostream>
#include<conio.h>

using namespace std;

class LinearSearch
{
      int A[20],size,n;
      public:
      void input();
      void L_Search();
      void print_array();

};

void LinearSearch::input()
{
     cout<<"Enter the size of the array (<20):";
     cin>>size;
     cout<<"\n\nNow enter elements in the array...";
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

void LinearSearch::L_Search()
{
     int i;
     
     system("cls");
     print_array();
     cout<<"\n\nEnter the number you want to search:";
     cin>>n;
     for(i=0;i<n;i++)
     {
             if(A[i]==n)
             {
                       cout<<"\n\n"<<n<<" found at "<<i+1<<" position.";getch();break;
             }
     }
     if(i==n)
     {cout<<endl<<endl<<n<<" NOT found in the array.";getch();}
}

void LinearSearch::print_array()
{
      cout<<"ARRAY STATUS:-";
      cout<<endl;
      for(int i=0;i<size;i++)
      {
              cout<<A[i]<<" ";
      }
}
 
int main()
{
    LinearSearch obj;
    obj.input();
    obj.L_Search();
    
    return 0;
} 
