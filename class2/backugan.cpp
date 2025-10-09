#include <iostream> 
using namespace std; 



int main() {
    int nBackugan;
    cin >> nBackugan;
    
    int energy[nBackugan];
    for (int i = 0; i < nBackugan; i++) cin >> energy[i];


    int cumulatativeEnergy[nBackugan];
    cumulatativeEnergy[0] = energy[0];
    for(int i = 1; i < nBackugan; i++) {
        cumulatativeEnergy[i] = energy[i] + cumulatativeEnergy[i - 1];
        //debug
        //cout << cumulatativeEnergy[i] <<endl;
    }

    int numberPhotos;
    cin >> numberPhotos; 
    for (int i = 0; i < numberPhotos; i++) {
        int indice1;
        int indice2; 

        cin >> indice1;
        cin >> indice2;

        //debug 
        //cout << cumulatativeEnergy[indice1-1] << "primeiro indice" <<endl;
        //cout << cumulatativeEnergy[indice2 -1] << "segundo indice" <<endl;
        cout << cumulatativeEnergy[indice2 - 1] - cumulatativeEnergy[indice1 -1] + energy [indice1 -1]<< endl; 
    }

    return 0; 

}