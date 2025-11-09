#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int nPeople;
    int nBest;

    cin >> nPeople >> nBest;

    vector<int> people(nPeople);
    for (int i = 0; i < nPeople; i++) cin >> people[i];

    sort(people.begin(), people.end());
    for (int i = nPeople -1; i > nPeople-  1- nBest; i--) {
        cout << people[i] << endl;
    }

    return 0;
}