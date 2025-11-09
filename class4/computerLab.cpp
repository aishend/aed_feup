#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct par {
    int numero;
    int isPresennt;
};
int main() {
    
    vector<par> times;
    vector<bool> isPresent;    
    int nStudents; 
    cin >> nStudents;


    for(int i = 0; i < nStudents; i++) 
    {
       int beginTime; 
       int endTime;
    
       cin >> beginTime >> endTime;
       times.push_back({beginTime, true});
       times.push_back({endTime, false});
       

       
    }
    sort(times.begin(), times.end(),
        [](const par& a, const par& b) {return a.numero < b.numero;});
    int counter = 0;
    int actual = 0; 
    for (int i = 0; i < times.size(); i++)
    {

        if (times[i].isPresennt) actual++;
        else actual--;

       if (actual > counter) {
        counter  = actual;
       } 
    }
    cout << counter << endl;
    return 0; 


}