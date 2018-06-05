// Series 1 - 2 + 3 - 4 + 5 ......

#include<iostream>
#include<conio.h>
using namespace std;
class series
{
      int n;
      float sum;
      public:
             series();
             void Sum();
};
series::series()
{n=0;}
void series::Sum()
{
     sum=0;
     cout<<"\nEnter the number of terms you want to add::";
     cin>>n;
     cout<<"The sum of series:: ";
     for(int i=1;i<=n;i=i+1)
     {
          if(i%2!=0)
          {sum+=i;
           cout<<i<<" - ";}
          else
          {sum-=i;
           cout<<i<<" + ";}
     }
     cout<<"\b\b = "<<sum<<endl;
 }
 
int main()
{
     series o;
     char ch='y';
     while(ch=='y')
     {
     o.Sum();
     cout<<"\nDo you want to cont???";
     cin>>ch;
     }
     getch();
     return 0;
}
