# include <iostream>
using namespace std;

void Merge_Sub_Array(int a[], int low, int mid, int high)
{
	// We have low to mid and mid+1 to high already sorted
	int i = low, j = mid + 1, k = 0, temp[high-low+1];

 
	// Merge the two parts into temp[]. Sorting at the same time. 
	while (i<=mid && j<=high)
	{
		if (a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i->mid into temp[] Array
	while(i<=mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j->high into temp[] Array
	while(j<=high)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
 
 
	// Assigning sorted data which is stored in temp[] to a[]
	for (i=low;i<=high;i++)
	{
		a[i] = temp[i-low];
	}
}

void Merge_Sort(int Arr[], int low, int high)
{
	if(low >= high)
	{ return; }
	
	int mid = low+(high-low)/2;
	
	Merge_Sort(Arr, low, mid);
	Merge_Sort(Arr, mid+1, high);
	
	Merge_Sub_Array(Arr, low, mid, high);
}

void print(int Arr[], int n) { for(int i=0;i<n;i++) { cout<<"["<<Arr[i]<<"]"<<ends; } cout<<endl; }

int main()
{
	int n;
	
	cout<<"enter the size of the array : "; cin>>n;
	
	int Arr[n];
	
	cout<<"enter the elements in the array : "; for(int i=0;i<n;i++) { cin>>Arr[i]; }
	
	cout<<"\nArray Elements Before Merge Sort Arr["<<n<<"] = "; print(Arr,n);
	
	Merge_Sort(Arr,0,n-1);
	
	cout<<endl<<"Array Elements After Merge Sort Arr["<<n<<"] = "; print(Arr,n);
}
