#include <vector>
#include <algorithm>
#include <iostream>
using namespace std; 
int countBits(int number)
{
    int counter = 0; 
    while(number > 0)
    {
        counter += number & 1;  
        number = number >> 1;
    }
    return counter;
}

bool compareBits(const int& number1, const int& number2)
{
    int c1 = countBits(number1);
    int c2 = countBits(number2);
    if (c1 != c2)
        return c1 > c2;
    else
        return number1 < number2; 
}

int main() {
    int nNumbers;
    cin >> nNumbers;
    vector<int> numbers(nNumbers);
    for (int i = 0; i < nNumbers; i++) cin >> numbers[i];
    sort(numbers.begin(), numbers.end(), compareBits);
    for (int i = 0; i < nNumbers; i++) cout << numbers[i] << endl;

    return 0; }