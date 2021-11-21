# include <iostream>
using namespace std;

void print(int Arr[], int n) { for(int i=0;i<n;i++) { cout<<"["<<Arr[i]<<"]"<<ends; } cout<<endl; }


void radix_sort(int array[],int n)
{
	int max = array[0];
	
    for (int i=1; i<n; i++) { if(array[i]>max) { max=array[i]; } }
	
	for(int p=1; max/p>0; p*=10)
	{
  		int output[n];
  		int count[10];

  		for (int i=0; i<10; i++) { count[i] = 0; } // initializing count values to zero


  		for (int i=0; i<n; i++){
   			count[(array[i] / p)%10]++; }     // Counting the elements and updating count values


  		for (int i=1; i<10; i++){ count[i] += count[i-1]; }  // Cumulating the count values


  		for (int i=n-1; i>=0; i--) 
 		{
    		output[count[(array[i] / p)%10] - 1] = array[i]; // Sorting and Placing Elements
    		count[(array[i] / p)%10]--;                      // according to its count value
  		}

  		for (int i=0; i<n; i++)
    		{
			array[i] = output[i];
		}
	}
}

int main()
{
	int n;
	
	cout<<"enter the size of the array : "; cin>>n;
	
	int arr[n];
	
	cout<<"enter the elements in the array : "; for(int i=0;i<n;i++) { cin>>arr[i]; }
	
	cout<<"Array Elements Before Radix Sort arr["<<n<<"] : "; print(arr,n);
	
	radix_sort(arr,n);
	
	cout<<"Array Elements After Radix Sort arr["<<n<<"] : "; print(arr,n);
}
