# include <iostream>
using namespace std;

class Array
{
	int **arr,r,c;
	
	public:
		
		void setsize()
		{
			cout<<"Enter Rows and Columns :";
			cin>>r>>c;
			
			arr = new int*[r];
			for(int i=0;i<r;i++)
			{
				arr[i] = new int[c];
			}
		}
		
		void read()
		{
			cout<<"Enter the elements for 2-d array : "<<endl;
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cin>>arr[i][j];
				}
			}
		}
		
		void del(int x)
		{	
		    
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(arr[i][j] == x)
					{
						arr[i][j] = 0;
						continue;
					}
					else
					cout<<arr[i][j]<<"  ";
				}
				cout<<endl;
			}
    		
		}
		
		void print()
		{
			cout<<"Entered 2-d array is : \n";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<arr[i][j]<<"   ";
				}
				cout<<endl;
			}
		}
};

int main()
{
	int temp;
	Array a;
	a.setsize();
	a.read();
	a.print();
	cout<<"enter the element to be deleted : "<<ends;
	cin>>temp;
	a.del(temp);
	return 0;
	
}