#include<iostream>
#include<conio.h>
#include<math.h>
#include<process.h>
using namespace std;

class Complex
{
      float r,i;
      public:
      Complex()
      {
               r=0;
               i=0;
      }
      Complex(Complex&);
      void add(Complex,Complex);
      void sub(Complex,Complex);
      void mul(Complex,Complex);
      void div(Complex,Complex);
      void input(float,float);
      void show();
};

void Complex::add(Complex c1,Complex c2)
{
      r=c1.r+c2.r;
      i=c1.i+c2.i;
}

void Complex::sub(Complex c1,Complex c2)
{
     r=c1.r-c2.r;
     i=c1.i-c2.i;
}

void Complex::mul(Complex c1,Complex c2)
{
     r=(c1.r*c2.r-c1.i*c2.i);
     i=(c1.r*c2.i+c1.i*c2.r);
}


void Complex::div(Complex c1,Complex c2)
{
     r=(c1.r*c2.r + c1.i*c2.i)/( pow(c2.r,2) + pow(c2.i,2) );
     i=(c1.i*c2.r - c1.i*c2.i)/( pow(c2.r,2) + pow(c2.i,2) );
}

void Complex::input(float r,float i)
{
     Complex::r= r;
     Complex::i= i;
}

void Complex::show()
{
     if(i>=0)
     cout<<r<<"+"<<i<<"i";
     else 
     cout<<r<<i<<"i";
}


Complex::Complex(Complex &c)
{
     r=c.r; i=c.i;
}



class Perform_Operations
{
      Complex c1,c2,c3;
      public:
      void input();
      void add();
      void sub();
      void mul();
      void div();
};

void Perform_Operations::input()
{
     float r,i;
     cout<<"Enter for complex no. c1:-";
     cout<<"Real Part:";
     cin>>r;
     cout<<"Imaginary Part:";
     cin>>i;
     c1.input(r,i);
     cout<<"Enter for complex no. c2:-";
     cout<<"Real Part:";
     cin>>r;
     cout<<"Imaginary Part:";
     cin>>i;
     c2.input(r,i);
}

void Perform_Operations::add()
{
     c3.add(c1,c2);
     cout<<"Sum of the complex nos. is:";
     c3.show();
     getch();
}

void Perform_Operations::sub()
{
     c3.sub(c1,c2);
     cout<<"Diff. of the complex nos. is:";
     c3.show();
     getch();
}

void Perform_Operations::mul()
{
     c3.mul(c1,c2);
     cout<<"Product of the complex nos. is:";
     c3.show();
     getch();
}

void Perform_Operations::div()
{
     c3.div(c1,c2);
     cout<<"Result of Division of the complex nos. is:";
     c3.show();
     getch();
}



int main()
{
     Perform_Operations obj;
     int ch;
     
     do{system("cls");
            cout<<"What do you want to do?";
            cout<<"\n1.Add Complex Numbers."           
                <<"\n2.Subtract Complex Numbers"
                <<"\n3.Divide Complex Numbers"
                <<"\n4.Multiply Complex Numbers"
                <<"\n5.Exit";
            cin>>ch;
            system("cls");
            switch(ch)
            {
                      case 1: obj.input();obj.add();break;
                      case 2: obj.input();obj.sub();break;
                      case 3: obj.input();obj.div();break;
                      case 4: obj.input();obj.mul();break;
                      case 5: exit(0);
                      default : cout<<"ERROR";
            }
            
     }while(ch<5);
            
 return 0;
}           
