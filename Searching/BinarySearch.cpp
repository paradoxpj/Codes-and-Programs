#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binSearch( int arr[], int x, int n ){

    int i = 0, j = n - 1;

    while( i <= j ){

        int mid = i + ( j - i ) / 2;

        if( arr[mid] < x ){
            i = mid + 1;
        }
        else if ( arr[mid] > x ){
            j = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){

    int t;
    cin>>t;

    while( t-- ){

        int n,k;
        cin>>n>>k;

        int arr[n];
        for( int i = 0; i < n; i++ ){
            cin>>arr[i];
        }

        cout<<binSearch( arr, k, n )<<"\n";

    }
    return 0;
}
