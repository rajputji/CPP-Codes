#include<iostream>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

class Triangle
{
      float a,b,c,area,s;
      public:
      Triangle()
      {
          a=b=c=area=s=0;
      }
      bool input()
      {
           cout<<"\nEnter a:";
           cin>>a;
           cout<<"\nEnter b:";
           cin>>b;
           cout<<"\nEnter c:";
           cin>>c;
           calcSemiPerimeter();
           if(!ifTriangleFormed())
           {
               cout<<"ERROR: Triangle Can't be formed.";
               a=b=c=0;
               s=0;
               area=0;
               return 0;
           }
           else
           return 1;
      }
      void show()
      {    cout<<"\na="<<a;
           cout<<"\nb="<<b;
           cout<<"\nc="<<c;
           cout<<"\narea="<<area;
           cout<<"\ns="<<s;
      }
      void calcArea(char); //to calculate area by standard formula for right triangle
      void calcArea(); //to calculate area by heron's forumula
      char chkRightTriangle();
      void calcSemiPerimeter();
      void operator=(const Triangle&);
      bool operator==(const Triangle &T);
      bool ifTriangleFormed();
};

bool Triangle::ifTriangleFormed()
{     
     if(a<=b+c && b<=c+a && c<=b+a)
     return true;
     else 
     return false;
}

void Triangle::calcSemiPerimeter()
{
      s=(a+b+c)/2;
}

char Triangle::chkRightTriangle()
{
     
     float max=a;
     int chk=0;
     if(max>b)
     {max=b;chk=1;}
     if(max>c)
     {max=c;chk=2;}
     switch(chk)
     {
                case 0: if(pow(a,2)==(pow(b,2)+pow(c,2)))
                        return 'a';
                case 1: if(pow(b,2)==(pow(a,2)+pow(c,2)))
                        return 'b';
                case 2: if(pow(c,2)==(pow(b,2)+pow(a,2)))
                        return 'c';
                default: return 0;
     }
}

void Triangle::calcArea(char hypotenuse)
{
          if(hypotenuse=='a')
          	area=(b*c)/2;
          else if(hypotenuse=='b')
          	area=(a*c)/2;
          else
          	area=(a*b)/2;
          
}

void Triangle::calcArea()
{
          
          area=sqrt(s*(s-a)*(s-b)*(s-c));
}

void Triangle::operator=(const Triangle &T)
{
     a=T.a;
     b=T.b;
     c=T.c;
     area=T.area;
     s=T.s;
     
}

bool Triangle::operator==(const Triangle &T)
{
     if(a==T.a&&b==T.b&&c==T.c || a==T.a&&b==T.c&&c==T.a || a==T.b&&b==T.c&&c==T.a 
        || a==T.b&&b==T.a&&c==T.c || a==T.c&&b==T.b&&c==T.a || a==T.c&&b==T.a&&c==T.b)
     return true;
     else
     return false;
}

int  main()
{
	int ch;
	Triangle T1,T2;
	char hypo;
	do{
         system("cls");
         cout<<"-----MENU------";
         cout<<"\n1. Find area";
         cout<<"\n2. Assign T1 to T2";
         cout<<"\n3. Compare T1 and T2";
         cout<<"\n4. Exit";
         cin>>ch;
         system("cls");
         switch(ch)
         {
                   case 1: cout<<"\nEnter triangle T1:";
                           if(T1.input())
                           {
                           hypo=T1.chkRightTriangle();;
                           if(hypo)
                           {
                                   T1.calcArea(hypo);
                                   cout<<"\nArea calculated using std.forumula";                           
                           }
                           else
                           {
                                   T1.calcArea();
                                   cout<<"\nArea calculated using heron's formula";
                           }
                                   T1.show();
                                   
                           }
                                   getch();
                                   break;
                   
                   case 2: cout<<"\nEnter T1:-";
                           if(T1.input())
                           {
                           T1.calcArea();
                           cout<<"\nOperating T2=T1";
                           T2=T1;
                           cout<<"\nafter T2=T1, Triangle T2:-";
                           T2.show();
                           }
                           getch();
                           break;
                   
                   case 3: cout<<"\nEnter T1:-";
                           if(T1.input())
                           {
                           cout<<"\nEnter T2:-";
                           if(T2.input())
                           {
                           if(T1==T2)
                           cout<<"\nTriangles are equal.";
                           else
                           cout<<"\nTriangles aren't equal.";
                           }
                           }
                           getch();
                           break;
                           
                   case 4: exit(0);
                   
                   default: cout<<"ERROR";getch();break;
         }
  	}while(1);
  	
	return 0;
}
                   
                   
                           
         


          
          
          

      
