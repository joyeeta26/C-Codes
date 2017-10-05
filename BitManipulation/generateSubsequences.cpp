#include<iostream>
#include<cstring>
using namespace std;
void filterchars(char *a,int i)
{
	int k=0;
	while(i)
	{
		(i&1)?cout<<a[k]:cout<<"";
		k++;
		i=i>>1;
	}
	cout<<endl;
}
void generateSubsets(char *a)
{
	int n=strlen(a);
	int range=1<<n;
	for(int i=0;i<range;i++)
	{
		filterchars(a,i);
	}
}
int main()
{
	char a[100];
	
	cout<<"Enter a string\n";
	cin>>a;

	generateSubsets(a);
	return 0;
}

