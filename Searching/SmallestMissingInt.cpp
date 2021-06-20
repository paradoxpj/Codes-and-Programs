#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int N;
    cout << "Enter N (Where N is the total numbers to input) : ";
    cin >> N;  
    
    int range;
    cout << "Enter range for integers in input data (value upto): ";
    cin >> range;
    
    vector<bool> present(range + 1, false); 
    // present vector to keep track of input integers (If the are present or not)
    // size (range + 1) for range of input integers
    
    cout << "Enter N integers in the range 1 - " << range << " (Inclusive) :\n";
    
    int temp; // to input integers
    
    for (int i = 1; i <= N; i++){ 
        cin >> temp;
        present[temp] = true; 
        // changes temp-th index to true which indicates integer temp is present in input data
    }
    
    // going through "present" vector to find first index with false value
    // false value tells us that this element is not present in input data
    for (int i = 1; i <= range; i++){  
        
        if (!present[i]){
            cout << "First missing positive integer : " << i;
            return 0; // exits program
        }
        
    }
    
    cout << "All integer int the range 1 - " << range << " are present";   // In case all the elements in the given range are present
    
    return 0;
}
