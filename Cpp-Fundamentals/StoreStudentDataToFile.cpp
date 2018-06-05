#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

struct Student
{
       int rollno;
       char Name[20];
       char Class[20];
       int Year;
       float TotalMarks;
};

int main()
{
    Student S[10];
    ofstream fout;
    fout.open("studentData.txt");
    for(int i=0;i<10;i++)
    {
    	cout<<"For Student "<<i+1<<" Enter details::"<<endl;
    	cout<<"Enter the roll number of the student:";
    	cin>>S[i].rollno;
    	cin.ignore(10,'\n');
    	cout<<"Enter the name of the student:";
    	gets(S[i].Name);
    	cout<<"Enter the class of the student:";
		gets(S[i].Class);
    	cout<<"Enter the total marks of the student:";
    	cin>>S[i].TotalMarks;
    	cout<<"Enter Year:";
    	cin>>S[i].Year;
        fout.write(reinterpret_cast<char *>(&S[i]),sizeof(Student));
        cout<<endl;
    }
    fout.close();    
    getch();
    return 0;
}
