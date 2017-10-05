
#include <iostream>

int main()
{
int arr[6][6];
    for(int arr_i = 0;arr_i < 6;arr_i++)
	{
       for(int arr_j = 0;arr_j < 6;arr_j++)
	   {
          std::cin >> arr[arr_i][arr_j];
       }
    }
    int max,sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
    for(int i=0;i<4;i++)
    {
		sum=0;
		for(int j=0;j<4;j++)
		{
			sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
			if(sum>max)
			max=sum;
		}
	}
	cout<<max;
	return 0;
}
