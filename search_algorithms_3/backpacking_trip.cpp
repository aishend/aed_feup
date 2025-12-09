#include <iostream>
#include <vector>

using namespace std;

// x = maximo, k igual ao numreo de grupos
bool isPossible(const vector<int> & v, int x, int k) {
    int sum = 0;
    int groups = 1;
    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i] > x) return false;        
        if (sum + v[i] <= x) {
            sum += v[i];
        } else {
            groups++;
            sum = v[i];
            if (groups > k) return false;
        }
    }
    return true;
}

int main() {
    int nDistances;
    cin >> nDistances;

    vector<int> distances(nDistances);
    
    int sumAll = 0;
    for(int i = 0; i < nDistances; i++) {
        cin >> distances[i]; 
        sumAll += distances[i];
    }


    int nDifNDays;
    cin >> nDifNDays;
    int nDays;
    
    for(int i = 0; i < nDifNDays; i++) {
        int res;
        int low = 0;
        int high = sumAll;
        cin >> nDays;

        while(low <= high) {
            int middle = low + (high - low) / 2;
            if (isPossible(distances, middle, nDays)) high = middle - 1, res = middle;
            else low = middle + 1; 
        }
        cout << res << endl;
    }

    return 0;
}