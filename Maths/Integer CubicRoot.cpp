//This program provides the integer cubic root or in other words,
//the floor of the cubic root of any number while also avoiding overflow.
//Time complexity is O(cubicroot(n))


#include<bits/stdc++.h>

using namespace std;

long long int  cuberoot(long long int n){
    long long int i=0, result=0, inc1=1, inc2=0;
    while(thing<=(n-result)){
        i+=1;
        result+=inc1;
        inc2+=6;
        inc1+=inc2;
    }
    return i;
}

int main(){
	
    cout << cuberoot(64);
    return 0;
}