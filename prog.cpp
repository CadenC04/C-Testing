#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

void calcCent(int points[][2], int pCount) {

    for (int i = 0; i < pCount; i++) {

    }
}



void getData() {
    int pCount;
    cout << "Enter # of points: ";
    cin >> pCount;
    int points[pCount][2];
    for (int i = 0; i < pCount; i++) {
        int x;
        int y;
        cout << "Enter point x" << i + 1 << ": ";
        cin >> x; 
        cout << "Enter point y" << i + 1 << ": ";
        cin >> y;
        points[i][0] = x;
        points[i][1] = y;
    }
    calcCent(points, pCount);
}



int main() {
    getData();
    return 0;
}

//https://owlcation.com/stem/How-to-Solve-Centroids-of-Compound-Shapes
//https://www.omnicalculator.com/math/centroid#centroid-of-a-set-of-points