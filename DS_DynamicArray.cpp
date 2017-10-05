#include<iostream>
#include<cmath>

#include<vector>
using namespace std;

int main()
{
	int N,Q;
	cin>>N>>Q;
int t,x,y;
	vector <vector <int> > s(N,vector <int> ());
	
	int lastAnswer=0;
	for(int i=0;i<Q;i++)
	{
		cin>>t>>x>>y;
		if(t==1)
			s[(x^lastAnswer)%N].push_back(y);
		else
		{
			lastAnswer=s[(x^lastAnswer)%N][y%s[(x^lastAnswer)%N].size()];
			cout<<lastAnswer<<"\n";
		}
	}
	
	return 0;
}
