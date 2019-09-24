// Counting Sort (a.k.a. Jatav Sort with a little stability)
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;  //Input size
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];    //Input element
	}
	int mx = arr[0];
	for(int i=1; i<n; i++){
		if(arr[i]>mx){
			mx = arr[i];    //finding maximum in the array
		}
	}
	
	int brr[mx+1];    //Creating an array to track frequencies with size = maximum in the input array
	
	for(int i=0; i<mx+1; i++){
		brr[i] = 0;      //initiating frequency as 0
	}
	for(int i=0; i<n; i++){
		brr[arr[i]]+=1;       //Counting frequencies
	}
	for(int i=1; i<mx+1; i++){
		brr[i] += brr[i-1];      //calculating prefix sum of the frequency array
	}
	
	int crr[n];
	for(int i=n-1; i>=0; i--){
		crr[brr[arr[i]]-1] = arr[i];     //storing the numbers in their respective places
		brr[arr[i]]-=1; 
	}
	for(int i=0; i<n; i++){
		cout << crr[i] << " ";
	}
	return 0;
}
