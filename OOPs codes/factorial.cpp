#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter a number for which you want to calculate factorial:\n";
	cin>>n;
	int fact=1;
	if(n==0)
	{
		fact=1;
	}
	else
	{
		for(int i=1;i<=n;i++)
			fact*=i;
	}
	cout<<"The factorial of number "<<n<<" is "<<fact;
	return 0;
}

