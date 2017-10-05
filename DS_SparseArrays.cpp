#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n,c=0;
	cin>>n;
	vector<string> ar(n);
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		
	}
	int q;
	cin>>q;
	string str;
	for(int j=0;j<q;j++)
	{
		c=0;
		cin>>str;
		for(int i=0;i<n;i++)
		{
			if(str==ar[i])
			c++;
		}
		cout<<c<<"\n";
	}
	return 0;	
}
