#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
	char ch;
	ifstream fin;
	ofstream fout;
	fout.open("file1.txt");
	cout<<"Enter the contents of first file::";
	while(cin.get(ch));
		fout.put(ch);
	cout<<"Writing done!!";
	fout.close();
	
    fin.open("file1.txt");
	fout.open("file2.txt");
	fin.get(ch);
	while(!fin.eof())
	{
		if(ch!=' ')
			fout.put(ch);
		fin.get(ch);
	}
	fin.close();
	fout.close();
	
	fin.open("file2.txt");
	cout<<"\nAfter copying, the new file with no whitespaces is::"<<endl;
	fin.get(ch);
	while(!fin.eof())
	{
		fin.get(ch);
		cout<<ch;
	}
	fin.close();

	getch();
	return 0;
}
