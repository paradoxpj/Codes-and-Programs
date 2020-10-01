//This program provides the integer square root or in other words,
//the floor of the square root of any number while also avoiding overflow.
//Time complexity is O(N^(1/2))


#include<bits/stdc++.h>

using namespace std;

long long int  squareroot(long long int n){
    long long int i=0, result=0, increment=1;
    while(thing<=(n-result)){
        i+=1;
        result+=increment;
        increment+=2;
    }
    return i;
}

int main(){
	
    cout << squareroot(64);
    return 0;
}