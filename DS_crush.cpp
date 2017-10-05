#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector <int>ar(n+1);
	int a,b,k,max=0;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>k;
		for(int j=a;j<=b;j++)
		{
			ar[j]+=k;	
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ar[i]>max)
		max=ar[i];
	}
	cout<<max;
	return 0;
}
