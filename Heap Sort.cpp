#include<bits/stdc++.h>

using namespace std;

void Heapify(int arr[], int n, int i){
	int a = i,lar = i;
	int b = 2*i + 1;
	int c = b+1;
	
	if(b<n && arr[b]>arr[a])
		lar = b;
	if(c<n && arr[c]>arr[b])
		lar = c;
	
	if(lar!=a && arr[lar]>arr[a]){
		swap(arr[a],arr[lar]);
		Heapify(arr,n,lar);
	}	
}

void Buildheap(int arr[], int n){
	int a = (n-2)/2;
	for(int i = a; i>=0; i--){
		Heapify(arr, n, i);
	}
	for(int i = 0; i<n; i++){
		swap(arr[0],arr[n-1-i]);
		Heapify(arr, n-1-i, 0);
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
	cout << "Sorted array: \n";
	Buildheap(arr, n);
	for(int i =0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

