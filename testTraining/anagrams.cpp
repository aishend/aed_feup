#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string normalize(const string& phrase) {
    string filtered;
    for (char c : phrase) {
        if (isalpha(c)) { // mantém só letras
            filtered += tolower(c);
        }
    }
    sort(filtered.begin(), filtered.end());
    return filtered;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // para consumir o \n do número

    vector<string> keys(N);
    for (int i = 0; i < N; i++) {
        string phrase;
        getline(cin, phrase);
        keys[i] = normalize(phrase);
    }

    sort(keys.begin(), keys.end());

    int countClasses = 0, groupCount = 1;
    for (int i = 1; i < N; i++) {
        if (keys[i] == keys[i - 1]) {
            groupCount++;
        } else {
            if (groupCount > 1) countClasses++;
            groupCount = 1;
        }
    }
    if (groupCount > 1) countClasses++;

    cout << countClasses << "\n";

    return 0;
}
