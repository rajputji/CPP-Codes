#include<iostream>
#include<conio.h>

using namespace std;

class array
{
    int a[10],n,i;
    float b,s;
    public:
    array();
	void input();
    void even();                
    void odd();
    void sum();
    void avg();
    void min();
    void max();
    void remove();
    void reverse();
};

array::array()
{
    i=0;n=0;s=0;b=0;
}
       
void array::input()
{
    cout<<"Enter Size of Array :  ";
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cout<<"\n Enter "<<i+1<<" element:   ";
        cin>>a[i];
   }  
}

void array::even()
{
    cout<<"\n Even numbers: \n";
    for(i=0;i<n;i++)
    {
    if(a[i]%2==0)
    cout<<" "<<a[i];
	}
}

void array::odd()
{
    cout<<"\n Odd numbers: \n";
    for(i=0;i<n;i++)
    {
    if(a[i]%2==1)
    cout<<" "<<a[i];
	}
}

void array::sum()
{      
    cout<<"\n sum of array \n";
    for(i=0;i<n;i++)
    s+=a[i];
    cout<<"\n"<<s;
}

void array::avg()
{
    cout<<"\n avarage of array:";
    b=s/n;
    cout<<"\n"<<b;
}

void array::min()
{   
    cout<<"\n Minimum number is: ";
    int min=a[0];
    for(i=1;i<n;i++)
    {
    if(a[i]<min)
    min=a[i];
	}
    cout<<"\n"<<min;
}

void array::max()
{    
    cout<<"\n Maximum number is: ";
    int max=a[0];
    for(i=1;i<n;i++)
    {
    if(a[i]>max)
    max=a[i];
    }
	cout<<"\n"<<max;
}

void array::remove()
{
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<n;)
        {
            if(a[j]==a[i])
            {
                for(int k=j;k<n;k++)
                {
                    a[k]=a[k+1];
                }
                    n--;
            }
            else
                j++;
        }
    }
	cout<<"\n After removing duplicates, New array :";
	for(i=0;i<n;i++)
	cout<<" "<<a[i];	
}

void array::reverse()
{
    cout<<"\n Reversed array : \n";
    for(i=n-1;i>=0;i--)
    {
    cout<<" "<<a[i];
	}
}

int main()
{
    array o;
	int choice; 
	do
	{
		system("cls");
		cout<<"\n\tMENU\n";
		cout<<"\n\t1. Enter Array \n";
        cout<<"\n\t2. Even Numbers \n";
        cout<<"\n\t3. Odd Numbers \n";
        cout<<"\n\t4. Sum of Array \n";
        cout<<"\n\t5. Average of Array \n";
        cout<<"\n\t6. Minimum Number of Array \n";
        cout<<"\n\t7. Maximum Number of Array \n";
        cout<<"\n\t8. Remove Duplicate Number from Array \n";
        cout<<"\n\t9. Reverse of Array \n";
        cout<<"\n\t0. Exit \n";
        cout<<"\n\tEnter your choice:";
        cin>>choice;
        switch(choice)
        {        	   
            case 1: o.input();
            		getch();
                    break;
            case 2: o.even();
                    getch();
					break;
            case 3: o.odd();
                    getch();
					break;
			case 4: o.sum();
                    getch();
					break;
			case 5: o.avg();
                    getch();
					break;
			case 6: o.min();
                    getch();
					break;
			case 7: o.max();
                    getch();
					break;		 
		    case 8: o.remove();
                    getch();
					break;
			case 9: o.reverse();
                    getch();
					break;			 		 
			case 0: exit(0);
			default: cout<<"\n\t\tWrong Choice";       
        }
                  
    }while(1);                                                          
	getch();
	return 0;
}
