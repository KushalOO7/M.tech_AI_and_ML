# include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
   int i,j,min;
   
   for (i=1; i<=n; i++)
   {
   	min = i;
   	
     for (j=i+1; j<=n; j++)
     {
        if (arr[min]>arr[j]) { min = j; }
     }
     
     swap(arr[min],arr[i]);
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
	
	SelectionSort(arr, n);
	
	cout<<endl<<"Array after sorting arr["<<n<<"] : "; print(arr,n);
	
}