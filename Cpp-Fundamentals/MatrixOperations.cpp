#include<iostream>
#include<conio.h>

using namespace std;

class Matrices
{
      int A[10][10],B[10][10],r1,r2,c1,c2;
      int C[10][10];
      public:
      Matrices();
      void input();
      void input(int);
      void addMatrices();
      void multiplyMatrices();
      void subMatrices();
      void transposeMatrix();
      void showMatrices();
};
      
Matrices::Matrices()
{
       r1=0;r2=0;c1=0;c2=0;
}     


void Matrices::showMatrices()
{
     if(r1==0&&c1==0)
     {
        cout<<"Matrix A is Empty.";
     }
     else
     {cout<<"Matrix A:-"<<endl;
     for(int i=0;i<r1;i++)
     {
             for(int j=0;j<c1;j++)
             {
                     cout<<A[i][j]<<" ";
             }
             cout<<endl;
     }
     }
     cout<<"\n\n";
     
     if(r2==0&&c2==0)
     {
         cout<<"Matrix B is Empty.";
     }
     else
     {cout<<"Matrix B:-"<<endl;
     for(int i=0;i<r1;i++)
     {
             for(int j=0;j<c1;j++)
             {
                     cout<<B[i][j]<<" ";
             }
             cout<<endl;
     }
     }
     cout<<endl<<endl;
                     
}
void Matrices::input()
{
     int i,j;
     cout<<"Enter r1:";cin>>r1;
     cout<<"Enter c1:";cin>>c1;
     cout<<"Enter r2:";cin>>r2;
     cout<<"Enter c2:";cin>>c2;
     system("cls");     
          
     cout<<"\t----Enter Elements in matrix A----\n";
     for(int i=0;i<r1;i++)
     {       
             for(j=0;j<c1;j++)
             {                
                cout<<"A["<<i<<"]["<<j<<"] = ";
                cin>>A[i][j];}
     }         
     system("cls");
     cout<<"\t----Enter Elements in matrix B----";
     for(i=0;i<r2;i++)
     {
             for(j=0;j<c2;j++)
             cin>>B[i][j];
     }
     system("cls");
     cout <<"Data Input complete...";
     getch();
}

void Matrices::input(int chk)
{
     int i,j;
     cout<<"Enter r1:";cin>>r1;
     cout<<"Enter c1:";cin>>c1;
     cout<<"\t----Enter Elements in matrix A----\n";
     for(int i=0;i<r1;i++)
     {       
             for(j=0;j<c1;j++)
             {                
                cout<<"A["<<i<<"]["<<j<<"] = ";
                cin>>A[i][j];}
     }         
}


void Matrices::addMatrices()
{
     if(r1==r2&&c1==c2)
     {
              for(int i=0;i<r1;i++)
              {         
                        for(int j=0;j<c1;j++)
                        {
                                C[i][j]=A[i][j]+B[i][j];
                        }
              }
              
              cout<<"Result of matrix addition A+B:-"<<endl;
     
              for(int i=0;i<r1;i++)
              {
                      for(int j=0;j<c2;j++)
                      {
                              cout<<C[i][j]<<" ";
                      }
                      cout<<endl;
              }
              getch();
     }                        
     
     else
     {cout<<"Matrix Addition not possible.";getch();}
}

void Matrices::multiplyMatrices()
{
     int i,j,k;
     if(c1==r2)
     {
               for(i=0;i<r1;i++)
               {
                  for(j=0;j<c2;j++)
                  {
                              C[i][j]=0;
                              for(k=0;k<c1;k++)
                              C[i][j]+=A[i][k]*B[k][j];
                  }
               }
               
               cout<<"Result of matrix multiplication AB:-"<<endl;
     
               for(int i=0;i<r1;i++)
               {
                       for(int j=0;j<c2;j++)
                       {
                               cout<<C[i][j]<<" ";
                       }
                       cout<<endl;
               }
               getch();
                        
     }
     
     else
     {cout<<"Matrix multiplication not possible.";getch();}
}

void Matrices::subMatrices()
{
     if(r1==r2&&c1==c2)
     {
              for(int i=0;i<r1;i++)
              {         
                        for(int j=0;j<c1;j++)
                        {
                                C[i][j]=A[i][j]-B[i][j];
                        }
              }
              
              cout<<"Result of matrix subtraction A-B:-"<<endl;
     
              for(int i=0;i<r1;i++)
              {
                      for(int j=0;j<c2;j++)
                      {
                              cout<<C[i][j]<<" ";
                      }
                      cout<<endl;
              }
              getch();
     }                        
     
     else
     {cout<<"Matrix Subtraction not possible.";getch();}
}

void Matrices::transposeMatrix()
{
     
     if(r1==c1)
     {
               for(int i=0;i<r1;i++)
               {
                       for(int j=0;j<c1;j++)
                       {
                               C[i][j]=A[j][i];
                       }
               }
               
              
               cout<<"Result of matrix transposition A':-"<<endl;
     
              for(int i=0;i<r1;i++)
              {
                      for(int j=0;j<c1;j++)
                      {
                              cout<<C[i][j]<<" ";
                      }
                      cout<<endl;
              }
              getch();
     }                
     
     else
     {cout<<"Transpose of the matrix A can't be evaluated.";getch();}
               
}




int main()
{
    Matrices obj;
    int ch,c;
    do
    {   system("cls");
        cout<<"\t==========MENU==========="<<endl;
        cout<<"\t1.INPUT MATRICES"<<endl
            <<"\t2.ADD MATRICES"<<endl
            <<"\t3.SUBTRACT MATRICES"<<endl
            <<"\t4.MULTIPLY MATRICES"<<endl
            <<"\t5.TRANSPOSE MATRIX"<<endl
            <<"\t6.EXIT"<<endl
            <<"\n\nENTER YOUR CHOICE:";
        cin>>ch;
        switch(ch)
        {
                  case 1: system("cls");
                          cout<<"1. Input both matrices\n2.Input matrix A";
                          cin>>c;
                          if(c==1)
                          obj.input();
                          else
                          obj.input(1);
                          break;
                  
                  case 2: system("cls");
                          obj.showMatrices();
                          obj.addMatrices();
                          break;
                  
                  case 3: system("cls");
                          obj.showMatrices();
                          obj.subMatrices();
                          break;
                  
                  case 4: system("cls");
                          obj.showMatrices();
                          obj.multiplyMatrices();
                          break;
                  
                  case 5: system("cls");
                          obj.showMatrices();
                          obj.transposeMatrix();
                          break;
                  
                  case 6: exit(0);
                  
                  default: cout<<"ERROR"; getch(); break;
        }
        
    }while(1);
    return 0;
}
