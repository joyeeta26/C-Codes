#include<iostream>
using namespace std;
void clearBit(int& n,int i)
{
	int mask=~(1<<i);
	n=n&mask;
}
int main()
{
	int n,i;
	cout<<"Enter the number\n";
	cin>>n;
	cout<<"Enter the position from where u want to clear the bit\n";
	cin>>i;
	clearBit(n,i);
	cout<<"Number after clearing the bit:"<<n;
	return 0;
}

