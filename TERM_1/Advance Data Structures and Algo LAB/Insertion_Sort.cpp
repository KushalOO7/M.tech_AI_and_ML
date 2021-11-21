# include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
   int i,j,key;
   
   for (i=2; i<=n; i++)
   {
     key=arr[i];
   	 j = i-1;
   	 
		while(j>=1 && key<arr[j])
		{
    	arr[j+1]=arr[j];
    	j-=1;
		}
	
	arr[j+1]=key;	
   }
}

void print(int Arr[], int n) { for(int i=0;i<n;i++) { cout<<"["<<Arr[i]<<"]"<<ends; } cout<<endl; }

main()
{
	int n;
	
	cout<<"enter the size of the array : "; cin>>n;
	
	int arr[n];
	
	cout<<"enter the elements in the array : "; for(int i=1;i<=n;i++) { cin>>arr[i]; }
	
	cout<<"Array arr["<<n<<"] : "; print(arr,n); 
	
	InsertionSort(arr, n);
	
	cout<<endl<<"Array after sorting arr["<<n<<"] : "; print(arr,n);
	
}