#include <iostream>
#include <cmath>
using namespace std;
#define MAX 20

//Print the forward and stirling differentiation tables
void printDiffTable(float y[][MAX], int n)  {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            cout << y[i][j] << "\t ";
        cout << endl;
    }
}

//Print the backward differentiation tables
void printBackDiffTable(float y[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << y[i][j] << "\t";
        cout << endl;
    }
}

//Selecting the type of data points to be entered
int getState() {
    int equiState = 0;
    cout << "1 - Equisacped\n2 - Not Equisacped" << endl;
    cout << "Select the type of data points to be entered: ";
    cin >> equiState;
    return equiState;
}

//Setting the state of data point inputs
bool setState(int equiState) {
    if(equiState == 1) {
        return true;
    }
    else if(equiState == 2) {
        return true;
    }
    return false;
}

//Calculating the factorial
int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

//Newton forward differentiation method
//Pterm to be used by forward function
float forwardPterm(float p,int it){
    float prod = 1, temp_sum = 0;
    int tag = 0;
    for (int i = 0; i<it; i++){
        if((p-i)!=0){
            prod = prod * (p - i);
        }
        else
            tag = 1;
    }

    if(tag==1)
        return prod;

    for(int i=0; i<it; i++){
            temp_sum += prod /(p-i);
    }
    return temp_sum;
}

//Calculating the difference table
void forwardDiffTable(float y[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
}

//Applying the newton forward differentiation formulae
float forward(float y[][MAX], float p, int n, int index) {
    float derivate = y[index][1];
    for(int i = 2; i < n - index; i++){
        cout<<forwardPterm(p,i)<<endl;
        derivate += ((y[index][i]*forwardPterm(p,i))/(fact(i)));
    }
    return derivate;
}

//Sterling differentiation method
//Forward coeffecient to be used by stirling function
float forward_coeff(float p, int it){
    float prod = 1, temp_sum = 0;
    int tag = 0;
    for (int i = it/2; i > floor(-it/2); i--) {
        if((p-i)!=0){
            prod = prod * (p - i);
        }
        else
            tag = 1;
    }

    if(tag==1)
        return prod;

    for(int i=0; i<it; i++) {
        temp_sum += prod / (p - i);
    }
    return temp_sum;
}

//Backward coeffecient to be used in striling function
float backward_coeff(float p, int it){
    float prod = 1, temp_sum = 0;
    int tag = 0;
    for (int i = floor(-it/2); i < it/2; i++) {
        if((p-i)!=0){
            prod = prod * (p - i);
        }
        else
            tag = 1;
    }

    if(tag==1)
        return prod;

    for(int i=0; i<it; i++) {
        temp_sum += prod /(p-i);
    }
    return temp_sum;
}

//Calculating the difference table
void strilingDiffTable(float y[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
}

//Applying the stirling differentiation formulae
float stirling(float y[][MAX], float p, int n) {
    float term1, term2, derivate = (y[n/2][1] + y[(n/2)-1][1])/2;
    for(int i=2; i<n; i++){
        int mid = (n-i)/2;
        if((n-i)%2==0){
            term1 =y[mid-1][i];
            term2=y[mid][i]/2;
        }
        else
            term1 = term2 = y[mid][i];

        derivate = derivate + (((term1*forward_coeff(p,i)) + (term2*backward_coeff(p,i)))/2)/(fact(i));
    }
    return derivate;
}

//Newton forward differentiation method
//Pterm to be used by forward function
float backwardPterm(float p,int it){
    float prod = 1, temp_sum = 0;
    int tag = 0;
    for (int i = 0; i < it; i++){
        if((p+i)!=0){
            prod = prod * (p + i);
        }
        else
            tag = 1;
    }

    if(tag==1)
        return prod;

    for(int i=0; i < it; i++){
            temp_sum += prod /(p + i);
    }
    return temp_sum;
}

//Calculating the difference table
void backwardDiffTable(float y[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }
}

//Applying the newton stirling differentiation formulae
float backward(float y[][MAX], float p, int n, int index) {
    float derivate = y[index][1];
    for(int i = 2; i <= index; i++){
        cout<<backwardPterm(p,i) <<" : "<<" "<<fact(i)<<endl;
        derivate += (y[index][i] * backwardPterm(p,i)) / fact(i);
        
    }
    return derivate;
}

//Newton Dividend Differentiation
//Pterm to be used by newton function
float newtonPterm(int n, float p, float x[]) {
    float product = 1, term = 0;
    bool set = 0;
    for(int i = 0; i < n; i++) {
        if(p - x[i] == 0) {
            set = 1;
            continue;
        }
        product = product * (p - x[i]);
    }
    if(set) {
        return product;
    }
    for(int i = 0; i < n; i++) {
        term = term + (product /(p - x[i]));
    }
    return term;
}

//Applying the newton dividend differentiation formulae
float newton(float z, float x[], float y[][MAX], int n) {
    float value = y[0][1];
    for(int i = 2; i < n; i++) {
        value = value + newtonPterm(i, z, x) * y[0][i];
    }
    return value;
}

//Calculating the difference table
void newtonDiffTable(float x[], float y[][MAX], int n) {
    for(int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[i + j] - x[j]);
        }
    }
}

