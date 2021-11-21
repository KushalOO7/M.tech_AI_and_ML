# include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int root = i;         // current root node
    int left = 2*i + 1;   // left child of the current root node
    int right = 2*i + 2;  // right child of the current root node
    
    
    if (arr[right]<arr[root] && right<n)  // If right child is less than the root node
        root = right;
        
    if (arr[left]<arr[root] && left<n)   // If left child is less than the root node
        root = left;
  
    
    if (root!=i)
	{
        swap(arr[i],arr[root]);
        heapify(arr,n,root);
    }
}

void Heap(int arr[], int n)
{
    int indx_first = (n/2)-1;  // reverse traversal
    
    for (int i=indx_first; i>=0; i--) 
	{
        heapify(arr,n,i);
    }
}


void print(int arr[], int n){ for (int i=0; i<n; i++){ cout<<arr[i]<<ends; } cout<<"\n"; }


int main()
{
int n;
cout<<"enter the no. of elements to be entered : "; cin>>n;
	
int arr[n];
cout<<"enter the elements to create MIN_HEAP : "; for(int i=0;i<n;i++) { cin>>arr[i]; } cout<<"\n";

cout<<"Before Building MIN_HEAP in array form is:\n";
print(arr,n);

Heap(arr,n);

cout<<"MIN_HEAP in array form is:\n";
print(arr,n);
  
return 0;
}