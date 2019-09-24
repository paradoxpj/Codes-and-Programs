//Radix Sort

#include<bits/stdc++.h>
#include<cmath>

using namespace std;

void CountSort(int arr[], int n, int c){
	int brr[10];    //Creating an array to track frequencies with size = digits possible
	
	for(int i=0; i<10; i++){
		brr[i] = 0;      //initiating frequency as 0
	}
	for(int i=0; i<n; i++){
		int x = arr[i]%(int)pow(10,c);
		x = x/(int)pow(10,c-1);        //Accessing the Cth digit
		brr[x]+=1;       //Counting frequencies
	}
	for(int i=1; i<10; i++){
		brr[i] += brr[i-1];      //calculating prefix sum of the frequency array
	}
	
	int crr[n];
	for(int i=n-1; i>=0; i--){
		int x = arr[i]%(int)pow(10,c);
		x = x/(int)pow(10,c-1);     //Accessing the Cth digit
		crr[brr[x]-1] = arr[i];     //storing the numbers in their respective places
		brr[x]-=1; 
	}
	
	for(int i=0; i<n; i++){
		arr[i] = crr[i];      //Storing the newly created array in the original array
	}
}

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
	int c = 0;
	while(mx>0){
		c+=1;      //keeping the track of the digit we are currently at
		CountSort(arr, n, c);      //Calling Counting Sort for that respective digit
		mx = mx/10;
	}
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	return 0;
}
