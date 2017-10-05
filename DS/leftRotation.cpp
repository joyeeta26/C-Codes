#include <iostream>
#include<vector>

using namespace std;

vector <int> leftRotation(vector <int> a, int d) {
   int tmp;
   int size=a.size(),i=0,j=0;
   
   if(d>=size)
   {
   	d-=size;
   }
   int k=size/2+1;
   if(d<=k)
   {
   
	   for( i=0;i<d;i++)
	   {
	   	tmp=a[0];
	   	for( j=0;j<a.size()-1;j++)
	   	{
			a[j]=a[j+1];   
		}
		a[j]=tmp;
	   }
	}
	else
	{
		d=size-d;
		for(i=0;i<d;i++)
		{
			tmp=a[size-1];
			for(j=size-1;j>0;j--)
			{
				a[j]=a[j-1];
			}
			a[j]=tmp;
		}
	}
	return a;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector <int> result = leftRotation(a, d);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

