#include<iostream>
using namespace std;
void swap(int & a,int & b)
{
	a=a^b;
	b=b^a;
	a=a^b;
}
int main()
{
	int m,n;
	cout<<"Enter 2 nos\n";
	cin>>m>>n;
	cout<<"The nos before swap are:"<<m<<" "<<n;
	swap(m,n);
	cout<<"\nThe nos after swap are:"<<m<<" "<<n;
	return 0;
}

