#include <iostream>
#include <vector>
using namespace std; 

int main() {
    int nPosRiver, length, minDepth;
    cin >> nPosRiver >> length >> minDepth;

    //guardar onde os valores sao maiores
    vector<int> seq(nPosRiver, false);
    for(int i = 0; i < nPosRiver; i++) {
        int tmp; 
        cin >> tmp; 
        if (tmp >= minDepth) seq[i] = true;
    }

    int validZone = 0; 
    int counter = 0;


    for(int i = 0; i < length; i++) {
        if (seq[i]) counter++;
    }

    if (counter >= (length + 1) / 2) {
        validZone++;
    }

    for(int i = length; i < nPosRiver; i++) {
        if (seq[i - length]) {
            counter--;
        }

        if (seq[i]) {
            counter++;
        }

        if (counter >= (length + 1) / 2) {
            validZone++;
        }
    }



    cout << validZone << endl; 
    return 0; 
}