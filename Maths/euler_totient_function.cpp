/*
Euler's totient function, also known as phi-function ϕ(n), counts the number of integers between 1 and n inclusive, which are co prime to n. 
*/

#include <iostream>
#include <vector>
using namespace std;


int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << "Euler totient function value for n = " << n << " is " << phi(n) << endl;
    return 0;
}
