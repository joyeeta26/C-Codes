#include<iostream>
using namespace std;
void setIthBit(int& n,int i)
{
	int mask=1<<i;
	n=n|mask; 
}
int main()
{
	int n,i;
	cout<<"Enter the number\n";
	cin>>n;
	cout<<"Enter the position where u want to set the bit\n";
	cin>>i;
	setIthBit(n,i);
	cout<<"Number after setting the bit:"<<n;
	return 0;
}

