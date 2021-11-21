# include <iostream>
using namespace std;

int main()
{
	int m,n;
	cout<<"enter the number of rows and columns for the 2-d Array : "<<ends;
	cin>>m>>n;
	int x[m][n],y[m][n],z[m][n];
	
	cout<<"\nEnter elements in First 2-d Array is : ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>x[i][j];
		}
	}
	
	cout<<"\nEnter elements in Second 2-d Array is : ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>y[i][j];
		}
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			z[i][j] = x[i][j] + y[i][j];
		}
	}
	
	cout<<"\nFinal 2-d Array after Adding First two 2-d Arrays is : \n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"      "<<z[i][j]<<ends;
			if(j==n-1)
			{
				cout<<"\n";
			}
		}
	}
	
}