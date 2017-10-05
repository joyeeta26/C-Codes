#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	float term,sum=0;
	cout<<"Upto how many numbers u want to find sum of cubes?\n";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		term=pow(i,3);
		sum+=term;
	}
	cout<<"the sumof cubes of first "<<n<<" natural numbers is: "<<sum<<"\n";
	return 0;
}

