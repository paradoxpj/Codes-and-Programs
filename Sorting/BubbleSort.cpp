#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n){
    for (int i = 0 ; i < n-1 ; i++){
        for (int j =  0 ; j < n-i-1; j++){
            if (arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}
int main(){
    int n;
    int arr_numbers [n];

    cout <<"Enter the max number of the array\n";
    cin >> n ;
    cout<<"Enter the array numbers to be sort them\n";
    for (int i = 0 ; i<n; i++)
        cin >> arr_numbers[i];
    BubbleSort(arr_numbers, n);
    cout << "The numbers after sorting.\n";
    for (int i = 0 ; i<n; i++)
        cout<< arr_numbers[i] << " ";
    cout<<endl;
}
