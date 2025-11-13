#include <vector>
#include <iostream>
#include <math.h>    
using namespace std; 
int main() {



    int entradas;
    cin >> entradas; 
    vector<int> numeros(entradas);
    for(int i = 0; i < entradas; i++) cin >> numeros[i];




    int queries; 
    cin >> queries;
    
    #include <math.h>


    for(int i = 0; i < queries; i++)
    {
        int numberToAnalyze;
        cin >> numberToAnalyze; 
        vector<int> bestCase;
        int bestDifference = 1001; 

        for(int w = 0; w < entradas-1; w++) {
            for(int j = w+1; j < entradas; j++) {
                int sum = numeros[w] + numeros[j];

                if (abs(numberToAnalyze - sum) == bestDifference) {
                    bestCase.push_back(sum); 
                }
                else if((abs(numberToAnalyze - sum) < bestDifference)) {
                    bestDifference = abs(numberToAnalyze - sum);
                    bestCase.clear(); 
                    bestCase.push_back(sum);
                }

            } 
        }

        for(int v : bestCase) {
            cout << v << " ";
        }
        cout << endl; 
        



    }
}