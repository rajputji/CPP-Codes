#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void showaddr(char *a);
int noofvow(char* a);
void cstrtolow(char* a);
void cstrtoup(char* a);
void cstrrev(char* a);

void showaddr(char *a)
{
     cout<<"\n\n\tThe string is: "<<a;
     for(int i=0;i<strlen(a);i++)
     {
             cout<<"\n\n\tAddress of "<<a[i]<<" is:"<<(void *)&a[i];
     }
}

int noofvow(char* a)
{
    int count=0;
    cout<<"\n\n\t\tThe string is: "<<a;
    for(int i=0;i<strlen(a);i++)
    {
            if((a[i]=='a')||(a[i]=='A')||(a[i]=='e')||(a[i]=='E')||(a[i]=='i')||(a[i]=='I')||(a[i]=='o')||(a[i]=='O')||(a[i]=='u')||(a[i]=='U'))
            {
                            count++;
            }
    }
    return count;
}        

void cstrtolow(char* a)
{
     for(int i=0;i<strlen(a);i++)
     {
            a[i]=tolower(a[i]);
     }
     cout<<"\n\n\tThe string in lower case is:"<<a;
}

void cstrtoup(char* a)
{
     for(int i=0;i<strlen(a);i++)
     {
            a[i]=toupper(a[i]);
     }
     cout<<"\n\n\tThe string in upper case is:"<<a;
}
     
void cstrrev(char* a)
{
     cout<<"\n\n\tThe string in reverse form is:"<<strrev(a);
}

class mystring
{
      public:
             int mycmp(char* a,char* b);
             char* myapp(char* a,char* b);
             int mylen(char* a);
             char mylow(char a);
             char myup(char a);
             void myrev(char* a);
};

char* mystring::myapp(char* a,char* b)
{
      int i=strlen(a);
      int j=0;
      
      for(int k=i;k<=(strlen(b)+i);k++)
      {
              a[k]=b[j++];
              cout<<a[k];
      }
      return a;
}
 
int mystring::mylen(char* a)
{
    int i;
    for(i=0;i<strlen(a);i++)
    {}
    return i;
}

char mystring::mylow(char a)
{
     if((a>=97)&&(a<=122))
     {
           a=a;
     }
     else
     {
         a=a+32;
     }
     return a;
}

char mystring::myup(char a)
{
     if((a>=65)&&(a<=90))
     {
           a=a;
     }
     else
     {
         a=a-32;
     }
     return a;
}
        
void mystring::myrev(char* a)
{
      char b;
      int i=strlen(a);
      i--;
      int j=0;
      while(j<=i)
      {
             b=a[j];
             a[j++]=a[i];
             a[i--]=b;
      }
      cout<<"\n\n\t\tReverse of string is:"<<a;
}    
int mystring::mycmp(char* a,char* b)
{
    int i=strlen(a);
    int j=strlen(b);
    if(i==j)
    {
           int k=0;
           while(k<i)
           {
                     if(a[k]==b[k])
                     {
                            k++;
                     }
                     else if(a[k]<b[k])
                     {
                          return -1;
                     }
                     else if(a[k]>b[k])
                     {
                          return 1; 
                     }  
                     return 0;     
            }
    }
    else if(i<j)
    {
         return -1;
    }
    
    else if(i>j)
    {
         return 1;
    }
}
            
    
    

