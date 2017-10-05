#include<iostream>
using namespace std;

int main()
{
	int num,primes=0,composites=0,f=0;
	cout<<"Enter Number(-1 to exit):\n";
	cin>>num;
	do{
		for(int i=2;i<=num/2;i++)
		{
			if(num%i==0)
				{
					f=1;
					break;
				}
		}
		if(f==0)
			primes++;
		else
			composites++;
		f=0;
		cout<<"Enter number:";
		cin>>num;
		cout<<"\n";
	}while(num!=-1);
	cout<<"The number of prime numbers entered is:"<<primes<<"\n";
	cout<<"The number of composites entered is:"<<composites<<"\n";
	return 0;
}

