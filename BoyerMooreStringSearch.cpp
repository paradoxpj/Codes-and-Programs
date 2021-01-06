#include <bits/stdc++.h>

using namespace std;

#define NO_OF_CHARS 256


void BCpreprocess(string pat, int m, int badchar[]){
    //function for Bad Character Heuristics
    
    for(int i=0; i<NO_OF_CHARS; i++)
        badchar[i] = -1;
    
    for(int i=0; i<m; i++)
        badchar[int(pat[i])] = i;
}


void GSpreprocess1(string pat, int m, int bpos[], int shift[]){
    //Function for Good Suffix Heuristic case 1
    
    int i=m, j=m+1;
    bpos[i] = j;
    
    while(i>0){
        while(j<=m && pat[i-1]!=pat[j-1]){
            if(shift[j]==0)
                shift[j] = j-i;
            j = bpos[j];
        }
        i--, j--;
        bpos[i] = j;
    }
    
}


void GSpreprocess2(string pat, int m, int bpos[], int shift[]){
    //Function for Good Suffix Heuristic case 2
    
    int i, j;
    j = bpos[0];
    
    for(i=0; i<=m; i++){
        if(shift[i]==0)
            shift[i]=j;
        if(i==j)
            j = bpos[j];
    }
}



void BoyerMooreSearch(string txt, int n, string pat, int m){
    
    int bpos[m+1], shift[m+1], badchar[NO_OF_CHARS];
    for(int i=0; i<m+1; i++)
        shift[i] = 0;
    
    GSpreprocess1(pat, m, bpos, shift);
    GSpreprocess2(pat, m, bpos, shift);
    BCpreprocess(pat, m, badchar);
    
    int i=0, j;
    int inc1, inc2;  //shift distance calculated by both Heuristics
    while(i <= (n-m)){
        j = m-1;
        while(j>=0 && pat[j]==txt[i+j]){
            j--;
        }
        if(j<0){
            cout << "found at: " << i << endl;
            if((i+m)<n)
                inc1 = m-badchar[txt[i+m]];
            else
                inc1 = 1;
        }
        else{
            inc1 = max(1, j-badchar[txt[i+j]]);
        }
        inc2 = shift[j+1];
        i += max(inc1, inc2);
    }
        
}


int main() {
	
	string txt, pat;
	cin >> txt >> pat;
	int n=txt.length(), m=pat.length();
	
	BoyerMooreSearch(txt, n, pat, m);
	
	return 0;
}
