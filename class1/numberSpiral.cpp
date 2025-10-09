#include <iostream>
using namespace std; 
struct cordinates {
    int x; 
    int y; 
};

int square(int n) {
    for (int i = 1; i <= n; i++) {
        if (i*i >= n) {
            return i;
        } 
    }
    return -1; 
}

cordinates cornerMapping(int point) {
    if (point == 1) return {0, 0};
    cordinates final; 
    int lado = square(point);
    int max_horizontal;
    int max_vertical; 
    int seg = lado - 1;
    int d = lado*lado - point;

    if (lado % 2) {
        int k = lado/2;
        cordinates corner = {k, k};
        max_horizontal = seg;

        if (d < seg) {
            final.x = corner.x - d;
            final.y = corner.y;
        } else if (d < 2*seg) {
            final.x = corner.x - seg;
            final.y = corner.y - (d - seg);
        } else if (d < 3*seg) {
            final.x = corner.x - seg + (d - 2*seg);
            final.y = corner.y - seg;
        } else {
            final.x = corner.x;
            final.y = corner.y - seg + (d - 3*seg);
        }
    } else {
        int k = lado/2;
        cordinates corner = {-k + 1, -k};
        max_horizontal = seg;

        if (d < seg) {
            final.x = corner.x + d;
            final.y = corner.y;
        } else if (d < 2*seg) {
            final.x = corner.x + seg;
            final.y = corner.y + (d - seg);
        } else if (d < 3*seg) {
            final.x = corner.x + seg - (d - 2*seg);
            final.y = corner.y + seg;
        } else {
            final.x = corner.x;
            final.y = corner.y + seg - (d - 3*seg);
        }
    };

    return final; 
}

int main() {
    int point;
    cin >> point;

    cordinates final = cornerMapping(point);
    cout << "(" << final.x << "," << final.y << ")" << endl;
    return 0; 
}
