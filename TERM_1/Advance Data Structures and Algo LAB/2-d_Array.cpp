# include <iostream>
using namespace std;

int main()
{
	int m,n;
	cout<<"enter the number of rows and columns for the 2-d Array : "<<ends;
	cin>>m>>n;
	int arr[m][n];
	
	cout<<"\nenter elements in 2-d Array is : ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	cout<<"\n2-d Array is : \n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"      "<<arr[i][j]<<ends;
			if(j==n-1)
			{
				cout<<"\n";
			}
		}
	}
}