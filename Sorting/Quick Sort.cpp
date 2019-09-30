#include<bits/stdc++.h>

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partiton(int arr[], int low, int high)
{
	int piv = arr[high];
	int i = low-1,j;
	for(j=low;j<high;j++)
	{
		if(arr[j]<=piv)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
void quickSort(int arr[], int low, int high)
{
	if(low<high)
	{
		int p = partiton(arr, low, high);
		quickSort(arr, low, p-1);
		quickSort(arr, p+1, high);
	}
}

int main()
{
	int n;
	cout << "Enter the strength of the array\n";
	cin >> n;
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0 , n-1);
	for(i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
