#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {

    int nSequence;
    cin >> nSequence; 

    vector<int> numbers(nSequence);
    for(int i = 0; i < nSequence; i++) {
        cin >> numbers[i]; 
    }
    
    int res = numbers[0];
    int maxEnding = res; 
    for(int i = 1; i < nSequence; i++) {
        maxEnding = max(numbers[i], maxEnding + numbers[i]);
        res = max(res, maxEnding);

    }
    

    cout << res << endl; 
    return 0; 
}