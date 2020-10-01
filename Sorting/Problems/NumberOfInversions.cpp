//Counting Number of Inversions in a list using Merge Sort

#include <iostream>
using namespace std;

long long merge( int arr[], int aux[], int low, int mid, int high );

long long countInversions( int arr[], int aux[], int low, int high ){

    long long inversions = 0;

    if( low < high ){

        int mid = low + ( high - low ) / 2 ;
        inversions += countInversions( arr, aux, low, mid );
        inversions += countInversions( arr, aux, mid + 1, high );
        inversions += merge( arr, aux, low, mid, high );

    }

    return inversions;

}

long long merge( int arr[], int aux[], int low, int mid, int high ){

    long long inversions = 0;
    int i = low, j = mid + 1, k = low;

    while( i <= mid && j <= high ){

        if( arr[i] <= arr[j] ){
            aux[k++] = arr[i++];
        }
        else{
            aux[k++] = arr[j++];
            inversions = inversions + ( mid + 1 - i );
        }

    }

    while( i <= mid ){
        aux[k++] = arr[i++];
    }

    while( j <= high ){
        aux[k++] = arr[j++];
    }

    for( int i = low; i <= high; i++ ){
        arr[i] = aux[i];
    }

    return inversions;
}

int main() {

	int t;
	cin>>t;

	while( t-- ){

	    int n;
	    cin>>n;

	    int arr[n];
	    int aux[n];

	    for( int i = 0; i < n; i++ ){
	        cin>>arr[i];
	    }

	    long long inversions  = countInversions( arr, aux, 0, n - 1 );

	    cout<<inversions<<"\n";
	}
	return 0;
}
