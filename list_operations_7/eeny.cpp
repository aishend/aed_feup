#include <iostream>
#include <list> 
#include <string> 
#include <algorithm>

using namespace std; 


int main() {

    list<string> names;
    string music;
    getline(cin, music); 
    int num_names; 
    cin >> num_names;

    for ( int i = 0; i < num_names; i++) {
        string name; 
        cin >> name; 
        names.push_back(name); 
    }

    auto it = names.begin(); 
    while (names.size() != 0) {
        for (int i = 0; i < count(music.begin(), music.end() + 1, ' ') + 2; i++) {
            if (it == names.end()) {
                it = names.begin(); 
            }

            // Eliminate the current name
            if (i == count(music.begin(), music.end(), ' ')) {
                cout << *it << endl;
                it = names.erase(it); 
                it++;
                if (it == names.end()) {
                    it = names.begin(); 
                }
            }
            else {
                it++; 
            }
            
        }
    }

}