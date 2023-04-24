#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

void complexShape(double& Cx, double& Cy, double& Ca);
void simpleShape(double& Cx, double& Cy, double& Ca);
void getData(int val, double& x, double& y, double& a);
void getRect(double& x, double& y, double& a);
void getTriangle(double & x, double& y, double& a);
void getCircle(int subType, double & x, double& y, double& a);
void getCircularSector(double & x, double& y, double& a);
void signum(double& a);
void solveCentroid(double shapes[][3], int sCount, double& Cx, double& Cy, double& Ca);

int main() {
    restart:
    string type;
    double Cx;
    double Cy;
    double Ca;
    cout << "Is it a 'complex', or a 'simple' shape?: ";
    cin >> type;
    if (type == "complex") {
        complexShape(Cx, Cy, Ca);
    } else {
        simpleShape(Cx, Cy, Ca);
    }
    string again;
    cout << "Centroid X: " << Cx << ", " << "Centroid Y: " << Cy << ", " << "Total Area: " << Ca;
    cout << "\n" << "\n" << "Restart? yes/no: ";
    cin >> again;
    if (again == "yes") {
        cout << "\n \n \n \n \n";
        goto restart;
    } else {
        return 0;
    }
    return 0;
}

void simpleShape(double& Cx, double& Cy, double& Ca) {
    int type;
    double x;
    double y;
    double a;
    cout << "\n" << "Please base your coordinates off of 0, 0 expanding in the positive direction." << "\n" << "Negative numbers will NOT work." << "\n";
    cout << "Please enter the number corresponding to the shape you wish to enter: " << "\n";
    cout << "1) Rectangle/Square" << "\n" << "2) Triangle" << "\n" << "3) Circular Shape" << "\n";
    cout << "Enter here: ";
    cin >> type;
    getData(type, x, y, a);
    Cx = x;
    Cy = y;
    Ca = a;
}

void complexShape(double& Cx, double& Cy, double& Ca) {
    int sCount;
    cout << "How many simple shapes make up the composite shape?: ";
    cin >> sCount;
    double shapes[sCount][3];
    for (int i = 0; i < sCount; i++) {
        double x;
        double y;
        double a;
        int type;
        cout << "Please base your coordinates off of 0, 0 expanding in the positive direction." << "\n" << "Negative numbers will NOT work." << "\n";
        cout << "Please make sure any negative spaces fall entirely within the positive space they reside in." << "\n";
        cout << "I am not smart enough nor have the time to compensate for details as such." << "\n \n";
        cout << "Please enter the number corresponding to the shape you wish to enter first: " << "\n";
        cout << "1) Rectangle/Square" << "\n" << "2) Triangle" << "\n" << "3) Circular Shape" << "\n";
        cout << "Enter Here: ";
        cin >> type;
        getData(type, x, y, a);
        shapes[i][0] = x;
        shapes[i][1] = y;
        signum(a);
        shapes[i][2] = a;
    }
    solveCentroid(shapes, sCount, Cx, Cy, Ca);
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
        cin >> subType;
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
            getCircularSector(x, y, a);
            break;
        default:
            break;
        }
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
}

void getCircle(int subType, double & x, double& y, double& a) {
    double xOrig;
    double yOrig;
    double radius;
    cout << "Please enter X: ";
    cin >> xOrig;
    cout << "Please enter Y: ";
    cin >> yOrig;
    cout << "Please enter r: ";
    cin >> radius;
    if (subType == 1) { // Regular Circle
        x = xOrig;
        y = yOrig;
        a = (M_PI * pow(radius, 2));
    } else if (subType == 2) { // Semi-Circle
        double angleOffset;
        cout << "Please enter the degrees of rotation: ";
        cin >> angleOffset;
        double centroid;
        centroid = ((4 * radius) / (3 * M_PI));
        if (angleOffset == 0) {
            x = xOrig;
            y = centroid;
        } else { 
        angleOffset = angleOffset + 90.0;
        cout << angleOffset;
        if (angleOffset == 180) {
            x = ((centroid) * (cos(angleOffset * (M_PI/180))));
            y = yOrig;
        } else if (angleOffset == 270) {
            x = xOrig;
            y = ((centroid) * (sin(angleOffset * (M_PI/180))));
        } else if (angleOffset == 0) {
            x = ((centroid) * (cos(angleOffset * (M_PI/180))));
            y = yOrig;
        } else {
            x = ((centroid) * (cos(angleOffset * (M_PI/180))));
            y = ((centroid) * (sin(angleOffset * (M_PI/180))));
        }
        }
        a = ((M_PI * pow(radius, 2)) / 2);
    } else { // Quarter Circle
        double angleOffset;
        cout << "Please enter the degrees of rotation: ";
        cin >> angleOffset;
        double centroid;
        centroid = ((4 * radius) / (3 * M_PI));
        angleOffset = angleOffset + 45;
        if (angleOffset == 90) {
            x = xOrig;
            y = yOrig + centroid;
        } else if (angleOffset == 135) {
            x = xOrig + (centroid * -1);
            y = yOrig + centroid;
        } else if (angleOffset == 180) {
            x = xOrig + (centroid * -1);
            y = yOrig;
        } else if (angleOffset == 225) {
            x = xOrig + (centroid * -1);
            y = yOrig + (centroid * -1);
        } else if (angleOffset == 270) {
            x = xOrig;
            y = yOrig + (centroid * -1);
        } else if (angleOffset == 315) {
            x = xOrig + centroid;
            y = yOrig + (centroid * -1);
        } else if (angleOffset == 0) {
            x = xOrig + centroid;
            y = yOrig;
        }
        a = ((M_PI * pow(radius, 2)) / 4);
    }
}

void getCircularSector(double & x, double& y, double& a) {
    double xOrig;
    double yOrig;
    double theta;
    double radius;
    double angleOffset;
    double centroid;
    double arc;
    double chord;
    cout << "Please enter X: ";
    cin >> xOrig;
    cout << "Please enter Y: ";
    cin >> yOrig;
    cout << "Please enter r: ";
    cin >> radius;
    cout << "Please enter theta: ";
    cin >> theta;
    cout << "Please enter the degrees of rotation: ";
    cin >> angleOffset;
    chord = ((2 * radius) * (sin((theta / 2))));
    arc = (radius * (M_PI * (theta / 180)));
    a = (pow(radius, 2) * M_PI * (theta / 360));
    centroid = ((2.0 / 3.0) * ((radius * chord) / arc));
    if (angleOffset != 0) {
        angleOffset = ((angleOffset + 90) * (M_PI/180));
        x = ((centroid * (cos(angleOffset))) + xOrig);
        y = ((centroid * (sin(angleOffset))) + yOrig);
    } else {
    x = xOrig;
    y = centroid + yOrig;
    }
}

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

void solveCentroid(double shapes[][3], int sCount, double& Cx, double& Cy, double& Ca) {
    double Axt;
    double Ayt;
    for (int i = 0; i < sCount; i++) {
        double Ax;
        double Ay;
        Ax = (shapes[i][0] * shapes[i][2]);
        Ay = (shapes[i][1] * shapes[i][2]);
        Ca += shapes[i][2];
        Axt += Ax;
        Ayt += Ay;
    }
    Cx = Axt / Ca;
    Cy = Ayt / Ca;
}