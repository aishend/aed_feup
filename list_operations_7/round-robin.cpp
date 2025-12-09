#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int maximumTime;
    cin >> maximumTime;

    int numProcesses; 
    cin >> numProcesses;

    list<pair<string, int>> processes; // name, time left

    for(int i = 0; i < numProcesses; i++) {
        string name; 
        int timeRequired;
        cin >> name >> timeRequired;
        processes.push_back({name, timeRequired});
    }


    int counter = 0; 
    int cycles = 0; 
    while (!processes.empty()) {
        auto it = processes.begin();
        // cout << it->first << " " << it->second <<  endl; 

        cycles++;
        if(it->second > maximumTime) {
            it->second -= maximumTime;
            processes.push_back(*it);
            processes.pop_front();
            counter += maximumTime;
        } else {
            counter += it->second;
            cout << it->first << " " << counter << " " << cycles << endl;
            processes.erase(it);
        }
    
    }
}