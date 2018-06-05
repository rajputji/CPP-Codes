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
	ifstream fin;
	Student S[10];
	fin.open("studentData.txt");
    cout<<"Rollno\t\tName\t\tClass\t\tYear\t\tTotal Marks\n\n";
    for(int i=0;i<10;i++)
    {
            fin.read(reinterpret_cast<char *>(&S[i]),sizeof(Student));
            cout<<S[i].rollno<<"\t\t"<<S[i].Name<<"\t\t"<<S[i].Class<<"\t\t"<<S[i].Year<<"\t\t"<<S[i].TotalMarks<<"\n\n";
    }
    fin.close();        	
	getch();
	return 0;
}
