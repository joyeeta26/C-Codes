//number of bits that needs to be changed to covert one no into another
#include<iostream>
using namespace std;

int count(int m,int n)
{
	int res=m^n;
	int c=0;
	while(res)
	{
		res=res&(res-1);
		c++;
	}
	return c;
}


int main()
{
	int m,n;
	cout<<"enter two numbers\n";
	cin>>m>>n;
	cout<<"The no of bits that needs to be changed to convert "<<m<<" into "<<n<<" is: "<<count(m,n);
	return 0;
}

