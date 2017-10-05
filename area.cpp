#include<iostream>
#include<cmath>
using namespace std;
float area(float a,float b)
{
	return a*b;
}
double area(double r)
{
	return 3.14*r*r;
}
float area(float a,float b,float c)
{
	float s=(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
	cout<<"enter whose area u want to find out?\n";
	cout<<"1.circle";
	float a,b,c;
	double r;char ch;
	cout<<"\n2.Rectangle\n";
	cout<<"3.triangle\n";
	int choice;
	do{
		cout<<"enter choice:\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the radius:\n";
				cin>>r;
				cout<<"area: "<<area(r)<<"\n";
				break;
			case 2:
				cout<<"Enter the length and breadth:\n";
				cin>>a>>b;
				cout<<"area: "<<area(a,b)<<"\n";
				break;
			case 3:
				cout<<"Enter the sides of the triangle:\n";
				cin>>a>>b>>c;
				cout<<"area: "<<area(a,b,c)<<"\n";
				break;
		}
		cout<<"Do you want to continue?";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
