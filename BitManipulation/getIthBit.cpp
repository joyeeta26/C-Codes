#include<iostream>
using namespace std;
int getIthBit(int m,int i)
{
	return (m & (1<<i))!=0?1:0;
}
int main()
{
	int m,n;
	cout<<"Enter the no:\n";
	cin>>m;
	cout<<"Which bit u want to fetch?\n";
	cin>>n;
	cout<<"The "<<n<<"th bit of "<<m<<" is "<<getIthBit(m,n);
	return 0;
}

