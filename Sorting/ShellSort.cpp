#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"\nEnter n elements of array : ";
    int arr[n];
    for( int i = 0; i < n; i++ ){
        cin>>arr[i];
    }

    for( int i = n / 2; i > 0; i = i / 2 ) {

            for( int j = i ; j < n ; j++ ){

                int k = j;
                int t = arr[j];

                while( k >= i && arr[k - i ] >= t ){
                        arr[k] = arr[ k - i ];
                        k = k - i;
                }
                arr[k] = t;
            }
    }
    cout<<"\nSorted array : ";
    for( int i = 0; i < n; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
