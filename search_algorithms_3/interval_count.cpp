#include <iostream>
#include <vector>
using namespace std;

int higherBoundIndexFinder(const vector<int>& v, int key) {
    int low = 0; 
    int high = (int)v.size() - 1;
    int res = -1;

    while(low <= high) {
        int middle = low + (high - low) / 2;
        if (key > v[middle]) low = middle + 1;
        else if (key < v[middle]) high = middle - 1;
        else low = middle + 1, res = middle;
    }

    if (res != -1) return res;
    return high >= 0 ? high : -1;
}

int lowerBoundIndexFinder(const vector<int> & v, int key) {
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

    int nQueries;
    cin >> nQueries;
    
    for(int i = 0; i < nQueries; i++) {
        int lowerLimit, higherLimit;
        cin >> lowerLimit >> higherLimit;
        int L = lowerBoundIndexFinder(numbers, lowerLimit);   
        int R = higherBoundIndexFinder(numbers, higherLimit); 

        int count = (L != -1 && R != -1 && R >= L) ? (R - L + 1) : 0;
        cout << count << endl;
 
    }
}