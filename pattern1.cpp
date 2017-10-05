#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char names[5][10];
	int length[5],max=-1;
	cout<<"Enter 5 strings:\n";
	for(int i=0;i<5;i++)
	{
		cin>>names[i];
		length[i]=strlen(names[i]);
		if(length[i]>max)
			max=length[i];
	}
	
	//first way
	cout<<"**********************************";
	cout<<"\n";
	for(int i=max;i>0;i--)
	{
		for(int j=0;j<5;j++)
		{
			if((length[j]-i)>=0)
			{
				cout<<names[j][length[j]-i]<<"\t";
			}
			else
			{
				cout<<"\t";
			}
		}
		cout<<"\n";
	}
	cout<<"\n**********************************\n";
	
	
	//second way
	for(int i=1;i<=max;i++)
	{
		for(int j=0;j<5;j++)
		{
			if((length[j]-i)>=0)
			{
				cout<<names[j][i-1]<<"\t";
			}
			else
			{
				cout<<"\t";
			}
			
		}
		cout<<"\n";
	}
	cout<<"\n**********************************\n";
	
	//third way
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<length[i];j++)
		{
			cout<<names[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n**********************************\n";
	
	//fourth way
		for(int j=0;j<5;j++)
		{
			for(int i=max;i>0;i--)
			{
				if((length[j]-i)>=0)
				{
					cout<<names[j][length[j]-i]<<"\t";
				}
				else
				{
					cout<<"\t";
				}
			}
			cout<<"\n";
		}

	return 0;
}

