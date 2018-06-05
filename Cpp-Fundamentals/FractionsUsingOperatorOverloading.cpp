#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Fraction
{
      int n,d;
      public:
      Fraction()
      { n=0;d=1;}
      Fraction(Fraction &f)
      {
          n=f.n;
          d=f.d;
      }
      void reduce();
      void input();
      void show();
      Fraction& operator++();
      Fraction operator++(int);
      Fraction& operator--();
      Fraction operator--(int);
      Fraction operator+(const Fraction&);
      Fraction operator-(const Fraction&);
      Fraction operator*(const Fraction&);
      Fraction operator/(const Fraction&);
      void operator=(const Fraction&);


};

void Fraction::operator=(const Fraction &f)
{
     n=f.n;
     d=f.d;
}

Fraction& Fraction::operator++()
{
    n=n+d;
    reduce();
    return(*this);
}

Fraction Fraction::operator++(int)
{
    Fraction f=(*this);
    n=n+d;
    reduce();
    f.reduce();
    return f;
}

Fraction& Fraction::operator--()
{
    n=n-d;
    reduce();
    return (*this);
}

Fraction Fraction::operator--(int)
{
    Fraction f=(*this);
    n=n-d;
    reduce();
    f.reduce();
    return f;
}

Fraction Fraction::operator+(const Fraction& f1)
{
    Fraction f;
    f.n=n*f1.d+f1.n*d;
    f.d=f1.d*d;
    f.reduce();
    return f;
}

Fraction Fraction::operator-(const Fraction& f1)
{
    Fraction f;
    f.n=n*f1.d-f1.n*d;
    f.d=f1.d*d;
    f.reduce();
    return f;
}

Fraction Fraction::operator*(const Fraction& f1)
{
     Fraction f;
     f.n=f1.n*n;
     f.d=f1.d*d;
     f.reduce();
     return f;
}

Fraction Fraction::operator/(const Fraction& f1)
{
     Fraction f;
     f.n=n*f1.d;
     f.d=d*f1.n;
     f.reduce();
     return f;
}

int gcd(int x,int y)
{
    int r;
    if(y==0)
    	return 0;
    else
    {
        r=x%y;
        if(r==0)
        	return y;
        else
        	return gcd(y,r);
    }
}

void Fraction::reduce()
{
     int g=gcd(n,d);
     n/=g;
     d/=g;
}

void Fraction::input()
{
     cout<<"Enter Numerator:";
     cin>>n;
     ag:
     cout<<"Enter Denominator:";
     cin>>d;
     if(d==0)
     {
             cout<<"Denominator can't be zero. Enter again.";
             goto ag;
     }
     reduce();
}

void Fraction::show()
{
    cout<<n<<"/"<<d;
}


int main()
{
    int ch;
    Fraction f1,f2,f3;

    do{

    system("cls");

    cout<<"----------Fractions----------";
    cout<<"\n1. Input/Change Default Fraction for unary operations."
        <<"\n2. Increment Fraction"
        <<"\n3. Decrement Fraction"
        <<"\n4. Add Fractions"
        <<"\n5. Subtract Fractions"
        <<"\n6. Divide Fractions"
        <<"\n7. Multiply Fractions"
        <<"\n8. Show Default Fraction"
        <<"\n0. Exit.";
    cout<<"\n\nEnter your choice:";
    cin>>ch;

     system("cls");
    switch(ch)
    {
              case 1: cout<<"Enter default fraction f1:-"<<endl;
                      f1.input();
                      break;

              case 2:
                      cout<<"1.Prefix\n2.Postfix";
                      cin>>ch;
                      if(ch==1)
                      {
                           cout<<"NOTE: f1 is default for unary operations";
                           cout<<"\n\nOperating: f2=++f1";
                           cout<<"\nf1 before operating=";
                           f1.show();
                           f2=++f1;
                           cout<<"\nf1 after operating=";
                           f1.show();
                           cout<<"\nf2 after operating=";
                           f2.show();
                      }
                      else if(ch==2)
                      {
                           cout<<"NOTE: f1 is default for unary operations";
                           cout<<"\n\nOperating: f2=f1++";
                           cout<<"\nf1 before operating=";
                           f1.show();
                           f2=f1++;
                           cout<<"\nf1 after operating=";
                           f1.show();
                           cout<<"\nf2 after operating=";
                           f2.show();
                      }
                           getch();
                           break;

              case 3:
                      cout<<"1.Prefix\n2.Postfix";
                      cin>>ch;
                      if(ch==1)
                      {
                           cout<<"NOTE: f1 is default for unary operations";
                           cout<<"\n\nOperating: f2=--f1";
                           cout<<"\nf1 before operating=";
                           f1.show();
                           f2=--f1;
                           cout<<"\nf1 after operating=";
                           f1.show();
                           cout<<"\nf2 after operating=";
                           f2.show();
                      }
                      else if(ch==2)
                      {
                           cout<<"NOTE: f1 is default for unary operations";
                           cout<<"\n\nOperating: f2=f1--";
                           cout<<"\nf1 before operating=";
                           f1.show();
                           f2=f1--;
                           cout<<"\nf1 after operating=";
                           f1.show();
                           cout<<"\nf2 after operating=";
                           f2.show();
                      }
                           getch();
                           break;

              case 4: cout<<"-------Addition------";
                      cout<<"\nEnter fraction f1:-"<<endl;
                      f1.input();
                      cout<<"\nEnter fraction f2:-"<<endl;
                      f2.input();
                      cout<<"\n\nOperating: f3=f1+f2"<<endl;
                      cout<<"\nFraction f1=";
                      f1.show();
                      cout<<"\nFraction f2=";
                      f2.show();
                      f3=f1+f2;
                      cout<<"\nFraction f3=";
                      f3.show();
                      getch();
                      break;


              case 5: cout<<"-------Subtraction------";
                      cout<<"\nEnter fraction f1:-"<<endl;
                      f1.input();
                      cout<<"\nEnter fraction f2:-"<<endl;
                      f2.input();
                      cout<<"\n\nOperating: f3=f1-f2"<<endl;
                      cout<<"\nFraction f1=";
                      f1.show();
                      cout<<"\nFraction f2=";
                      f2.show();
                      f3=f1-f2;
                      cout<<"\nFraction f3=";
                      f3.show();
                      getch();
                      break;



              case 6: cout<<"-------Multiplication------";
                      cout<<"\nEnter fraction f1:-"<<endl;
                      f1.input();
                      cout<<"\nEnter fraction f2:-"<<endl;
                      f2.input();
                      cout<<"\n\nOperating: f3=f1*f2"<<endl;
                      cout<<"\nFraction f1=";
                      f1.show();
                      cout<<"\nFraction f2=";
                      f2.show();
                      f3=f1*f2;
                      cout<<"\nFraction f3=";
                      f3.show();
                      getch();
                      break;


              case 7: cout<<"-------Division------";
                      cout<<"\nEnter fraction f1:-"<<endl;
                      f1.input();
                      cout<<"\nEnter fraction f2:-"<<endl;
                      f2.input();
                      cout<<"\n\nOperating: f3=f1/f2"<<endl;
                      cout<<"\nFraction f1=";
                      f1.show();
                      cout<<"\nFraction f2=";
                      f2.show();
                      f3=f1/f2;
                      cout<<"\nFraction f3=";
                      f3.show();
                      getch();
                      break;

              case 8: cout<<"Fraction f1=";
                      f1.show();
                      getch();
                      break;
              case 0: exit(0);
              default: cout<<"ERROR";
    }

    }while(1);
    return 0;
}

