#include<iostream>
using namespace std;

bool isPowerOfTwo(int x)
{
	return (x && !(x& (x-1)));
}
int main()
{
	int num;
	cout<<"Enter a number:";
	cin>>num;
	if(isPowerOfTwo(num))
	{
		cout<<"The number is a power of 2\n";
	}
	else
	{
		cout<<"The number is not a power of 2\n";
	}
	return 0;
}

