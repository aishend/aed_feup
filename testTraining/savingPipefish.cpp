#include <iostream>
#include <vector>

using namespace std; 

int main() {
    int arraySize, windowSize, minDepth;
    cin >> arraySize >> windowSize >> minDepth; 
    vector<bool> piscinas(arraySize);


    for(int i = 0; i < arraySize; i++) {
        int tmp; 
        cin >> tmp; 
        if (tmp >= minDepth) piscinas[i] = true; 
        else piscinas[i] = false;

    }


    int validSections = 0;
    int currentCount = 0; 

    int half = (windowSize  + 1)/ 2;

    for(int i = 0; i < windowSize; i++) { 
        if(piscinas[i]) currentCount++;
    }    

    if (currentCount >= half) validSections++;


    for(int i = windowSize; i < arraySize; i++ ) {
        if (piscinas[i]) currentCount++;
        if(piscinas[i - windowSize]) currentCount--;
        

        if (currentCount >= half) validSections++;
    }


    cout << validSections << endl; 

    return 0;
}