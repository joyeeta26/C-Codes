#include<iostream>
using namespace std;
class student
{
	char name[20];
	int roll;
	int marks[5];
	public:
		void readData()
		{
			float sum=0;
			cout<<"Enter the following information:\n";
			cout<<"Name:";
			cin>>name;
			cout<<"\n";
			cout<<"Roll No:";
			cin>>roll;
			cout<<"\n";
			cout<<"Enter the marks in 5 subjects:\n";
			for(int i=0;i<5;i++)
			{
				cout<<"Subject "<<i+1<<":";
				cin>>marks[i];
				sum+=marks[i];
				cout<<"\n";
			}
			stream(sum);
		}
		void stream(float sum)
		{
			float percentage=(sum/5);
			cout<<"Your percentage marks:"<<percentage<<"%\n";
			if(percentage>=96)
				cout<<"Stream alloted: Computer Science";
			else if(percentage>=91&&percentage<96)
				cout<<"Stream alloted: Electronics";
			else if(percentage>=86&&percentage<91)
				cout<<"Stream alloted: Mechanical";
			else if(percentage>=81&&percentage<86)
				cout<<"Stream alloted: Electrical";
			else if(percentage>=76&&percentage<81)
				cout<<"Stream alloted: Chemical";
			else if(percentage>=71&&percentage<76)
				cout<<"Stream alloted: Civil";
			else
				cout<<"Not alloted\n";
		}
};
int main()
{
	student s;
	s.readData();
	return 0;
}