int main()
{
    int n;
    mystring m;
    do
    {
    	system("cls");
        cout<<"\n\t\t\t*****String Operations****\n";
        cout<<"\n\t\t\t1. Compare strings.\n";
        cout<<"\n\t\t\t2. Append strings.\n";
        cout<<"\n\t\t\t3. Find length of string.\n";
        cout<<"\n\t\t\t4. Convert to lower case.\n";
        cout<<"\n\t\t\t5. Convert to upper case.\n";
        cout<<"\n\t\t\t6. Reverse my string.\n";
        cout<<"\n\t\t\t7. Count number of vowels.\n";
        cout<<"\n\t\t\t8. Show address of each character in string.\n";
        cout<<"\n\t\t\tEnter your choice:";
        cin>>n;
        
        
        if(n==1)
        {
                char A[20];
                char B[20];
                cin.ignore(40,'\n');
                cout<<"\n\n\t\tEnter string A:";
                gets(A);
                cout<<"\n\t\tEnter string B:";
                gets(B);
                do
                {
                        system("cls");
                        cout<<"\n\n\n\t\t\t1. Compare strings with mystring class function.\n";
                        cout<<"\n\t\t\t2. Compare strings with C string function.\n";
                        cout<<"\n\t\t\t3. Compare strings with C++ string function.\n";
                        cout<<"\n\t\t\tEnter your choice:";
                        cin>>n;
                        
                        if(n==1)
                        {
                                if(m.mycmp(A,B)==0)
                                {
                                     cout<<"\n\n\t\tStrings A and b are same.";
                                }
                                
                                else if(m.mycmp(A,B)<0)
                                {
                                     cout<<"\n\n\t\tString A is smaller than string B.";
                                }
                                
                                else if(m.mycmp(A,B)>0)
                                {
                                     cout<<"\n\n\t\tString A is greater than string B.";
                                }
                                getch();

                        }
                        
                        else if(n==2)
                        {
                                if(strcmp(A,B)==0)
                                {
                                                   cout<<"\n\n\t\tStrings A and b are same.";
                                }
                                
                                else if(strcmp(A,B)<0)
                                {
                                     cout<<"\n\n\t\tString A is smaller than string B.";
                                }
                                
                                else if(strcmp(A,B)>0)
                                {
                                     cout<<"\n\n\t\tString A is greater than string B.";
                                }
                                getch();

                        }
                        
                        else if(n==3)
                        {
                                 string a;
                                 cin.ignore(40,'\n');
                                 cout<<"\n\n\t\tEnter string A:";
                                 getline(cin,a);
                                 
                                 if(a.compare(B)==0)
                                 {
                                                   cout<<"\n\n\t\tStrings A and b are same.";
                                 }
                                
                                 else if(a.compare(B)<0)
                                 {
                                     cout<<"\n\n\t\tString A is smaller than string B.";
                                 }
                                
                                 else if(a.compare(B)>0)
                                 {
                                     cout<<"\n\n\t\tString A is greater than string B.";
                                 }
                                 getch();
                        }
                        else
                        {
                            break;
                        }
                }while(1);
        }//n=1 ends
        
        else if(n==2)
        {
                char A[20];
                char B[20];
                cin.ignore(40,'\n');
                cout<<"\n\n\t\tEnter string A:";
                gets(A);
                cout<<"\n\n\t\tEnter string B:";
                gets(B);
                do
                {
                        system("cls");
                        cout<<"\n\n\n\t\t\t1. Append strings with mystring class function.\n";
                        cout<<"\n\t\t\t2. Append strings with C string function.\n";
                        cout<<"\n\t\t\t3. Append strings with C++ string function.\n";
                        cout<<"\n\t\t\tEnter your choice:";
                        cin>>n;
                        
                        if(n==1)
                        {
                                
                                cout<<"\n\n\t\tThe appended string is: "<<m.myapp(A,B);
                                getch();
                        }
                        
                        else if(n==2)
                        {
                                cout<<"\n\n\t\tThe appended string is:"<<strcat(A,B);
                                getch();
                        }
                        
                        else if(n==3)
                        {
                                 string a;
                                 cin.ignore(40,'\n');
                                 cout<<"\n\n\t\tEnter string A:";
                                 getline(cin,a);
                                 cout<<"\n\n\t\tThe appended string is:"<<a.append(B);
                                 getch();
                        }
                        else
                        {
                            break;
                        }
                }while(1);
        }//n=2 ends
         
        else if(n==3)
        {
                char A[20];
                char B[20];
                cin.ignore(40,'\n');
                cout<<"\n\n\t\tEnter string A:";
                gets(A);
                cout<<"\n\n\t\tEnter string B:";
                gets(B);
                do
                {
                        system("cls");
                        cout<<"\n\n\n\t\t\t1. Find length of strings with mystring class function.\n";
                        cout<<"\n\t\t\t2. Find length of strings with C string function.\n";
                        cout<<"\n\t\t\t3. Find length of strings with C++ string function.\n";
                        cout<<"\n\t\t\tEnter your choice:";
                        cin>>n;
                        
                        if(n==1)
                        {
                                cout<<"\n\n\t\tString "<<A<<" length is:"<<m.mylen(A);
                                cout<<"\n\n\t\tString "<<B<<" length is:"<<m.mylen(B);
                        }
                        
                        else if(n==2)
                        {
                                cout<<"\n\n\t\tString "<<A<<" length is:"<<strlen(A);
                                cout<<"\n\n\t\tString "<<B<<" length is:"<<strlen(B);
                                
                        }
                        
                        else if(n==3)
                        {
                                 string a;
                                 cin.ignore(40,'\n');
                                 cout<<"\n\n\t\tEnter string A:";
                                 getline(cin,a);
                                 cout<<"\n\n\t\tString "<<A<<" length is:"<<a.length();
                        }
                        else
                        {
                            break;
                        }
                        getch();
                }while(1);
        }//n=3 ends
                  
        else if(n==4)
        {
                char A[20];
                char B[20];
                cin.ignore(40,'\n');
                cout<<"\n\n\t\tEnter string A:";
                gets(A);
                cout<<"\n\n\t\tEnter string B:";
                gets(B);
                do
                {
                        system("cls");
                        cout<<"\n\n\n\t\t\t1. Convert strings to lower case with C string function.\n";
                        cout<<"\n\t\t\t2. Convert strings to lower case with mystring class function.\n";
                        cout<<"\n\t\t\tEnter your choice:";
                        cin>>n;
                        
                        if(n==1)
                        {
                                cstrtolow(A);
                                cstrtolow(B);
                                
                        }
                        
                        else if(n==2)
                        {
                                for(int i=0;i<strlen(A);i++)
                                {
                                        A[i]=m.mylow(A[i]);
                                }
                                
                                for(int i=0;i<strlen(B);i++)
                                {
                                        B[i]=m.mylow(B[i]);
                                }
                                
                                cout<<"\n\n\t\tThe string A in lower case is :"<<A;
                                cout<<"\n\n\t\tThe string b in lower case is :"<<B;
                        }
                                
                        
                        else
                        {
                            break;
                        }
                        getch();
                }while(1);
        }//n=4 ends
        
        else if(n==5)
        {
                char A[20];
                char B[20];
                cin.ignore(40,'\n');
                cout<<"\n\n\t\tEnter string A:";
                gets(A);
                cout<<"\n\n\t\tEnter string B:";
                gets(B);
                do
                {
                        system("cls");
                        cout<<"\n\n\n\t\t\t1. Convert strings to upper case with C string function.\n";
                        cout<<"\n\t\t\t2. Convert strings to upper case with mystring class function.\n";
                        cout<<"\n\t\t\tEnter your choice:";
                        cin>>n;
                        
                        if(n==1)
                        {
                                cstrtoup(A);
                                cstrtoup(B);
                        }
                        
                        else if(n==2)
                        {
                                
                                for(int i=0;i<strlen(A);i++)
                                {
                                        A[i]=m.myup(A[i]);
                                }
                                
                                for(int i=0;i<strlen(B);i++)
                                {
                                        B[i]=m.myup(B[i]);
                                }
                                
                                cout<<"\n\n\t\tThe string A in upper case is :"<<A;
                                cout<<"\n\n\t\tThe string b in upper case is :"<<B;
                                
                        }
                        else
                        {
                            break;
                        }
                        getch();
                }while(1);
        }//n=5 ends
             
        else if(n==6)
        {
                char A[20];
                char B[20];
                cin.ignore(40,'\n');
                cout<<"\n\n\t\tEnter string A:";
                gets(A);
                cout<<"\n\n\t\tEnter string B:";
                gets(B);
                do
                {
                        system("cls");
                        cout<<"\n\n\n\t\t\t1. Reverse strings  with C string function.\n";
                        cout<<"\n\t\t\t2. Reverse strings with mystring class function.\n";
                        cout<<"\n\t\t\tEnter your choice:";
                        cin>>n;
                        
                        if(n==1)
                        {
                                cstrrev(A);
                                cstrrev(B);
                        }
                        
                        else if(n==2)
                        {
                                m.myrev(A);
                                m.myrev(B);
                        }
                        else
                        {
                            break;
                        }
                        getch();
                }while(1);
        }//n=6 ends
           
        else if(n==7)
        {
             int i;
             char A[20];
             cin.ignore(40,'\n');
             cout<<"\n\n\t\tEnter string A:";
             gets(A);
             i=noofvow(A);
             cout<<"\n\n\t\tNumber of vowels is: "<<i;
        }
        
           
        else if(n==8)
        {
             char A[20];
             cin.ignore(40,'\n');
             cout<<"\n\n\t\tEnter string A:";
             gets(A);
             showaddr(A);
        }
        
                  
        else
        {
            break;
        }
        
    }while(1);
    
    getch();
    return 0;
}          
                                  
                        
                         
             
