#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

void calcCent(int points[][2], int pCount) {
double Cx;
double Cy;
double Aix;
double Aiy;
    for (int i = 0; i < pCount; i++) {
        Aix += points[i][0];
        Aiy += points[i][1];
        cout << points[i][0] << " ";
        cout << points[i][1] << " ";
    }
    Cx = (Aix / pCount);
    Cy = (Aiy / pCount);
    cout << Aix << " " << Aiy << "\n";
    cout << "Centroid X: " << Cx << "\n";
    cout << "Centroid Y: " << Cy << "\n";
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

void breakdownShape() {
    
}



int main() {
    string type;
    cout << "Please enter the type of shape: (complex or simple N-Sided polygon)";
    cin >> type;
    if (type == "complex") {
        breakdownShape();
    } else {
        getData();
    }
    return 0;
}

//https://owlcation.com/stem/How-to-Solve-Centroids-of-Compound-Shapes
//https://www.omnicalculator.com/math/centroid#centroid-of-a-set-of-points