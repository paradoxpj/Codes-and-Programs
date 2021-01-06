#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)  
{  
	
    int min_index = 0;   
    for (int i = 0; i < n-1; i++)  
    {    
        min_index = i;  
        for (int j = i+1; j < n; j++)  
        {
        	if (arr[j] < arr[min_index])  
            min_index = j;  
		}
  
        int temp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = temp; 
    }  
}  
int main()
{
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array elements: \n";
	for(int i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<":";
		cin>>arr[i];
	}
	selection_sort(arr,n);
	cout<<"Array after sorting: \n";
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	return 0;
}
