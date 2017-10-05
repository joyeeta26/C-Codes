#include<iostream>
using namespace std;
const int size=3;
class vector
{
	int v[size];
	public:
		vector();
		vector(int* x);
		friend vector operator*(vector b,int a);
		friend vector operator*(int a,vector b);
		friend istream & operator>>(istream&,vector&);
		friend ostream & operator<<(ostream&, vector&); 
};
vector::vector()
{
	for(int i=0;i<size;i++)
		v[i]=0;
}
vector::vector(int * x)
{
	for(int i=0;i<size;i++)
	{
		v[i]=x[i];
	}
}
vector operator*(vector b,int a)
{
	vector temp;
	for(int i=0;i<size;i++)
	{
		temp.v[i]=a*b.v[i];
	}	
	return temp;
} 
vector operator*(int a,vector b)
{
	vector c;
	for(int j=0;j<size;j++)
	{
		c.v[j]=a*b.v[j];
	}
	return c;
}
istream & operator>>(istream& din,vector &b)
{
	for(int i=0;i<size;i++)
		din>>b.v[i];
	return din;
}
ostream & operator<<(ostream& dout,vector&b)
{
	dout<<"(";
	for(int i=0;i<size-1;i++)
		dout<<b.v[i]<<",";
	dout<<b.v[size-1]<<")\n";
	return dout;
}
int x[size]={2,3,4};
int main()
{
	vector m;
	vector n=x; 
	cout<<"Enter the elements of vector m \n ";
	cin>>m;
	cout<<"m = "<<m<<"\n";
	vector p,q;
	p=2 * m;
	q=n * 2;
	cout<<"\n";
	cout<<"p = "<<p<<"\n";
	cout<<"q = "<<q<<"\n";
	return 0;
}

