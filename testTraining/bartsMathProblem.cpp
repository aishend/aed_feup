#include <iostream>
using namespace std;
#include <vector>


vector<int> primes(int n)
{
    for(int i = 2; i*i < n; i++)
    {
        if(n % i == 0) return false;
    }
    return true; 
}
int main()
{
    int size; 
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        int tmp; 
        cin >> tmp; 

        cout << tmp << "=";
        bool isFirst = true; 
        while(tmp != 1)
        {

            for(int i = 2; i <= tmp; i++) {
                if (isPrime(i) && tmp % i == 0)
                {
                    if(!isFirst) cout << "*";
                    cout << i;
                    tmp /= i; 
                    break;
                }
            } 
            isFirst = false; 
        }

        cout << endl; 

    }

}