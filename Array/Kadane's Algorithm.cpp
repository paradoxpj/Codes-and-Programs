#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;

    int arr[n];
    cout<<"\nEnter elements of array : ";
    for( int i = 0; i < n; i++ ){
        cin>>arr[i];
    }
    int res = arr[0];
    int temp = arr[0];
    for( int i = 1; i < n ; i++ ){
        temp = max( arr[i], temp + arr[i] );
        res = max( res, temp );
    }
    cout<<"Result : "<<res<<"\n";
    return 0;
}
