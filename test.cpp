#include <iostream>
#include <cmath>
using namespace std;

/*
000 // null
111 // all sides solve angles
110 // 2 sides pythag then solve angles
011 // 2 sides pythag then solve angles
101 // 2 sides pythag then solve angles

*/

void getEquation(double a, double b, double c, double A, double B, double C) {
	string type;
	if (a != 0) {
		type += "1";
	} else {
		type += "0";
	}
	if (b != 0) {
		type += "1";
	} else {
		type += "0";
	}
	if (c != 0) {
		type += "1";
	} else {
		type += "0";
	}
	int Type = stoi(type);

	switch (Type)
	{
	case 0:
		cout << "Null";
		break;
	case 111: 
		cout << "111";
		break;
	case 110:
		cout << "110";
		break;
	case 11:
		cout << "011";
		break;
	case 101:
		cout << "101";
		break;
	default:
		break;
	}
}









void getData() {
	double a, b, c, A, B, C;
	cout << "Enter side a: ";
	cin >> a;
	cout << "Enter side b: ";
	cin >> b;
	cout << "Enter side c: ";
	cin >> c;
	cout << "Enter angle A: ";
	cin >> A;
	cout << "Enter angle B: ";
	cin >> B;
	cout << "Enter angle C: ";
	cin >> C;
	getEquation(a, b, c, A, B, C);
}

/*
	cout << "          /|C" << "\n" << "         / |" << "\n";
	cout << "        /  |" << "\n" << "       /   |" << "\n";
	cout << "     c/    |b" << "\n" << "     /     |" << "\n";
	cout << "    /      |" << "\n" << "  A/_______|B" << "\n" << "       a"; 
	cout << "\n" << "\n";
*/


int main() {
	cout << "This program will calculate the remaining ";
	cout << "angles and/or sides for the triangle." << "\n";
	cout << "If the data you are being asked to input is ";
	cout << "unknown then just enter 0." << "\n" << "\n";
	getData();
	return 0;
}




/*
	if (A != 0) {
		type += "1";
	} else {
		type += "0";
	}
	if (B != 0) {
		type += "1";
	} else {
		type += "0";
	}
	if (C != 0) {
		type += "1";
	} else {
		type += "0";
	}
*/