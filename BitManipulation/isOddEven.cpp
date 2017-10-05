#include<iostream>
using namespace std;

bool isOddEven(int n)
{
	return (!(n & 1));
}

int main()
{
	int n;
	cout<<"Enter number\n";
	cin>>n;
	if(isOddEven(n))
	{
		cout<<"Even\n";
	}
	else
	{
		cout<<"Odd!!\n";
	}
	return 0;
}

