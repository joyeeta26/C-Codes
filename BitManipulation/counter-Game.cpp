#include<iostream>
using namespace std;

int main()
{
	int T,N;
	cin>>T;
	cin>>N;
	bool c=true;
	int n;
	for(int i=0;i<T;i++)
	{
		while(N!=1)
		{
			if(!(N&1))
			{
				N/=2;		
			}
			else	
			{
				n=N;
				n=n|(n>>1);
				n=n|(n>>2);
				n=n|(n>>3);
				n=n|(n>>4);
				N-=(n+1)>>1;
				
			}
			c=!c;
		}
			if(c)
	cout<<"Richard";
	else
	cout<<"Louise";
	}

	return 0;
}

