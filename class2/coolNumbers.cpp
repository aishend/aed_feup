#include <iostream>
#include <vector>
using namespace std; 

int main() {
    int pairNumber;
    cin >> pairNumber; 

    vector<vector<int>> pares(pairNumber, vector<int>(2));
    
    for(vector<int>& a : pares) {
        cin >> a[0];
        cin >> a[1];
    }

    for(vector<int> a : pares) {
        // minimo de 9
        int minNine = a[1] / 9;

        for()
    }

    return 0; 
}