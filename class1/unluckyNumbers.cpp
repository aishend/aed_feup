#include <iostream>

int remove(int a[], int n, int x) {
    int used = 0; 
    int pos = 0; 

    while (pos < n) {
        if (a[pos]!= x) {
            a[used] = a[pos];
            used++;
        } 
        pos++;
    }
    return used;
}

int main() {
    int arraySize;
    int unluckyNumber;
    std::cin >> arraySize;
    std::cin >> unluckyNumber;

    int arrayNumbers[arraySize]; 

    for(int i = 0; i < arraySize; i++) {
        std::cin >> arrayNumbers[i]; 
    }

    int newArraySize = remove(arrayNumbers, arraySize, unluckyNumber);

    std::cout << newArraySize << std::endl; 

    for(int i = 0; i < newArraySize - 1; i++) {
        std::cout << arrayNumbers[i] << " "; 
    }
    std::cout << arrayNumbers[newArraySize - 1] << std::endl;

    return 0; 
}