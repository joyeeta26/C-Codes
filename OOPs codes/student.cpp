#include<iostream>
using namespace std;
class student
{
	int roll;
	char name[20];
	char std[8];
	int marks[5];
	float percentage;
	void calculate()
	{
		float sum;
		for(int i=0;i<5;i++)
		{
			sum+=marks[i];
		}
		percentage=sum/5;
		
	}
	public:
		void readMarks()
		{
			cout<<"Enter the following information about student:\n";
			cout<<"Roll NO:";
			cin>>roll;
			cout<<"\n";
			cout<<"Name:";
			cin>>name;
			cout<<"\n";
			cout<<"Standard:";
			cin>>std;
			cout<<"\n";
			cout<<"Enter Marks in 5 subjects:\n";
			for(int i=0;i<5;i++)
			{
				cout<<"Subject "<<i+1<<":";
				cin>>marks[i];
				cout<<"\n";
			}
			calculate();		
		}
		void display()
		{
			cout<<"*****Student Details*****\n";
			cout<<"Roll NO:"<<roll<<"\n";
			cout<<"Name:"<<name<<"\n";
			cout<<"Standard:"<<std<<"\n";
			cout<<"Percentage:"<<percentage<<"%\n";
		}
};
int main()
{
	student s;
	s.readMarks();
	s.display();
	return 0;
}

