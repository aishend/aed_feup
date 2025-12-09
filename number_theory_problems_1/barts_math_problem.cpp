#include <iostream>
#include <vector>
using namespace std; 

void primeFactors(int a, vector<int>& divisors) {
    divisors.clear();

    while(a % 2 == 0) {
        a /= 2; 
        divisors.push_back(2); 
    }

    for (int i = 3; i*i <= a; i +=2) {
        while(a % i == 0) {
            a /= i; 
            divisors.push_back(i); 
        }
    }
    if (a > 1) {
        divisors.push_back(a);
    }
}

int main() {
    int arraySize; 
    cin >> arraySize;

    int a[arraySize];
    vector<int> divisors; 
    for (int i = 0; i < arraySize; i++) {
        cin >> a[i];
        cout << a[i] << "=";
        primeFactors(a[i], divisors);
        for (int& b : divisors) {
            cout << b;
            if (&b != &divisors.back()) cout << "*";
        }
        cout << endl; 
    }    


    return 0; 
}