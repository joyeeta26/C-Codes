#include<iostream>
using namespace std;
class Triangle
{
	float a,b,c;
	
	public:
		float area()
		{
			if(c>a && c>b)
			return 0.5*a*b;
			else if(b>a)
			return 0.5*a*c;
			else 
			return 0.5*c*b; 
		}
		void input()
		{
			cout<<"Enter the sides of the right angled triangle:\n";
			cin>>a>>b>>c;
		}
		float peri()
		{
			return a+b+c;
		}
};
int main()
{
	Triangle a;
	a.input();
	cout<<"The area of the triangle is:"<<a.area()<<"sq. units\n";
	cout<<"The perimeter of the triangle is:"<<a.peri()<<"units\n";
	return 0;
}