//Lagrange Differential 
//Numerator to used in lagrange function
float lagrangePnum(int n, float x[], float z, int K) {
    float num = 0, product = 1;
    bool set = 0;
    for(int i = 0; i < K; i++) {
        if(i == n) {
            continue;
        }
        else if(z == x[i]) {
            set = 1;
            continue;
        }
        product = product * (z - x[i]);
    }
    if(set) {
        return product;
    }
    for(int i = 0; i < K; i++) {
        if(i == n) {
            continue;
        }
        num = num + (product / (z - x[i]));
    }
    return num;
}

//Denominator to used in lagrange function
float lagrangePdenom(int n, float x[], int K) {
    float denom = 1;
    for(int i = 0; i < K; i++) {
        if(i == n)
            continue;
        denom = denom * (x[n] - x[i]);
    }
    return denom;
}

float lagrange(float x[], float y[][MAX], float z, int K) {
    float value = 0;
    for(int i = 0; i < K; i++) {
        value = value + (lagrangePnum(i, x, z, K) * y[i][0] / lagrangePdenom(i, x, K));
    }
    return value;
}

int main() {

    // The status of the input data points
    int equiState = getState(), lenght = 0;
    float x[MAX], y[MAX][MAX], z = 0;
    bool set = setState(equiState);
    while(!set) {
        equiState = getState();
        set = setState(equiState);
    }
    cout << "Enter the number of data points ";
    cin >> lenght;

    if(equiState == 1) {
        // The input of data points for equi-spaced data
        float interval = 1, minDiff;
        int method = 2, minInd = 0;
       cout << "Enter the first value of X: ";
        cin >> x[0];
        cout << "Enter the interval: ";
        cin >> interval;
        for(int i = 1; i < lenght; i++) {
            x[i] = x[i - 1] + interval;
        }
        cout << "Enter the Y values: " << endl;
        for(int i = 0; i < lenght; i++) {
            cin >> y[i][0];
        } 
        cout << "The first differential at x = ";
        cin >> z;

        // Figuring out the best possible method for given data points
        minDiff = z - x[0];
        for(int i = 0; i < lenght/2; i++) {
            if( z>=x[i] && z<x[i+1]){
                minInd = i;
            }
        }
        for(int i = lenght-1; i >= lenght/2; i--) {
            if(x[i]>=z && x[i-1]<z){
                minInd = i;
            }
        }

        if(minInd < lenght * 0.4) {
            method = 1;
        }
        else if(minInd > lenght * 0.6) {
            method = 3;
        }

        // The methods applied
        if(method == 1) {
            // Forward
            float p = (z - x[minInd]) / interval;
            forwardDiffTable(y, lenght);
            cout << "Forward Table: " << endl;
            printDiffTable(y, lenght);
            cout << "Newton Forward Differential = " << forward( y, p, lenght, minInd) / interval << endl;
        }
        else if(method == 2){
            // Stirling
            float p = (z - x[lenght/2]) / interval;
            strilingDiffTable(y, lenght);
            cout << "Stirling Table: " << endl;
            printDiffTable(y, lenght);
            cout << "Stirling Differential = " << stirling(y, p, lenght) / interval << endl;
        }
        else if(method == 3) {
            // Backward
            float p = (z - x[minInd]) / interval;
            backwardDiffTable(y, lenght);
            cout << "Backward Table: " << endl;
            printBackDiffTable(y, lenght);
            cout << "Newton Backward Differential = " << backward(y, p, lenght, minInd) / interval << endl;
        }
        else {
            cout << "The value cannot be evaluated" << endl << "Out of bound" << endl;
        }
    }
    else {
        // The input of data points for unequi-spaced data
        cout << "Enter the X values: " << endl;
        for(int i = 0; i < lenght; i++) {
            cin >> x[i];
        }
        cout << "Enter the Y values: " << endl;
        for(int i = 0; i < lenght; i++) {
            cin >> y[i][0];
        }
        cout << "The first differential at x = ";
        cin >> z;

        // Newton
        newtonDiffTable(x, y, lenght);
        cout << "Newton Dividend Differential Table:" << endl;
        printDiffTable(y, lenght);
        cout << "Newton Dividend Differential = " << newton(z, x, y, lenght) << endl;

        // Lagrange
        cout << "Lagrange Differential = " << lagrange(x, y, z, lenght) << endl;
    }
    return 0;
}
