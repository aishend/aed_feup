#include <list>
#include <iostream>
#include <strstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string music; 
    getline(cin, music);
    
    int numberOfNames; 
    cin >> numberOfNames; 
    list<string> names;

    for(int i = 0; i < numberOfNames; i++) {
        string tmp; 
        cin >> tmp; 
        names.push_front(tmp);
    } 



}