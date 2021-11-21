# include <iostream>
using namespace std;

int Partition(int Arr[], int low, int high)
{
	int pivot = Arr[low];      // Taking Pivot as First Element
	int i = low;
	
	for(int j=low+1;j<=high;j++)
	{
		if(Arr[j]<pivot)
		{
			i++;
			swap(Arr[i],Arr[j]);
		}
	}
	swap(Arr[i],Arr[low]);
	return (i);
}

void print(int arr[], int n) { for(int i=1;i<=n;i++) { cout<<arr[i]<<ends; } cout<<endl; }

void Quick_Sort(int Arr[], int low, int high)
{
	if(low < high)
	{
		int pivot = Partition(Arr,low,high);
		
		Quick_Sort(Arr,low,pivot-1);
		Quick_Sort(Arr,pivot+1,high);
	}
}

int main()
{
	int n;
	
	cout<<"enter the size of the array : "; cin>>n;
	
	int arr[n];
	
	cout<<"enter the elements in the array : "; for(int i=1;i<=n;i++) { cin>>arr[i]; }
	
	cout<<"Array arr["<<n<<"] : "; print(arr,n);
	
	Quick_Sort(arr,1,n);
	
	cout<<endl<<"\nArray after sorting arr["<<n<<"] : "; print(arr,n);
}