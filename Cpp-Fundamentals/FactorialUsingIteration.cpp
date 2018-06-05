#include<iostream>
#include<conio.h>

using namespace std;

class Factorial
{
      unsigned long long int n,factorial,m;
      public:
      void calcFactorial();
      void input();      
      void show();
      Factorial();
};

Factorial::Factorial()
{n=0;factorial=1;m=0;}

void Factorial::input()
{
     cout<<"Enter n:";
     cin>>n;
     m=n;
}

void Factorial::calcFactorial()
{
     unsigned long long int tmp=n;
     while(tmp>=1)
     {
         factorial*=tmp;
         tmp--;
     }
}

void Factorial::show()
{
     system("cls");
     cout<<"Factorial of "<<n<<" = "<<factorial;
     getch();
}

int main()
{
    Factorial obj;
    obj.input();
    obj.calcFactorial();
    obj.show();
    return 0;
}
