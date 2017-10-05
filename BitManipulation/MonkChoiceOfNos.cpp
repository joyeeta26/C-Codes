#include<iostream>
using namespace std;

void findMax(int *ar1,int* max)
{
	int ct=0,num;
	for(int i=0;i<2;i++)
	{
	
		num=ar1[i];
		while(num)
		{
			num=num & (num-1);
			ct++;
		}
		
	}
	if(ct>*max)
	{
		*max=ct;
	}
}
int main()
{
	int N,T,K,max=0;
	cin>>T;
for(int i=0;i<T;i++)
{

	cin>>N>>K;
	int ar[N];
	for(int i=0;i<N;i++)
	{
		cin>>ar[i];
	}
	int range=1<<N;
	int ar1[2],k=0,flag;
	for(int i=0;i<range;i++)
	{
		k=0;flag=1;
		for(int j=0;j<N;j++)
		{
			if(i&(1<<j))
			{
				if(k>=2)
				{
					flag=0;
					break;
				}
				ar1[k]=ar[j];
				k++;
			}
		}
		if(k==2&&flag==1)
		{
			findMax(ar1,&max);
		}
	}
	
	cout<<max;
}
	return 0;
}

