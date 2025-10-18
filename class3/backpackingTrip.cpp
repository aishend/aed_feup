#include <iostream>
#include <vector>

using namespace std;

// x = maximo, k igual ao numreo de grupos
bool isPossible(const vector<int> & v, int x, int k) {
    int sum = 0;
    int groupCount = 0;

    for(int i = 0; i < v.size(); i ++) {
        
        if (sum + v[i] <= x) {
            if (i == v.size() - 1) return true;
            sum += v[i];
            
        } else {
            if (groupCount == k - 1) return false;
            sum = v[i];
            groupCount++;
        }
    }
    return false;
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
        int low = 1;
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
