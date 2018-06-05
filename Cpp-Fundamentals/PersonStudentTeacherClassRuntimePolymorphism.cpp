//Implementation of Runtime polymorphism using Pure Virtual Functions

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


class Person
{
    protected:
    	char *name,*address,*fatherHusbandName,*mobNo,*occupation,*dob;
    public:
    	Person();
    	virtual void input()=0;  //pure virtual
    	virtual void show()=0;   //pure virtual
    
};
//Abstract class

Person::Person()
{
        name=new char;
        fatherHusbandName=new char;
        address=new char;
        mobNo=new char;
        occupation=new char;
        dob=new char;
}

class Student:public Person
{
    char *institution,*course;
    public:
    Student();
    void input();
    void show();

};

Student::Student()
{
       institution=new char;
       course=new char;
}

void Student::input()
{
    system("cls");

    do
    {

        system("cls");
        cout<<"----------STUDENT ENTRY PAGE------------";
        cout<<"\n\nEnter Name:";
        gets(name);  
        system("cls");
        if(!name)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}
    }while(!name);

    do
    {
        system("cls");
        cout<<"----------STUDENT ENTRY PAGE------------";
        cout<<"\n\nEnter Father's/Husband's name:";

        
        gets(fatherHusbandName);
        system("cls");
        if(*fatherHusbandName==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }while(*fatherHusbandName==NULL);

    do
    {
        system("cls");
        cout<<"----------STUDENT ENTRY PAGE------------";
        cout<<"\n\nEnter Address:";
        
        gets(address);
        system("cls");
        if(*address==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }while(*address==NULL);

    do
    {
        system("cls");
        cout<<"----------STUDENT ENTRY PAGE------------";
        cout<<"\n\nEnter Mobile Number:";
        
        gets(mobNo);
        system("cls");
        if(*mobNo==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }while(*mobNo==NULL);

    occupation="Student";

    bool chk=true;
    while(chk)
    {
        system("cls");
        cout<<"----------STUDENT ENTRY PAGE------------";
        cout<<"\n\nEnter Date of Birth (yyyy/mm/dd):";
        
        gets(dob);
        
        if(*dob!=NULL)
        chk=false;
        
        else if(*(dob+4)=='a'&&*(dob+7)=='a')
        chk=false;
        
        system("cls");
        if(chk)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }

    do
    {
        cout<<"----------STUDENT ENTRY PAGE------------";
        cout<<"\n\nEnter Institution Name:";
        
        gets(institution);
        system("cls");
        if(*institution==NULL)
        cout<<"\nInvalid Entry. Enter Again.";

    }while(*institution==NULL);

    do
    {
        system("cls");
        cout<<"----------STUDENT ENTRY PAGE------------";
        cout<<"\n\nEnter Course:";
        
        gets(course);
        system("cls");
        if(*course==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }while(*course==NULL);
}

void Student::show()
{
    cout<<"----------STUDENT DISPLAY PAGE-----------";
    cout<<"\nName:"<<name;
    cout<<"\nAddress:"<<address;
    cout<<"\nFather/Husband Name:"<<fatherHusbandName;
    cout<<"\nMobile No:"<<mobNo;
    cout<<"\nOccupation:"<<occupation;
    cout<<"\nDOB:"<<dob;
    cout<<"\nInstitution:"<<institution;
    cout<<"\nCourse:"<<course;
    
}


class Teacher:public Person
{
      char *department,*qualification;
      float annualSalary;
      public:
      Teacher();
      void input();
      void show();
};



Teacher::Teacher()
{
      department=new char;
       qualification=new char;
       annualSalary=0;
}

void Teacher::input()
{
    system("cls");

    do
    {

        system("cls");
        cout<<"----------TEACHER ENTRY PAGE------------";
        cout<<"\n\nEnter Name:";
        gets(name);  
        system("cls");
        if(*name==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}
    }while(*name==NULL);

    do
    {
        system("cls");
        cout<<"----------TEACHER ENTRY PAGE------------";
        cout<<"\n\nEnter Father's/Husband's name:";

        
        gets(fatherHusbandName);
        system("cls");
        if(*fatherHusbandName==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }while(*fatherHusbandName==NULL);

    do
    {
        system("cls");
        cout<<"----------TEACHER ENTRY PAGE------------";
        cout<<"\n\nEnter Address:";
        
        gets(address);
        system("cls");
        if(*address==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }while(*address==NULL);

    do
    {
        system("cls");
        cout<<"----------TEACHER ENTRY PAGE------------";
        cout<<"\n\nEnter Mobile Number:";
        
        gets(mobNo);
        system("cls");
        if(*mobNo==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }while(*mobNo==NULL);

    occupation="Teacher";

    bool chk=true;
    while(chk)
    {
        system("cls");
        cout<<"----------TEACHER ENTRY PAGE------------";
        cout<<"\n\nEnter Date of Birth (yyyy/mm/dd):";
        
        gets(dob);
        
        if(*dob!=NULL)
        chk=false;
        
        else if(*(dob+4)=='a'&&*(dob+7)=='a')
        chk=false;
        
        system("cls");
        if(chk)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}

    }
    
    do
    {
        system("cls");
        cout<<"----------TEACHER ENTRY PAGE------------";
        cout<<"\nEnter Department:";
        gets(department);
        
        if(*department==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}
        
    }while(*department==NULL);
    
    do
    {
        system("cls");
        cout<<"----------TEACHER ENTRY PAGE------------";
        cout<<"\nEnter Qualification:";
        cin>>qualification;
       if(*qualification==NULL)
        {cout<<"\nInvalid Entry. Enter Again.";getch();}
    }while(*qualification==NULL);
    
    system("cls");
        cout<<"----------TEACHER ENTRY PAGE------------";
    cout<<"\nEnter Annual Salary:";
    cin>>annualSalary;

}


void Teacher::show()
{
    cout<<"----------TEACHERS DISPLAY PAGE-----------";
    cout<<"\nName:"<<name;
    cout<<"\nAddress:"<<address;
    cout<<"\nFather/Husband Name:"<<fatherHusbandName;
    cout<<"\nMobile No:"<<mobNo;
    cout<<"\nOccupation:"<<occupation;
    cout<<"\nDOB:"<<dob;
    cout<<"\nDepartment:"<<department;
    cout<<"\nQualification:"<<qualification;
    cout<<"\nAnnual Salary:"<<annualSalary;
}


int main()
{
    Person *p;
    Student s;
    Teacher t;
    int ch;
    
    do{
            system("cls");
            cout<<"1. Teacher Entry";
            cout<<"\n2. Student Entry";
            cin>>ch;
            system("cls");
            switch(ch)
            {
                 case 1: p=&t;
                         p->input();
                         p->show();
                         getch();
                         break;
                         
                 case 2: p=&s;
                         p->input();
                         p->show();
                         getch();
                         break;
                         
                 default: cout<<"ERROR";
                         
            }
      }while(1);  
            
    
    
    getch();
    return 0;
    
}
