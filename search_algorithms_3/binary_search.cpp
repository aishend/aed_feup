#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nNumbers;
    cin >> nNumbers;
    
    vector<int> numbers(nNumbers ); 
    for(int i = 0; i < nNumbers; i++) cin >> numbers[i];

    int queries;
    cin >> queries; 

    for(int i = 0; i < queries; i++) {
        int search; 
        cin >> search;
        
        int low = 0, high = nNumbers - 1; 
        bool keyFound = false; 

        while (low <= high) {
            int middle = low + (high - low) / 2;
            
            if (search < numbers[middle]) high = middle - 1;
            
            else if (search > numbers[middle]) low = middle + 1 ;

            else {
                keyFound = true, cout << middle << endl;
                break;
            }

        } 
        if(!keyFound) {
            cout << -1 << endl; 
        }
    }

    
    return 0; 
}