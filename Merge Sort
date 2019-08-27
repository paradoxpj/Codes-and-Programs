#include<bits/stdc++.h>

using namespace std;

void Merge(int arr[], int l, int m, int r)
{
	int n1 = m-l+1, n2 = r-m;
	int i,j,k=l,L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=arr[l+i];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=arr[m+1+i];
	}
	i = 0;
	j = 0;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=R[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void MergeSort(int arr[], int l, int r){
	if(l<r)
	{
		int m=l+(r-l)/2;
		MergeSort(arr, l, m);
		MergeSort(arr, m+1, r);
		Merge(arr, l, m, r);
	}
}

int main(){
	int n;
	cout << "Enter size: ";
	cin >> n;
	int arr[n];
	cout << "Enter array: \n";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int l = 0, r = n-1;
	MergeSort(arr, 0 , n-1);
	for( int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}



