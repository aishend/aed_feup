#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int nChests, initialPos, nInstructions, finalCount = 0;
    string treasures;

    cin >> nChests >> initialPos >> nInstructions >> treasures;

    int cumulatativeSteps_size = nInstructions + 1;
    int cumulatativeSteps[cumulatativeSteps_size];
    cumulatativeSteps[0] = initialPos;

    for (int i = 1; i <= nInstructions; i++) {
        char direction;
        int steps;
        cin >> direction;
        cin >> steps;

        if (direction == 'L') steps = -steps;

        cumulatativeSteps[i] = cumulatativeSteps[i - 1] + steps;
    }

    int minv = cumulatativeSteps[0];
    int maxv = cumulatativeSteps[0];
    for (int i = 1; i <= nInstructions; ++i) {
        if (cumulatativeSteps[i] < minv) minv = cumulatativeSteps[i];
        if (cumulatativeSteps[i] > maxv) maxv = cumulatativeSteps[i];
    }

    //cout << minv << " " << maxv << endl;

    for (int i = minv; i <= maxv; i++) {
        if (treasures[i - 1] == 'T') finalCount++;
    }
    cout << finalCount << endl;

    return 0;
}
