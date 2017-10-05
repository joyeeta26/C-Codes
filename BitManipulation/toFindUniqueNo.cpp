#include<iostream>
using namespace std;

int unique(int A[],int n)
{
	int res=A[0];
	for(int i=1;i<n;i++)
	{
		res=res^A[i];
	}
	return res;
}
int main()
{
	int n;
	
	cout<<"Enter  no of elements u want to enter\n";
	cin>>n;
	int A[n];
	cout<<"Enter array elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<"The unique element in the array is:"<<unique(A,n);
	return 0;
}

