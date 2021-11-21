# include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
   int i,j,flag=0;
   
   for (i=1; i<=n; i++)
   {
   	
     for (j=1; j<=n-i; j++)
     {
        if (arr[j]>arr[j+1]) { swap(arr[j],arr[j+1]); flag=1; }
     }
     
     if (flag==0){break;}
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
	
	BubbleSort(arr, n);
	
	cout<<endl<<"Array after sorting arr["<<n<<"] : "; print(arr,n);
	
}