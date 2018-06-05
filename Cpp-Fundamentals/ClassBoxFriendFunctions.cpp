#include<iostream>
#include<conio.h>
//#include<iomanip.h>


using namespace std;

class Box
{
      float l,b,h;
      float sa,vol;
      public:
      Box(); 
      Box(float,float,float); 
      Box(const Box&);      
      void input();
      void show();
      void calcSurfaceArea();
      void calcVolume();
      friend Box& operator++();
      friend Box operator++(int);
      friend Box& operator--();
      friend Box operator--(int);
      friend bool operator==(const Box&) const;
      friend void operator=(const Box&); 
      friend void coc();  
      
      friend Box operator+(const Box&) const;
      friend Box operator-(const Box&) const;
      friend Box operator*(const Box&) const;
      friend Box operator/(const Box&) const;
      
};

Box::Box()
{
          l=0;
          b=0;
          h=0;
}

Box::Box(float l,float b,float h)
{
         Box::l=l;                      
         Box::b=b;
         Box::h=h;
}

Box::Box(const Box &b1)
{
         l=b1.l;
         b=b1.b;
         h=b1.h;
}

void Box::input()
{
     cout<<"Enter length,breadth & height and key return:-"<<endl;
     cin>>l>>b>>h;
}

void Box::show()
{
     cout<<"======Box======";
     cout<<endl<<"Length ="<<l;
     cout<<endl<<"Breadth ="<<b;
     cout<<endl<<"Height ="<<h;
     cout<<endl<<"Surface Area="<<sa;
     cout<<endl<<"Volume="<<vol;
}

void Box::calcSurfaceArea()
{
     sa= 2*( (l*b)+(b*h)+(h*l) );
}

void Box::calcVolume()
{
     vol=l*b*h;
}

Box& Box::operator++()
{
     ++l;
     ++b;
     ++h;
     return (*this);
}

Box Box::operator++(int)
{
     Box saveObject=(*this);
     l++;
     b++;
     h++;
     return saveObject;
}

Box& Box::operator--()
{
     --l;
     --b;
     --h;
     return(*this);
}

Box Box::operator--(int)
{
     Box saveObject=(*this);
     l--;
     b--;
     h--;
     return saveObject;
}

bool Box::operator==(const Box &b1) const
{
     if(l==b1.l&&b==b1.b&&h==b1.h)
     return true;
     else
     return false;
}

void Box::operator=(const Box &b1) 
{
     l=b1.l;
     b=b1.b;
     h=b1.h;
}

void Box::coc()
{
     if(l==b==h)
     cout<<endl<<" The Box is a CUBE.";
     else
     cout<<endl<<" The Box is a CUBOID.";
}

Box Box::operator+(const Box &b1) const
{
     Box b2;
     b2.l=l+b1.l;
     b2.b=b+b1.b;
     b2.h=h+b1.h;
     return b2;
}     
     
Box Box::operator-(const Box &b1) const
{
     Box b2;
     b2.l=l-b1.l;
     b2.b=b-b1.b;
     b2.h=h-b1.h;
     
     if(b2.l<0)
     b2.l=-b2.l;
     if(b2.b<0)
     b2.b=-b2.b;
     if(b2.h<0)
     b2.h=-b2.h;
     
     return b1;
}   

Box Box::operator/(const Box &b1) const
{
     Box b2;
     b2.l=l/b1.l;
     b2.b=b/b1.b;
     b2.h=h/b1.h;
     return b1;
}

Box Box::operator*(const Box &b1)  const
{
     Box b2;
     b2.l=l*b1.l;
     b2.b=b*b1.b;
     b2.h=h*b1.h;
     
}



