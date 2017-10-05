#include<iostream>
using namespace std;

int countSetBits(int n)
{
	int count=0;
	while(n)
	{
		n = n & (n-1);
		count++;
		
	}
	return count;
}
int main()
{
	int n;
	cout<<"Enter number:\n";
	cin>>n;
	
	cout<<"Number of set bits in the no:"<<countSetBits(n);
	return 0;
}

