#include<iostream>
using namespace std;

int main()
{
	int a[10];
	float sum=0;
	cout<<"Enter 10 nos\n";
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	float avg=sum/10;
	cout<<"The average of 10 nos: "<<avg<<"\n";
	return 0;
}

