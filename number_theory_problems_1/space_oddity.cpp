#include <iostream>


inline bool isOdd(int number) {
    return (number & 1) != 0; 
}


int lastOddNumber = -1; 
int count = 0;

int removeOds(int a[], int arraySize) {



    for (int i = 0; i < arraySize; i++) {
        if (isOdd(a[i])) {
            count ++; 
            lastOddNumber= a[i];
        }
    }


    return count;
}
using namespace std; 

int main() {
    int arraySize;
    cin >> arraySize;

    int arrayA[arraySize]; 
    
    for (int i = 0; i < arraySize; i++) {
        int tmp;
        cin >> tmp; 
        arrayA[i] = tmp; 
    }
    removeOds(arrayA, arraySize);
    cout << count << " " << lastOddNumber << endl;
    return 0; 
}