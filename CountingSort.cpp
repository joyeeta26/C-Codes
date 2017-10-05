 #include<iostream>
using namespace std;
#define MAX_SIZE 10
int main()
{
	int ar[MAX_SIZE],Ar[MAX_SIZE];
	int C[7];
	int j=0;
	for(int i=0;i<7;i++)
	C[i]=0;
	cout<<"enter the elements of the array(b/w 0-6)";
	for(int i=0;i<MAX_SIZE;i++)
	{
		cin>>ar[i];
		C[ar[i]]++;
	}
	int t[7];
	t[0]=0;
	for(int i=1;i<7;i++)
	{
		t[i]=t[i-1]+C[i-1];
	}
	for(int i=0;i<MAX_SIZE;i++)
	{
		Ar[t[ar[i]]]=ar[i];
		t[ar[i]]++;
	}
	cout<<"The sorted elements of the array are:\n";
	for(int i=0;i<MAX_SIZE;i++)
	{
		cout<<Ar[i]<<" ";	
	}
	return 0;
}

