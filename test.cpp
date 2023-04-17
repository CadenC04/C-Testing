#include <iostream>
#include <cmath>
using namespace std;

/*
	cout << "Enter angle A: ";
	cin >> A;
	cout << "Enter angle B: ";
	cin >> B;
	cout << "Enter angle C: ";
	cin >> C;
*/

double pythagThe(double x, double y, double z) {
	if (z != 0) {
		if (x != 0) {
			return sqrt((z * z) - (x * x));
		}
		else {
			return sqrt((z * z) - (y * y));
		}
	}
	else {
            return sqrt((x * x) + (y * y));
	}
}

int getMissing() {
	double a;
	double b;
	double c;
	double A;
	double B;
	double C;
	cout << "          /|C" << "\n" << "         / |" << "\n";
	cout << "        /  |" << "\n" << "       /   |" << "\n";
	cout << "     c/    |b" << "\n" << "     /     |" << "\n";
	cout << "    /      |" << "\n" << "  A/_______|B" << "\n" << "       a"; 
	cout << "\n" << "\n";
	cout << "Enter side a: ";
	cin >> a;
	cout << "Enter side b: ";
	cin >> b;
	cout << "Enter side c: ";
	cin >> c;

	cout << "Side A: " << a << " Side B: " << b << " Side C: " << c << " " << "\n" << "Output: ";

	if (a != 0 && b != 0 || a != 0 && c != 0 || b != 0 && c != 0) {
		if (a == 0) {
			a = pythagThe(a, b, c);
		}
		else if (b == 0) {
			b = pythagThe(a, b, c);
		}
		else {
			c = pythagThe(a, b, c);
		}
    } else if (a != 0 && b != 0 && c != 0) {
                // can solve for angles
	} else if (a == 0 && b == 0 && c == 0) {
                // cannot get side lengths
    } 

	cout << "Side A: " << a << " Side B: " << b << " Side C: " << c << " " << "\n";

	return 0;
}


int main() {
	cout << "This program will calculate the remaining ";
	cout << "angles and/or sides for the triangle." << "\n";
	cout << "If the data you are being asked to input is ";
	cout << "unknown then just enter 0." << "\n" << "\n";
	getMissing();
	return 0;
}