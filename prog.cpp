#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

void breakdownShape();
void getData(int val, double& x, double& y, double& a);
void getRect(double& x, double& y, double& a);
void getTriangle(double & x, double& y, double& a);
void getCircle(int subType, double & x, double& y, double& a);
void getCircularSector();
void getArc();
void getSpandrel();
void signum(double& a);

int main() {
    string type;
    cout << "Is it a 'complex', or a 'simple' shape?: ";
    cin >> type;
    if (type == "complex") {
        breakdownShape();
    } else {
        return 0;
    }
    return 0;
}

void breakdownShape() {
    int sCount;
    double Cx;
    double Cy;
    double Ca;
    cout << "How many simple shapes make up the composite shape?: ";
    cin >> sCount;
    double shapes[sCount][3];
    for (int i = 0; i < sCount; i++) {
        double x;
        double y;
        double a;
        int type;
        cout << "Please base your coordinates off of 0, 0." << "\n";
        cout << "Please enter the number corresponding to the shape you wish to enter first: " << "\n";
        cout << "1) Rectangle/Square" << "\n" << "2) Triangle" << "\n" << "3) Circular Shape" << "\n" << "4) Arc" << "\n" "5) Spandrel" "\n";
        cout << "Enter Here: ";
        cin >> type;
        getData(type, x, y, a);
        shapes[i][0] = x;
        shapes[i][1] = y;
        shapes[i][2] = a;
    }
}

void getData(int type, double& x, double& y, double& a) {
    switch (type)
    {
    case 1:
        getRect(x, y, a);
        break;
    case 2:
        getTriangle(x, y, a);
        break;
    case 3:
        int subType;
        cout << "1) Circle" << "\n" << "2) Semi-Circle" << "\n" << "3) Quarter-Circle" << "\n" << "4) Circular Sector" << "\n" << "Enter here: ";
        switch (subType)
        {
        case 1:
            getCircle(1, x, y, a);
            break;
        case 2:
            getCircle(2, x, y, a); //semi
            break;
        case 3:
            getCircle(3, x, y, a);//quarter
            break;
        case 4:
            getCircularSector();
            break;
        default:
            break;
        }
        break;
    case 4:
        int subType;
        cout << "1) Segment Arc" << "\n" << "2) Semicircular Arc" << "\n" << "Enter here: ";
        cin >> subType;
        switch (subType)
        {
        case 1:
            getArc(); //segment arc
            break;
        case 2:
            getArc(); //semicircular arc
            break;
        default:
            break;
        }
        break;
    case 5:
        getSpandrel(); // what is this thing?
        break;
    default:
        break;
    }
}

void getRect(double& x, double& y, double& a) {
    double points[4][2];
    for (int i = 0; i < 4; i++) {
        double xx;
        double yy;
        cout << "Please enter X" << i << ": ";
        cin >> xx;
        cout << "Please enter Y" << i << ": ";
        cin >> yy;
        points[i][0] = xx;
        points[i][1] = yy;
    }
    x = ((points[0][0] + points[1][0] + points[2][0] + points[3][0]) / 4);
    y = ((points[0][1] + points[1][1] + points[2][1] + points[3][1]) / 4);
    a = (sqrt(pow((points[1][0] - points [0][0]), 2) + pow((points[1][1] - points[0][1]), 2)) * sqrt(pow((points[3][0] - points [0][0]), 2) + pow((points[3][1] - points[0][1]), 2)));
    signum(a);
}

void getTriangle(double & x, double& y, double& a) {
    double points[3][2];
    for (int i = 0; i < 3; i++) {
        double xx;
        double yy;
        cout << "Please enter X" << i << ": ";
        cin >> xx;
        cout << "Please enter Y" << i << ": ";
        cin >> yy;
        points[i][0] = xx;
        points[i][1] = yy;
    }
    x = ((points[0][0] + points[1][0] + points[2][0]) / 3);
    y = ((points[0][1] + points[1][1] + points[2][1]) / 3);
    a = (((points[1][1] - points[0][1]) * (points[2][0] - points[0][0])) / 2);
    signum(a);
}

void getCircle(int subType, double & x, double& y, double& a) {
    double xx;
    double yy;
    double rr;
    cout << "Please enter X: ";
    cin >> xx;
    cout << "Please enter Y: ";
    cin >> yy;
    cout << "Please enter r: ";
    cin >> rr;
    if (subType == 1) {
        x = xx;
        y = yy;
        a = (M_PI * pow(rr, 2));
    } else if (subType == 2) {
        double angle;
        cout << "Please enter the degrees of rotation: ";
        cin >> angle;
        double theta = (angle * (M_PI/180));
        double ty;
        ty = ((4 * rr) / (3 * M_PI));
        x = xx;
        y = (ty * (sin(theta)));
        a = ((M_PI * pow(rr, 2)) / 2);
    } else {
        double angle;
        cout << "Please enter the degrees of rotation: ";
        cin >> angle;
        double theta = (angle * (M_PI/180));
        double ty;
        ty = ((4 * rr) / (3 * M_PI));
        x = (ty * (cos(theta)));
        y = (ty * (sin(theta)));
        a = ((M_PI * pow(rr, 2)) / 4);
    }
}
/*
void getCircularSector();
void getArc();
void getSpandrel();
*/






void signum(double& a) {
    int space;
    cout << "1) Positive Space" << "\n" << "2) Negative Space" << "\n" << "Enter here: ";
    cin >> space;
    if (space == 0) {
        a = (a * (-1));
    } else {
        a = a;
    }
}

//https://owlcation.com/stem/How-to-Solve-Centroids-of-Compound-Shapes
//https://www.omnicalculator.com/math/centroid#centroid-of-a-set-of-points