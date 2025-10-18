#include <vector>
#include <iostream>
using namespace std; 

int lowerBound(const vector<int> & v, int key) {
    int high = (int)v.size() - 1;
    int low = 0; 
    int res = -1;

    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) {high = middle - 1 ;}
        else if (key > v[middle]) {low = middle + 1;}
        else {
            high = middle - 1, res = middle;
        }
    }
    if (res != -1) return res;
    return (low < (int)v.size()) ? low : -1;

}

int main() {
    int nNumbers;
    cin >> nNumbers; 

    vector<int> numbers(nNumbers);

    for(int i = 0; i < nNumbers; i++) cin >> numbers[i];

    int nKeys;
    cin >> nKeys;

    for(int i = 0; i < nKeys; i++) {int key; cin >> key; cout << lowerBound(numbers, key) << endl;}
    
    return 0; 
}