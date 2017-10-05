#include<iostream>
#include<iomanip>
#define MAXS 10
using namespace std;
struct sparse
{
	int row;
	int col;
	int value;
};
void sparseTranspose(sparse A[],sparse B[])
{
	int m,n,t,i,C[MAXS],D[MAXS];
	 m=A[0].row;
	 n=A[0].col;
	 t=A[0].value;
	
	for(i=0;i<n;i++)
		C[i]=0;
	for(i=1;i<=t;i++)
	{
		C[A[i].col]++;
	}
	D[0]=1;
	for(i=1;i<n;i++)
		D[i]=D[i-1]+C[i-1];
	
	for(i=1;i<=t;i++)
	{
		B[D[A[i].col]].col=A[i].row;
		B[D[A[i].col]].row=A[i].col;
		B[D[A[i].col]].value=A[i].value;
		D[A[i].col]++;
	}
	B[0].row=A[0].col;
	B[0].col=A[0].row;
	B[0].value=t;
}
void display(sparse M[])
{
	int m=M[0].row;
	int n=M[0].col;
	int val=0;
	int t=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(t<=M[0].value)
			{
				if(i==M[t].row &&j==M[t].col)
				{
					cout<<setw(6)<<M[t].value;
					t++;
					continue;
				}
				
			}
			cout<<setw(6)<<val;
		}
		cout<<"\n";
	}
}
int main()
{
sparse A[20],B[20];
cout<<"Enter rows and columns of matrix A:\n";
cin>>A[0].row>>A[0].col;
cout<<"Enter the Number of non zero elements in matrix:\n";
cin>>A[0].value;
cout<<"Enter the non zero elements of the matrix along with their row and column(row,col,val):\n";
for(int i=1;i<=A[0].value;i++)
{
	cin>>A[i].row>>A[i].col>>A[i].value;
}
	sparseTranspose(A,B);
	
cout<<"Matrix before Transpose:\n";
display(A);
	cout<<"Matrix Afer transpose:\n";
	display(B);
return 0;
}

