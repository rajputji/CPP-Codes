#include<iostream>
#include<conio.h>

using namespace std;
void stars(int);

int main()
{
    int num;
    char ch='y';
    while(ch=='y')
    {
          cout<<"\nEnter the number of lines you want the triangle to have:"<<endl;
          cin>>num;
          stars(num);
          cout<<"\nDo you want to continue(y/n)?"<<endl;
          cin>>ch;
          if(ch!='y')
            exit(0);
     }
     getch();
     return 0;
}

void stars(int num)
{
     for(int i=1;i<=num;i++)
     {
          for(int j=1;j<=num-i;j++)
              cout<<"  ";
          for(int k=1;k<=i;k++)
              cout<<"* ";
          for(int l=1;l<i;l++)
              cout<<"* ";
          cout<<endl;
     }
}