int main()
{
    int ch;
    Box b1,b2,b3,tempBox;
    
    do{
        
        system("cls");
           
    cout<<"=================MENU=================";
    cout<<"\n1.Input/Change Box b1"
        <<"\n2.Show Box"              
        <<"\n3.Increment Box"
        <<"\n4.Decrement Box"
        <<"\n5.Compare Two Boxes"
        <<"\n6.Copy one Box to another using assignment"
        <<"\n7.Check if Box is cube or cuboid"
        <<"\n8.Add two Boxes"
        <<"\n9.Subtract two Boxes"
        <<"\n10.Multiply two Boxes"
        <<"\n11.Divide two Boxes"
        <<"\n0.EXIT";
        
        cout<<"\n\nEnter your choice:";
        cin>>ch;
        
        system("cls");
    
    switch(ch)
    {
              case 1:  b1.input();
                       cout<<"This box will be the default box for unary operations.";
                       getch();
                       break;
              case 2:  b1.calcSurfaceArea();
                       b1.calcVolume();
                       b1.show();
                       getch();
                       break;
              
              case 3:  cout<<"1. Postfix Increment";
                       cout<<"2. Prefix Increment";
                       cin>>ch;
                       
                       if(ch==1)
                       {
                                cout<<"\ntempBox assigned b1++"<<endl;
                                cout<<"\nOriginal Box b1:-"<<endl;
                                b1.show();
                                tempBox = b1++;
                                cout<<"\nPost Incremented Box tempBox:-"<<endl;
                                tempBox.show();
                                getch();
                                break;
                       }
                       else if(ch==2)
                       {             
                                cout<<"\nOriginal Box b1:-"<<endl;
                                b1.show();
                                tempBox=++b1;
                                cout<<"\ntempBox assigned ++b1"<<endl;
                                cout<<"\nPre Incremented Box tempBox:-"<<endl;
                                tempBox.show();
                       }
                       
                         getch();
                         break;
                       
              case 4:  cout<<"1. Postfix Decrement";
                       cout<<"2. Prefix Decrement";
                       cin>>ch;
                       if(ch==1)
                       {
                                cout<<"\nOriginal Box b1:-"<<endl;
                                b1.show();
                                tempBox = b1--;
                                cout<<"\ntempBox assigned b1--"<<endl;
                                cout<<"\nPost Decremented Box tempBox:-"<<endl;
                                tempBox.show();
                                getch();
                                break;
                       }
                       else if(ch==2)
                       {
                                cout<<"\ntempBox assigned --b1"<<endl;
                                cout<<"\nOriginal Box b1:-"<<endl;
                                b1.show();
                                tempBox=--b1;
                                cout<<"\nPre Decremented Box tempBox:-"<<endl;
                                tempBox.show();
                       }
                       
                         getch();
                         break;
                       
              case 5: cout<<"----------Compare Boxes----------";
                      cout<<"\nEnter box b1:-"<<endl;
                      b1.input();
                      cout<<"\nEnter box b2:-"<<endl;
                      b2.input();
                      if(b1==b2)
                      cout<<"The boxes are equal";
                      else
                      cout<<"The boxes are UNEQUAL";
                      getch();
                      break;
                      
              case 6: cout<<"--------Assign one box to other-------";
                      cout<<"\nEnter box b2:-"<<endl;
                      b2.input();
                      system("cls");
                      cout<<"\n\nNOTE:b1 is used as the LHS box, b2 used as RHS box";
                      cout<<"\n\nb1 before b1=b2:-"<<endl;
                      b1.show();
                      b1=b2;  //ASSIGNMENT
                      cout<<"\n\nb1 after b1=b2:-";
                      b1.show();
                      getch();
                      break;
                      
              case 7: cout<<"\nFor Box b1:-"<<endl;
                      b1.coc();
                      getch();
                      break;
                      
              case 8: cout<<"---------Add Two Boxes--------";
                      cout<<"\nEnter box b1:-"<<endl;
                      b1.input();
                      cout<<"\nEnter box b2:-"<<endl;
                      b2.input();
                      
                      b3=b1+b2;  //ADDITION
                      
                      cout<<"\nResult of addition copied to b3 using assignment.";
                      cout<<"Box b1:-"<<endl;
                      b1.show();
                      cout<<"Box b2:-"<<endl;
                      b2.show();
                      cout<<"Box b3=b1+b2:-"<<endl;
                      b3.show();
                      getch();
                      break;
                      
              case 9: cout<<"---------Subtract Two Boxes--------";
                      cout<<"\nEnter box b1:-"<<endl;
                      b1.input();
                      cout<<"\nEnter box b2:-"<<endl;
                      b2.input();
                      
                      b3=b1-b2;  //SUBTRACTION
                      
                      cout<<"\nResult of subtraction copied to b3 using assignment.";
                      cout<<"Box b1:-"<<endl;
                      b1.show();
                      cout<<"Box b2:-"<<endl;
                      b2.show();
                      cout<<"Box b3=b1-b2:-"<<endl;
                      b3.show();
                      getch();
                      break;
                      
              case 10: cout<<"---------Multiply Two Boxes--------";
                      cout<<"\nEnter box b1:-"<<endl;
                      b1.input();
                      cout<<"\nEnter box b2:-"<<endl;
                      b2.input();
                      
                      b3=b1*b2;  //MULTIPLICATION
                      
                      cout<<"\nResult of multiplication copied to b3 using assignment.";
                      cout<<"Box b1:-"<<endl;
                      b1.show();
                      cout<<"Box b2:-"<<endl;
                      b2.show();
                      cout<<"Box b3=b1*b2:-"<<endl;
                      b3.show();
                      getch();
                      break;
                      
              case 11: cout<<"---------Divide Two Boxes--------";
                      cout<<"\nEnter box b1:-"<<endl;
                      b1.input();
                      cout<<"\nEnter box b2:-"<<endl;
                      b2.input();
                      
                      b3=b1/b2;  //DIVISION
                      
                      cout<<"\nResult of division copied to b3 using assignment.";
                      cout<<"Box b1:-"<<endl;
                      b1.show();
                      cout<<"Box b2:-"<<endl;
                      b2.show();
                      cout<<"Box b3=b1/b2:-"<<endl;
                      b3.show();
                      getch();
                      break;
                      
              case 0: exit(0);
                      
              default: cout<<"ERROR";getch();
    }
    
    }while(1);
    
    return 0;
    
                      
}
      
      
