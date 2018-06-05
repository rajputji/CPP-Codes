#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class Palindrome
{
      char string[20],s[20];
      int flag;
      public:
      Palindrome();
      void input();
      void check();
};

Palindrome::Palindrome()
{
    flag=0;
}

void Palindrome::input()
{
     cout<<"Enter the string you want to check is palindrome or not:";
     gets(string);
}

void Palindrome::check()
{
     
     int len=strlen(string),i;
     for(i=0;i<len;i++)
     {  
             s[i]=string[len-i-1];
     }
     s[len]='\0';
     
     if(strcmpi(string,s)==0)
     cout<<"\nThe string is palindrome.";
     else
     cout<<"\nString isn't palindrome.";
     getch();
}        
    
int main()
{
     Palindrome obj;
     obj.input();
     obj.check();
     return 0;
}
